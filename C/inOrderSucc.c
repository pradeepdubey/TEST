#include <stdio.h>
#include <stdlib.h>
 
 /* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node
{
int data;
struct node *left, *right;
};
 
 // A utility function to swap two integers
 void swap( int* a, int* b )
 {
 int t = *a;
 *a = *b;
 *b = t;
 }

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

// This function does inorder traversal to find out the two swapped nodes.
// It sets three pointers, first, middle and last.If the swapped nodes are
// adjacent to each other, then first and middle contain the resultant nodes
// Else, first and last contain the resultant nodes
void correctBSTUtil( struct node* root, struct node** first,
 struct node** middle, struct node** last,
struct node** prev )
{

if (root) {
    correctBSTUtil(root->left,first,middle,last,prev);    

    if (*prev && root->data < (*prev)->data)
    {
        if (!*first) {
            *first = *prev;
            *middle = root;
        }
        else
            *last = root;
    }

    *prev = root;


    correctBSTUtil(root->right,first,middle,last,prev);    
}

}
 
 // A function to fix a given BST where two nodes are swapped.This
 // function uses correctBSTUtil() to find out two nodes and swaps the
 // nodes to fix the BST
 void correctBST( struct node* root )
 {
 // Initialize pointers needed for correctBSTUtil()

 struct node *first, *prev, *last, *middle;

first=prev=last=middle=NULL;
 
 correctBSTUtil(root, &first,&middle,&last,&prev);

 if (first && last)
    swap(&(first->data),&(last->data));
 else if(first && middle)
    swap(&(first->data),&(middle->data));


// else nodes have not been swapped, passed tree is really BST.
}
 
 /* A utility function to print Inoder traversal */
 void printInorder(struct node* node)
 {
 if (node == NULL)
 return;
 printInorder(node->left);
 printf("%d ", node->data);
 printInorder(node->right);
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
 printInorder(root);

correctBST(root);
 
 printf("\nInorder Traversal of the fixed tree \n");
 printInorder(root);

return 0;
}
