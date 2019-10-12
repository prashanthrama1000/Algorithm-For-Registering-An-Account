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
char ucopy[50][50], pcopy[50][50];
int upcount, hid;

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

class Login {

protected:
  char username[50];
  int i, ran[100];
  char pass[50], username1[50], pass1[50];

public:

  int hstore[100];

  void getId() {
    doesnot:
    cout<<"Enter the Username : ";
    cin>>username;cout<<endl;
    cout<<"Enter the Password : ";
    cin>>pass;cout<<endl;

    for(i=0;i<upcount;i++) {
      if((strcmp(username,ucopy[i])==0)&&(strcmp(pass,pcopy[i])==0)) {
        cout<<"Loading . . . .";cout<<endl;
        cout<<"Username and Password Matches :) ";
        cout<<endl;
        break;
      }
      else {
        if(i==(upcount-1)) {
          cout<<"Username and Password does not match :|";
          cout<<endl;
          goto doesnot;
        }
      }
    }
  }

  void devdis() {
    cout<<" -----------------------"<<endl;
    cout<<"Username : "<<username<<endl;
    cout<<"Password : "<<pass<<endl;
    cout<<" -----------------------"<<endl;
  }

  void counter() {
    ++count;
  }

  void checkhid() {
    if(count==0)
    hid=0;
    else {
      hid=count;
    }
  }
};

class Registe:public Login {

protected:
  char name[50], address[100]; HelperMethods helperObject;

public:
  void rget() {
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
    cin>>username1;
    cout<<endl;
    strcpy(ucopy[up],username1);
    cout<<"Please enter your Password (Conditions Apply) : ";
    cin>>pass1;
    cout<<endl;
    strcpy(pcopy[up],pass1);
    ++up;upcount=up;
    cout<<"Your House ID is "<<hid;
    cout<<endl;
    if(hid==0) {
      ran[0]=rand()%100;
      cout<<"Your Encryption Key is "<<ran[0]<<endl;
    }
    if(hid>0) {
      ran[hid]=rand()%100;
      cout<<"Your Encryption Key is "<<ran[hid]<<endl;
    }
  }

};

int main()
{
  int choice;
  Login l1;Registe r1[10];int r2=0, roption[15], r2option[15], r4=0;
  label1:
  cout<<"1.Login"<<endl;
  cout<<"2.Register"<<endl;
  cout<<"3.Developer Mode"<<endl;
  cout<<"4.About"<<endl;
  cout<<"5.Quit"<<endl;
  cout<<"Enter your selection : ";
  cin>>choice;
  switch(choice)
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
      r1[r2].checkhid();
      r1[r2].rget();
      ++r2;++count;
      {
        ofstream outfile;
        outfile.open("counterfile.txt");
        outfile<<count<<endl;
        outfile.close();
        ++r4;
      }
      cout<<"Do you wish to register an another account? 1/0 : ";
      cin>>roption[r2];
      cout<<endl;
      if(roption[r2]==1)
        goto again;
      cout<<"Do you wish to log in? 1/0 : ";
      cin>>r2option[r2];
      cout<<endl;
      if(r2option[r2]==1)
        goto logpath;
      break;
    }

    case 3:
    {
      cout<<"Introducing the feature 'Developer Mode'."<<endl;
      cout<<"The aim is to use the encryption key created at the time of user registration in case the account gets locked.";
      cout<<endl<<endl;
      goto label1;
    }

    case 4:
    {
      cout<<"About the application.";
      cout<<endl;
      cout<<"A basic template for registering an account with common fields and to log in with the same.";
      cout<<endl<<endl;
      goto label1;
    }

    case 5:
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
  cout<<"Count : "<<count;
  return 0;
}
