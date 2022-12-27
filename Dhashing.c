#include <stdio.h>
#include <stdlib.h>
void inintialize(int n,int prob[])
{
    for (int i = 0; i < n; i++)
    {
        prob[i] = NULL;
    }
}
void insert(int value,int n,int p,int prob[])
{
    int i;
    int key = value % n;
    int key1=p-(value%p);
    for (i = 0; i < n; i++)
    {
        int key2 = (key+i*key1)%n;
        if (prob[key2] == NULL)
        {
            prob[key2] = value;
            break;
        }
        else
            continue;
    }
}
void display(int n,int prob[])
{
    for (int i = 0; i < n; i++)
    {
        if (prob[i] != NULL)
            printf(" |%d| ", prob[i]);
        else
            printf(" |-| ");
    }
}
void search(int value,int n,int prob[],int p)
{
    int flag = 0, key = value % n,key1=p-(value%p),key2;
    for (int i = 0; i < n; i++)
    {
        key2 = (key + (i*key2))%n;
        if (prob[key2] == value)
            flag = 1;
    }
    if (flag)
        printf("\nElement found");
    else
        printf("\nElement not found");
}
int prime(int n){
    int flag=1,i,j;
    for(i=n-1;i>0;i--)
    {
        flag=1;
        for(j=2;j<i;j++)
        {
            if(i%j==0)
            {
                flag=0;
                break;
            }
        }
        if(flag)
            break;
    }
    return i;
}
int main()
{
    int n;
    printf("Enter table size:");
    scanf("%d",&n);
    int p=prime(n);
    int ch,val;
    int prob[n];
    inintialize(n,prob);
    while(1){
        printf("\n1-Insert\n2-Display\n3-Search\n4-Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("\nEnter element:");
                    scanf("%d",&val);
                    insert(val,n,p,prob);
                    break;
            case 2:printf("\nElemnts in hashmap are:\n");
                    display(n,prob);
                    break;
            case 3:printf("\nElement to search:");
                    scanf("%d",&val);
                    search(val,n,prob,p);
                    break;
            default:exit(0);
        }
    }
}
