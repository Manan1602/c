#include<iostream.h>
#include<conio.h>
void main()
{
int a,b,c,d;
cout<<"enter any number"<<endl;
cin>>a;
b=a*a;
c=b%10;
d=a%10;
if(c==d)
{
cout<<"it is an armstrong number";
}
else
{
cout<<"it is not a armstrong number";
}
}