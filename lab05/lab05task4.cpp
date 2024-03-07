#include <iostream>
#include<string>
using namespace std;
class BankAccount{
    string accountno;
    double balance;
    string holdername;
    public:
    BankAccount(){

    }
    BankAccount(string accountno,string holdername,double balance){
        this->accountno=accountno;
        this->holdername=holdername;
        this->balance=balance;
    }
    void deposit(double amount){
       
            if(amount>=0){
                balance=balance+amount;
                }
            else{
                cout<<"Invalid input"<<endl;
            }
    }
   
    void withdraw(double amount){
       
       
        if(amount<balance){
        balance= balance - amount;
        }
        else{
            cout<<"You do not have sufficient balance";
          }
    }
    void display(){
        cout<<"The account number is : "<<accountno<<"\n";
        cout<<"The account holder name  is : "<<holdername<<"\n";
        cout<<"Your Current Balance is : "<<balance<<"\n";
    }
};

int main() {
    BankAccount arracc[3];
    for(int i=0;i<3;i++){
    string accountno;
    string holdername;
    double balance;
    cout<<"Enter your Account number; \n";
    getline(cin,accountno);
    cout<<"Enter the holder name:\n ";
    getline(cin,holdername);
    cout<<"Enter the Balance: \n";
   cin>>balance;
   cin.ignore();
   
    arracc[i]=BankAccount(accountno,holdername,balance);
    cout<<"Details Before taransaction; \n";
    arracc[i].display();
    arracc[i].deposit(500);
    arracc[i].withdraw(200);
    cout<<"Details After Transaction: \n";
    arracc[i].display();
   
}
}
