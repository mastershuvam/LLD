//static keyword and static function 

#include<iostream>
using namespace std;

class Customer{

    string name;
    int account_no;
    int balance;
    
    static int total_account;
    static int total_balance;


    public:
    //parameterized constructor
    Customer(string name, int account_no, int balance){
        this->name = name;
        this->account_no = account_no;
        this->balance = balance;
        total_account++;
        total_balance += balance;
    }

    //static function

    static void getTotalAccount(){
        cout<<"Total Account: "<<total_account<<endl;
    }

    static void getTotalBalance(){
        cout<<"Total Balance: "<<total_balance<<endl;
    }

    //display function

    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Account No: "<<account_no<<endl;
        cout<<"Balance: "<<balance<<endl;
        //cout<<"Total Account: "<<total_account<<endl;
        cout<<endl;
    }

    //deposit function
    void deposit(int amount){
        if(amount > 0){
            balance += amount;
            total_balance += amount;
            cout<<"Amount deposited successfully your balance :"<<balance<<endl;
        }
    }

    //withdraw function
    void withdraw(int amount){
        if(amount>0 && amount<=balance){
            balance -= amount;
            total_balance -= amount;
            cout<<"Amount withdrawn successfully your balance :"<<balance<<endl;
        }
    }

    //total account and total balance with password

    void showTotalAccount(int pass){
        if(pass == 1234){
            cout<<"Total Account: "<<total_account<<endl;
        }else{
            cout<<"Invalid Password"<<endl;
        }
    }

    void showTotalBalance(int pass){
        if(pass == 1234){
            cout<<"Total Balance: "<<total_balance<<endl;
        }else{
            cout<<"Invalid Password"<<endl;
        }
    }


};

int Customer :: total_account = 0;
int Customer :: total_balance = 0;

int main(){
    Customer c1("Rohit", 101, 5000);
    Customer c2("Sohan", 102, 6000);
    Customer c3("Mohan", 103, 7000);

    /*
    c1.display();
    c2.display();
    c3.display();

    c1.showTotalAccount(1234);
    c2.showTotalBalance(1234);

    c1.deposit(2000);
    c2.withdraw(1000);

    c1.showTotalBalance(1234);
    */

    //static function call
    Customer::getTotalAccount();
    Customer::getTotalBalance();

    c1.deposit(2000);
    Customer::getTotalBalance();
    c1.display();


}