#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head, *tail, *temp, *temp1, *temp2, *newnode;
typedef struct node node;
node* chain[];
void initialize(int n)
{
    for (int i = 0; i < n; i++)
        chain[i] = NULL;
}
void insert(int value,int n)
{
    temp=(node*)malloc(sizeof(node));
    newnode=(node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;
    int key = value % n;
    temp = chain[key];
    if (chain[key] == NULL)
        chain[key] = newnode;
    else
    {
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void display(int n)
{
    temp = (node *)malloc(sizeof(node));
    for (int i = 0; i < n; i++)
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
void search(int value,int n)
{
    int key = value % n;

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
    initialize(n);
    while(1){
        printf("\n1-Insert\n2-Display\n3-Search\n4-Deletion\n5-Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("\nEnter element:");
                    scanf("%d",&val);
                    insert(val,n);
                    break;
            case 2:printf("\nElemnts in hashmap are:\n");
                    display(n);
                    break;
            case 3:printf("\nElement to search:");
                    scanf("%d",&val);
                    search(val,n);
                    break;
            default:exit(0);
        }
    }
}
