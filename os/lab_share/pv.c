#ifndef _PV
#define _PV

#include<sys/sem.h>
/*P操作*/
void P(int sem_id,int index)
{
    struct sembuf sem;
    sem.sem_num = index;
    sem.sem_op = -1;
    sem.sem_flg = 0;
    semop(sem_id,&sem,1);
}

/*V操作*/
void V(int sem_id,int index)
{
    struct sembuf sem;
    sem.sem_num = index;
    sem.sem_op = 1;
    sem.sem_flg = 0;
    semop(sem_id,&sem,1);
    return;
}
#endif
