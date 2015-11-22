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

/* Druver program to test above function */
int main()
{
struct node *start = NULL;
 
 /* The constructed linked list is:
1->2->3->4->5->6->7 */

push(&start, 1);
push(&start, 1);
push(&start, 2);
push(&start, 2);
push(&start, 0);
push(&start, 0);
push(&start, 1);
push(&start, 0);
push(&start, 1);
 
 printf("\nLinked list before callingpairWiseSwap() \n");
 printList(start);
 printf("\n");
 sort123(&start);
 printf("\nLinked list after callingpairWiseSwap() \n");
 printList(start);
 printf("\n");

return 0;
}
