#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
//#include<iomanip.h>
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
 date checkin,checkout;
 int noofdays;
 address res;
 char phone[11];
 public:
 hotel()
 {
  strcpy(name," ");
  strcpy(phone," ");
  strcpy(type," ");
  roomno,noofdays=0;
  checkin.d,checkin.m,checkin.y=0;
  checkout.d,checkout.m,checkout.y=0;
  res.bloc,res.houseno=0;
  strcpy(res.place," ");
 }
 void edit()
 {
  cout<<endl<<"Enter the new numberof the room:"<<endl;
  cin>>roomno;
 }
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
 int retr()
 {
  return(roomno);
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
 cout<<endl<<"Enter the rooom no."<<endl;
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
 mf.open("hotel.dat",ios::binary|ios::out);
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
  cout<<endl<<"Want to continue?"<<endl;
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
  cout<<endl<<"File can't be opeaned"<<endl;
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
 while(mf&&y==0)
 {
  if(strcmpi(x,h.getname())==0)
  {
   cout<<"Search successfull"<<endl;
   y++;
   h.print();
  }
  mf.read((char*)&h,sizeof(h));
 }
 if(mf.eof()==1&&y==0)
 {
  cout<<"Search unsuccessfull"<<endl;
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
 while(mf&&y==0)
 {
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
  cout<<"Search unsuccessfull"<<endl;
 }
 mf.close();
}
//1>TYPE
void report1()
{
 ifstream mf;
 mf.open("hotel.dat",ios::binary|ios::in);
 if(!mf)
 {
  cout<<endl<<"File can't be opened"<<endl;
 }
 hotel h;
 int y=0;
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
  cout<<"Search unsuccessfull"<<endl;
 }
 mf.close();
}
//2.CHECK IN
void report2()
{
 ifstream mf;
 mf.open("hotel.dat",ios::binary||ios::in);
 if(!mf)
 {
  cout<<endl<<"File can't be opened"<<endl;
 }
 hotel h;
 date x;
 int y=0;
 cout<<endl<<"Enter the date of cheacking in to be searched"<<endl;
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
 cout<<"Search unsuccessfull"<<endl;
 }
 mf.close();
}
//2.CHECK OUT
void report3()
{
 ifstream mf;
 mf.open("hotel.dat",ios::binary||ios::in);
 if(!mf)
 {
  cout<<endl<<"File can't be opened"<<endl;
 }
 hotel h;
 date x;
 int y=0;
 cout<<endl<<"Enter the date of checking in to be searched"<<endl;
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
  cout<<"Search unsuccessfull"<<endl;
 }
 mf.close();
}
void appending()
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
   h.edit();
   mf.write((char*)&h,sizeof(h));
  }
  mf.read((char*)&h,sizeof(h));
 }
 if(mf.eof()==1&&y==0)
 {
  cout<<endl<<"Search unsuccesfull"<<endl;
 }
 mf.close();
}
void calculate()
{
 hotel h;
 float net=0,total=0;
 float p=0,t=0,tax=0;
 char c;
 int days=0;
 cout<<"Enter the type of room youo are staying in: ";
 cin>>c;
 cout<<"Enter the no. od days of stay: ";
 cin>>days;
 if(c=='s')
	p=109;
 else if(c=='e')
	p=139;
 else if(c=='d')
	p=169;
 else if(c=='f')
	p=270;
 int rs=50,eb=50,sn=15,i;
 if((c=='d')||(c=='f'))
 {
  i=20*days;
 }
 t=(rs+eb+sn+i)*days;
 total=(p*days);
 tax=(total+t)/8;
 net=total+tax+t;
 cout<<endl<<"Rent=\t"<<total<<"$"<<endl;
 cout<<endl<<"Tax=\t"<<tax<<"$"<<endl;
 cout<<endl<<"Total Expenses=\t"<<net<<"$"<<endl;
 cout<<endl<<"Want to see details?"<<endl;
 cout<<endl<<"Press enter"<<endl;
/* cin>>c;
 if((c=='b')||(c=='B'))   */
 system("pause");
  cout<<endl<<"The details are as follows:"<<endl;
  cout<<endl<<"\tFACILITY\tRATES\tNO OF DAYS\tPRICE"<<endl;
  cout<<endl<<"\tTarrif\t\t"<<p<<"\t"<<days<<"\t\t"<<p*days<<endl;
  cout<<endl<<"\tSnacks\t\t15\t"<<days<<"\t\t"<<sn*days<<endl;
  cout<<endl<<"\tRoom Service\t50\t"<<days<<"\t\t"<<rs*days<<endl;
  cout<<endl<<"\tElectricity\t50\t"<<days<<"\t\t"<<eb*days<<endl;
  if((c=='d')||(c=='f'))
  {
   cout<<endl<<"\tInternet\t20\t"<<days<<"\t\t"<<i<<endl;
  }
  cout<<endl<<"\tTax\t\t\t"<<days<<"\t\t"<<tax<<endl;
  cout<<endl<<"\tNet\t\t\t\t\t"<<net<<endl;
}
void deleting()
{
 int r1;
 long p;
 fstream nf;
 nf.open("new.dat",ios::binary|ios::in);
 fstream mf;
 mf.open("hotel.dat",ios::binary|ios::out);
 hotel h;
 cout<<"enter the room no. to be deleted";
 cin>>r1;
 while(mf.read((char*)&h,sizeof(h)))
 {
  if(h.getroomno()!=r1)
  {
   p=mf.tellg();
   p=p-sizeof(h);
   mf.seekg(p,ios::beg);
   nf.write((char*)&h,sizeof(h));
  }
 }
 nf.close();
 mf.close();
 rename("hotel.dat","deleted.dat");
 rename("new.dat","hotel.dat");
}
void presentation()
{
 cout<<"         /\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\"<<endl;
 cout<<"        <  WELCOME TOO HOTEL UNOVA ROYAL >"<<endl;
 cout<<"        <  A Sharma-Agarwal enterprise   >"<<endl;
 cout<<"         \\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/ "<<endl;
 getch();
 clrscr();
 cout<<endl<<"The four types of accomodation facilities we offer are"<<endl;
 cout<<endl<<"Standard Rooms"<<endl;
 cout<<"Executive Rooms"<<endl;
 cout<<"Deluxe Suites"<<endl;
 cout<<"Family Bunk Rooms"<<endl;
 cout<<endl<<"Press enter to continue....."<<endl;
 getch();
 clrscr();
 cout<<endl<<endl<<"STANDARD ROOMS"<<endl;
 cout<<endl<<"*\tPrivate Balconies"<<endl;
 cout<<endl<<"*\t1 King Sized Bed"<<endl;
 cout<<endl<<"*\tIron & Ironing Board"<<endl;
 cout<<endl<<"*\tRefrigerator"<<endl;
 cout<<endl<<endl<<"\t\tRent:109$"<<endl;
 cout<<endl<<"Press enter to continue"<<endl;
 getch();
 clrscr();
 cout<<endl<<endl<<"EXECUTIVE"<<endl;
 cout<<endl<<"*\t1 King Sized Bed"<<endl;
 cout<<endl<<"*\tFree In-room Safes"<<endl;
 cout<<endl<<"*\tRefrigerator"<<endl;
 cout<<endl<<"*\tIron & Ironing Board"<<endl;
 cout<<endl<<"*\tPrivate Balconies With Seaside View"<<endl;
 cout<<endl<<endl<<"\t\tRent:139$"<<endl;
 cout<<endl<<"Press enter to continue"<<endl;
 getch();
 clrscr();
 cout<<endl<<endl<<"DELUXE SUITES"<<endl;
 cout<<endl<<"*\t1 King Sized Bed"<<endl;
 cout<<endl<<"*\tFree In-room Safes"<<endl;
 cout<<endl<<"*\tRefrigerator"<<endl;
 cout<<endl<<"*\tIron & Ironing Board"<<endl;
 cout<<endl<<"*\tHigh Speed Inter net Access"<<endl;
 cout<<endl<<"*\tPrivate Balconies With Stunning Harbour View"<<endl;
 cout<<endl<<endl<<"\t\tRent:169$"<<endl;
 cout<<endl<<"Press enter to continue"<<endl;
 getch();
 clrscr();
 cout<<endl<<endl<<"FAMILY BUNK ROOMS"<<endl;
 cout<<endl<<"*\t2 King Sized Beds & 1 Set of Bunk Beds"<<endl;
 cout<<endl<<"*\tFree In-Room Safes"<<endl;
 cout<<endl<<"*\tRefrigerator"<<endl;
 cout<<endl<<"*\tIron & Ironing Board"<<endl;
 cout<<endl<<"*\tHigh Speed Internet Access"<<endl;
 cout<<endl<<"*\tPrivate Balconies with Beachside View"<<endl;
 cout<<endl<<endl<<"\t\tRent: 270$"<<endl;
 cout<<"Press Enter to continue"<<endl;
 getch();
 clrscr();
}
void delrec()
{
 ifstream fin("deleted.dat",ios::app|ios::in);
 fin.read((char*)&h,sizeof(h));
 h.print();
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
  cout<<endl<<"Select an option from the following menu"<<endl;
  cout<<endl<<"1>.........create"<<endl;
  cout<<endl<<"2>.........display"<<endl;
  cout<<endl<<"3>.........calculate"<<endl;
  cout<<endl<<"4>.........search(name)"<<endl;
  cout<<endl<<"5>.........search(roomno)"<<endl;
  cout<<endl<<"6>.........delete"<<endl;
  cout<<endl<<"7>.........modify"<<endl;
  cout<<endl<<"8>.........report(type)"<<endl;
  cout<<endl<<"9>.........report(check in)"<<endl;
  cout<<endl<<"10>........report(check out)"<<endl;
  cout<<endl<<"11>........view deleted records"<<endl;
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
	calculate();
   break;
   case 4:
	search1();
   break;
   case 5:
	search2();
   break;
   case 6:
	deleting();
   break;
   case 7:
	appending();
   break;
   case 8:
	report1();
   break;
   case 9:
	report2();
   break;
   case 10:
	report3();
   break;
   case 11:
	delrec();
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