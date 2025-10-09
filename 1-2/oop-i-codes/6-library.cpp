#include<iostream>
using namespace std;

class book{
    int id;
    string ttl;
    string ath;
    bool avl;
    int rtn;

public:
    book(){}
    book(int idd,string ttll,string athh,bool avll){
        id=idd;
        ttl=ttll;
        ath=athh;
        avl=avll;
    }
    inline void check(){
        if(avl)
            cout<< "available\n";
        else
            cout<< "not available\n";
    }
    inline void print(){
        cout<< "book id: "<<id<<endl;
        cout<< "title: "<<ttl<<endl;
        cout<< "author: "<<ath<<endl;
        cout<< "return in: "<<rtn<< " days"<<endl;
    }
    void issue(int rtnn=14){
        rtn=rtnn;
    }
}b[20];

void prt(book b1){
    b1.print();
}
book getb(int j){
    return b[j];
}

int main(){
    int n;
    cout<< "enter number of books: ";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<< "\nbook #"<<i+1<<endl;

        int idd;
        cout<< "enter book id: ";
        cin>>idd;

        string ttll;
        cout<< "enter title: ";
        cin.ignore();
        getline(cin,ttll);

        string athh;
        cout<< "enter author: ";
        getline(cin,athh);

        bool avll;
        cout<< "available? (1/0): ";
        cin>> avll;

        b[i]=book(idd,ttll,athh,avll);

        bool x;
        cout<< "edit issue length? (1/0): ";
        cin>>x;

        if(x){
            int rtnn;
            cout<< "enter length: ";
            cin>>rtnn;
            b[i].issue(rtnn);
        }
        else
            b[i].issue();
    }
    int p;
    cout<< "\ncheck availability? (1/0): ";
    if(cin>>p&&p==1){
        int k;
        cout<< "enter book number: #";
        cin>>k;
        b[k-1].check();
    }
    int q;
    cout<< "\ndisplay a book? (1/0): ";
    if(cin>>q&&q==1){
        int k;
        cout<< "enter book number: #";
        cin>>k;
        prt(getb(k-1));
    }
    int r;
    cout<< "\ndisplay collections? (1/0): ";
    if(cin>>r&&r==1){
        cout<< "\nlibrary collections:\n";
        for(int i=0;i<n;i++){
            cout<< "\nbook #"<<i+1<<endl;
            b[i].print();
        }
    }
    return 0;
}
