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

int height(struct node *root)
{
    if (root==NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;

    return (max(height(root->left)+1, height(root->right)+1));
}
void printSpiral(struct node *root,int level,int dir)
{
    if (root == NULL)
        return;

    if (level == 1)
        printf("%d ", root->data);

     if (dir == 0) {
        printSpiral(root->left,level-1,dir);
        printSpiral(root->right,level-1,dir);
     } else { 
        printSpiral(root->right,level-1,dir);
        printSpiral(root->left,level-1,dir);
     }

}
void printLevel(struct node *root,int level)
{
    if (root == NULL)
        return;

    if (level == 1)
        printf("%d ", root->data);

     printLevel(root->left,level-1);
     printLevel(root->right,level-1);

}
void printLevelSpiral(struct node *root) {

 int ht = height(root),i,dir=0;

 for (i = 1 ; i<=ht;i++) {
    if (dir == 0) {
        printSpiral(root,i,dir);
        dir = 1;
    } else {
        printSpiral(root,i,dir);
        dir = 0;
    }
}
}
void printLevelOrder(struct node *root) {

 int ht = height(root),i;

 for (i = 1 ; i<=ht;i++) {
    printLevel(root,i);
    }
}
int main()
{
/* 6
  / \
 10  2
 / \ / \
1 3 7  12
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

 
printf("The Height of odd level leaf is %d\n", height(root));
printLevelOrder(root);
printf("The Height of odd level leaf is %d\n", height(root));
printLevelSpiral(root);

return 0;
}
