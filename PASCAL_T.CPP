#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int n,value=1,i=0,s=0,j=0;
cout<<"Enter the number of lines"<<endl;
cin>>n;
for(i=0;i<=n;i++)
{
 for(s=1;s<=n-1;s++)
 {
 cout<<"   ";
 }
 for(j=0;j<=i;j++)
 {
  if(j==0||i==0)
  {
  value=1;
  }
  else
  {
  value=value*(i-j+1)/j;
  }
  cout<<"   "<<value;
  }
  cout<<endl;
  }
  getch();
  }

