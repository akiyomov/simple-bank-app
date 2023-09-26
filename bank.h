//
// Created by asadbek on 23. 9. 25.
//

#ifndef BANKAPP_BANK_H
#define BANKAPP_BANK_H
void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);
int GetAccIdx(int);
void UpdateAccountInfo(void);
void DeleteAccount(void);
void TransferFunds(void);
enum class bank { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE,UPDATE_ACCOUNT, DELETE_ACCOUNT,TRANSFER_FUNDS, EXIT };
const int NAME_LEN = 40;
const int MAX_ACC_NUM = 100;

typedef struct
{
    int accID;
    int balance;
    char cusName[NAME_LEN];
} Account;
#endif //BANKAPP_BANK_H
