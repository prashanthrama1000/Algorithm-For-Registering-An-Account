#include<iostream>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include<fstream>

using namespace std;

static int count=0, up=0;
char storedUsernameList[50][50], storedPassList[50][50];
int upcount, houseId;

class HelperMethods {

public:
  bool hasLettersOnly(char *name) {
    for(int i=0;i<strlen(name);i++) {
      if(!((int(name[i])>=65 && int(name[i])<=90) || (int(name[i])>=97 && int(name[i])<=132))) {
        return false;
      }
    }
    return true;
  }
};

class LoginAccount {

protected:
  char username[50], pass[50];

public:

  int hstore[100];

  void getId() {
    doesnot:
    cout<<"Enter the Username : ";
    cin>>username;cout<<endl;
    cout<<"Enter the Password : ";
    cin>>pass;cout<<endl;

    for(int i=0;i<upcount;i++) {
      if((strcmp(username,storedUsernameList[i])==0)&&(strcmp(pass,storedPassList[i])==0)) {
        cout<<endl;
        cout<<"Username and Password Matches";
        cout<<endl;
        break;
      } else {
        if(i==(upcount-1)) {
          cout<<"Username and Password does not match";
          cout<<endl;
          goto doesnot;
        }
      }
    }
  }

  void counter() {
    ++count;
  }

  void checkHouseId() {
    if(count==0)
    houseId=0;
    else {
      houseId=count;
    }
  }
};

class RegisterAccount:public LoginAccount {

protected:
  char name[50], address[100]; HelperMethods helperObject;

public:
  void invokeRegistration() {
    cout<<"Registration : "<<endl;
    while(true) {
      cout<<"Please enter your name : ";
      cin>>name;
      cout<<endl;
      if(helperObject.hasLettersOnly(name)){
        break;
      }
      cout<<"Only letters are allowed. Please enter again"<<endl;
    }
    cout<<"Please enter your House Address : ";
    cin>>address;
    cout<<endl;
    cout<<"Please enter your Username : ";
    cin>>username;
    cout<<endl;
    strcpy(storedUsernameList[up],username);
    cout<<"Please enter your Password (Conditions Apply) : ";
    cin>>pass;
    cout<<endl;
    strcpy(storedPassList[up],pass);
    ++up;upcount=up;
    cout<<"Your House ID is "<<houseId;
    cout<<endl;
  }

};

int main()
{
  int userChoice;
  LoginAccount l1;
  RegisterAccount registerAccount;
  int toRegister, toLogin;
  label1:
  cout<<"1.Login"<<endl;
  cout<<"2.Register"<<endl;
  cout<<"3.About"<<endl;
  cout<<"4.Quit"<<endl;
  cout<<"Enter your selection : ";
  cin>>userChoice;
  switch(userChoice)
  {
    case 1:
    {
      logpath:
      cout<<"1.Login Selected"<<endl;
      l1.getId();
      break;
    }

    case 2:
    {
      again:
      {
        ifstream infile;
        infile.open("counterfile.txt");
        infile>>count;
        cout<<"Count : "<<count<<endl;
        infile.close();
      }
      registerAccount.checkHouseId();
      registerAccount.invokeRegistration();
      ++count;
      {
        ofstream outfile;
        outfile.open("counterfile.txt");
        outfile<<count<<endl;
        outfile.close();
      }
      cout<<"Do you wish to register an another account? 1/0 : ";
      cin>>toRegister;
      cout<<endl;
      if(toRegister==1)
        goto again;
      cout<<"Do you wish to log in? 1/0 : ";
      cin>>toLogin;
      cout<<endl;
      if(toLogin==1)
        goto logpath;
      break;
    }

    case 3:
    {
      cout<<"About the application.";
      cout<<endl;
      cout<<"A basic template for registering an account with common fields and to log in with the same.";
      cout<<endl<<endl;
      goto label1;
    }

    case 4:
    {
      int wantToExit = 0;
      cout<<endl;
      cout<<"Do you want to exit the application? 1/0 : ";
      cin>>wantToExit;
      cout<<endl;
      if(wantToExit == 1)
      {
        cout<<"Exiting the application"<<endl<<endl;
        exit(0);
      }
      else
      {
        goto label1;
      }
    }

    default:
    {
      cout<<"Invalid Selection"<<endl<<endl;
      goto label1;
    }
  }
  return 0;
}
