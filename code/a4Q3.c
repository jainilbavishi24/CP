    #include <stdio.h>
    #include <stdlib.h>

    typedef struct Node
    {
        int color;
        struct Node *next;
    } Node;

    typedef Node *LinkedList;

    void insertNode(LinkedList *head, int color)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->color = color;
        newNode->next = NULL;

        if (*head == NULL)
        {
            *head = newNode;
        }
        else
        {
            Node *temp = *head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    LinkedList removeDuplicates(LinkedList head)
    {
        LinkedList temp = head;
        while (temp != NULL && temp->next != NULL)
        {
            if (temp->color == temp->next->color)
            {
                LinkedList temporary = temp->next;
                temp->next = temp->next->next;
                free(temporary);
            }
            else
            {
                temp = temp->next;
            }
        }
        return head;
    }

    void printList(LinkedList head)
    {
        while (head != NULL)
        {
            printf("%d", head->color);
            if (head->next != NULL)
            {
                printf(" -> ");
            }
            head = head->next;
        }
        printf("\n");
    }

    int main()
    {
        int n;
        printf("Enter the number of colors in the list: ");
        scanf("%d", &n);

        Node *head = NULL;

        printf("Enter the colors: ");
        for (int i = 0; i < n; i++)
        {
            int color;
            scanf("%d", &color);

            insertNode(&head, color);
        }

        head = removeDuplicates(head);

        printf("Modified Linked List: ");
        printList(head);

        return 0;
    }
