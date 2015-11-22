#include <stdio.h>
#include <stdlib.h>
 
 /* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node
{
int data;
struct node *left, *right;
};
 
/* Helper function that allocates a new node with the
 given data and NULL left and right pointers. */
 struct node* newNode(int data)
 {
 struct node* node = (struct node *)malloc(sizeof(struct node));
 node->data = data;
 node->left = NULL;
 node->right = NULL;
 return(node);
 }

/* A utility function to print Preoder traversal */
void printMorrisPreorder(struct node* root)
{

    while (root){
        if (root->left == NULL) {
            printf("%d ", root->data);
            root=root->right;
        } else {
        struct node *curr= root->left;
        while(curr->right !=NULL && curr->right != root) 
            curr= curr->right;
        if (curr->right == root) {
            curr->right=NULL;
            printf("%d ",root->data);
            root = root->right;
        } else {
            curr->right = root; 
            root = root->left;
        }   
      }
   }
}
/* A utility function to print Inoder traversal */
void printMorrisInorder(struct node* root)
{

    struct node *curr,*pre;
    if (root== NULL)
        return;

    curr = root;
    while (curr){
        if (curr->left == NULL) {
            printf("%d ", curr->data);
            curr=curr->right;
        } else {
            pre = curr->left;

        while(pre->right !=NULL && pre->right != curr) 
            pre = pre->right;
        if (pre->right == NULL) {
            pre->right = curr; 
            curr= curr->left;
        } else {
            pre->right=NULL;
            printf("%d ",curr->data);
            curr=curr->right;
        }   
      }
   }
}

/* Driver program to test above functions*/
int main()
{
/* 6
/\
 102
 / \ / \
1 3 712
 10 and 2 are swapped
 */

struct node *root = newNode(6);
root->left= newNode(10);
root->right = newNode(2);
root->left->left= newNode(1);
root->left->right = newNode(3);
root->right->right = newNode(12);
root->right->left = newNode(7);
 
 printf("Inorder Traversal of the original tree \n");
 printMorrisInorder(root);

 
 printf("\nPost Traversal of the fixed tree \n");
 printMorrisPreorder(root);

return 0;
}
