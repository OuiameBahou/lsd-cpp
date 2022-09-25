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

 
int main(void)
{
    printBits(2);
    printf("\n");
    printBits(3);
}
