#include<iostream>
#include<string>
#include "phonebook.hpp"
using namespace std;
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



void PhoneBook::ADD(){

    Contact cont;
    cont.getinput();
    cout<<"contact created !";
    if(index==8)
    {
        contarr[0]=cont;
        return;
        
    }
    else
    {
        contarr[index]=cont;
        index++;
        return;
    }
}
void PhoneBook::SEARCH()
{
    for(int i=0;i<index;i++)
    {
        cout<<i<<"|"<<endl;
        contarr[i].showinput();
    }
    return;
    
}
void PhoneBook::EXIT()
{
    cout<<"goodbye !";
    
    
}
void Contact::getinput(){
    cout<<"give a first_name :";
    cin>>first_name;
    cout<<"give a last_name : ";
    cin>>last_name;
    cout<<"give a nickname : ";
    cin>>nickname;
    cout<<"give a phone number : ";
    cin>>phonenumber;
}

void Contact::showinput(){
    cout<<Ten(first_name)<<"|";
    cout<<Ten(last_name)<<"|";
    cout<<Ten(nickname)<<"";
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
    PhoneBook PhoneBookk;
    int option;
    do{
        option = menu();
        switch(option)
        {
            case 1:PhoneBookk.ADD();
                break;
            case 2:PhoneBookk.SEARCH();
                break;
            case 3:PhoneBookk.EXIT();
                break;
            default: cout<<"invalid option !\n\n";
                break;
            
        }
    }
    while(option!=3);
    return 0;
    
}
