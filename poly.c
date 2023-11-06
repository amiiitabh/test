#include<stdio.h>
#include<stdlib.h>

struct node{
    int coeff;
    int expo;
    struct node *link;
};
struct node1{
    float coeff;
    int expo;
    struct node1 *link;
};
struct node*insert(struct node* head,int co,int ex){
    struct node*temp;
    struct node*newP=malloc(sizeof(struct node));
    newP->coeff=co;
    newP->expo=ex;
    newP->link=NULL;

    if(head== NULL || ex > head->expo){
        newP->link=head;
        head=newP;
    }
    else{
        temp=head;
        while(temp->link != NULL && temp->link-> expo >= ex)
        temp=temp->link;
        newP->link =temp->link;
        temp->link =newP;
    }
    return head;
}
//create fxn
struct node * create(struct node* head)
{
    int n,i;
    int coeff;
    int expo;

    printf("enter the number of terms");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        printf("Enter the coefficient for term %d :",i);
        scanf("%d",&coeff);

        printf("Enter the exponent for the term %d :",i);
        scanf("%d",&expo);
        head=insert(head,coeff,expo);
    }
    return head;
}    
//print fxn

void print(struct node* head){
    if(head==NULL){
        printf("Polynomial not exits");
    }
    else{
        struct node* temp = head;
        while(temp!=NULL){
            printf("(%dx^%d)",temp->coeff,temp->expo);
            temp=temp->link;
            if(temp!=NULL){
                printf("+");
            }
            else{
                printf("\n");
            }
        
        }
    }
}
//add fxn
void add(struct node* head1,struct node*head2)
{
    struct node* ptr1= head1;
    struct node* ptr2=head2;
    struct node* head3=NULL;
    while (ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->expo == ptr2->expo){
            head3=insert(head3,ptr1->coeff + ptr2->coeff,ptr1->expo);
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
        else if(ptr1->expo > ptr2->expo){
            head3=insert(head3,ptr1->coeff ,ptr1->expo );
            ptr1 = ptr1->link;
        }
        else if (ptr2->expo > ptr1->expo)
        {
            head3=insert(head3, ptr2->coeff,ptr2->expo);
            ptr2 = ptr2->link;
        }
    }
    while(ptr1!=NULL){
        head3=insert(head3,ptr1->coeff  ,ptr1->expo ) ;
        ptr1=ptr1->link;
    }
    while (ptr2!=NULL){
        head3=insert(head3,ptr2->coeff   ,ptr2->expo ) ;
        ptr2=ptr2->link;
    }
    printf("Added Polynomial is:");
    print(head3);
}
//subtraction function
void subtraction(struct node* head1,struct node* head2)
{
    struct node* ptr1=head1;
    struct node* ptr2=head2;
    struct node* head3 =NULL;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->expo==ptr2->expo){
            head3 = insert(head3, ptr1->coeff - (ptr2->coeff),ptr1->expo);
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
        else if(ptr1->expo > ptr2->expo){
            head3 = insert(head3, ptr1->coeff,ptr1->expo);
            ptr1=ptr1->link;
        }
        else if(ptr2->expo >ptr1->expo){
            head3=insert(head3,ptr2->coeff,ptr2->expo);
        }
    }

    while(ptr1!=NULL){
    head3=insert(head3,ptr1->coeff  ,ptr1->expo ) ;
    ptr1=ptr1->link;
}
 while(ptr2!=NULL){
        head3=insert(head3,ptr2->coeff  ,ptr2->expo ) ;
        ptr2=ptr2->link;
 }
 printf("subtracted polynomial:");
 print(head3);
} 
    

void multiplication(struct node* head1, struct node*head2){
    struct node* ptr1=head1;
    struct node* ptr2=head2;
    struct node* head3=NULL;

    if(head1==NULL ||head2==NULL ){
        printf("No polynomial");
    }
    else{
        while(ptr1!=NULL){
            while(ptr2!=NULL){
                head3= insert(head3,ptr1->coeff * ptr2->coeff,ptr1->expo + ptr2->expo);{
                    ptr2=ptr2->link;
                }
                }
                ptr1= ptr1->link;
                ptr2=head2;
                }
                printf("\n befor simplification Multiplied Polynomial:\t ");
                print(head3)   ;
                
            
       // new resultant linkedlist... 
        struct node* ptr3= head3;
        struct node* temp=NULL;
        
        while(ptr3->link!=NULL){
            if(ptr3->expo == ptr3->link->expo){
                ptr3->coeff= ptr3->coeff + ptr3->link->coeff;
                temp = ptr3->link;
                ptr3->link=ptr3->link->link;
                free(temp);

            }
            else{
                ptr3=ptr3->link;
            }
            
        }
        printf("\nMultiplied polynomial\n");
        print(head3);
}
}  


  /* float Peval(struct node1* head3){
    if(head==NULL){
        printf("Polynomial not exits");
    }
    else{
        struct node* temp = head;
        while(temp!=NULL){
            printf("(%0.2fx^%d)",(temp->coeff),temp->expo);
            temp=temp->link;
            if(temp!=NULL){
                printf("+");
            }
            else{
                printf("\n");
            }
        
        }
    }
}
void Perase(struct node* head3){
    int pos,i=1;
    struct node* temp,*temp1;
    if (head3==NULL){
        printf("Polynomial does not exist");
    }
    else{
        printf("Enter the index");
        scanf("%d",&pos);

        while(i<= pos-1){
            temp=temp->link;
            i++;
        }
        temp1 = temp->link;
        temp->link = temp1-> link;
        free(temp1);
    }
    print(head3);
    

}*/


int main(){
    struct node* head1=NULL;
    struct node* head2=NULL;
   // struct node* head3=NULL;
   
    printf("Enter the first polynomial\n ");
    head1=create(head1);
    printf("Enter the second polynomial\n");
    head2= create(head2);

   add(head1,head2);
   subtraction(head1,head2);
   multiplication(head1,head2);
    //Perase(head3);
    return 0;
}