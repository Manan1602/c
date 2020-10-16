#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
struct date
{
int y,m,d;
};
struct address
{
 int bloc;
 int houseno;
 char place[20];
};
class hotel
{
 char name[20];
 int roomno;
 char type[15];
 int noofdays;
 char phone[11];
 date checkin,checkout;
 address res;
 public:
 int getday()
 {
  return(checkin.d);
 }
 int getmonth()
 {
  return(checkin.m);
 }
 int getyear()
 {
  return(checkin.y);
 }
 int getcday()
 {
  return(checkout.d);
 }
 int getcmonth()
 {
  return(checkout.m);
 }
 int getcyear()
 {
  return(checkout.y);
 }
 char* getname()
 {
  return(name);
 }
 char* gettype()
 {
  return(type);
 }
 int getroomno()
 {
  return(roomno);
 }
 void getcheckin()
 {
  cout<<endl<<"Enter the date of your checking in:"<<endl;
  cin>>checkin.d>>checkin.m>>checkin.y;
 }
 void getcheckout()
 {
  cout<<endl<<"Enter the date of your checking out"<<endl;
  cin>>checkout.d>>checkout.m>>checkout.y;
 }
 void input();
 int checkdate(date dd);
 void print()
 {
  clrscr();
  char d[15];
  cout<<endl<<"The guest's name is: "<<endl<<name<<endl;
  cout<<"The address is: "<<endl;
  cout<<res.bloc<<"/"<<res.houseno<<endl<<res.place<<endl;
  cout<<endl<<"The phone no. is :"<<endl<<"+91 "<<phone<<endl;
  cout<<endl<<"The room no. is:"<<endl<<roomno<<endl;
  cout<<endl<<"The type of room is: ";
  puts(type);
  cout<<endl;
  cout<<endl<<"The date of checking in is: "<<endl;
  cout<<checkin.d<<"/"<<checkin.m<<"/"<<checkin.y<<endl;
  cout<<endl<<"The date of checking out is:"<<endl;
  cout<<checkout.d<<"/"<<checkout.m<<"/"<<checkout.y<<endl;
  cout<<endl<<"The no of days of stay are:"<<endl;
  cout<<noofdays;
  cout<<endl<<"<================********================>"<<endl;
  getch();
 }
}h;
void hotel::input()
{
 char t;
 cout<<endl<<"Enter your name"<<endl;
 gets(name);
 cout<<endl<<"Enter your phone no"<<endl<<"+91 ";
 cin>>phone;
 cout<<endl<<"Enter your block no."<<endl;
 cin>>res.bloc;
 cout<<endl<<"Enter the house number"<<endl;
 cin>>res.houseno;
 cout<<endl<<"Enter the city"<<endl;
 gets(res.place);
 cout<<endl<<"Enter the type of room required from the following options"<<endl;
 cout<<endl<<" Standard space: s \n Executive: e \n Delux: d \n Family bunk: f"<<endl;
 cin>>t;
 switch(t)
 {
  case 's':
   strcpy(type,"standard");
  break;
  case 'e':
   strcpy(type,"executive");
  break;
  case 'd':
   strcpy(type,"deluxe");
  break;
  case 'f':
   strcpy(type,"family bunk");
  break;
  default:
   cout<<endl<<"Wrong choice";
 }
 cout<<endl<<"Enter the room no."<<endl;
 cin>>roomno;
 int x=1,y=1;
 getcheckin();
 x=checkdate(checkin);
 if(x==0)
 {
  cout<<endl<<"Invalid date"<<endl;
  getcheckin();
 }
 getcheckout();
 y=checkdate(checkout);
 if(y==0)
 {
  cout<<"Invalid date"<<endl;
  getcheckout();
 }
 cout<<endl<<"Enter the no of days of stay"<<endl;
 cin>>noofdays;
 float net=0, total=0;
 float p=0,t1=0,tax=0;
 if(t=='s')
	p=109;
 else if(t=='e')
	p=139;
 else if(t=='d')
	p=169;
 else if(t=='f')
	p=270;
 int rs=50,eb=50,sn=15,i=0;
 if((t=='d')||(t=='f'))
 {
  i=20*noofdays;
 }
 t1=(rs+eb+sn+i)*noofdays;
 total=(p*noofdays);
 tax=(total+t1)/8;
 net=total+tax+t1;
 system("pause");
 cout<<endl<<"The details are as follows:"<<endl;
 cout<<endl<<"\tFACILITY\tRATES\tNO OF DAYS\tPRICE"<<endl;
 cout<<endl<<"\tTarrif\t\t"<<p<<"\t"<<noofdays<<"\t\t"<<p*noofdays<<endl;
 cout<<endl<<"\tSnacks\t\t15\t"<<noofdays<<"\t\t"<<sn*noofdays<<endl;
 cout<<endl<<"\tRoom Service\t50\t"<<noofdays<<"\t\t"<<rs*noofdays<<endl;
 cout<<endl<<"\tElectricity\t50\t"<<noofdays<<"\t\t"<<eb*noofdays<<endl;
 if((t=='d')||(t=='f'))
 {
  cout<<endl<<"\tInternet\t20\t"<<noofdays<<"\t\t"<<i<<endl;
 }
 cout<<endl<<"\tTax\t\t\t"<<noofdays<<"\t\t"<<tax<<endl;
 cout<<endl<<"\tNet\t\t\t\t\t"<<net<<endl;
}
int hotel::checkdate(date dd)
{
 int ddate=1;
 if((dd.d>=1)&&(dd.d<=31)&&(dd.m>=1)&&(dd.m<=12)&&(dd.y>=1))
 {
  if((dd.d==31)&&(dd.m==2)||(dd.m==4)||(dd.m==6)||(dd.m==9)||(dd.m==11))
  {
   ddate=0;
  }
  else if((dd.d==30)&&(dd.m==2))
  {
   ddate=0;
  }
  else if((dd.d==29)&&(dd.m==2))
  {
   if((dd.y%4==0)&&(dd.y&100==0)||(dd.y%400==0))
   {
    ddate=1;
   }
   else
   {
    ddate=0;
   }
  }
 }
 else
 {
  ddate=0;
 }
 return ddate;
}
void create()
{
 ofstream mf;
 mf.open("hotel.dat",ios::binary|ios::out|ios::ate);
 if(!mf)
 {
  cout<<"File can't be opened"<<endl;
 }
 hotel h;
 char ch;
 do
 {
  h.input();
  mf.write((char*)&h,sizeof(h));
  cout<<endl<<"Want to continue? (y/n)"<<endl;
  cin>>ch;
 }
 while(ch=='y'||ch=='Y');
 mf.close();
}
void display()
{
 ifstream mf;
 mf.open("hotel.dat",ios::binary|ios::in);
//seekg(0);
 if(!mf)
 {
  cout<<endl<<"File can't be opened"<<endl;
 }
 hotel h;
 mf.read((char*)&h,sizeof(h));
 while(mf)
 {
  h.print();
  getch();
  clrscr();
  mf.read((char*)&h,sizeof(h));
 }
 mf.close();
}
//1.NAME
void search1()
{
 ifstream mf;
 mf.open("hotel.dat",ios::binary|ios::in);
 if(!mf)
 {
  cout<<endl<<"File can't be opened"<<endl;
 }
 hotel h;
 char x[20];
 cout<<endl<<"Enter the name to be searched"<<endl;
 gets(x);
 int y=0;
 mf.read((char*)&h,sizeof(h));
 while(!mf.eof())
 {
    if(mf.eof())
  {
  break;
  }
  if(strcmpi(x,h.getname())==0)
  {
   cout<<"Search successfull"<<endl;
   y++;
   h.print();
  }
  mf.read((char*)&h,sizeof(h));
 }
  if(y==0)
 {
  cout<<"SEARCH UNSUCCESSFUL"<<endl;
 }
 mf.close();
}
//2.ROOMNUMBER
void search2()
{
 ifstream mf;
 mf.open("hotel.dat",ios::binary|ios::in);
 if(!mf)
 {
  cout<<endl<<"File can't be opeaned"<<endl;
 }
 hotel h;
 int x;
 int y=0;
 cout<<endl<<"Enter the room no. to be searched";
 cin>>x;
 mf.read((char*)&h,sizeof(h));
 while(!mf.eof())
 {
    if(mf.eof())
  {
  break;
  }
  if(x==h.getroomno())
  {
   cout<<"Search successfull"<<endl;
   y++;
   h.print();
  }
  mf.read((char*)&h,sizeof(h));
 }
  if(y==0)
 {
  cout<<"SEARCH UNSUCCESSFUL"<<endl;
 }
 mf.close();
}
//1>TYPE
void report1()
{
 int y=0;
 ifstream mf;
 mf.open("hotel.dat",ios::binary|ios::in);
 if(!mf)
 {
  cout<<endl<<"File can't be opened"<<endl;
 }
 hotel h;
 char x[20];
 cout<<endl<<"Enter the type of room to be searched"<<endl;
 gets(x);
 mf.read((char*)&h,sizeof(h));
 while(!mf.eof())
 {
  if(mf.eof())
  {
  break;
  }
  if(strcmp(x,h.gettype())==0)
  {
   y++;
   h.print();
  }
  mf.read((char*)&h,sizeof(h));
 }
 if(y==0)
 {
  cout<<"SEARCH UNSUCCESSFUL"<<endl;
 }
 mf.close();
}
//2.CHECK IN
void report2()
{
 int y=0;
 ifstream mf;
 mf.open("hotel.dat",ios::binary||ios::in);
 if(!mf)
 {
  cout<<endl<<"File can't be opened"<<endl;
 }
 hotel h;
 date x;
 cout<<endl<<"Enter the date of checking in to be searched"<<endl;
 cin>>x.d>>x.m>>x.y;
 mf.read((char*)&h,sizeof(h));
 while(!mf.eof())
 {
 if(mf.eof())
  {
  break;
  }
  if((h.getday()==x.d)&&(h.getmonth()==x.m)&&(h.getyear()==x.y))
  {
   y++;
   h.print();
  }
  mf.read((char*)&h,sizeof(h));
 }
 if(y==0)
 {
  cout<<"SEARCH UNSUCCESSFUL"<<endl;
 }
 mf.close();
}
//2.CHECK OUT
void report3()
{
 int y=0;
 ifstream mf;
 mf.open("hotel.dat",ios::binary||ios::in);
 if(!mf)
 {
  cout<<endl<<"File can't be opened"<<endl;
 }
 hotel h;
 date x;
 cout<<endl<<"Enter the date of checking out to be searched"<<endl;
 cin>>x.d>>x.m>>x.y;
 mf.read((char*)&h,sizeof(h));
 while(!mf.eof())
 {
 if(mf.eof())
  {
  break;
  }
  if((h.getcday()==x.d)&&(h.getcmonth()==x.m)&&(h.getcyear()==x.y))
  {
   y++;
   h.print();
  }
  mf.read((char*)&h,sizeof(h));
 }
 if(y==0)
 {
  cout<<"SEARCH UNSUCCESSFUL"<<endl;
 }
 mf.close();
}
void modify()
{
 hotel h;
 fstream mf;
 mf.open("hotel.dat",ios::binary|ios::in|ios::out);
 if(!mf)
 {
  cout<<endl<<"File cant be opened"<<endl;
 }
 int t,nt;
 int y=0;
 int pos;
 long p;
 cout<<endl<<"Enter your room no."<<endl;
 cin>>t;
 mf.read((char*)&h,sizeof(h));
 while(mf&&y==0)
 {
  if(t==h.getroomno())
  {
   y++;
   p=mf.tellg();
   p=p-sizeof(h);
   mf.seekg(p,ios::beg);
   h.input();
   mf.write((char*)&h,sizeof(h));
  }
  mf.read((char*)&h,sizeof(h));
 }
 if(y==0)
 {
  cout<<endl<<"Search unsuccesfull"<<endl;
 }
 mf.close();
}
void presentation()
{
 cout<<"         /\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\ "<<endl;
 cout<<"        <   WELCOME TO HOTEL NOVA ROYAL  >"<<endl;
 cout<<"        <   A Sharma-Agarwal Enterprise  >"<<endl;
 cout<<"         \\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/ "<<endl;
 getch();
 clrscr();
 cout<<endl<<"The four types of accomodation facilities we offer are -"<<endl;
 cout<<endl<<"Standard Rooms"<<endl;
 cout<<"Executive Rooms"<<endl;
 cout<<"Deluxe Suites"<<endl;
 cout<<"Family Bunk Rooms"<<endl;
 cout<<endl<<"Press enter to continue....."<<endl;
 getch();
 clrscr();
 cout<<endl<<endl<<"STANDARD ROOMS"<<endl;
 cout<<endl<<"*\t1 King Sized Bed"<<endl;
 cout<<endl<<"*\tIron & Ironing Board"<<endl;
 cout<<endl<<"*\tRefrigerator"<<endl;
 cout<<endl<<endl<<"\t\tRent:109$"<<endl;
 cout<<endl<<"Press enter to continue"<<endl;
 getch();
 clrscr();
 cout<<endl<<endl<<"EXECUTIVE"<<endl;
 cout<<endl<<"*\t1 King Sized Bed"<<endl;
 cout<<endl<<"*\tRefrigerator"<<endl;
 cout<<endl<<"*\tIron & Ironing Board"<<endl;
 cout<<endl<<"*\tPrivate Balconies With Seaside View"<<endl;
 cout<<endl<<endl<<"\t\tRent:139$"<<endl;
 cout<<endl<<"Press enter to continue"<<endl;
 getch();
 clrscr();
 cout<<endl<<endl<<"DELUXE SUITES"<<endl;
 cout<<endl<<"*\t1 King Sized Bed"<<endl;
 cout<<endl<<"*\tFree In-room Locker"<<endl;
 cout<<endl<<"*\tRefrigerator"<<endl;
 cout<<endl<<"*\tIron & Ironing Board"<<endl;
 cout<<endl<<"*\tHigh Speed Internet Access"<<endl;
 cout<<endl<<"*\tPrivate Balconies With Stunning Harbour View"<<endl;
 cout<<endl<<endl<<"\t\tRent:169$"<<endl;
 cout<<endl<<"Press enter to continue"<<endl;
 getch();
 clrscr();
 cout<<endl<<endl<<"FAMILY BUNK ROOMS"<<endl;
 cout<<endl<<"*\t2 King Sized Beds & 1 Set of Bunk Beds"<<endl;
 cout<<endl<<"*\tFree In-Room Locker"<<endl;
 cout<<endl<<"*\tRefrigerator"<<endl;
 cout<<endl<<"*\tIron & Ironing Board"<<endl;
 cout<<endl<<"*\tHigh Speed Internet Access"<<endl;
 cout<<endl<<"*\tPrivate Balconies with Beachside View"<<endl;
 cout<<endl<<endl<<"\t\tRent: 270$"<<endl;
 cout<<"Press Enter to continue"<<endl;
 getch();
 clrscr();
}
void main()
{
 int c;
 char ch;
 clrscr();
 presentation();
 do
 {
  clrscr();
  cout<<endl<<"Select an option from the following menu:"<<endl;
  cout<<endl<<"1> CREATE"<<endl;
  cout<<endl<<"2> DISPLAY"<<endl;
  cout<<endl<<"3> SEARCH BY NAME"<<endl;
  cout<<endl<<"4> SEARCH BY ROOM NO."<<endl;
  cout<<endl<<"5> MODIFY"<<endl;
  cout<<endl<<"6> REPORT BY TYPE"<<endl;
  cout<<endl<<"7> REPORT BY CHECKIN DATE"<<endl;
  cout<<endl<<"8> REPORT BY CHECKOUT DATE"<<endl;
  cin>>c;
  switch(c)
  {
   case 1:
	 create();
   break;
   case 2:
	display();
   break;
   case 3:
	search1();
   break;
   case 4:
	search2();
   break;
   case 5:
	modify();
   break;
   case 6:
	report1();
   break;
   case 7:
	report2();
   break;
   case 8:
	report3();
   break;
   default:
	cout<<"Wrong Entry"<<endl;
  }
  cout<<"Want to continue to main menu? y/n_";
  cin>>ch;
 }
 while(ch=='y'||ch=='Y');
 getch();
}