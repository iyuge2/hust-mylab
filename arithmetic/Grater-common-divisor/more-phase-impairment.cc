/*
 * author: iyuge2
 * update time: 20161201 19:47
 * function: 利用更相减损术去求解两个数的最大归约数
 * */

/*return the Greater comman num*/
int more_phase_impairment(int x,int y)
{
    if(x == y){
        return x;
    }
    else if(x == 1 || y == 1){
        return 1;
    }
    return x > y ? more_phase_impairment(x-y,y) : more_phase_impairment(x,y-x);
}
