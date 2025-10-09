#include<bits/stdc++.h>
using namespace std;

class Person{
    protected:
    string name;

    public:
    int patientID;

    Person(){}
    Person(int id,string nm){
        patientID=id;
        name=nm;
    }
    void displayPerson(){
        cout<<"\nPatient ID: "<<patientID;
        cout<<"\nName: "<<name;
    }
};

class MedicalRecord:virtual public Person{
    protected:
    string disease;
    double treatmentCost;

    public:
    MedicalRecord(string ds,double tc){
        disease=ds;
        treatmentCost=tc;
    }
    void addTreatmentCost(){
        double atc;
        cout<<"Enter Additional Cost: ";
        cin>>atc;

        treatmentCost+=atc;
        cout<<"\nAdded: "<<atc<<" | Total Cost: "<<treatmentCost<<"\n";
    }
    double calculateInsuranceCoverage(){
        return treatmentCost*0.3;
    }
    void displayMedical(){
        cout<<"\nDisease: "<<disease;
        cout<<"\nTreatment Cost: "<<treatmentCost;
        cout<<"\nInsurance Coverage (30 %): "<<calculateInsuranceCoverage();
    }
};

class InsurancePolicy:virtual public Person{
    protected:
    int policyNumber;
    double monthlyPremium;

    public:
    InsurancePolicy(int pn,double mp){
        policyNumber=pn;
        monthlyPremium=mp;
    }
    double calculateYearlyPremium(){
        return monthlyPremium*12;
    }
    void displayPolicy(){
        cout<<"\nPolicy Number: "<<policyNumber;
        cout<<"\nMonthly Premium: "<<monthlyPremium;
        cout<<"\nYearly Premium: "<<calculateYearlyPremium()<<"\n";
    }
};

class Patient:public MedicalRecord,public InsurancePolicy{
    public:
    Patient(int id,string nm,string ds,double tc,int pn,double mp):Person(id,nm),MedicalRecord(ds,tc),InsurancePolicy(pn,mp){}
    void displayAllDetails(){
        cout<<"\n--- Patient Details ---";
        displayPerson();
        displayMedical();
        displayPolicy();
    }
    friend void compareTreatmentCost(Patient& x,Patient& y);
    friend void generateBill(Patient& x);
};

void compareTreatmentCost(Patient& x,Patient& y){
    cout<< "\n--- Comparing Treatment Costs ---";
    if(x.treatmentCost>y.treatmentCost)
        cout<<"\n"<<x.name<<" has higher treatment cost ("<<x.treatmentCost<<") than "<<y.name<< " ("<<y.treatmentCost<<")\n";
    else if(x.treatmentCost<y.treatmentCost)
        cout<<"\n"<<x.name<<" has lower treatment cost ("<<x.treatmentCost<<") than "<<y.name<< " ("<<y.treatmentCost<<")\n";
    else
        cout<<"\n"<<x.name<<" and "<<y.name<<" have equal treatment costs ("<<x.treatmentCost<<")\n";
}
void generateBill(Patient& x){
    cout<<"\n--- Patient Bill ---";
    cout<<"\nName: "<<x.name;
    cout<<"\nTreatment Cost: "<<x.treatmentCost;
    cout<<"\nInsurance Coverage (30%): "<<x.calculateInsuranceCoverage();
    cout<<"\nNet Payable Amount: "<<x.treatmentCost-x.calculateInsuranceCoverage()<<"\n";
}
vector<Patient> p;

Patient* findID(int id){
    for(int i=0;i<p.size();i++){
        if(p[i].patientID==id){
            return &p[i];
        }
    }
    return nullptr;
}

int main(){
    p.emplace_back(5139,"Abdul Hamim Sheikh","Heart Failure",372000,6825,1100);
    p.emplace_back(3774,"Zakaria Chowdhury","Appendicitis",125000,7911,800);
    cout<<fixed<<setprecision(2);

    while(1){
        cout<<"\n=== Healthcare System Menu ===";
        cout<<"\n1. Add New Patient";
        cout<<"\n2. Add Treatment Cost";
        cout<<"\n3. Display Patient Details";
        cout<<"\n4. Compare Treatment Costs";
        cout<<"\n5. Generate Patient Bill";
        cout<<"\n6. Exit";
        cout<<"\n\nEnter Your Choice: ";

        int ch;
        cin>>ch;

        if(ch==1){
            int id;
            while(1){
                cout<<"\nEnter Patient ID: ";
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

            string ds;
            cout<< "Enter Disease: ";
            getline(cin,ds);
            
            double tc,mp;
            int pn;

            cout<<"Enter Treatment Cost: ";
            cin>>tc;
            cout<<"Enter Policy Number: ";
            cin>>pn;
            cout<<"Enter Monthly Premium: ";
            cin>>mp;

            p.emplace_back(id,nm,ds,tc,pn,mp);
            cout<<"\nPatient Added Successfully!\n";
        }
        else if(ch==2){
            int id;
            cout<<"Enter Patient ID: ";
            cin>>id;

            Patient* ob=findID(id);
            if(ob!=nullptr){
                ob->addTreatmentCost();
            }
            else{
                cout<<"Patient Not Found!\n";
            }
        }
        else if(ch==3){
            int id;
            cout<<"Enter Patient ID: ";
            cin>>id;

            Patient* ob=findID(id);
            if(ob!=nullptr){
                ob->displayAllDetails();
            }
            else{
                cout<<"Patient Not Found!\n";
            }
        }
        else if(ch==4){
            int id1,id2;
            cout<<"Enter 1st Patient ID: ";
            cin>>id1;
            cout<<"Enter 2nd Patient ID: ";
            cin>>id2;

            Patient* ob1=findID(id1);
            Patient* ob2=findID(id2);

            if(ob1!=nullptr&&ob2!=nullptr){
                compareTreatmentCost(*ob1,*ob2);
            }
            else{
                cout<<"Patients Not Found!\n";
            }
        }
        else if(ch==5){
            int id;
            cout<<"Enter Patient ID: ";
            cin>>id;

            Patient* ob=findID(id);
            if(ob!=nullptr){
                generateBill(*ob);
            }
            else{
                cout<<"Patient Not Found!\n";
            }
        }
        else if(ch==6){
            cout<<"Exiting Healthcare System...\n\n";
            break;
        }
        else{
            cout<<"Invalid Choice!\n";
        }
    }
    return 0;
}