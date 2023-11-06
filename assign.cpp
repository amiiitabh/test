#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;
node *createnode(int val)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = val;
    new->next = NULL;
    new->prev = NULL;
    return new;
}
void addnode(node **head, node **tail, int val)
{
    if (*head == NULL)
    {
        (*head) = createnode(val);
        *tail = *head;
    }
    else
    {
        node *new = createnode(val);
        (*tail)->next = new;
        new->prev = *tail;
        *tail = (*tail)->next;
    }
}
void print(node **head)
{
    node *temp = *head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if(temp->next!=NULL){
            printf(" -> ");
        }
        temp = temp->next;
    }
}
int reverse(int num) {
    int reversedNum = 0;

    while (num != 0) {
        int remainder = num % 10;
        reversedNum = reversedNum * 10 + remainder;
        num /= 10;
    }

    return reversedNum;
}
void printans(node **tail){
    node *temp = *tail;
    while (temp != NULL)
    {
        printf("%d",(temp->data));
        temp = temp->prev;
    }
}
void addition(node **head1,node **head2,node **head3,node **tail3){
    node *temp1 = *head1 ,*temp2 = *head2 ;
    int carry = 0;
    while(temp1 != NULL || temp2 != NULL){
        int sum =carry;
        if(temp1!=NULL){
            sum+=reverse(temp1->data);
            temp1=temp1->next;
        }
        if(temp2!=NULL){
            sum+=reverse(temp2->data);
            temp2=temp2->next;
        }
        carry = sum/100000;
        sum = sum%10000;
        addnode(head3,tail3,sum);
    }
}
int main()
{
    node *head1 = NULL, *tail1 = NULL;
    node *head2 = NULL, *tail2 = NULL;
    node *head3 = NULL, *tail3 = NULL;

    char a[100000], b[100000];
    printf("Enter the First Number: ");
    scanf("%[^\n]s", a);
    fflush(stdin);
    printf("Enter the Second Number: ");
    scanf("%[^\n]s", b);
    int i = strlen(a) - 1;
    while (i >= 0)
    {
        if (i - 3 >= 0)
        {
            addnode(&head1, &tail1, (a[i] - '0') * 1000 + (a[i - 1] - '0') * 100 + (a[i - 2] - '0') * 10 + (a[i - 3] - '0'));
            i -= 4;
        }
        else if (i - 2 >= 0)
        {
            addnode(&head1, &tail1, (a[i] - '0') * 100 + (a[i - 1] - '0') * 10 + (a[i - 2] - '0') * 1);
            i -= 3;
        }
        else if (i - 1 >= 0)
        {
            addnode(&head1, &tail1, (a[i] - '0') * 10 + (a[i - 1] - '0') * 1);
            i -= 2;
        }
        else if (i == 0)
        {
            addnode(&head1, &tail1, (a[i] - '0'));
            i--;
        }
    }
    int j = strlen(b) - 1;
    while (j >= 0)
    {
        if (j - 3 >= 0)
        {
            addnode(&head2, &tail2, (b[j] - '0') * 1000 + (b[j - 1] - '0') * 100 + (b[j - 2] - '0') * 10 + (b[j - 3] - '0'));
            j -= 4;
        }
        else if (j - 2 >= 0)
        {
            addnode(&head2, &tail2, (b[j] - '0') * 100 + (b[j - 1] - '0') * 10 + (b[j - 2] - '0') * 1);
            j -= 3;
        }
        else if (j - 1 >= 0)
        {
            addnode(&head2, &tail2, (b[j] - '0') * 10 + (b[j - 1] - '0') * 1);
            j -= 2;
        }
        else if (j == 0)
        {
            addnode(&head2, &tail2, (b[j] - '0'));
            j--;
        }
    }
    printf("Linked List representation Of Number 1: ");
    print(&head1);
    printf("\n");
    printf("Linked List representation Of Number 2: ");
    print(&head2);
    printf("\n");
    printf("Sum of %s and %s = ",a,b);
    addition(&head1,&head2,&head3,&tail3);
    printans(&tail3);
}

