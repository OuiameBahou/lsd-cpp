//unfinshed


#include<iostream>
#include<string>

using namespace std;



class Book : public Page
{
public :
  string book_name;
  string author_name;
  string link;
  int ISBN_number;
  int totalnum;
  Page arr[10];
  Boolean b {
      if(b==1){
          cout<<"this book could be read from the link ";
      }
      
  }
  Page
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
    
};
class Page{
public:
    int page_number;
    string content;
    string title;
}
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
    cout<<"is this book naive to the library :"<<"\n";
    cout<<"yes.if this book is naive, enter page title :"<<"\n";
    
    cout<<"yes.if this book is naive, enter paige content :";
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
            case yes :Libraryy.ADD();
                break;
            
            default: cout<<"invalid option !\n\n";
                break;
            
        }
    }
    while(option!=3);
    return 0;
    
}

