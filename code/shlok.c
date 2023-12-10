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
    int accountnumber;
    AccountType type;
    char name[50];
    float balance;
    struct AccountInfo *next;
} AccountInfo;

AccountInfo *startnode = NULL;
int boss = 100;

void createAccount(AccountType at, char *name, float amount);
void deleteAccount(AccountType at, char *name);
void lowBalanceAccounts();
void transaction(int accountno, float amount, int code);
void display();
void sort();

int main()
{
    char command[20];
    while (1)
    {
        scanf("%s", command);
        if (strcmp(command, "CREATE") == 0)
        {
            int type_int;
            char name[50];
            float amount;
            
            scanf("%d %s %f", &type_int, name, &amount);
            createAccount((AccountType)type_int, name, amount);
        }
        else if (strcmp(command, "DELETE") == 0)
        {
            int type_int;
            char name[50];
            scanf("%d %s", &type_int, name);
            deleteAccount((AccountType)type_int, name);
        }
        else if (strcmp(command, "TRANSACTION") == 0)
        {
            int accountno, code;
            float amount;
            scanf("%d %f %d", &accountno, &amount, &code);
            transaction(accountno, amount, code);
        }
        else if (strcmp(command, "LOWBALANCE") == 0)
        {
            lowBalanceAccounts();
        }
        else if (strcmp(command, "DISPLAY") == 0)
        {
            display();
        }
        else
        {
            printf("Invalid command\n");
        }
    }
    return 0;
}

void createAccount(AccountType at, char *name, float amount)
{
    AccountInfo *newnode = (AccountInfo *)malloc(sizeof(AccountInfo));
    newnode->type = at;
    strcpy(newnode->name, name);
    newnode->balance = amount;

    if (startnode == NULL)
    {
        newnode->accountnumber = boss;
        boss++;
        newnode->next = NULL;
        startnode = newnode;
    }
    else
    {
        AccountInfo *temp = startnode;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newnode->accountnumber = boss;
        boss++;
        newnode->next = NULL;
        temp->next = newnode;
    }

    printf("Account Number: %d\n", newnode->accountnumber);
    printf("Account Holder: %s\n", newnode->name);
    printf("Account Type: %s\n", (newnode->type == SAVINGS) ? "Savings" : "Current");
    printf("Balance: Rs %.2f\n", newnode->balance);
}

void deleteAccount(AccountType at, char *name)
{
    AccountInfo *temp = startnode;
    AccountInfo *prev = NULL;

    while (temp != NULL)
    {
        if (temp->type == at && strcmp(temp->name, name) == 0)
        {
            if (prev == NULL)
            {
                startnode = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            printf("Account deleted successfully\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Invalid: User does not exist\n");
}

void lowBalanceAccounts()
{
    AccountInfo *temp = startnode;

    while (temp != NULL)
    {
        if (temp->balance < 100)
        {
            printf("Account Number: %d, Name: %s, Balance: %.2f\n", temp->accountnumber, temp->name, temp->balance);
        }
        temp = temp->next;
    }
}

void transaction(int acctnumber, float amount, int code)
{
    AccountInfo *temp = startnode;

    while (temp != NULL)
    {
        if (temp->accountnumber == acctnumber)
        {
            if (code == 1)
            {
                temp->balance += amount;
                printf("Updated balance is: Rs %.2f\n", temp->balance);
                return;
            }
            else if (code == 0 && temp->balance - amount >= 100)
            {
                temp->balance -= amount;
                printf("Updated balance is: Rs %.2f\n", temp->balance);
                return;
            }
            else if (code == 0 && temp->balance - amount < 100)
            {
                printf("The balance is insufficient for the specified withdrawal.\n");
                return;
            }
        }
        temp = temp->next;
    }

    printf("Invalid: User does not exist\n");
}

void display()
{
    if (startnode == NULL)
    {
        printf("No Accounts to display\n");
        return;
    }

    sort();
    AccountInfo *temp = startnode;

    printf("Account Number\tAccount Type\tName\tBalance\n");
    printf("--------------------------------------------------------------\n");

    while (temp != NULL)
    {
        printf("%d\t%s\t%s\t%.2f\n", temp->accountnumber, (temp->type == SAVINGS) ? "savings" : "current", temp->name, temp->balance);
        temp = temp->next;
    }
}

void sort()
{
    AccountInfo *ptr;
    AccountInfo *cpt;
    int temp;
    char tname[50];
    float taccbalance;
    AccountType tacctype;

    for (ptr = startnode; ptr != NULL; ptr = ptr->next)
    {
        for (cpt = ptr->next; cpt != NULL; cpt = cpt->next)
        {
            if (ptr->accountnumber > cpt->accountnumber)
            {
                temp = ptr->accountnumber;
                strcpy(tname, ptr->name);
                tacctype = ptr->type;
                taccbalance = ptr->balance;

                ptr->accountnumber = cpt->accountnumber;
                ptr->balance = cpt->balance;
                ptr->type = cpt->type;
                strcpy(ptr->name, cpt->name);

                cpt->accountnumber = temp;
                cpt->type = tacctype;
                cpt->balance = taccbalance;
                strcpy(cpt->name, tname);
            }
        }
    }
}
