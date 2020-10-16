#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
 clrscr();
 int a[10],b,j,i;
 randomize();
 for(i=0;i<10;i++)
 {
  a[i]=rand()%100;
  cout<<a[i]<<" ";
 }
 cout<<endl<<endl;
 for(i=0;i<10;i++)
 {
  for(j=i+1;j<10;j++)
  {
   if(a[i]>a[j])
   {
    b=a[i];
    a[i]=a[j];
    a[j]=b;
   }
  }
 }
 for(i=0;i<10;i++)
 {
  cout<<a[i]<<" ";
 }
}