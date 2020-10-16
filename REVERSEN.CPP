#include<iostream.h>
#include<conio.h>
void main()
{
int a[50],m[50],n,x;
char answer;
clrscr();
do
{
cout<<"Enter the number you want to reverse"<<endl;
cin>>a[50];
 for(n=0;a[n]!='\0';n++)
  {
  }
n=n-1;
 for(x=0;n>=0;x++)
  {
  m[x]=a[n];
  n=n-1;
  }
m[x+1]='\0';
cout<<m<<endl<<endl;
cout<<"press y to start again------>";
cin.sync();
cin>>answer;
}
while(answer=='y');
}

