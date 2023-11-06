#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node {
    int num;
    struct node *next;
};

void insert(struct node **head,int num)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->num = num;
    new->next = NULL;
    if (*head == NULL)
    {
        new->next=*head;
        *head = new;
        return;
    }
    else{
        struct node *tmp=*head;
        while(tmp->next!=NULL)
        {
            tmp=tmp->next;
        }
        new->next=tmp->next;
        tmp->next=new;

    }
}

void print(struct node *head)
{
    struct node *temp = head;
    printf("\n");
    while (temp != NULL)
    {
        printf("%d ",temp->num);
        temp = temp -> next ;
    }
    printf("\n\n");
}

int digit(struct node **head)
{
    struct node *tmp=*head;
    int max=0,c=0;
    while(tmp!=NULL)
    {
        if(tmp->num>max)
        {
            max=tmp->num;
        }
        tmp=tmp->next;
    }
    while(max>0)
    {
        max=max/10;
        c++;
    }
    return c;
}

void Radix_Sort(struct node** head, int digit) {
    struct node* buckets[10] = { NULL };
    while (*head != NULL) {
        int index = ((*head)->num / digit) % 10;
        insert(&buckets[index],(*head)->num);
        *head=(*head)->next;
    }
    
    for (int i = 0; i < 10; i++) {
        while (buckets[i] != NULL) {
            struct node* next = buckets[i]->next;
            insert(head, buckets[i]->num);
            free(buckets[i]);
            buckets[i] = next;
        }
    }
}

void linkedListRadix_Sort(struct node** head) {
    int max = 0;
    struct node *temp =*head;
    while(temp!=NULL) {
        if(temp->num>max) {
            max=temp->num;
        }
        temp=temp->next;
    }
    for(int digit=1;max/digit>0;digit*=10) {
        Radix_Sort(head,digit);
    }
}

int main(){
    struct node *head=NULL;
    int num,terms;
    printf("Enter No of Terms of ");
    scanf("%d",&terms);
    for(int i=0;i<terms;i++)
    {
        printf("Enter %d the term ",i+1);
        scanf("%d",&num);
        insert(&head,num);
    }
    linkedListRadix_Sort(&head);
    print(head);
}
