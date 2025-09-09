#include<iostream>
using namespace std;

class account{
    string name;
    int number;
    float balance;
    string message;
    float interest;

public:
    int rate;
    account(){}
    account(string nam,int num){
        name=nam;
        number=num;
        balance=0;
    }
    void deposit(float amt){
        balance+=amt;
        message="n/a";
    }
    void deposit(float amt,string msg){
        balance+=amt;
        message=msg;
    }
    void calculate(int rt=5){
        rate=rt;
        interest=balance*(float)rate/100.0*12.0;
    }
    static void transfer(account& x,account&y,float amt){
        x.balance-=amt;
        y.balance+=amt;
    }
    inline void display(){
        cout<< "holder name: "<<name<<endl;
        cout<< "a/c no: "<<number<<endl;
        cout<< "balance: "<<balance<<endl;
        cout<< "yearly interest: "<<interest<<endl;
        cout<< "deposit message: "<<message<<endl;
    }
}a[20];

int main(){
    int n;
    cout<< "enter number of accounts: ";
    cin>>n;
    cin.ignore();

    for(int i=0;i<n;i++){
        cout<< "\naccount #"<<i+1<<endl;

        string namm;
        cout<< "enter holder name: ";
        getline(cin,namm);

        int numm;
        cout<< "enter a/c no: ";
        cin>>numm;

        a[i]=account(namm,numm);

        int amtt;
        cout<< "deposit amount: ";
        cin>>amtt;

        int rtt;
        cout<< "interest rate? (-1 to skip): ";
        cin>>rtt;

        if(rtt!=-1)
            a[i].calculate(rtt);
        else
            a[i].calculate();

        string msgg;
        cout<< "deposit message? (0 to skip): ";
        cin.ignore();
        getline(cin,msgg);

        if(msgg!="0")
            a[i].deposit(amtt,msgg);
        else
            a[i].deposit(amtt);
    }

    char yn;
    int amnt;
    cout<< "\ntransfer? (y/n): ";
    cin>>yn;

    if(yn=='y'){
        int m,n;
        cout<< "#from and #to: ";
        cin>>m>>n;
        cout<< "enter amount: ";
        cin>>amnt;
        account::transfer(a[m-1],a[n-1],amnt);
    }
    for(int i=0;i<n;i++)
        a[i].calculate(a[i].rate);

    cout<< "\naccount details:\n";

    for(int i=0;i<n;i++){
        cout<< "\naccount #"<<i+1<<endl;
        a[i].display();
    }
    return 0;
}
