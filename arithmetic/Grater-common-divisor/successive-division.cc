/*
 * author: iyuge2
 * update time: 20161201 20:10
 * function: 利用辗转相除法去求解两个数的最大归约数
 * */

/*return the Greater comman num*/
int successive_division(int x,int y)
{
    if(x % y == 0){
        return y;
    }
    else if(y % x == 0){
        return x;
    }
    return x > y ? successive_division(x%y,y) :successive_division(x,y%x);
}
