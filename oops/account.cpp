// bank problem using inheritance
// cs20b1085 gugulothu ravindar
#include <iostream>

using namespace std;

class Account
{

private:

double balance;

public:
      double creditAmount,totalAmount,account;
      double debitAmount;
      double rate;
      double interest;
      double amount;
      double savingsAccount,checkingAccount;
      double checkingAccountNumber;
       void openAccount()
       {
       double account;
       int choice;
       cout<<"\n 1.savings account ";
       cout<<"\n 2.checking account";
       cout<<"\n enter your choice ";
       cin>>choice;
       switch(choice)
       {
            case 1:
            {
                cout<<"enter the saavings account no :";
                cin>>savingsAccount;
             }
             break; 
             case 2:
            {
                 double bal2;
                cout<<"enter the checking account no :";
                cin>>checkingAccountNumber;
                cout<<"enter the initial balance :";
                cin>>bal2;
             }
             break;
             case 3:
             exit(1);
        }        
       
       }
       void creditAccount()
       {
          
         cout<<"enter the account no :\n";
         cin>>account;
         if(account==savingsAccount)
         {
         cout<<"enter the amount to be credited in your account :";
        cin>>creditAmount;
         }     
        else 
        {
        cout<<"invalid account no ";
        }
        
        if(balance>0)
        {
           totalAmount = balance+creditAmount;
         }
         else
         {
           totalAmount = creditAmount;
           }
           cout<<totalAmount;
         }
         void debitAccount()
         {
         double dAccount;
         cout<<" enter the account no :";
         cin>>dAccount;
         if(dAccount==savingsAccount)
         {
         cout<<"enter the amount to be debited from your account :";
        cin>>debitAmount;
         }     
        else 
        {
        cout<<"invalid account no ";
        }
         if(debitAmount>totalAmount){
          cout<<"not sufficent balance "<<endl; 
          }
          else
          {
           totalAmount = creditAmount - debitAmount;
           }
          cout<<totalAmount;
          }
          void interestRate()
          {
            cout<<" enter the interest :";
            cin>>rate;
            cout<<rate<<"%";
          }
          void calculateInterest()
          {
          //double interest;
          interest = (rate*totalAmount)/100;
          cout<<interest;
         }
         void updateInterest()
         {
         amount = totalAmount + interest ;
         cout<<amount;
         }
  };
class CheckingAccount : public Account
{
 public:
        int newFee;
        
        void feeUpdate();
        void printCheckingFee();
        void transactAndUpdate();
       
};

void CheckingAccount :: feeUpdate()
{
 int feeAccNumber;
 cout<<"Information regarding Checking/Updating FEE amount"<<endl;
 
 cout<<"\nEnter Checking Account Number"<<endl;
 cin>>feeAccNumber;
 
 
 if(feeAccNumber != checkingAccount || checkingAccountNumber)
 {
  cout<<"Enter the New fee amount - ";
  cin>>newFee;
  cout<<"The NEW fee amount for further transaction is Rs."<<newFee<<" "<<endl;
 }
 else
 {
  cout<<"Account number exists in SAVING Account"<<endl;
 }
 
}

void CheckingAccount :: printCheckingFee()
{
 int feeAccNumber;
 
 cout<<"\nEnter Checking Account Number"<<endl;
 cin>>feeAccNumber;
 
 
 if(feeAccNumber != checkingAccount || checkingAccountNumber)
 {
  cout<<"New FEE amount for account number "<<feeAccNumber<<" for further transaction is Rs."<<newFee<<" "<<endl;
 }
 else
 {
  cout<<"Account number exists in SAVING Account"<<endl;
 }
 
 
}


void CheckingAccount :: transactAndUpdate()
{
 int feeAccNumber;
 
 cout<<"\nEnter Checking Account Number"<<endl;
 cin>>feeAccNumber;
 
 
 if(feeAccNumber != checkingAccount || checkingAccountNumber)
 {
  cout<<"New FEE amount for account number "<<feeAccNumber<<" for further transaction is Rs."<<newFee<<" "<<endl;
 }
 else
 {
  cout<<"Account number exists in SAVING Account"<<endl;
 }
 
 }
      
int main()

{
   Account a;
   CheckingAccount b;
     int choice, num, Choice;
      while(1)
     {
        cout<<"\n 1. Open Account (Savings or Checking Account)";
        cout<<"\n 2. Credit (Savings or Checking Account)";
        cout<<"\n 3. Debit (Savings or Checking Account)";
        cout<<"\n 4. Change/Update Interest rate (Savings Account)";
        cout<<"\n 5. Calculate Interest (Savings Account - Print)";
        cout<<"\n 6. Calculate and Update Interest (Savings Account - Credit)";
        cout<<"\n 7. Change/Update Fee Amount (Checking Account)";
        cout<<"\n 8. Print Checking Fee (Checking Account)";
        cout<<"\n 9. Transact and Update (Checking Account - Debit)";
        cout<<"\n 10. Exit";
        cout<<"\nEnter your choice:";
        cin>>choice;
        switch(choice)
        {
                case 1:
                {
                  a.openAccount();
                }                   
                break;
                case 2:
                {
                  a.creditAccount(); 
                }
                break;
                case 3:
                {
                  a.debitAccount();
                }
                break;
                case 4:
                {
                   a.interestRate();
                }                   
                break;
                case 5:
                {
                   a.calculateInterest();
                }                   
                break;
                case 6:
                {
                   a.updateInterest();
                }                   
                break;
                case 7:
                {
                   b.feeUpdate();
                }                   
                break;
                case 8:
                {
                   b.printCheckingFee();
                }                   
                break;
                case 9:
                {
                   b.transactAndUpdate();
                }                   
                break;
                case 10:
                exit(1);
            default:
                cout<<"\nWrong choice, try again!\n";
        }
    }
return 0;
}