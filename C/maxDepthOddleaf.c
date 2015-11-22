#include <stdio.h>
#include <stdlib.h>
 
 /* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node
{
int data;
struct node *left, *right;
};
 
int max(int x, int y) { return (x > y)? x : y; }
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

int maxDepth(struct node *root,int level)
{ 
    if (root==NULL)
        return 0;
    if (root->left == NULL && root->right == NULL && level%2 == 1)
        return level;

    return (max(maxDepth(root->left,level+1), maxDepth(root->right,level+1)));
}

int main()
{
/* 6
/\
 102
 / \ / \
1 3 712
 10 and 2 are swapped
 */

struct node *root = newNode(1);
root->left = newNode(2);
root->right = newNode(3);
root->left->left = newNode(4);
root->right->left = newNode(5);
root->right->right = newNode(6);
root->right->left->right = newNode(7);
root->right->right->right = newNode(8);
root->right->left->right->left = newNode(9);
root->right->right->right->right = newNode(10);
root->right->right->right->right->left = newNode(11);

 
printf("The max depth of odd level leaf is %d\n", maxDepth(root, 1));

return 0;
}
