#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<fstream.h>
#include<conio.h>
class stu
{
int roll_no;
float mks_per;
public:
 char name[20];
 void in()                                               //input
 {
  cout<<"Enter roll number"<<endl;
  cin>>roll_no;
  cout<<"Enter your name"<<endl;
  cin>>name;
  cout<<"Enter your overall percentage"<<endl;
  cin>>mks_per;
 }
 void out()                                                //output
 {
  cout<<roll_no<<"\t"<<name<<"\t"<<mks_per<<endl;
 }
 int rno()
 {
  return roll_no;
 }
 float mks()
 {
  return mks_per;
 }
}info;
void main()
{
 clrscr();
 int choice,s_choice,ser;
 float perc;
 char start_again,st_a,chk='n',nam[20];
 do
 {
  cout<<endl<<"1> Add record"<<endl;
  cout<<"2> Display record"<<endl;
  cout<<"3> search record"<<endl<<endl;
  cout<<"Enter the number corresponding to what you want to do?_____";
  cin>>choice;
  switch(choice)
  {
   case 1:
   {
    ofstream fout("Stu_info.dat",ios::app|ios::out);  //INPUT DATA
    do
    {
     info.in();
     fout.write((char*)&info,sizeof(info));      //How to use while(!fout.eof())
     cout<<"Enter another record? y/n_";
     cin>>start_again;
    }
    while(start_again=='y');
    fout.close();
    break;
   }
   case 2:
   {
    ifstream fin("Stu_info.dat",ios::in);           //DISPLAY
    while(!fin.eof())
    {
     if(fin.eof())
      {
       break;
      }
     fin.read((char*)&info,sizeof(info));
     info.out();
    }
    fin.close();
    break;
   }
   case 3:                                                 //SEARCH
   {
   // do
   // {
    cout<<"1> Search by roll no."<<endl;
    cout<<"2> Search by name"<<endl;
    cout<<"3> Search by percentage"<<endl;
    cout<<"Enter the number corresponding to your choice__";
    cin>>s_choice;
    switch(s_choice)
    {
     case 1:
     {
      cout<<"Enter the roll no. you want to search for"<<endl;
      cin>>ser;
      ifstream serh("Stu_info.dat",ios::in);
      while(!serh.eof())
      {
       //cout<<"hebsfjrhbgje";
       serh.read((char*)&serh, sizeof(serh));
       if(info.rno()==ser)                    //<--there's some problem here
       {
	cout<<"File found"<<endl<<endl;
	info.out();
	chk='y';
	break;
       }
      }
      //cout<<"dbhjgbdjhbgjfdbj";
      serh.close();
      if(chk=='n')
      {
       cout<<"File not found"<<endl<<endl;
      }
     }
     case 2:
     {
      cout<<"Enter the name you want to search for"<<endl;
      cin>>nam;
      ifstream serh("Stu_info.dat", ios::in);
      while(!serh.eof())
      {
       //jcout<<"sjgfhbgjbfdj";
       serh.read((char*)&serh,sizeof(serh));
       if(strcmp(info.name,nam))
       {
	cout<<"Data found:"<<endl<<endl;
	info.out();
	chk='y';
	break;
       }
      }
      serh.close();
      if(chk=='n')
      {
       cout<<"Data not found"<<endl;
      }
     }
     case 3:
     {
      cout<<"Enter the percentage you want to search for"<<endl;
      cin>>perc;
      ifstream serh("Stu_info.dat", ios::in);
      while(!serh.eof())
      {
       serh.read((char*)&serh, sizeof(serh));
       if(info.mks()==perc)
       {
	cout<<"Data found"<<endl<<endl;
	info.out();
	chk='y';
	break;
       }
      }
      serh.close();
      if(chk=='n')
      {
       cout<<"Data not found"<<endl<<endl;
      }
     }/*End of case 3 of main case 3*/
    } /*End of main case 3*/
   }
  }
  fflush(0);
  cout<<"Go back to menu?y/n_";
  cin>>st_a;
 }
 while(st_a=='y');
}
