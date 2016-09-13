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

static int count=0;static int up=0;char ucopy[50][50];char pcopy[50][50];int upcount;int hid;

class login
{
protected:
char username[50];int i;int ran[100];char pass[50];char username1[50];char pass1[50];

public:

int hstore[100];

void getid()
{
doesnot:

cout<<"Enter the Username : ";cin>>username;cout<<endl;
cout<<"Enter the Password : ";cin>>pass;cout<<endl;

for(i=0;i<upcount;i++)
{
if((strcmp(username,ucopy[i])==0)&&(strcmp(pass,pcopy[i])==0))
{
cout<<"Loading . . . .";cout<<endl;
cout<<"Username and Password Matches :) ";cout<<endl;break;
}
else
{
if(i==(upcount-1))
{
cout<<"Username and Password does not match :|";cout<<endl;
goto doesnot;
}
}
}
}
void devdis()
{
cout<<" -----------------------";cout<<endl;
cout<<"Username : "<<username;cout<<endl;
cout<<"Password : "<<pass;cout<<endl;
cout<<" -----------------------";cout<<endl;
}
void counter()
{
++count;
}
void checkhid()
{
if(count==0)
hid=0;
else
{
hid=count;
}
}
};

class registe:public login
{

protected:
char name[50];char address[100];
public:
void rget()
{

cout<<"Registration : ";cout<<endl;
cout<<"Please enter your name : ";cin>>name;cout<<endl;
cout<<"Please enter your House Address : ";cin>>address;cout<<endl;
cout<<"Please enter your Username : ";cin>>username1;cout<<endl;strcpy(ucopy[up],username1);
cout<<"Please enter your Password (Conditions Apply) : ";cin>>pass1;cout<<endl;strcpy(pcopy[up],pass1);++up;upcount=up;
cout<<"Your House ID is "<<hid;cout<<endl;
if(hid==0)
{
ran[0]=rand()%100;cout<<"Your Encryption Key is "<<ran[0];cout<<endl;
}
if(hid>0)
{
ran[hid]=rand()%100;cout<<"Your Encryption Key is "<<ran[hid];cout<<endl;
}
}

};


int main()
{
int choice;
login l1;registe r1[10];int r2=0;int roption[15];int r2option[15];int r4=0;
label1:
cout<<"1.Login";cout<<endl;
cout<<"2.Register";cout<<endl;
cout<<"3.Developer Mode";cout<<endl;
cout<<"4.About";cout<<endl;
cout<<"5.Quit";cout<<endl;
cout<<"Enter your selection : ";cin>>choice;
switch(choice)
{
case 1:
{
logpath:
cout<<"1.Login Selected";cout<<endl;
l1.getid();
break;
}

case 2:
{
again:
{

ifstream infile;
infile.open("counterfile.txt");
infile>>count;
cout<<"Count : "<<count;cout<<endl;
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
cout<<"Do you wish to register an another account? 1/0 : ";cin>>roption[r2];cout<<endl;
if(roption[r2]==1)
goto again;
cout<<"Do you wish to log in? 1/0 : ";cin>>r2option[r2];cout<<endl;
if(r2option[r2]==1)
goto logpath;
break;
}

case 5:
{
cout<<" . . . . ";cout<<endl<<endl;
exit(0);
}

default: 
{
cout<<"Invalid Selection";cout<<endl<<endl;
goto label1;
}
}

cout<<"Count : "<<count;

return;  
}

