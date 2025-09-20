#include<bits/stdc++.h>
using namespace std;

class Customer{
    protected:
    string name;

    public:
    int customerID;

    Customer(){
        customerID=0;
    }
    Customer(string nm,int id){
        name=nm;
        customerID=id;
    }
    void displayCustomer(){
        cout<<"\nName: "<<name;
        cout<<"\nCustomer ID: "<<customerID;
    }
};

class SavingsAccount:virtual public Customer{
    protected:
    float interestRate;
    float balance;

    public:
    SavingsAccount(){}
    SavingsAccount(float bl,float ir){
        balance=bl;
        interestRate=ir;
    }
    void deposit(){
        float dp;
        cout<<"Enter Deposit Amount: ";
        cin>>dp;

        balance+=dp;
        cout<<"\nDeposited: "<<dp<<" | Total Balance: "<<balance<<"\n";
    }
    float calculateInterest(){
        return balance*interestRate/100;
    }
    void displaySavings(){
        cout<<"\nBalance: "<<balance;
        cout<<"\nInterest Rate: "<<interestRate<<" %";
        cout<<"\nMonthly Interest: "<<calculateInterest();
    }
};

class LoanAccount:virtual public Customer{
    protected:
    float loanAmount;
    float EMI;

    public:
    LoanAccount(){}
    LoanAccount(float la){
        loanAmount=la;
    }
    float calculateEMI(){
        EMI=loanAmount/12;
        return EMI;
    }
    void displayLoan(){
        cout<<"\nLoan Amount: "<<loanAmount;
        cout<<"\nEMI: "<<calculateEMI()<<"\n";
    }
};

class AccountHolder:public SavingsAccount,public LoanAccount{
    public:
    AccountHolder(){}
    AccountHolder(string nm,int id,float bl,float ir,float la):SavingsAccount(bl,ir),LoanAccount(la),Customer(nm,id){}
    void displayAllDetails(){
        cout<< "\n--- Account Details ---";
        displayCustomer();
        displaySavings();
        displayLoan();
    }
    friend void compareSavings(AccountHolder& x,AccountHolder& y);
    friend void generateLoanSummary(AccountHolder& x);
};

void compareSavings(AccountHolder& x,AccountHolder& y){
    cout<< "\n--- Comparing Savings Balances ---";
    if(x.balance>y.balance)
        cout<<"\n"<<x.name<<" has higher balance ("<<x.balance<<") than "<<y.name<< " ("<<y.balance<<")\n";
    else if(x.balance<y.balance)
        cout<<"\n"<<x.name<<" has lower balance ("<<x.balance<<") than "<<y.name<< " ("<<y.balance<<")\n";
    else
        cout<<"\n"<<x.name<<" and "<<y.name<<" have equal balances ("<<x.balance<<")\n";
}
void generateLoanSummary(AccountHolder& x){
    cout<<"\n--- Loan Summary ---";
    cout<<"\nCustomer Name: "<<x.name;
    x.displayLoan();
}
vector<AccountHolder> a;

AccountHolder* findID(int id){
    for(int i=0;i<a.size();i++){
        if(a[i].customerID==id){
            return &a[i];
        }
    }
    return nullptr;
}

int main(){
    a.emplace_back("Abdul Hamim Sheikh",5139,872000,3,190000);
    a.emplace_back("Zakaria Chowdhury",3774,525000,5,250000);
    cout<<fixed<<setprecision(2);

    while(1){
        cout<<"\n=== Banking System Menu ===";
        cout<<"\n1. Add New Account";
        cout<<"\n2. Deposit to Savings";
        cout<<"\n3. Display Account Details";
        cout<<"\n4. Compare Savings Balances";
        cout<<"\n5. Generate Loan Summary";
        cout<<"\n6. Exit";
        cout<<"\n\nEnter Your Choice: ";

        int ch;
        cin>>ch;

        if(ch==1){
            string nm;
            cout<< "\nEnter Name: ";
            cin.ignore();
            getline(cin,nm);

            int id;
            float bl,ir,la;

            while(1){
                cout<<"Enter Customer ID: ";
                cin>>id;
                if(findID(id)!=nullptr){
                    cout<<"Already in Use!\n";
                }
                else break;
            }
            cout<<"Enter Balance: ";
            cin>>bl;
            cout<<"Enter Interest Rate %: ";
            cin>>ir;
            cout<<"Enter Loan Amount: ";
            cin>>la;

            a.emplace_back(nm,id,bl,ir,la);
            cout<<"\nAccount Added Successfully!\n";
        }
        else if(ch==2){
            int id;
            cout<<"Enter Customer ID: ";
            cin>>id;

            AccountHolder* ob=findID(id);
            if(ob!=nullptr){
                ob->deposit();
            }
            else{
                cout<<"Account Not Found!\n";
            }
        }
        else if(ch==3){
            int id;
            cout<<"Enter Customer ID: ";
            cin>>id;

            AccountHolder* ob=findID(id);
            if(ob!=nullptr){
                ob->displayAllDetails();
            }
            else{
                cout<<"Account Not Found!\n";
            }
        }
        else if(ch==4){
            int id1,id2;
            cout<<"Enter 1st Customer ID: ";
            cin>>id1;
            cout<<"Enter 2nd Customer ID: ";
            cin>>id2;

            AccountHolder* ob1=findID(id1);
            AccountHolder* ob2=findID(id2);

            if(ob1!=nullptr&&ob2!=nullptr){
                compareSavings(*ob1,*ob2);
            }
            else{
                cout<<"Accounts Not Found!\n";
            }
        }
        else if(ch==5){
            int id;
            cout<<"Enter Customer ID: ";
            cin>>id;

            AccountHolder* ob=findID(id);
            if(ob!=nullptr){
                generateLoanSummary(*ob);
            }
            else{
                cout<<"Account Not Found!\n";
            }
        }
        else if(ch==6){
            cout<<"Exiting Banking System...\n\n";
            break;
        }
        else{
            cout<<"Invalid Choice!\n";
        }
    }
    return 0;
}
