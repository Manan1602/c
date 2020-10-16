#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
class vector
{
int n,l;
int a[10];
public:
void enter();
void modify();
void largest();
void output();
};
void vector :: enter()
{
 for(n=0;n<10;n++)
 {
  cout<<"Enter the "<<n+1<<"th term:\t\t";
  cin>>a[n];
  //a[n]=rand()%100;
 }
}
void vector :: modify()
{
int m,i;
cout<<"Enter the value you want to replace\t\t";
cin>>m;
cout<<"Enter the number you want to replace it with\t";
cin>>i;
for(n=0;n<10;n++)
{
 if(a[n]==m)
 {
  a[n]=i;
 }
}
cout<<"The new modified array is:"<<endl;
for(n=0;n<10;n++)
{
 cout<<a[n]<<endl;
}
}
void vector :: largest()
{
l=0;
for(n=0;n<10;n++)
{
 if(a[n]>l)
 {
  l=a[n];
 }
}
cout<<"The largest number is "<<l<<endl;
}
void vector :: output()
{
 for(n=0;n<10;n++)
 {
  cout<<a[n]<<"\t";
 }
}
void main()
{
char a;
clrscr();
vector x;
x.enter();
cout<<"Press 'o' to display all"<<endl;
cout<<"Press 'c' to change an element"<<endl;
cout<<"Press 'l' to display the largest number"<<endl;
cin>>a;
switch(a)
{
 case 'o':
  x.output();
 break;
 case 'c':
  x.modify();
 break;
 case 'l':
  x.largest();
 break;
 default:
  cout<<"INVALID RESPONSE";
}
getch();
}
