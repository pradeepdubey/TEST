#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
 
 /* A linked list node */
 struct node
 {
 int data;
 struct node *next;
 };

void sort123 ( struct node **head_ref)
{
    struct node *ptr = *head_ref;

    int count[3] = {0,0,0},i=0;

    while(ptr!=NULL)
    {
        count[ptr->data]++;
        ptr = ptr->next;
    }
    i=0;
    ptr = *head_ref;
    while(ptr!=NULL)
    {

    if (count[i] == 0)
        i++;
    ptr->data = i;
    count[i]--;
    ptr=ptr->next;
    }
}
 void push(struct node** head_ref, int new_data)
 {
 /* allocate node */
 struct node* new_node =
 (struct node*) malloc(sizeof(struct node));

/* put in the data*/
new_node->data = new_data;
 
 /* link the old list off the new node */
 new_node->next = (*head_ref);

/* move the head to point to the new node */
(*head_ref)= new_node;
}
 
 /* Function to print nodes in a given linked list */
 void printList(struct node *node)
 {
 while(node != NULL)
 {
 printf("%d ", node->data);
 node = node->next;
 }
 }

struct node *mergeList1(struct node *l1, struct node *l2)
{
    if (l1 == NULL)
        return NULL;
    struct node *res = NULL,*prev=NULL,*tmp;
    while (l1 && l2) {
        if (l1->data != l2->data) {
           tmp = (struct node*) malloc(sizeof(struct node));
           tmp->data = l1->data;
           prev->next = NULL;
           if (prev == NULL) {
                res=prev;
            } else {
                prev->next = tmp;
            }
            if (l1->data < l2->data)
                l1=l1->next;
            else
                l2=l2->next;

        }
        l1=l1->next;
        l2=l2->next;
    }
    if (l1 == NULL)
        return res;
    if (l2 == NULL) {
           while (l2) {
            tmp = (struct node*) malloc(sizeof(struct node));
            tmp->data = l1->data;
            prev->next = NULL;
            l2=l2->next;
        }
    }
}
/* Druver program to test above function */
int main()
{
struct node *start1 = NULL,*start2 = NULL;
 
 /* The constructed linked list is:
1->2->3->4->5->6->7 */

push(&start1, 5);
push(&start1, 4);
push(&start1, 3);
push(&start1, 2);
push(&start1, 1);
push(&start2, 100);
push(&start2, 10);
push(&start2, 4);
push(&start2, 2);
 
 printf("\nLinked list before callingpairWiseSwap() \n");
 printList(start1);
 printf("\n");
// sort123(&start);
 printf("\nLinked list after callingpairWiseSwap() \n");
 printList(start2);
 printf("\n");
struct node *merge = mergeList1(start1,start2);
 printf("\nLinked list after merge is () \n");
 printList(merge);
 printf("\n");
return 0;
}
