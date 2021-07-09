#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
class bank
{ private:
  char name[20];
  int pin;
  int accno;
  char typeacc[20];
  int balance;
  int loan;
public:
	void setvalue()
	{
		cout<<"enter name"<<endl;
		char n;
        cin.get();
		gets(name);
		balance=0;
		loan=0;
		cout<<"data verified"<<endl;
	}
	void ac(int u)
	{
		cout<<"your account no will be  "<<(1000+u)<<endl;
		accno=1000+u;
	}


	void pincheck()
	{
		cout<<"enter pin code of ur choice"<<endl;
		cin>>pin;
	}
	void deposit()
	{
       cout<<"enter money to be depodited"<<endl;
       int b;
       cin>>b;
       balance=balance+b;
       cout<<"total money in your account-"<<balance<<endl<<"your ammount is added"<<endl;

	}
	void withdraw()
	{
		cout<<"enter ammount to withdraw"<<endl;
		int a;
		cin>>a;
		balance=balance-a;
		if(balance<0)
		{
			cout<<"sorry you dont have enough money"<<endl;
			balance=balance+a;
			cout<<"money in your account-"<<balance<<endl;
		}
		else
		{
			cout<<"thanks for for transaction"<<endl;
			cout<<"money in your account-"<<balance<<endl;
		}
	}
	void balancecheck()
	{
		cout<<"your name is-"<<name<<endl<<"your balance is-"<<balance<<endl<<"loan to be paid-"<<loan<<endl;
	}
	int honesty(int u , bank *w)
	{
	cout<<"enter pin number"<<endl;
             int p;
             cin>>p;
             for(int k=0;k<=u;k++)
             {
             	if ((w+k)->pin==p)
             	{
             		cout<<"\n welcome "<<(w+k)->name<<endl<<"your account no is "<<(1000+k+1)<<endl;
             		return(k+1);

             	}

             }
             return(0);

	}
	void exchange(int u, bank *w)
	{
		cout<<"enter account no where u have to transfer money"<<endl;
		int y;
		int q;
		cin>>y;
		int k;
		for( k=0;k<=u;k++)
             {
             	if ((w+k)->accno==y)
             	{
             		cout<<"\n his name is "<<(w+k)->name<<endl;
             		goto hey;

             	}}
        {cout<<"no such account no exist"<<endl;
                return;}
       hey: cout<<"enter money to deposit"<<endl;
        int r;
        cin>>r;
        if(r<=balance)
        {
          balance=balance-r;
          (w+k)->balance+=r;
          cout<<"money has been transfered"<<endl<<"money left in your account is "<<balance<<endl;
        }
        else{cout<<"you dont have enough money"<<endl<<"money in your account is"<<balance<<endl;
             return;}
	}
	void loantake()
	{
		cout<<endl<<"interest to be paid will be 20 percent"<<endl;
		cout<<"press 1 to take loan "<<endl<<"press 2 to return loan"<<endl<<"press 3 to go back to main menu"<<endl;
		int o;
		cin>>o;
		switch(o)
		{
			case 1:cout<<"enter amount you want as loan"<<endl;
			       int y;
			       cin>>y;
			       loan=loan+y+y*20/100;
			       cout<<"you have to pay "<<loan<<" back to bank"<<endl<<"THANKS"<<endl;
			             break;
            case 2:cout<<"loan you have to back to bank is -"<<loan<<endl;
                   cout<<"enter ammount you want to pay back and ammount will be deducted from your account"<<endl;
                   int d;
                   cin>>d;
                   int e;
                   e=balance-d;
                   if(e>=0)
                   {
                   loan=loan-d;
                   balance=e;
                   cout<<"now loan to be paid left -"<<loan<<endl;
                   cout<<"your balance is -"<<balance<<endl;}
                   else
                   {
                   	cout<<"sorry you dont have enough ammount in account"<<endl;
                   	cout<<"money in your account is -"<<balance<<endl;
                   }
                   break;
            case 3:break;
		}
	}
	/*void verify(bank b1)
	{
		cout<<"enter your account number";
		int q;
		cin>>q;

	}*/
};

int main()
{
	bank s[100];
	for(int j=1;;j++)
	{ ab:
	cout<<"press 1 to add account"<<endl<<"press 2 to add money to existing account"<<endl<<"press 3 withdraw money"<<endl;
	cout<<"press  4 to see account details"<<endl<<"press 5 to take loan issues."<<endl<<"press 6 to give money to other account"<<endl;
	int z;
	cin>>z;
	if(z==0)
	{
   cout<<"error";
   goto ab;

	}
	switch(z)
	{
      case 1:s[j].setvalue();
             s[j].ac(j);
             s[j].pincheck();
             break;
      case 2:int t;
              t=s[j].honesty(j,&s[1]);
              cout<<t;
             if (t>0)
             {
             	s[t].deposit();
             	goto ab;
             }
             else
                {cout<<"sorry you dont have a account first create account"<<endl;
             goto ab;}
      case 3:t=s[j].honesty(j,&s[1]);
             if (t>0)
             {
             	s[t].withdraw();
             	goto ab;
             }
             else
                {cout<<"sorry you dont have a account first create account"<<endl;
             goto ab;}
      case 4:t=s[j].honesty(j,&s[1]);
             if (t>0)
             {
             	s[t].balancecheck();
             	goto ab;
             }
             else
                {cout<<"sorry you dont have a account first create account"<<endl;
             goto ab;}
       case 5:t=s[j].honesty(j,&s[1]);
              if (t>0)
             {
             	s[t].loantake();
             	goto ab;
             }
             else
                {cout<<"sorry you dont have a account first create account"<<endl;
             goto ab;}
       case 6:t=s[j].honesty(j,&s[1]);
             if (t>0)
             {
             	s[t].exchange(j,&s[1]);
             	goto ab;
             }
             else
                {cout<<"sorry you dont have a account first create account"<<endl;
             goto ab;}
      default: goto ab;
	}cout<<"OUR TOTAL CUSTOMERS-"<<j<<endl;
	 }
}
