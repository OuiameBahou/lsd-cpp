//I worked with an online compiler

#include<iostream>
#include<string>

using namespace std;


class Book
{
public :
  string book_name;
  string author_name;
  string link;
  int ISBN_number;
  void getinput();
  void showinput();
  Book(){
    book_name="";
    author_name="";
    link="";
    ISBN_number=0;
}
};
class Library: public Book
{
    public :
    int index = 0;
    Book bookarr[8];
    void ADD();
    void SEARCH();
    void EXIT();
    ~Library(){
        cout<<"all books are lost  forever !";}
};
string Ten(string s){
    int n=s.length();
    string res="";
    if(n==10){
    }
    if(n>10){
        res=s.substr(0,10);
    }
    if(n<10){
        res=s;
        for (int i=n; i<10;i++){
            res+=" ";}
    }
    return res;
}



void Library ::ADD(){

    Book b;
    b.getinput();
    cout<<"book created !";
    if(index==8)
    {
        bookarr[0]=b;
        return;
        
    }
    else
    {
        bookarr[index]=b;
        index++;
        return;
    }
}
void Library::SEARCH()
{
    for(int i=0;i<index;i++)
    {
        cout<<i<<"|"<<endl;
        bookarr[i].showinput();
    }
    return;
    
}
void Library::EXIT()
{
    cout<<"goodbye !";
    
    
}
void Book::getinput(){
    cout<<"give a book_name :";
    cin>>book_name;
    cout<<"give a author_name : ";
    cin>>author_name;
    cout<<"give a link : ";
    cin>>link;
    cout<<"give a ISBN number : ";
    cin>>ISBN_number;
}

void Book::showinput(){
    cout<<Ten(book_name)<<"|";
    cout<<Ten(author_name)<<"|";
    cout<<Ten(link)<<"";
}
int menu()
{
    int choice;
    cout<<"welcome to the Library application :"<<"\n";
    cout<<"1.add a book :"<<"\n";
    cout<<"2.search for a book :"<<"\n";
    cout<<"3.exit :"<<"\n";
    cout<<"enter ur choice :";
    cin>>choice;
    return choice;
}
int main()
{
    Library Libraryy;
    int option;
    do{
        option = menu();
        switch(option)
        {
            case 1:Libraryy.ADD();
                break;
            case 2:Libraryy.SEARCH();
                break;
            case 3:Libraryy.EXIT();
                break;
            default: cout<<"invalid option !\n\n";
                break;
            
        }
    }
    while(option!=3);
    return 0;
    
}
