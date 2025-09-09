#include<iostream>
#include<string>
using namespace std;

class Customer{
protected:
    string name;
    int customerID;
public:
    Customer(){}
    Customer(string nm,int id){
        name=nm;
        customerID=id;
    }
    void displayCustomer(){
        cout<< "Name: "<<name<<endl;
        cout<< "Customer ID: "<<customerID<<endl;
    }
};

class SavingsAccount:virtual public Customer{
protected:
    float balance;
    float interestRate;
public:
    SavingsAccount(float bl,float ir){
        balance=bl;
        interestRate=ir;
    }
    void deposit(float dp){
        balance+=dp;
    }
    float calculateInterest(){
        return balance*interestRate/100;
    }
};

class LoanAccount:virtual public Customer{
protected:
    float loanAmount;
    float EMI;
public:
    LoanAccount(float la){
        loanAmount=la;
    }
    float calculateEMI(){
        EMI=loanAmount/12;
        return EMI;
    }
};

class AccountHolder:public SavingsAccount,public LoanAccount{
public:
    AccountHolder(string nm,int id,float bl,float ir,float la):SavingsAccount(bl,ir),LoanAccount(la),Customer(nm,id){}
    void displayAllDetails(){
        cout<< "\nCustomer Details:\n";
        displayCustomer();
        cout<< "Balance: "<<balance<<endl;
        cout<< "Interest Rate: "<<interestRate<< "%\n";
        cout<< "Monthly Interest: "<<calculateInterest()<<endl;
        cout<< "Loan Amount: "<<loanAmount<<endl;
        cout<< "EMI: "<<calculateEMI()<<endl<<endl;
    }
};

int main(){
    string nm;
    cout<< "\nEnter Name: ";
    getline(cin,nm);

    int id;
    cout<< "Enter Customer ID: ";
    cin>>id;

    float bl;
    cout<< "Enter Balance: ";
    cin>>bl;

    float ir;
    cout<< "Enter Interest Rate%: ";
    cin>>ir;

    float la;
    cout<< "Enter Loan Amount: ";
    cin>>la;

    AccountHolder a(nm,id,bl,ir,la);

    float dp;
    cout<< "Deposit Amount: ";
    cin>>dp;

    a.deposit(dp);
    a.displayAllDetails();
    return 0;
}
