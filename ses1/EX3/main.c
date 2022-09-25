#include"functions.h"
#include <stdio.h>
#define BITS sizeof(int) * 8 
void check_msb(int n ){
    int msb = 1 << (BITS - 1);
    if(n & msb)
        printf("MSB of %d is set (1).", n);
    else
        printf("MSB of %d is unset (0).", n);
}
void printBits(unsigned n)
{
    
    unsigned r;
    for (r = 1 << 31; r > 0; r = r >> 1)
        if(n&r){
            printf("1");
        }
        else{
            printf("0");
        }
    return ;
}

int main()

{
    int n;
    printf("Enter any number: ");
    scanf("%d", &n);
    check_msb(n);
    printf("\n");
    printBits(2);
    printf("\n");
    printBits(3);
    return 0;
}
