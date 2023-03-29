#include <stdio.h>
#include <stdlib.h>


int hanoi(int discos,char ori,char aux, char dest){

    if(discos==1)
        printf("\n%c--->%c",ori,dest);
    else{
        hanoi(discos-1,ori,dest,aux);
        printf("\n%c--->%c",ori,dest);
        hanoi(discos-1,aux,ori,dest);
    }

    return 0;

}
int main()
{
    hanoi(3,'A','B','C');
    return 0;
}
