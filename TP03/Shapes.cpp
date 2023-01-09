#include<iostream>
using namespace std;

class Shape{
public :
    int width;
    int height;
    Shape(){
        width=0;
        height=0;
    }
};
class Triangle : public Shape
{
public:
    int area()
    {
        return height*width/2; 
    }
};
class Rectangle : public Shape
{
public :
    int area()
    {
        return width*height;
    }
};
int main()
{
    Triangle T;
    T.width=3;
    T.height=2;
    cout<<T.area()<<"\n";
    Rectangle R;
    R.width=5;
    R.height=4;
    cout<<R.area()<<"\n";
    return 0;
    
    
    
    
    
    
}
