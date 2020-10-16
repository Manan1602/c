#include<iostream.h>
#include<stdio.h>
#include<conio.h>
void main()
{
int i,j;
char a[100],b[100];
cout<<"Enter the word"<<endl;
gets(a);
for(i=0;a[i]!='\0';i++);
j=i-1;
for(i=0;i<j;i++)
{
 b[i]=a[j];
 j--;
}
cout<<b[i];
}