#include"iostream.h"
#include"dos.h"
#include"conio.h"
#include"time.h"
void main()
{
clrscr();
int a,b=1;
float c;
clock_t s,e;
s=clock();
for(a=10000;a>b;a++)
{
 cout<<"\\/";
 b+=2;
}
delay(2000);
e=clock();
c=(e-s)/CLK_TCK;
cout<<endl<<endl;
cout<<"The time taken for the execution was "<<c<<" sec.";
}