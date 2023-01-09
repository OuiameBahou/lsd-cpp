#include<iostream>
#include<string>
#include "phonebook.hpp"
using namespace std;
string makeTen(string a){
    int n=a.length();
    string res="";
    if(n==10){
    }
    if(n>10){
        res=a.substr(0,10);
    }
    if(n<10){
        res=a;
        for (int i=n; i<10;i++){
            res+=" ";}
    }
    return res;
}



void PhoneBook::ADD(){

    Contact c;
    c.getdata();
    cout<<"contact created !";
    if(index==8)
    {
        contarr[0]=c;
        return;
        
    }
    else
    {
        contarr[index]=c;
        index++;
        return;
    }
}
void PhoneBook::SEARCH()
{
    for(int i=0;i<index;i++)
    {
        cout<<i<<"|"<<endl;
        contarr[i].showdata();
    }
    return;
    
}
void PhoneBook::EXIT()
{
    cout<<"goodbye !";
    
    
}
void Contact::getdata(){
    cout<<"give a first_name :";
    cin>>first_name;
    cout<<"give a last_name : ";
    cin>>last_name;
    cout<<"give a nickname : ";
    cin>>nickname;
    cout<<"give a phone number : ";
    cin>>phonenumber;
}

void Contact::showdata(){
    cout<<makeTen(first_name)<<"|";
    cout<<makeTen(last_name)<<"|";
    cout<<makeTen(nickname)<<"";
}
int menu()
{
    int choice;
    cout<<"welcome to the phonebook application :"<<"\n";
    cout<<"1.add a contact :"<<"\n";
    cout<<"2.search for a contact :"<<"\n";
    cout<<"3.exit :"<<"\n";
    cout<<"enter ur choice :";
    cin>>choice;
    return choice;
}
int main()
{
    PhoneBook PhoneBook1;
    int option;
    do{
        option = menu();
        switch(option)
        {
            case 1:PhoneBook1.ADD();
                break;
            case 2:PhoneBook1.SEARCH();
                break;
            case 3:PhoneBook1.EXIT();
                break;
            default: cout<<"invalid option !\n\n";
                break;
            
        }
    }
    while(option!=3);
    return 0;
    
}
