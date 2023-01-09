#include<iostream>
template<typename T>
T powiter(T a,int n)
{
    T res=1;
    if(n==0)
    {
        return 1;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            res=res*a;
        }
    return res;
    }
    
}
template<typename T>

T powrec(T a, int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        a=a*powrec(a,n-1);
    }
    return a;
}
int main()
{
    std::cout<<powiter(2,3)<<"\n";
    std::cout<<powiter(1.2,3)<<"\n";
    std::cout<<powrec(2,3)<<"\n";
    std::cout<<powrec(1.2,3);
    return 0;
}
