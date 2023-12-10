#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum Accounttype
{
    savings,
    current
} Accounttype;

typedef struct Account
{
    int Accountnumber;
    char name[50];
    Accounttype type;
    float balance;
} Account;

typedef struct node
{
    Account data;
    struct node *link;
} node;

int flag;

node *addatend(node *head, Account val)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->link = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        node *p = head;
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
    return head;
}

int find(node *head, char name[], Accounttype typee)
{
    node *p = head;
    while (p != NULL)
    {
        if (strcmp(name, p->data.name) == 0 && p->data.type == typee)
        {
            return 1;
        }
        p = p->link;
    }
    return 0;
}

node *deleteAccount(node *head, char name[], Accounttype type)
{
    node *p = head;
    node *temp = NULL;
    if (head->data.type == type && strcmp(head->data.name, name) == 0)
    {
        free(head);
        return NULL;
    }
    else
    {
        while (p != NULL)
        {
            int count = 0;
            if (strcmp(name, p->data.name) == 0 && p->data.type == type)
            {
                if (temp != NULL)
                {
                    temp->link = p->link;
                    free(p);
                    flag = count;
                    return head;
                }
                else
                {
                    node *new_head = p->link;
                    free(p);
                    flag = count;
                    return new_head;
                }
            }
            temp = p;
            p = p->link;
            count++;
        }
        return head;
    }
}

node *createAccount(node *head, Accounttype type, char name[], float amount, int maxAccountNo)
{
    int accountNo = maxAccountNo + 1;

    Account newAccount;
    newAccount.Accountnumber = accountNo;
    strcpy(newAccount.name, name);
    newAccount.type = type;
    newAccount.balance = amount;

    if (find(head, newAccount.name, newAccount.type) == 0)
    {
        head = addatend(head, newAccount);
    }
    else
    {
        printf("Invalid: User already exists!");
    }

    return head;
}

void display(node *head)
{
    if (head == NULL)
    {
        printf("No Accounts to display\n");
    }
    else
    {
        printf("Account Number\tAccount Type\tName\tBalance\n");
        printf("--------------------------------------------------------------\n");

        node *temp = head;

        while (temp != NULL)
        {
            printf("%d\t\t", temp->data.Accountnumber);
            if (temp->data.type == savings)
            {
                printf("savings\t\t");
            }
            else
            {
                printf("current\t\t");
            }
            printf("%s\t%.2f\n", temp->data.name, temp->data.balance);

            temp = temp->link;
        }
    }
}

void lowBalanceAccounts(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data.balance < 100)
        {
            printf("Account Number: %d, Name: %s, Balance: %.2f\n", temp->data.Accountnumber, temp->data.name, temp->data.balance);
        }
        temp = temp->link;
    }
}

int getMaxAccountNumber(node *head)
{
    int max = -1;
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data.Accountnumber > max)
        {
            max = temp->data.Accountnumber;
        }
        temp = temp->link;
    }
    return max;
}

int main()
{
    node *head = NULL;
    
    while (1)
    {
        printf("\n1. Create Account\n");
        printf("2. Delete Account\n");
        printf("3. Display Accounts\n");
        printf("4. Display Low Balance Accounts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int accountType;
            char name[50];
            float amount;

            printf("Enter Account Type (0 for savings, 1 for current): ");
            scanf("%d", &accountType);

            printf("Enter Name (max 50 characters): ");
            scanf("%s", name);

            printf("Enter Initial Amount: ");
            scanf("%f", &amount);

            int maxAccountNo = getMaxAccountNumber(head);
            head = createAccount(head, accountType ? current : savings, name, amount, maxAccountNo);
            break;
        }
        case 2:
        {
            int accountType;
            char name[50];

            printf("Enter Account Type (0 for savings, 1 for current): ");
            scanf("%d", &accountType);

            printf("Enter Name to Delete: ");
            scanf("%s", name);

            head = deleteAccount(head, name, accountType ? current : savings);

            if (flag == -1)
            {
                printf("Invalid: User does not exist!\n");
            }
            else
            {
                printf("Account deleted successfully\n");
            }
            break;
        }
        case 3:
            display(head);
            break;
        case 4:
            lowBalanceAccounts(head);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
