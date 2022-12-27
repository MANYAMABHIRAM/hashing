#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head, *tail, *temp, *temp1, *temp2, *newnode;
typedef struct node node;
void initialize(int prob[])
{
    for (int i = 0; i < 5; i++)
        chain[i] = NULL;
}
void insert(int value,int n,int prob[])
{
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
void display(int prob[])
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
void search(int value,int n,int prob[])
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
    int n,val,ch;
    printf("Enter size of the table:");
    scanf("%d",&n);
    int prob[n];
    initialize(prob[])
    while(1){
        printf("\n1-Insert\n2-Display\n3-Search\n4-Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("\nEnter element:");
                    scanf("%d",&val);
                    insert(val,n,prob);
                    break;
            case 2:printf("\nElemnts in hashmap are:\n");
                    display(n,prob);
                    break;
            case 3:printf("\nElement to search:");
                    scanf("%d",&val);
                    search(val,n,prob);
                    break;
            default:exit(0);
        }
    }
}
