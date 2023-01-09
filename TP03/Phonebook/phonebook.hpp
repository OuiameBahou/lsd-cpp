#include<iostream>
#include<string>
using namespace std;
string makeTen(string a);
class Contact
{
public :
  string first_name;
  string last_name;
  string nickname;
  int phonenumber;
  void getdata();
  void showdata();
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
        cout<<"phonebook is deconstructed !";}
};
