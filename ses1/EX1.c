
#include <stdio.h>
#define BITS sizeof(int) * 8 
void check_msb(int n ){
    int msb = 1 << (BITS - 1);
    if(n & msb)
        printf("MSB of %d is set (1).", n);
    else
        printf("MSB of %d is unset (0).", n);
}

int main()

{
    int n;
    printf("Enter any number: ");
    scanf("%d", &n);
    check_msb(n);
    
    return 0;
}
