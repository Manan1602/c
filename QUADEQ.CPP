#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{
clrscr();
int a,b,c,C,r1,r2,s1,s2,choice;
char Qtyp,Var1,Var2;
cout<<"Question type 'a'------> Finding the root of the equation"<<endl;
cout<<"Question type 'b'------> finding the value of variable"<<endl<<endl;
cout<<"Enter the type of question:        ";
cin>>Qtyp;
if(Qtyp=='a')
 {
 printf("enter the coefficent of x*x\n");
 scanf("%d",&a);
 printf("Enter the coefficient of x\n");
 scanf("%d",&b);
 printf("Enter the constant term\n");
 scanf("%d",&c);
 C=c;
 answer:
  s1=sqrt(b*b-4*a*C);
  r1=(-b-s1)/(a*2);
  r2=(-b+s1)/(2*a);
 printf("The first answer is %d\n",r1);
 printf("The second answer is %d\n",r2);
 }
else if(Qtyp=='b')
 {
 printf("///PROGRAM IS ONLY READY FOR SOLVING QUESTIONS WITH EQUAL ROOTS\\\\\n");
 printf("Enter the coefficient of x^2:                ");
 scanf("%d",&a);
 printf("Enter the constant coefficient of x:         ");
 scanf("%d",&b);
 printf("Enter the value of the constant term         ");
 scanf("%d",&c);
 printf("Enter the variable coefficient of x:         ");
 scanf("%c",&Var1);
 cout<<"does your equation contain variable with constant term?"<<endl<<"Y/N";
 cout<<endl;
 cin>>Var2;
   if(Var2=='Y')
   {
   printf("choose your quadratic equation:\n");
   printf("--%d*x^2+%d*%c*x+%d+%c------->Type '1'",a,b,Var1,c,Var2);
   printf("--%d*x^2+(%d+%c)*x+%d+%c----->Type '2'",a,b,Var1,c,Var2);
   printf("--%d*x^2+%d*%c*x+%d*%c------->Type '3'",a,b,Var1,c,Var2);
   printf("--%d*x^2+(%d+%c)*x+%d*%c----->Type '4'",a,b,Var1,c,Var2);
   scanf("%d",&choice);
    switch(choice)
    {
     case1:
      a=b;
      b=4;
      C=-1*4*c;
      goto answer;
     break;
     case2:
      a=1;
      C=(b-c)*(b+c);
      b=2*b-4;
      goto answer;
     break;
     case3:
      a=b*b;
      b=-1*4*c;
      C=0;
      goto answer;
     break;
     case4:
      C=b*b;
      b=(2*b)-(4*c*a);
      a=1;
      goto answer;
     break;
     }
   }}
 else if(Var2=='N')
 {
 ;
 }
}

