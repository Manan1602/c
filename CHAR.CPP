#include<iostream.h>
#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
char a[400];
int i,j,n=1;
cout<<"Enter the sentence"<<endl;
gets(a);
for(i=0;a[i]!='\0';i++)
{
}
j=i-1;
for(i=0;i<j;i++)
{
 if(a[i]==' ')
 {
  n++;
 }
}
cout<<"Number of words = "<<n;
getch();
}