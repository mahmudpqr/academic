#include<iostream>
#include<string>
using namespace std;

class Person{
    protected:
    string name;
    int patientID;

    public:
    Person(){}
    Person(string nm,int id){
        name=nm;
        patientID=id;
    }
    void displayPerson(){
        cout<<"Patient ID: "<<patientID<<endl;
        cout<<"Name: "<<name<<endl;
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
    double addTreatmentCost(double atc){
        treatmentCost+=atc;
        return treatmentCost;
    }
    double calculateInsuranceCoverage(){
        return treatmentCost*0.3;
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
};

class Patient:public MedicalRecord,public InsurancePolicy{
    public:
    Patient(string nm,int id,string ds,double tc,int pn,double mp):Person(nm,id),MedicalRecord(ds,tc),InsurancePolicy(pn,mp){}
    void displayAllDetails(){
        cout<<"\n--- Patient Healthcare Details ---\n";
        displayPerson();
        cout<<"Disease: "<<disease<<endl;
        cout<<"Treatment Cost: "<<treatmentCost<<endl;
        cout<<"Insurance Coverage (30%): "<<calculateInsuranceCoverage()<<endl;
        cout<<"Policy Number: "<<policyNumber<<endl;
        cout<<"Monthly Premium: "<<monthlyPremium<<endl;
        cout<<"Yearly Premium: "<<calculateYearlyPremium()<<endl<<endl;;
    }
};

int main(){
    int id;
    cout<<"\nEnter Patient ID: ";
    cin>>id;

    string nm;
    cout<<"Enter Patient Name: ";
    cin.ignore();
    getline(cin,nm);

    string ds;
    cout<<"Enter Disease: ";
    getline(cin,ds);

    double tc;
    cout<<"Enter Initial Treatment Cost: ";
    cin>>tc;

    int pn;
    cout<<"Enter Policy Number: ";
    cin>>pn;

    double mp;
    cout<<"Enter Monthly Premium: ";
    cin>>mp;

    Patient p(nm,id,ds,tc,pn,mp);

    double atc;
    cout<<"\nEnter additional treatment cost: ";
    cin>>atc;

    cout<<"Added treatment cost: "<<atc<<" | Total Cost: "<<p.addTreatmentCost(atc)<<endl;
    p.displayAllDetails();
    return 0;
}