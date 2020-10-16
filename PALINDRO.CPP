#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int a,b,c,d,e;
cout<<"Enter a three digit number"<<endl;
cin>>a;
b=a/100;
c=(a%100)/10;
d=a%10;
e=d*100+c*10+b;
cout<<"The reverse of number is "<<e<<endl;
if (e==a)
{
cout<<"It is a palindrome";
}
else
{
cout<<"It is not a palindrome";
}
}

