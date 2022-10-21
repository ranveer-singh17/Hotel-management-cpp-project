#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string.h>

class hotel
{
int room_no;
char name[30];
char address[50];
char phone[10];

public:
void main_menu();       //to display the main menu
void add();             //to book a room
void display();         //to display the customer record
void rooms();           //to display allotted rooms
void edit();            //to edit the customer record
int check(int);         //to check room status
void modify(int);       //to modify the record
void delete_rec(int);   //to delete the record
void secure_login();    //main display with password
};

void hotel::main_menu()
{
int choice;
while(choice!=5)
{
clrscr();
cout<<"\n\t\t\t\t*************";
cout<<"\n\t\t\t\t* MAIN MENU *";
cout<<"\n\t\t\t\t*************";
cout<<"\n\n\n\t\t\t1.Book A Room";
cout<<"\n\t\t\t2.Customer Record";
cout<<"\n\t\t\t3.Rooms Allotted";
cout<<"\n\t\t\t4.Edit Record";
cout<<"\n\t\t\t5.Exit";
cout<<"\n\n\t\t\t Enter Your Choice: ";
cin>>choice;

switch(choice)
{
case 1: add();
break;
case 2: display();
break;
case 3: rooms();
break;
case 4: edit();
break;
case 5: break;
default:
{
cout<<"\n\n\t\t\tWrong choice...!!!";
cout<<"\n\t\t\tPress any key to continue..!!";
getch();
}
}
}
}


void hotel::add()
{
clrscr();
int r,flag;
ofstream fout("Record",ios::app);    

cout<<"\n Enter Customer Detalis";
cout<<"\n --------";
cout<<"\n\n Room no: ";
cin>>r;
flag=check(r);

if(flag)
cout<<"\n Sorry..!!! Room is already booked";

else
{
room_no= r;
cout<<" Name: ";
gets(name);
cout<<" Address: ";
gets(address);
cout<<" Phone No: ";
gets(phone);
fout.write((char*)this,sizeof(hotel));
cout<<"\n Room is booked...!!!";
}

cout<<"\n Press any key to continue...!!";
getch();
fout.close();
}

void hotel::display()
{
clrscr();
ifstream fin("Record",ios::in);
int r,flag;
cout<<"\n Enter room no: ";
cin>>r;

while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
if(room_no == r)
{
clrscr();
cout<<"\n Customer Details";
cout<<"\n -------";
cout<<"\n\n Room no: "<<room_no;
cout<<"\n Name: "<<name;
cout<<"\n Address: "<<address;
cout<<"\n Phone no: "<<phone;
flag=1;
break;
}
}

if(flag==0)
cout<<"\n Sorry Room no. not found or vacant..!!";

cout<<"\n\n Press any key to continue..!!";
getch();
fin.close();

}

void hotel::rooms()
{
clrscr();
ifstream fin("Record",ios::in);
cout<<"\n\t\t\t    List Of Rooms Allotted";
cout<<"\n\t\t\t    -------";
cout<<"\n\n Room No.\tName\t\tAddress\t\t\t\tPhone No.";

while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
cout<<"\n\n "<<room_no<<"\t\t"<<name;
cout<<"\t\t"<<address<<"\t\t"<<phone;
}
cout<<"\n\n\n\t\t\tPress any key to continue...!!";
getch();
fin.close();
}

void hotel::edit()
{
clrscr();
int choice,r;

cout<<"\n EDIT MENU";
cout<<"\n -------";
cout<<"\n\n 1.Modify Customer Record";
cout<<"\n 2.Delete Customer Record";

cout<<"\n Enter your choice: ";
cin>>choice;
clrscr();
cout<<"\n Enter room no: " ;
cin>>r;

switch(choice)
{
case 1: modify(r);
break;
case 2: delete_rec(r);
break;
default: cout<<"\n Wrong Choice..!!";
}
cout<<"\n Press any key to continue...!!!";
getch();
}

int hotel::check(int r)     
{
int flag=0;
ifstream fin("Record",ios::in);
while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{
flag=1;
break;
}
}

fin.close();
return(flag);
}

void hotel::modify(int r)
{
long pos,flag=0;
fstream file("Record",ios::in|ios::out|ios::binary);
while(!file.eof())
{
pos=file.tellg();                     //returns the position
file.read((char*)this,sizeof(hotel));
if(room_no==r)
{
cout<<"\n Enter New Details";
cout<<"\n -------";
cout<<"\n Name: ";
gets(name);
cout<<" Address: ";
gets(address);
cout<<" Phone no: ";
gets(phone);

file.seekg(pos);
file.write((char*)this,sizeof(hotel));
cout<<"\n Record is modified..!!";
flag=1;
break;
}
}

if(flag==0)
cout<<"\n Sorry Room no. not found or vacant..!!";
file.close();
}

void hotel::delete_rec(int r)
{
int flag=0;
char ch;
ifstream fin("Record",ios::in);
ofstream fout("temp",ios::out);
while(!fin.eof())
{
    fin.read((char*)this,sizeof(hotel));
    if(room_no==r)
  {
     cout<<"\n Name: "<<name;
     cout<<"\n Address: "<<address;
cout<<"\n Pone No: "<<phone;
cout<<"\n\n Do you want to delete this record(y/n): ";
cin>>ch;

if(ch=='n')
fout.write((char*)this,sizeof(hotel));
flag=1;
   }
  else
  fout.write((char*)this,sizeof(hotel));
}

fin.close();
fout.close();
if(flag==0)
cout<<"\n Sorry room no. not found or vacant..!!";
else
{
remove("Record");
rename("temp","Record");
}
}

void hotel:: secure_login()
{
  char pwd[]="password", verify[20], ch;
  int i, chance=1;
  start:                 //label defined
  clrscr();
  i=0;
  cout<<"\n\t\t\t****************************";
  cout<<"\n\t\t\t* HOTEL MANAGEMENT PROJECT *";
  cout<<"\n\t\t\t****************************";


  cout<<"\n\n\n\n\t\tMade By:";

  cout<<"\t SHUBHAM AGRAWAL ";

  cout<<"\n\n\t\tSubmitted To:";

  cout<<"\t Mr. Narendra Aliani sir";
  cout<<"\n\n\nEnter the password to verify: ";
  do
 {
  ch=getch();
  if(ch!=13)     //carriage return
  {
   verify[i++]=ch;
   cout<<"*";
  }
  else
  {
   verify[i++]='\0';
  }
 }while(ch!=13);

  if(strcmp(pwd,verify)==0)
 {
  cout<<"\nPassword Matched...";
  cout<<"\nWelcome Shubham Agrawal....";
 }
 else
 {
  cout<<"\nPassword Wrong....\n";
  cout<<chance<<" used of 3 chances...";
  cout<<"\nEnter the correct credentials";
  chance++;
  getch();
  if(chance<=3) goto start;
 }
}

void main()
{
hotel h;
textbackground(BLACK);
textcolor(WHITE);

clrscr();

h.secure_login();
h.main_menu();
getch();
}

