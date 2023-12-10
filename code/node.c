#include "stdio.h"
#include "stdlib.h"
#define MAX_NAME_LEN 100

typedef struct Person
{
    char name[MAX_NAME_LEN];
    int age;
} Person;

typedef struct Node
{
    Person data;
    struct Node *next;
    //struct Node *prev
} Node;
//front linkedlist
//back linkedlist
//circular linkedlist

typedef Node *LinkedList;

void print_list(LinkedList l)
{
    printf("-----------------------------------\n");
    while (l != NULL)
    {
        printf("%s\t\t%d\n", l->data.name, l->data.age);
        l = (*l).next;
    }
    printf("-----------------------------------\n");
}

int size(LinkedList l)
{
    int s = 0;
    while (l != NULL)
    {
        l = l->next;
        s++;
    }
    return s;
    // Simpler recursive solution
    //     return l==NULL? 0: size(l->next) + 1;
}
int size_recursive(LinkedList l)
{
    return l == NULL ? 0 : size_recursive(l->next) + 1;
}

Person* element_at(int pos, LinkedList l)
{
    //why Person[] will not work
    int s = 0;
    while (l != NULL)
    {
        if (s == pos)
            return &(l->data); // Why &l->data and not l->data
        l = l->next;
        s++;
    }
    return NULL;
}

Person* element_at_recursive(int pos, LinkedList l)
{
    // TODO
    if (l == NULL)
        return NULL;
    if (pos == 0)
    {
        return &(l->data) ;
    }
    else
    {
        return element_at_recursive(pos - 1, l->next);
    }

    // return pos == 0 ? &(l->data): element_at(pos-1, l->next);
}
LinkedList element_at_recursivelist(int pos, LinkedList l)
{
    // TODO
    if (l == NULL)
        return NULL;
    if (pos == 0)
    {
        return (l) ;
    }
    else
    {
        return element_at_recursivelist(pos - 1, l->next);
    }

    // return pos == 0 ? &(l->data): element_at(pos-1, l->next);
}

LinkedList append(Person p, LinkedList l)
{

    // Node D = {{"Raj", 18}, NULL};
    // Node D;
    //Node *D;
    Node *D = (Node *)malloc(sizeof(Node));//why we declare Node* D in this manner cant we simply do Node *D
     D->data = p;
    D->next = NULL;
    if (l == NULL)
        return D;
    while (l->next != NULL)
    {
        l = l->next;
    }
    l->next =D;
    return l;
}
 Node *reverse_inplace(LinkedList l)
{
    // TODO
     Node *ptr1=NULL;
     Node *ptr2=NULL;
    while(l!=NULL)
    {
        ptr2=l->next;
        l->next=ptr1;  
        ptr1=l;
        l=ptr2;


    }  
    return ptr1;//this is backward linkedlist
}
void reverse_v2(LinkedList *l)
{
    *l=reverse_inplace(*l);
}
Node *reverse_inplace_recursive(LinkedList l)
{
    // TODO
    if(l==NULL)
        return l;
    else
    {
        LinkedList temp=reverse_inplace_recursive(l->next);
        l->next=NULL;

    }
}
void free_linked_list(LinkedList l)
{
    // TODO
    int s=0;
    
        Node *temp = (Node *)malloc(sizeof(Node));
        l = l->next;
        free(temp);
       s++;
     
    printf("Loop counter is %d\n", s);
     printf("Size of the list is %d\n", size(l));   
}
void free_linked_list_recursive(LinkedList l)
{
    // TODO
    if (l == NULL)
        return;
    free_linked_list_recursive(l->next);
    free(l);
} 

    // If l is a->b->c->d
    //         a<-b<-c<-d
    // after executing reverse_inplace(l)
    // l should become d->c->b->a
    // the function also should not use another linkedlist or array

//50 students class
/*
    1, 15,18,
*/
LinkedList appendnew(Person p, LinkedList l){
    //Node D = {{"Raj", 18, Single}, NULL}; //This wont work as the input values are lost when we later call the function
    Node* D=(Node *)malloc(sizeof(Node)); //pointer to the node that is needed to be added
    D->data = p; //copying the data from the person  
    D->next = NULL;
    if(l==NULL){
        return D;
    }
    while(l->next!=NULL){
        l=l->next;
    }
    l->next = D; 
    return l;
}
LinkedList swap(LinkedList l,int a,int b)//a and b are positions which are to be swapped
{
   //going to position linked by poistion a
    //going to position linked by poistion b
    //swapping the data
    //returning the linkedlist
    //TODO
    //return NULL;
    int s=0;
    Node *ptr1=l;
    Node *ptr2=l;
    while(s!=a)
    {
        ptr1=ptr1->next;
        s++;
    }
    s=0;
    while(s!=b)
    {
        ptr2=ptr2->next;
        s++;
    }
    Person temp=ptr1->data;
    ptr1->data=ptr2->data;
    ptr2->data=temp;
    return l;
}

LinkedList insert(Person p, int pos, LinkedList l)
{
    Node *D = (Node *)malloc(sizeof(Node));
    D->data = p;
    if (pos == 0)
    {
        (*D).next = l;
        return D;
    }
    int current_pos = 0;
    LinkedList current_node = l;
    while (current_node != NULL)
    {

        if (current_pos >= pos - 1)
        {
            // return l;
            break;
        }
        else
        {
            l=l->next;
            current_node = current_node->next;
            current_pos++;
        }
    }
    if (current_node != NULL)
    {
        D->next = current_node->next;
        l->next = D; // How is it ensured to shift the right elements by 1 position
    }

    return l;
    // TODO
    // return NULL;
}

int main()
{
    Node third = {
        {"Alice", 22},
        NULL};
    Node second = {
        {"Bob", 26},
        &third};
    Node first = {
        {"Charlie", 20},
        &second};
    Person D = {"Raj", 18};
    Person E = {"Jainil", 18};
    LinkedList l = &first;
   // l->next;


    printf("Size of the list is %d\n", size(l));
    printf("Size of the list is %d\n", size_recursive(l));
    print_list(l);
    printf("Element at 1st position: %s\n", element_at(1, l)->name);
    printf("Element at 2nd position: %s\n", element_at_recursive(2, l)->name);
    printf("Element at 2nd position: %s\n", element_at_recursivelist(2, l)->data.name);
    append(D, l);
    printf("List after appending\n");
    print_list(l);
    insert(E, 3, l);
    printf("List after inserting\n");
    print_list(l);
    LinkedList l2=l;
    printf("List after reversing\n");
    print_list(reverse_inplace(l));
    free_linked_list(l);
    return 0;
    /*
    hemal.next=jainil.next
    jainil.next.previous=hemalzl

    */
}