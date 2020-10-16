#include<iostream.h>
#include<stdio.h>
#include<math.h>
#include<conio.h>
void main()
{
clrscr();
int m,x1,y1,x2,y2,x3,y3,d,h;
char q,sq,a;
do
{
cout<<"To find the slope_____________________________'s'"<<endl;
cout<<"To find the equation of the line:"<<endl;
cout<<"\tTwo pts are given___________________________'t'"<<endl;
cout<<"\tLine perpendicular to the other line________'p'"<<endl;
cout<<"\tLine parallel to another line_______________'a'"<<endl;
cout<<"To find the distance between two pts._________'d'"<<endl;
cin>>q;
cout<<"Enter the x and y coordinate of the pt."<<endl;
cin>>x1>>y1;
switch(q)
{
 case 's':
  cout<<"Enter the x and y co-ordinate of one of the pts."<<endl;
  cin>>x1>>y1;
  cout<<"Enter the x and y co-ordinate of the second pt."<<endl;
  cin>>x2>>y2;
  m=(y2-y1)/(x2-x1);
  cout<<"The slope is_______"<<m;
 break;
 case 'd':
  cout<<"Enter the x and y co-ordinate of one of the pts."<<endl;
  cin>>x1>>y1;
  cout<<"Enter the x and y co-ordinate of the second pt."<<endl;
  cin>>x2>>y2;
  h=((x2-x1)*(x2-x1))-((y2-y1)*(y2-y1));
  d=sqrt(h);
  cout<<"The distance btw the pts. is "<<d;
 break;
 case 't':
  cout<<"Enter the x and y coordinates of the second pt."<<endl;
  cin>>x2>>y2;
  cout<<"The equation is :"<<endl<<"\t";
  cout<<"x+("<<-1*((x2-x1)/(y2-y1))<<")y+("<<((x2*y1)-(x1*y2))/(y2-y1);
 break;
 case 'a':
 case 'p':
  cout<<"Is the slope of the other line given _________y/n?"<<endl;
  cin>>sq;
  switch(sq)
  {
   case 'y':
    cout<<"Enter the slope of the other line"<<endl;
    cin>>m;
    cout<<"Enter the x and y coordinates of the pt."<<endl;
    cin>>x1,y1;
    if(q=='a')
    {
     cout<<"The equation is:"<<endl;
     cout<<"\t"<<m<<"x-y+("<<y1-(m*x1)<<")";
    }
    else
    {
    m=-1*(1/m);
    cout<<"The equation is:"<<endl;
    cout<<"\t"<<m<<"x-y+("<<y1-(m*x1)<<")";
    }
   break;
   case 'n':
    cout<<"Enter the x and y coordinate of the first pt on the other line"<<endl;
    cin>>x1>>y1;
    cout<<"Enter the x and y coordinate of the second pt on the line"<<endl;
    cin>>x2>>y2;
    cout<<"Enter the x and y coordinate of the pt on the line you want the equation of"<<endl;
    cin>>x3>>y3;
    m=(y2-y1)/(x2-x1);
    if(q=='a')
    {
     cout<<"The equation is:"<<endl;
     cout<<"\t"<<m<<"x-y+("<<y3-(m*x3)<<")";
    }
    else
    {
    m=-1*(1/m);
    cout<<"The equation is:"<<endl;
    cout<<"\t"<<m<<"x-y+("<<y3-(m*x3)<<")";
    }
  break;
  default:
  cout<<"Invalid value";
  }
 break;
 default:
 cout<<"Invalid value";
}
fflush(0);
cout<<endl<<endl<<"Try again________y/n?"<<endl;
cin>>a;
}
while(a=='y');
}