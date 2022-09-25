#include <stdio.h>

void print_nth_bit(unsigned num, unsigned n){
    int B = (num >> n) & 1;
    printf("The %d bit is set to %d", n, B);
    
    
}


int main()
{
    unsigned num, n, bitStatus;
    printf("Enter any number: ");
    scanf("%d", &num);
    printf("Enter nth bit to check (0-31): ");
    scanf("%d", &n);
    print_nth_bit(num,n);
    



    return 0;
}
