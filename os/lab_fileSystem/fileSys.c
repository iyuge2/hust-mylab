/*
 * filename: fileSys.c
 * creat-time: 20161228 11:31
 * update-time: 20161228 14:47
 * function: "ls -lR"
 * */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<time.h>
#include<pwd.h>

/*判断非目录文件类型*/
char filetype(struct stat* s)
{
    switch(s->st_mode & S_IFMT){
        case S_IFBLK: return 'b';//块设备文件
        case S_IFCHR: return 'c';//一次性读写文件
        case S_IFDIR: return 'd';//目录
        case S_IFIFO: return 'p';//输入输出流文件
        case S_IFLNK: return 'l';//链接文件
        case S_IFREG: return '-';//普通文件
        case S_IFSOCK: return 's';
        default:
            return '@';//出错标志，自己设的
    }
}

/*返回权限类型*/
char* filerwx(unsigned short n)
{
    switch(n){
        case 0:
            return "---";
        case 1:
            return "--x";
        case 2:
            return "-w-";
        case 3:
            return "-wx";
        case 4:
            return "r--";
        case 5:
            return "r-x";
        case 6:
            return "rw-";
        case 7:
            return "rwx";
        default:
            fprintf(stderr,"RWXerror");
    }
}

/*
 * op->0 ls
 * op->1 ls -l
 * op->2 ls -R
 * op->3 ls -lR
 * */
void printdir(char *dir,int depth,int op)
{
    char *t;
    unsigned long totalSize = 0;
    DIR *dp;
    struct passwd *gname,*uname;
    struct dirent *entry;
    struct stat statbuf;
    if((dp = opendir(dir)) == NULL){
        fprintf(stderr,"open %s dir error!\n",dir);
        exit(0);
    }
    chdir(dir);//将dir设置为当前目录
    while((entry = readdir(dp)) != NULL){
        lstat(entry->d_name,&statbuf);
        totalSize += statbuf.st_size;
        if((op >= 2) && S_ISDIR(statbuf.st_mode)){//此文件为目录且有-R
            if(strcmp(entry->d_name,".") == 0 || strcmp(entry->d_name,"..") == 0){
                continue;
            }
            printf("<dir>%s.:\n",entry->d_name);
            printdir(entry->d_name,depth+4,op);//递归打印目录
        }
        else{//非目录或无-R
            if(!(op % 2)){//ls
                printf("%s\n",entry->d_name);
            }
            else{//ls -l
                t = ctime(&statbuf.st_ctime);
                strncpy(t,t,strlen(t)-1);
                t[strlen(t)-1] = '\0';
                /*以上三行为了去掉ctime默认加的\n*/
                gname = getpwuid(statbuf.st_gid);
                uname = getpwuid(statbuf.st_uid);
                printf("%c%s%s%s %4ld %s %s %8ld %s %s\n",filetype(&statbuf),filerwx((statbuf.st_mode & 0700) >> 6),\
                        filerwx((statbuf.st_mode & 070) >> 3),filerwx(statbuf.st_mode & 07),(long)statbuf.st_nlink,\
                        uname->pw_name,gname->pw_name,statbuf.st_size,t,entry->d_name);
                /*st_mode为8进制数*/
            }
        }
    }
    printf("Total size: %ld\n\n",totalSize);
    chdir("..");
    closedir(dp);
}

int main(int argc,char**argv)
{
    char *topdir = ".";//初始化为当前目录
    int i = 1;
    while(i < argc){//判断目录
        if(argv[i][0] != '-'){
            topdir = argv[i];
            break;
        }
        ++i;
    }
    if(argc >= 2){//判断参数
        for(i = 1;i < argc;++i){
            if(argv[i][0] == '-'){
                if(!strcmp(argv[i],"-l")){
                    printdir(topdir,0,1);
                }
                else if(!strcmp(argv[i],"-R")){
                    printdir(topdir,0,2);
                }
                else if(!strcmp(argv[i],"-lR")){
                    printdir(topdir,0,3);
                }
                return 0;
            }
        }
    }
    printdir(topdir,0,0);
    return 0;
}
