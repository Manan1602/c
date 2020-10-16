#include<iostream.h>
#include<conio.h>
struct compl
{
float real;
float img;
} no[3];
void main()
{
clrscr();
int i;
char ans;
for(i=0;i<2;i++)
{
 cout<<"Enter the real part_______";
 cin>>no[i].real;
 cout<<"Enter the imaginary part__";
 cin>>no[i].img;
}
cout<<endl;
cout<<"For addition________a"<<endl;
cout<<"For substraction____s"<<endl;
cout<<"For multiplication__m"<<endl;
cout<<"For division________d"<<endl;
cin>>ans;
switch(ans)
{
 case 'a':
  no[2].real=no[0].real+no[1].real;
  no[2].img=no[0].img+no[1].img;
  cout<<"The no. is"<<endl;
  cout<<no[2].real<<"+"<<no[2].img<<"i";
 break;
 case 's':
  no[2].real=no[0].real-no[1].real;
  no[2].img=no[0].img-no[1].img;
  cout<<"The no is"<<endl;
  cout<<no[2].real<<"+("<<no[2].img<<")i";
 break;
 case 'm':
  no[2].real=(no[0].real*no[1].real)+(no[0].img*no[1].img);
  no[2].img=(no[0].real*no[1].img)+(no[0].img+no[1].real);
  cout<<"The no. is"<<endl;
  cout<<no[2].real<<"+("<<no[2].img<<")i";
 break;
 case 'd':
  no[2].real=((no[0].real*no[1].real)+(no[0].img+no[1].img))/(no[1].real*no[1].real+no[1].img*no[1].img);
  no[2].img=((no[0].real*no[1].img)+(no[0].img*no[1].real))/(no[1].real*no[1].real+no[1].img*no[1].img);
  cout<<"The no. is"<<endl;
  cout<<no[2].real<<"+("<<no[2].img<<")i";
}
getch();
}
