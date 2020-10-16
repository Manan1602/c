#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
char a[30],b[30];
int i,x=0;
cout<<"Enter the first sequence"<<endl;
cin.getline(a,30);
cout<<"Enter the second sequence"<<endl;
cin.getline(b,30);
for(i=0;a[i]!='\0'&&b[i]!='\0';i++)
{
if(a[i]==b[i])
{
x=1;
}
else
{
x=0;
}
}
if(x==1)
{
cout<<"The sequences are equal";
}
else
{
cout<<"The sequences are not equal";
}
}
