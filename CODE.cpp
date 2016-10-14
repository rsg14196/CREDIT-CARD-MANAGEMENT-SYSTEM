#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<process.h>
#include<string.h>
#include<dos.h>
void box()
{
	char ch=254;
	int i;
	for(i=1;i<=79;i++)
	{
		gotoxy(i,1);
		cout<<ch;
		delay(10);
	}
	for(i=1;i<=25;i++)
	{
		gotoxy(79,i);
		cout<<ch;
		delay(10);
	}
	for(i=79;i>=1;i--)
	{
		gotoxy(i,25);
		cout<<ch;
		delay(10);
	}
	for(i=25;i>=1;i--)
	{             gotoxy(1,i);
		cout<<ch;
		delay(10);
	}}
void box1()
{              char ch=254;
	int i;
	for(i=1;i<=79;i++)
	{	gotoxy(i,1);
		cout<<ch;           }
	for(i=1;i<=25;i++)
	{              gotoxy(79,i);
		cout<<ch;           }
	for(i=79;i>=1;i--)
              {              gotoxy(i,25);
		cout<<ch;            }
	for(i=25;i>=1;i--)
	{              gotoxy(1,i);
		cout<<ch;           }}

class menu_class
{		public:
		void menu();
		void report_menu();
		void card_edit_menu();
		void customer_edit_menu();     };
class card
{   		private:
		char cardname[15];
		int cardcode;
		int limit;
	
	public:
		void input(int c,char n[],int l)
		{              cardcode=c;
			strcpy(cardname,n);
			limit=l;                          }
		void addcard();
		void deletecard();
		void display_cardrecord();
		void display_cardlist();
		int returncode();
		int returncardcode()
		{  return cardcode;                   }
		int returnlimit()
		{     return limit;                        }
		char *returncardname()
		{   return cardname;                }};
class customer
{ 		public:
		void addcust();
		void deletecustomer();
		void display_customerrecord();
		void display_customerlist();
		int returncardno();
	private:
		int cardno,t_cardcode,t_limit;
		char name[21], phone[8], address[50];   };
void menu_class::menu()
{                            char ch;
		clrscr();
		box1();
		gotoxy(30,2);
		cout<<"WELCOME TO MAIN MENU";
		gotoxy(30,7);
		cout<<"1. Customer";
		gotoxy(30,9);
		cout<<"2. Credit Card";
		gotoxy(30,11);
		cout<<"3. Report";
		gotoxy(30,13);
		cout<<"0. Exit ";
		gotoxy(30,20);
		cout<<"Enter Your Choice :";
		ch=getch();
		switch(ch)
		{                                          case '1':
					customer_edit_menu();
					break;
				case '2':
					card_edit_menu();
					break;
				case '3':
					report_menu();
					break;
				case '0': exit(0);
		}}
/////////////////////////////
void menu_class::card_edit_menu()
{ 	char ch;
	card r;
	do
	{
	clrscr();
	box1();
	gotoxy(30,8);
	cout<<"1. Add New Card";
	gotoxy(30,10);
	cout<<"2. Delete Card Records";
	gotoxy(30,12);
	cout<<"3. Display Card Records";
	gotoxy(30,14);
	cout<<"0. Exit";
	gotoxy(30,16);
	cout<<"Enter Your Choice";
	ch=getch();
	if (ch=='1')
		r.addcard();
	else if(ch=='2')
		r.deletecard();
	else if(ch=='3')
		r.display_cardrecord();
	else if (ch=='0')
		menu();
	else
	{             gotoxy(30,20);
		cout<<"wrong choice";        }
              }while(ch!='0');                                     }
///////////////////////////////////////////////////////
void menu_class::customer_edit_menu()
{                            char ch;
		customer c;
		do
		{    clrscr();
		box1();
		gotoxy(30,8);
		cout<<"1. New Customer";
		gotoxy(30,10);
		cout<<"2. Delete Customer";
		gotoxy(30,12);
		cout<<"3. Display Customer Record";
		gotoxy(30,14);
		cout<<"0. EXIT";
		gotoxy(30,17);
		cout<<"Enter Your Choice";
		ch=getch();
		if(ch == '1')
			c.addcust();
		else if(ch=='2')
			 c.deletecustomer();
		else if(ch=='3')
			c.display_customerrecord();
		else if (ch=='0')
			menu();
		else
		{              gotoxy(30,20);
			cout<<"wrong choice";   }
                                           }while(ch!='0'); 		}
///////////////////////////////////////
void menu_class::report_menu()
{		char ch;
		do
{                            clrscr();
		box1();
		gotoxy(30,4);
		cout<<"1. List of Cards";
		gotoxy(30,6);
		cout<<"2. List of Customers";
		gotoxy(30,8);
		cout<<"0. Exit";
		gotoxy(30,10);
		cout<<"Enter your choice";
		ch=getch();
		if(ch=='1')
		{       card r;
		    r.display_cardlist();        }
		else if(ch=='2')
		{   customer c;
		    c.display_customerlist(); }
		else if(ch=='0')
			menu();
		else
		{
			gotoxy(30,12);
			cout<<"wrong choice";
		}
		}while(ch!='0');
}

////////////////////////
int card::returncode()
{			fstream file;
			int code=0;
			file.open("CARD.DAT",ios::in|ios::binary);
			while(file.read((char *)this,sizeof(card)))
			{	 code++;}
			file.close();
			return code;		}

///////////////////////////////////////////////////////////////////
int customer::returncardno()
{ 			fstream file;
			int n=0;
			file.open("CUST.DAT",ios::in|ios::binary);
			while(file.read((char *)this,sizeof(customer)))
			{    n++; 			}
			file.close();
			return n;		}
//////////////////////////////
void card::addcard()
{	char ch;
	clrscr();
	box1();
	gotoxy(25,2);
	cout<<"WELCOME TO ADD CARD RECORD FORM";
	A:
	gotoxy(10,4);
	int code;
	code=returncode();
	cout<<"Enter the Card Name :";
	gotoxy(35,4);
	gets(cardname);
	if (strlen(cardname)<=0 || strlen(cardname)>15)
	{ 	gotoxy(25,6);
		cout<<"IT SHOULD NOT BE ZERO OR GREATER THAN 15";
		gotoxy(25,8);
		cout<<"Press any key to continue...";
		getche();
		gotoxy(25,6); clreol();
		gotoxy(25,8); clreol();
		gotoxy(25,4); clreol();
		goto A;				}
	B:
	gotoxy(10,6);
	cout<<"Enter the Limit for Card :";
	gotoxy(35,6);
	cin>>limit;
	if(limit<=0)
	{	gotoxy(10,8);
		cout<<"limit is greater than 0";
		gotoxy(10,10);
		cout<<"Press any key to continue...";
		gotoxy(10,8); clreol();
		gotoxy(10,10); clreol();
		gotoxy(25,6); clreol();
		goto B;
	 }
	cardcode=code+1;
	fstream file;
	file.open("CARD.DAT",ios::app|ios::binary);
	file.write((char *)this,sizeof(card));
	file.close();
}
///////////////////////////////////////////////////////////////////
void card::deletecard()
{
	clrscr();
	int flag=1;
	char ch;
	int n;
	gotoxy(25,2);
	cout<<"WELCOME TO DELETE CARD RECORD FORM";
	gotoxy(10,4);
	cout<<"Enter the card code to be deleted :";
	cin>>n;
	gotoxy(1,10);

	fstream file;
	file.open("CARD.DAT",ios::in|ios::binary);
	fstream tempfile;
	tempfile.open("TCARD.DAT",ios::out|ios::binary);

	while(file.read((char *)this,sizeof(card)))
	{
		if(cardcode!=n)
			tempfile.write((char *)this,sizeof(card));
		if(cardcode==n)
			flag=0;
	}
	file.close();
	tempfile.close();

	if(flag==0)
	{
		fstream f1;
		f1.open("TCARD.DAT",ios::in|ios::binary);
		fstream t1;
		t1.open("CARD.DAT",ios::out|ios::binary);
		while(f1.read((char *)this,sizeof(card)))
		{
			t1.write((char *)this,sizeof(card));
		}
		gotoxy(10,6);
		cout<<"RECORD DELETED...";
	}
	else
	{
		gotoxy(10,6);
		cout<<"RECORD NOT FOUND...";
	}
	gotoxy(40,18);
	cout<<"PRESS ANY KEY TO CONT...";
	getch();

}
void card::display_cardrecord()
{
	int n,flag=1;
	clrscr();
	box1();
	gotoxy(25,2);
	cout<<"WELCOME TO CARD DISPLAY RECORD FORM";
	gotoxy(10,4);
	cout<<"\n Enter the card code :";
	cin>>n;
	fstream file;
	file.open("CARD.DAT",ios::in|ios::binary);
	while(file.read((char *)this,sizeof(card)))
	{
		  if(n==cardcode)
		  {
			gotoxy(10,6);
			cout<<"CARD NAME ="<<cardname;
			gotoxy(10,8);
			cout<<"CARD LIMIT ="<<limit;
			flag=0;
		  }
	}
	if(flag==1)
	{
		gotoxy(10,6);
		cout<<"CARD CODE NOT EXIST :";
	}
	gotoxy(40,18);
	cout<<"PRESS ANY KEY TO CONT...";
	getch();
	file.close();

}
////////////////////////
void card::display_cardlist(void)
{
	fstream file;
	file.open("card.dat",ios::in|ios::binary);
	int row=5, pageno=1;
	C:
	clrscr();
	box1();
	gotoxy(18,2);
	cout<<"LIST OF CARD";
	gotoxy(8,5);
	cout<<"Card Code ";
	gotoxy(25,5);
	cout<<"Card Name  ";
	gotoxy(40,5);
	cout<<"Limit  ";
	while (file.read((char *)this, sizeof(card)))
	{
		row++;
		gotoxy(8,row);
		cout<<cardcode;
		gotoxy(25,row);
		cout<<cardname;
		gotoxy(40,row);
		cout<<limit;
		if(row==22)
		{
			  row=6;
			  gotoxy(53,23);
			  cout<<"Page no.: " <<pageno;
			  pageno++;
			  gotoxy(53,24);
			  cout<<"Press any key to continue...";
			  getch();
			  goto C;
		}
	}
	gotoxy(53,23);
	cout<<"Page No. : " <<pageno;
	gotoxy(53,24);
	cout<<"Press any key to continue...";
	getch();
	file.close();
}
///////////////////////////////////////////////////
void customer::addcust()
{
		clrscr();
		box1();
		int n=returncardno();
		gotoxy(25,2);
		cout<<"WELCOME TO CUSTOMER ADD RECORD FORM";
		gotoxy(10,4);
		cout<<"Enter the name of the customer :";
		gets(name);
		gotoxy(10,5);
		cout<<"Enter the Address of the Customer :";
		gets(address);
		CC:
		gotoxy(10,6);
		cout<<"ENTER THE PHONE NO. :";
		gotoxy(30,6);
		cin>>phone;
		for(int i=0;i<strlen(phone);i++)
		{
			if(isalpha(phone[i]))
			{
			gotoxy(10,7);
			cout<<"ONLY NUMBERS ";
			getch();
			gotoxy(10,7);
			clreol();
			gotoxy(30,6);
			clreol();
			goto CC;
			}
		}
		D:
		char str[10];
		gotoxy(10,7);
		cout<<"Enter the Card Code ";
		gotoxy(30,7);
		cin>>str;
		for(i=0;i<strlen(str);i++)
		{
			if(isalpha(str[i]))
			{
				gotoxy(10,8);
				cout<<"ONLY NUMBERS ";
				getch();
				gotoxy(10,8);
				clreol();
				gotoxy(30,7);
				clreol();
				goto D;
			}
		}
		t_cardcode=atoi(str);

		fstream file;
		file.open("CARD.DAT",ios::in|ios::binary);
		int found=0;
		card r;
		while(file.read((char *)&r,sizeof(card)))
		{
			if(t_cardcode==r.returncardcode())
			{
					found=1;
					break;
			}
		}
		if(found==0)
		{
			gotoxy(10,8);
			cout<<"Card Code Not Exist ";
			gotoxy(10,9);
			cout<<"Enter Again ";
			gotoxy(10,8);
			getch();
			clreol();
			gotoxy(10,9);
			clreol();
			gotoxy(30,7);
			clreol();
			goto D;
		}
		cardno=n+1;
		t_limit=r.returnlimit();
		gotoxy(10,8);
		cout<<"Your Card Number."<<cardno;
		gotoxy(10,10);
		cout<<"Avaliable Cash Limit (Rs.)"<<t_limit;
		fstream file1;
		file1.open("CUST.DAT",ios::app|ios::binary);
		file1.write((char *)this,sizeof(customer));
		file1.close();
		file.close();
		gotoxy(40,18);
		cout<<"PRESS ANY KEY TO CONT...";
		getch();
}
////////////////////////////////////
void customer:: deletecustomer()
{
		clrscr();
		box1();
		int n,flag=0;
		char str[10];
		gotoxy(25,2);
		cout<<"WELCOME TO CUSTOMER DELETE RECORD FORM";
		AA:
		gotoxy(10,4);
		cout<<"Enter Card Number ";
		gotoxy(30,4);
		cin>>str;
		for(int i=0;i<strlen(str);i++)
		{
		if(isalpha(str[i]))
		{
			gotoxy(10,5);
			cout<<"ONLY NUMBERS ";
			getch();
			gotoxy(10,5);
			clreol();
			gotoxy(30,4);
			clreol();
			goto AA;
		}
		}
		n=atoi(str);
		fstream file;
		file.open("CUST.DAT",ios::in|ios::binary);
		fstream temp;
		temp.open("TEMP.DAT",ios::out|ios::binary);

		while(file.read((char *)this,sizeof(customer)))
		{
			if(n!=cardno)
			       temp.write((char *)this,sizeof(customer));
			if(n==cardno)
				flag=1;
		}
		file.close();
		temp.close();
		if(flag==1)
		{

			fstream f1;
			f1.open("TEMP.DAT",ios::in|ios::binary);
			fstream t1;
			t1.open("CUST.DAT",ios::out|ios::binary);
			while(f1.read((char *)this,sizeof(customer)))
			{
				t1.write((char *)this,sizeof(customer));
			}
			gotoxy(10,8);
			cout<<"RECORD DELETED...";
			f1.close();
			t1.close();
		}
		else
		{
			gotoxy(10,8);
			cout<<"RECORD NOT FOUND...";
		}
		gotoxy(40,18);
		cout<<"PRESS ANY KEY TO CONT...";
		getch();
		file.close();
		temp.close();
}
//////////////////////////////////////////////////////
void customer :: display_customerrecord()
{
	clrscr();
	int n,flag=0;
	char str[10];
	box1();
	gotoxy(25,2);
	cout<<"WELCOME TO CUSTOMER DISPLAY RECORD FORM";
	BB:
	gotoxy(10,4);
	cout<<"Enter the Card Number :";
	gotoxy(35,4);
	cin>>str;
	for(int i=0;i<strlen(str);i++)
	{
		if(isalpha(str[i]))
		{
			gotoxy(10,5);
			cout<<"ONLY NUMBERS ";
			getch();
			gotoxy(10,5);
			clreol();
			gotoxy(35,4);
			clreol();
			goto BB;
		}
	}
	n=atoi(str);
	fstream file;
	file.open("CUST.DAT",ios::in|ios::binary);
	while(file.read((char *) this, sizeof(customer)))
	{
		  if(n==cardno)
		  {
			gotoxy(10,6);
			cout<<"Customer Name ="<<name;
			gotoxy(10,8);
			cout<<"Customer Address ="<<address;
			gotoxy(10,10);
			cout<<"Customer phone ="<<phone;
			gotoxy(10,12);
			cout<<"Card Code ="<<t_cardcode;

			card r;
			fstream file1;
			file1.open("CARD.DAT",ios::in|ios::binary);
			while(file1.read((char *)&r,sizeof(card)))
			{
				if(t_cardcode==r.returncardcode())
				{
					gotoxy(10,14);
					cout<<"Card Name ="<<r.returncardname();
				}
			}
			gotoxy(10,16);
			cout<<"Card Limit ="<<t_limit;
			flag=1;
		  }
	}
	if(flag==0)
	{
		gotoxy(10,6);
		cout<<"CARD NUMBER NOT EXIST :";
	}
	gotoxy(40,18);
	cout<<"PRESS ANY KEY TO CONT...";
	getch();
	file.close();
	getch();
}
//////////////////////////////////////////
void customer :: display_customerlist()
{
	clrscr();
	fstream file;
	box1();
	file.open("CUST.DAT", ios::in|ios::binary);
	card r;
	int row=3,pageno=1;
	gotoxy(25,2);
	cout<<"LIST OF CUSTOMERS";
	gotoxy(5,3);
	cout<<"Card No.";
	gotoxy(15,3);
	cout<<"Name ";
	gotoxy(25,3);
	cout<<"Phone";
	gotoxy(35,3);
	cout<<"Card Code";
	gotoxy(48,3);
	cout<<"Card Name";
	gotoxy(65,3);
	cout<<"Card Limit";
	while(file.read((char *)this,sizeof(customer)))
	{
		row++;
		gotoxy(5,row);
		cout<<cardno;
		gotoxy(15,row);
		cout<<name;
		gotoxy(25,row);
		cout<<phone;
		gotoxy(35,row);
		cout<<t_cardcode;
		fstream file1;
		file1.open("CARD.DAT",ios::in|ios::binary);
		while(file1.read((char *)&r,sizeof(card)))
		{
			if(t_cardcode==r.returncardcode())
			{
				gotoxy(48,row);
				cout<<r.returncardname();
			}
		}
		gotoxy(65,row);
		cout<<t_limit;

		if(row==22)
		{
			row=5;
			gotoxy(53,23);
			cout<<"Page no.;"<<pageno;
			pageno++;
			gotoxy(53,24);
			cout<<"Press any key to continue...";
			getch();
		}
	}
	gotoxy(53,23);
	cout<<"Page No.: "<<pageno;
	gotoxy(53,24);
	cout<<"Press any key to continue...:";
	getch();
	file.close();
}

void madeby()
{
	textbackground(8);
	clrscr();
	box();
	gotoxy(30,12);
	cprintf("PROJECT MADE BY");
	gotoxy(30,13);
	cprintf("RISHABH and VARUN");
	gotoxy(50,20);
	cprintf("PRESS ANY KEY TO CONT...");
	getch();

}
void welcome()
{
	textbackground(8);
	clrscr();
	box();
	gotoxy(21,12);
	cprintf("WELCOME TO CREDIT CARD MANAGEMENT SYSTEM");
	gotoxy(50,20);
	cprintf("PRESS ANY KEY TO CONT...");
	getch();
	madeby();
}
void writecard()
{
	fstream file;
	card r[4];
	r[0].input(1,"Base card",8000);
	r[1].input(2,"Silver card",9000);
	r[2].input(3,"Gold card",10000);
	r[3].input(4,"Platinum card",12000);

	file.open("CARD.DAT",ios::out|ios::binary);
	for(int i=0;i<=3;i++)
	{     file.write((char *)&r[i],sizeof(card));
}        file.close();   }
void main(void) {
	menu_class m;
	welcome();
	writecard();
	m.menu();  }






