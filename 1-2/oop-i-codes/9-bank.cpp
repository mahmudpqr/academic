#include<bits/stdc++.h>
using namespace std;

class Customer{
    protected:
    string name;

    public:
    int customerID;

    Customer(){}
    Customer(int id,string nm){
        customerID=id;
        name=nm;
    }
    void displayCustomer(){
        cout<<"\nCustomer ID: "<<customerID;
        cout<<"\nName: "<<name;
    }
};

class SavingsAccount:virtual public Customer{
    protected:
    double balance;
    double interestRate;

    public:
    SavingsAccount(double bl,double ir){
        balance=bl;
        interestRate=ir;
    }
    void deposit(){
        double dp;
        cout<<"Enter Deposit Amount: ";
        cin>>dp;

        balance+=dp;
        cout<<"\nDeposited: "<<dp<<" | Total Balance: "<<balance<<"\n";
    }
    double calculateInterest(){
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
    double loanAmount;
    double EMI;

    public:
    LoanAccount(double la){
        loanAmount=la;
    }
    double calculateEMI(){
        EMI=loanAmount/12;
        return EMI;
    }
    void displayLoan(){
        cout<<"\nLoan Amount: "<<loanAmount;
        cout<<"\nEMI (12 Months): "<<calculateEMI()<<"\n";
    }
};

class AccountHolder:public SavingsAccount,public LoanAccount{
    public:
    AccountHolder(int id,string nm,double bl,double ir,double la):Customer(id,nm),SavingsAccount(bl,ir),LoanAccount(la){}
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
    a.emplace_back(5139,"Abdul Hamim Sheikh",872000,5,190000);
    a.emplace_back(3774,"Zakaria Chowdhury",525000,3,250000);
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
            int id;
            while(1){
                cout<<"\nEnter Customer ID: ";
                cin>>id;
                if(findID(id)!=nullptr){
                    cout<<"Already in Use!\n";
                }
                else break;
            }

            string nm;
            cout<< "Enter Name: ";
            cin.ignore();
            getline(cin,nm);

            double bl,ir,la;

            cout<<"Enter Balance: ";
            cin>>bl;
            cout<<"Enter Interest Rate %: ";
            cin>>ir;
            cout<<"Enter Loan Amount: ";
            cin>>la;

            a.emplace_back(id,nm,bl,ir,la);
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
