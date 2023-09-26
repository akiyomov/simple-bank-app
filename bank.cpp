//
// Created by asadbek on 23. 9. 25.
//
#include <iostream>
#include "bank.h"
#include <cstring>

using namespace std;

Account accArr[MAX_ACC_NUM]; // Account array
int accNum = 0;      // # of accounts

void ShowMenu(void) {
    cout << "-----Menu------" << endl;
    cout << "1. Make Accout" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdrawal" << endl;
    cout << "4. Display all" << endl;
    cout << "5. Update Account" << endl;
    cout << "6. Delete Account" << endl;
    cout << "7. Transfer Funds" << endl;
    cout << "8. Exit" << endl;

}

void MakeAccount(void) {
    int id;
    char name[NAME_LEN];
    int balance;

    if (accNum >= MAX_ACC_NUM) {
        cout << "Sorry! cannot make an account anymore." << endl;
        return;
    }

    cout << "[Make Account]" << endl;
    cout << "Account ID: ";
    cin >> id;
    cin.ignore(); // Clear the input buffer before reading the name
    cout << "Customer Name: ";
    cin.getline(name, NAME_LEN);
    cout << "Deposit amount: ";
    cin >> balance;
    cout << endl;

    if (GetAccIdx(id) != -1) {
        cout << "Error: Existing account ID" << endl;
        return;
    }

    accArr[accNum].accID = id;
    accArr[accNum].balance = balance;

    strcpy(accArr[accNum].cusName, name);
    accNum++;
}

void DepositMoney(void) {
    int money;
    int id;
    cout << "[Deposit]" << endl;
    cout << "Account ID: ";
    cin >> id;
    cout << "Deposit amount: ";
    cin >> money;

    for (int i = 0; i < accNum; i++) {
        if (accArr[i].accID == id) {
            accArr[i].balance += money;
            cout << "Deposit completed" << endl << endl;
            return;
        }
    }
    cout << "This ID is not valid." << endl << endl;
}

void WithdrawMoney(void) {
    int money;
    int id;
    cout << "[Withdrawal]" << endl;
    cout << "Account ID: ";
    cin >> id;
    cout << "Withdrawal amount: ";
    cin >> money;

    for (int i = 0; i < accNum; i++) {
        if (accArr[i].accID == id) {
            if (accArr[i].balance < money) {
                cout << "Not enough balance" << endl << endl;
                return;
            }

            accArr[i].balance -= money;
            cout << "Withdrawal completed" << endl << endl;
            return;
        }
    }
    cout << "This ID is not valid." << endl << endl;
}

void ShowAllAccInfo(void) {
    for (int i = 0; i < accNum; i++) {
        cout << "Account ID: " << accArr[i].accID << endl;
        cout << "Name: " << accArr[i].cusName << endl;
        cout << "Balance: " << accArr[i].balance << endl << endl;
    }
}

int GetAccIdx(int id) {
    for (int i = 0; i < accNum; i++) {
        if (accArr[i].accID == id) {
            return i;
        }
    }
    return -1;
}

void UpdateAccountInfo(void) {
    int id;
    cout << "[Update Account Information]" << endl;
    cout << "Account ID: ";
    cin >> id;

    int index = GetAccIdx(id);

    if (index != -1) {
        char newName[NAME_LEN];
        cout << "New Customer Name: ";
        cin.ignore();
        cin.getline(newName, NAME_LEN);

        strcpy(accArr[index].cusName, newName);
        cout << "Account information updated" << endl << endl;
    } else {
        cout << "This ID is not valid." << endl << endl;
    }
}


void DeleteAccount(void){
    int id;
    cout << "[Delete Account]" << endl;
    cout << "Account ID: ";
    cin >> id;

    for (int i = 0; i < accNum; i++) {
        if (accArr[i].accID == id) {
            for(int j = i; j < accNum; j++){
                accArr[j] = accArr[j+1];
            }
            accNum--;
            cout << "Delete completed" << endl << endl;
            return;
        }
    }
    cout << "This ID is not valid." << endl << endl;
}

void TransferFunds(void) {
    int fromID, toID, amount;
    cout << "[Transfer Funds]" << endl;
    cout << "From Account ID: ";
    cin >> fromID;
    cout << "To Account ID: ";
    cin >> toID;
    cout << "Amount to Transfer: ";
    cin >> amount;

    int fromIndex = GetAccIdx(fromID);
    int toIndex = GetAccIdx(toID);

    if (fromIndex == -1 || toIndex == -1) {
        cout << "Invalid account ID(s)." << endl << endl;
        return;
    }

    if (accArr[fromIndex].balance < amount) {
        cout << "Not enough balance in the source account." << endl << endl;
        return;
    }

    accArr[fromIndex].balance -= amount;
    accArr[toIndex].balance += amount;

    cout << "Transfer completed" << endl << endl;
}
