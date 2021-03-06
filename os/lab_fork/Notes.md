#<center>进程的创建与进程之间通信  
    本次实验中,涉及了Linux环境下子进程的创建(fork),父子进程之间信号的传递(signal)以及兄弟进程之间数据的传递(管道)  
###目录  
*	[进程的创建](#进程的创建)  
*	[进程的等待](#进程的等待)  
*	[进程的退出](#进程的退出)  
*	[信号的传递](#信号的传递--signal)  
*	[数据的传递](#数据的传递--管道pipe)  

![just for you](../../pg/just for you.jpg) 
####*进程的创建*   
使用fork()函数可以直接创建一个当前进程的副本,该函数无参,但是,有两个返回值. 返回值中等于0的为子进程,大于0的为父进程.  
 所以,可以采用如下方式对两个进程进行操作.  
 
	int p1;  
	p1 = fork();  
	if(p1 == 0){  
        	;//执行子进程操作  
	}  
        else{//实际上是else if(p1 > 0)  
            ;//执行父进程操作  
        }    
注意:首先,要明白进程与上次线程之间的区别,线程之间是共用地址空间的,需要特别理解其中**副本**的概念,就是父子进程虽然有不同的地址空间,但是两者会执行**完全相同**的两份代码,因此,若要再用父进程创建一个子进程,应该在只有父进程可以进入的语句块中去再次fork(), 创建子进程2,否则,若在语句p1=fork();后面加上p2=fork();那么,后面那条fork语句将会被执行两次,分别是父进程和子进程1创建的. 显然这不是我们所需要的.而采用前面的方式,当父进程需要创建多个子进程时,if-else的深度将是不可想象的.为了避免这个,可以使用exec函数族,使得父子进程相互独立.因此,linux中去创建一个真正独立的子进程往往需要两步--fork()&&exec(这是一个函数**族**).   

 *	引申:  
exec函数族的作用是根据指定的文件名找到可执行文件,并用它来取代调用进程的内容.即在调用进程内部执行一个可执行文件.这个可执行文件可以是二进制文件,也可以是任何Linux下可执行的脚本文件.  
exec函数族中包括六个函数:(path-->文件路径)  

            int execl(const char*path,const char*arg,...);  
            int execlp(const char* file,const char*arg,...);  
            int execle(const char*path,const char*arg,...,char*const envp[]);  
            int execv(const char*path,char*const argv[]);  
            int execvp(const char*file,char* const argv[]);  
            int execve(const char*path,char*const argv[],char*const envp[]);  
 exec用被执行的程序替换调用它的程序,与fork的区别是:fork创建一个新的进程,产生一个新的PID;  
 exec启动一个新程序,替换原有的进程,因此进程的PID不会改变.两者经常搭配使用. 如一个进程希望  
 执行另一个程序时,就可以先利用fork函数创建出一个新进程,然后调用任何一个exec函数执行希望执行的那个程序. 

####*进程的等待*  
进程的等待用到的函数是wait,也可以用waitpid.对于两者的用法可以直接man一下. 对于函数wait,其原型为int wait(int*status);当父进程调用此函数时,父进程将会一直等待,一直到有一个子进程结束为止,然后, 将子进程结束的转态用status返回.  
        -->若当前进程没有任何子进程时,该函数返回-1.  
        -->若当前进程有子进程,但是却没有调用等待函数时,子进程将会变成僵尸进程.当然,若父进程结束,其子进程将会自动挂载到其祖父进程上,在linux中,一般会挂载到终极进程**init**上,毕竟,linux中所有的进程都是由其产生.  
####*进程的退出*  
进程退出使用的函数是exit,当退出值为0[exit(0)]时,表示正常退出,非0[一般为exit(1)]时为异常退出.平时写C语言代码时,用的更多的是return语句.但其实两者之间是有区别的:return是一个关键字,一般用于函数的返回,内部涉及的其实是堆栈调用的返回,并不会结束进程,只是平时在C语言中main函数被return时,其进程也随之终止;  
而exit是一个函数,是系统级别的退出,直接结束进程,并关闭所有的I/O流的操作.另外,还有一个异常退出函数是abort(),它只用于异常退出,会返回一个异常退出码.在C++中这三者之间的区别则表现得更为直观了----析构函数.  
####*信号的传递--signal*  
signal函数用于设置信号,表示如果接收到某信号时,该采取什么响应,一般是一个信号处理函数. 所以,signal函数有两个参数,第一个是信号的类型,第二个是函数指针.表示当检测到这个信号时,转向指向该函数指针所指向的函数.当然,也可以对收到的信号进行忽略(SIG_IGN)或者执行系统的默认操作.  
本实验中涉及到三种信号类型--SIGINT,SIGUSR1,SIGUSR2  

            SIGINT--用于接收软中断信息,linux下为(ctrl-c)  
            SIGUSR1,SIGUSR2--用户自定义的信号  
 所以,本实验中,由于在fork之前设置了软中断信息,所以在子进程调用的函数中应该忽略软中断信息--signal(SIGINT,SIG_IGN);  
注: 终止或停止信号(SIGKILL和SIGSTOP)是不能忽略的!  
所以,当碰到僵尸进程时,可以在另一个终端中利用kill命令将其杀死.  
####*数据的传递--管道pipe*  

        int pipefd[2];  
        pipe(pipefd);  
上面两行代码将会创建一个无名管道,返回两个管道描述符,读描述符--pipefd[0] && 写描述符--pipefd[1].  
管道实际上是一个缓冲区,当创建进程时,并不会增加新的管道,即父子进程共用一个管道,那么此实验中有三个读描述符和三个写描述符指向同一个管道.根据需求,可以使用close();关闭相应的管道描述符.比如:close(pipefd[0]);将关闭当前进程的读描述符.那么,该进程将不能从管道中读取数据.  

        往管道中读取数据的函数为read(int pid,void *buf,int size);  
                            write(int pid,void *buf,int size);  
            参数说明:pid--当前进程的标识符  
                     buf--读取数据的存放的位置  
                     size--读取数据的大小  
        Bingo-->sprint函数可以将字符串输入到一个特定的内存中.  
        eg:(1) char buf[10]; sprintf(buf,"I send you %d times.\n",++i);  
           (2) FILE fd; fd = fopen(...); sprintf(fd,"hello world!\n");
         与之对应的函数是fscanf;  
         与printf和scanf函数用法类似,只是增加了文件重定向指针.  
###[返回目录](#目录) 
###[未完待续](../os-notes.md) 
