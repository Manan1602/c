#include<iostream.h>
int primeno();
void main()
{
int num,b;
cout<<"Enter a number"<<endl;
cin>>num;
primeno(num);
if(b==1)
{
 cout<<"It is prime"<<endl;
}
else
{
 cout<<"It is composite"<<endl;
}
}
primeno(int num)
{
int a=2,b;
while(a<num)
{
 if(num%a!=0)
 {
 b=1;
 }
 else
 {
 b=0;
 break;
 }
 a++;
 }
return b;
}
