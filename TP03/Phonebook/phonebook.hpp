#include<iostream>
#include<string>
using namespace std;
string Ten(string s);
class Contact
{
public :
  string first_name;
  string last_name;
  string nickname;
  int phonenumber;
  void getinput();
  void showinput();
  void contact(){
    first_name="";
    last_name="";
    nickname="";
    phonenumber=0;
}
};
class PhoneBook : public Contact
{
    public :
    int index = 0;
    Contact contarr[8];
    void ADD();
    void SEARCH();
    void EXIT();
    ~PhoneBook(){
        cout<<"all contacts are lost  forever !";}
};
