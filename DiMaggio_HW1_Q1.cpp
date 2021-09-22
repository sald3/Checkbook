#include <iostream>
using namespace std;

struct Check{
    int CheckNum;
    string CheckMemo;
    float CheckAmount;
};
class CheckBook{
public:
    float balance;
    int checkLimit = N;
    Check arr[5];
    float lastDeposit;
    int numOfChecks;
    const int N=5;

    CheckBook(){
        balance = 0.00;
        numOfChecks = 0;
    }
    CheckBook(float balance){
        this->balance = balance;
        numOfChecks = 0;
    }

    void deposit(float amount){
        balance += amount;
    }

    void displayChecks(){
        cout << "Check Number\t Check Memo\t Check Amount" <<endl;
        for(int i = numOfChecks - 1; i >= 0; i--){
            cout << arr[i].CheckNum << "\t\t" << arr[i].CheckMemo << "\t\t" << arr[i].CheckAmount<<endl;
        }
    }
    bool writeCheck(float amount){
        if(amount <= balance){
            cout<<"Enter the memo: ";
            cin >> arr[numOfChecks].CheckMemo;
            arr[numOfChecks].CheckAmount = amount;
            arr[numOfChecks].CheckNum = numOfChecks + 1;
            numOfChecks++;
            balance -= amount;
        }
        else
            return false;
    }
};

int main() {
    CheckBook cb1(1000), cb2(500);

    for (int i = 0; i < 10; i++) {
        cb1.writeCheck(150);
        cb2.writeCheck(130);
    }
    cout << "cb1 check details" << endl;
    cb1.displayChecks();
    cout << "cb2 check details" << endl;
    cb2.displayChecks();
}
