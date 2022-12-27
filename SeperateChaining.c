#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head, *tail, *temp, *temp1, *temp2, *newnode;
typedef struct node node;
node *chain[5];
void initialize()
{
    for (int i = 0; i < 5; i++)
        chain[i] = NULL;
}
void insert(int value)
{
    temp = (node *)malloc(sizeof(node));
    newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;
    int key = value % 5;
    if (chain[key] == NULL)
        chain[key] = newnode;
    else
    {
        temp = chain[key];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void print()
{
    temp = (node *)malloc(sizeof(node));
    for (int i = 0; i < 5; i++)
    {
        temp = chain[i];
        printf("chain[%d]-->", i);
        while (temp)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
void search(int value)
{
    int key = value % 5;

    if (chain[key] == NULL)
    {
        printf("\nElement does not found");
        return;
    }
    else
    {
        temp = chain[key];
        while (temp)
        {
            if (temp->data == value)
            {
                printf("\nElement is found");
                return;
            }
            temp = temp->next;
        }
    }
    printf("\nElement does not found");
}
int main()
{
    initialize();
    insert(5);
    insert(1);
    insert(2);
    insert(3);
    insert(10);
    insert(11);
    print();
    search(5);
    search(15);
    search(4);
}
