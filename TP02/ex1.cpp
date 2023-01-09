#include<iostream>

template <typename T>
T multiply(T x, int y)
{
    return x*y;
    
}
int main()
{
    std::cout<<multiply(2,3)<<"\n";
    std::cout<<multiply(1.2,3)<<"\n";
    return 0;
    
}
