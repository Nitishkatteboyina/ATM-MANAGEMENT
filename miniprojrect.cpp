#include<iostream>
#include<vector>
using namespace std;
double accnumber;
int pin,i;
int balance[5]={30000,100000,500000,2000,0};
double accounts[5][2]={998877665544,7799,1,9999,779924490800,1011,986681617600,2580,444000888000,1234};
class ATM
{
    
    public :
    void checkbalance(int i)
    {
        cout<<"the available amount in your account = "<<balance[i]<<endl;
    }
    void deposit(int i)
    {
        int amount;
        cout<<"enter the amount you want to deposit :-"<<endl;
        cin>>amount;
        if(amount<=20000)
        {
            if(amount%100==0 & amount>=100)
            {
                balance[i]= balance[i] + amount;
                cout<<amount<<" succesfully deposited"<<endl;
                checkbalance(i);
            }
            else
            {
                cout<<"the atm only takes 100 notes and 500 notes ,";
                cout<<" enter the amount regarding to that"<<endl;
                deposit(i);
            }
        }
        else
        {
            cout<<"you can only deposit twenty thousand at once."<<endl;
        }
    }
    void withdraw(int i)
    {
        int amount;
        cout<<"enter the required amount to withdraw :-"<<endl;
        cin>>amount;
        if(amount<=balance[i] & amount<=20000)
        {
            if(amount%100==0 & amount>=100)
            {
                balance[i] = balance[i] - amount;
                cout<<amount<<" withdrawn"<<endl;
                checkbalance(i);
            }
            else
            {
               cout<<"the atm only gives notes of 100's enter the amount in 100's"<<endl;
            }
        }
        else if(amount>balance[i])
        {
          cout<<"insufficent balance in your account to withdraw"<<endl; 
          checkbalance(i);
        }
        else
        {
            cout<<"you can only withdraw twenty thousand at once"<<endl;
        }
        
    }
    void pinchange(int  i)
    {
        int newpin;
        cout<<"enter your new pin :-"<<endl;
        cin>>newpin;
        accounts[i][1]=newpin;
        cout<<"pin changed succesfully"<<endl;
    }
    
};
int main()
{
    ATM atm;
    int choice;
    cout<<"___________________________________________________________________________________"<<endl<<endl;
    cout<<"**************************************WELCOME**************************************"<<endl;
    cout<<"****************************************TO*****************************************"<<endl;
    cout<<"****************************************ATM****************************************"<<endl;
    cout<<"___________________________________________________________________________________"<<endl<<endl;
    while(1)
    {
    cout<<"enter your account number :- "<<endl;
    cin>>accnumber;
    cout<<endl;
    cout<<"enter pin :-"<<endl;
    cin>>pin;
   for(int l=0;l<5;l++)
   {
    if(accnumber==accounts[l][0])
    {
        i=l;
    }
   }
    for(int x=0;x<5;x++)
    {
        if(accnumber ==accounts[x][0] & pin==accounts[x][1])
        {
         cout<<"enter your choice :- "<<endl;
         cout<<"1.check balance"<<endl;
         cout<<"2.deposit money"<<endl;
         cout<<"3.withdraw money"<<endl;
         cout<<"4.pin change"<<endl;
         cout<<"5.exit"<<endl;
         cin>>choice;
         switch (choice)
          {
            case 1 :
            {
                atm.checkbalance(i);
                break;
            }
             case 2 :
            {
                atm.deposit(i);
                break;
            }
             case 3 :
            {
                atm.withdraw(i);
                break;
            }
            case 4:
            {
                atm.pinchange(i);
                break;
            }
             case 5 :
            {
                cout<<"*********Thanks for visiting*********"<<endl;
                exit(1);
                break;
            }
            default :
            {
                cout<<"invalid choice..! enter your choice again :-"<<endl;
            }
          }
          break;
        }
    }
    }
}
