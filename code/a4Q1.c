#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum AccountType
{
    SAVINGS,
    CURRENT
} AccountType;

typedef struct AccountInfo
{
    int accountNumber;
    AccountType accountType;
    char name[50];
    float balance;
    struct AccountInfo *next;
    struct AccountInfo *prev;
} AccountInfo;

AccountInfo *head = NULL;

int accountNumberCounter = 100;

int findLowestAvailableAccountNumber()
{
    AccountInfo *current = head;
    int lowestAvailable = accountNumberCounter;

    while (current != NULL)
    {
        if (current->accountNumber == lowestAvailable)
        {
            lowestAvailable++;
            current = head;// So that we can check again from the start. If we dont do this then we will miss some account numbers or rather the new account number will be just greater than the last account number
        }
        else
        {
            current = current->next;
        }
    }

    return lowestAvailable;
}

void display()
{
    AccountInfo *current = head;
    if (current == NULL)
    {
        printf("No Accounts to display\n");
        return;
    }


    printf("Account Number\tAccount Type\tName\tBalance\n");
    printf("---------------------------------------------------------------\n");

    while (current != NULL)
    {
        printf("%d\t\t%s\t\t%s\t%.2f\n", current->accountNumber,
               (current->accountType == SAVINGS) ? "savings" : "current",
               current->name, current->balance);
        current = current->next;
    }
}

void deleteAccount(AccountType accountType, char *name)
{
    AccountInfo *current = head;
    AccountInfo *prev = NULL;
    int deletedAccountNumber = -1;

    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0 && current->accountType == accountType)
        {
            deletedAccountNumber = current->accountNumber;
            if (prev != NULL)
            {
                prev->next = current->next;
            }
            else
            {
                head = current->next;
            }
            free(current);
            printf("Account deleted successfully\n");
            break;
        }
        prev = current;
        current = current->next;
    }

    /* if (deletedAccountNumber != -1) {
         if (deletedAccountNumber == accountNumberCounter - 1) {
             accountNumberCounter--;
         }
     }*/

    if (deletedAccountNumber == -1)
    {
        printf("Invalid: User does not exist\n");
    }
}

void createAccount(AccountType accountType, char *name, float amount)
{
    AccountInfo *current = head;

    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0 && current->accountType == accountType)
        {
            printf("Invalid: User already exists!\n");
            return;
        }
        current = current->next;
    }

    AccountInfo *newAccount = (AccountInfo *)malloc(sizeof(AccountInfo));
    newAccount->accountNumber = findLowestAvailableAccountNumber();
    newAccount->accountType = accountType;
    strcpy(newAccount->name, name);
    newAccount->balance = amount;

    // Insert in sorted order
    if (head == NULL || head->accountNumber > newAccount->accountNumber)
    {
        newAccount->next = head;
        if (head != NULL)
        {
            head->prev = newAccount;
        }
        newAccount->prev = NULL;
        head = newAccount;
    }
    else
    {
        AccountInfo *temp = head;
        while (temp->next != NULL && temp->next->accountNumber < newAccount->accountNumber)
        {
            temp = temp->next;
        }
        newAccount->next = temp->next;
        if (temp->next != NULL)
        {
            temp->next->prev = newAccount;
        }
        temp->next = newAccount;
        newAccount->prev = temp;
    }

    printf("Account Number: %d\n", newAccount->accountNumber);
    printf("Account Holder: %s\n", newAccount->name);
    printf("Account Type: %s\n", (newAccount->accountType == SAVINGS) ? "Savings" : "Current");
    printf("Balance: Rs %.2f\n", newAccount->balance);
}
void lowBalanceAccounts()
{
    AccountInfo *current = head;

    while (current != NULL)
    {
        if (current->balance < 100)
        {
            printf("Account Number: %d, Name: %s, Balance: Rs %.2f\n", current->accountNumber, current->name, current->balance);
        }
        current = current->next;
    }
}

void transaction(int accountNumber, float amount, int code)
{
    AccountInfo *current = head;

    while (current != NULL)
    {
        if (current->accountNumber == accountNumber)
        {
            if (code == 1)
            {
                current->balance += amount;
                printf("Updated balance is Rs %.2f\n", current->balance);
            }
            else if (code == 0)
            {
                if (current->balance - amount >= 100)
                {
                    current->balance -= amount;
                    printf("Updated balance is Rs %.2f\n", current->balance);
                }
                else
                {
                    printf("The balance is insufficient for the specified withdrawal.\n");
                }
            }
            return;
        }
        current = current->next;
    }

    printf("Invalid: User does not exist\n");
}

int main()
{
    char command[100];
    while (1)
    {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "CREATE") == 0)
        {

            int type, amount;
            char name[50];
            printf("Enter account type (0 for savings, 1 for current), name and amount: \n");
            scanf("%d %s %d", &type, name, &amount);
            createAccount(type == 0 ? SAVINGS : CURRENT, name, amount);
        }
        else if (strcmp(command, "DELETE") == 0)
        {
            int type;
            char name[50];
            printf("Enter account type (0 for savings, 1 for current) and name: \n");
            scanf("%d %s", &type, name);
            deleteAccount(type == 0 ? SAVINGS : CURRENT, name);
        }
        else if (strcmp(command, "TRANSACTION") == 0)
        {
            int accountNumber, code;
            float amount;
            printf("Enter account number, amount and code (0 for withdrawal, 1 for deposit): \n");
            scanf("%d %f %d", &accountNumber, &amount, &code);
            transaction(accountNumber, amount, code);
        }
        else if (strcmp(command, "LOWBALANCE") == 0)
        {
            lowBalanceAccounts();
        }
        else if (strcmp(command, "DISPLAY") == 0)
        {
            display();
        }
        else if (strcmp(command, "EXIT") == 0)
        {
            break;
        }
    }

    return 0;
}
