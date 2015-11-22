#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    long long data;
    struct Node *next;
};


struct Node *head=NULL,*tail=NULL;
void insert(long long num){

    struct Node *tmp = new Node;
    struct Node *curr=NULL;
    tmp->data = num;
    tmp->next = NULL;
    if (head == NULL) {
        head = tmp;
        tail = tmp;
        return;
    }

    curr = head;
    while (curr->next != NULL)
        curr= curr->next;
    curr->next = tmp;
    tail = tmp;
}

void operate (int op, long long left,long long right,long long num)
{

int l=left,r=right;

struct Node *curr=head,*prev,*next,*lNode,*rNode;
struct Node *rNext=NULL,*lNext=NULL, *lPrev=NULL;


    if (l == 1) {
        prev = NULL;
        lNode = curr;
    } else {
        while(l>1 && curr) {
            lPrev=curr;
            curr=curr->next;
            lNode = curr;;
            l--;
        }
    }
    //cout <<"Left Node is" << lNode->data << "\n";
    r = right - left;
    while (r > 0) {
        rNode = curr->next;
        r--;
        curr=curr->next;
    }
    rNext = rNode->next;
    //cout <<"Right Node is" << rNode->data << "\n";

    if (op == 1)
    {
        if (left == 1)
            return;

        rNode->next = head;
        lPrev->next = rNext;
        head = lNode;
    } else if ( op == 2) {
        if (right == num)
            return;

        curr = rNext;
        while (curr->next !=NULL)
            curr=curr->next;
        curr->next = lNode;
        if (lPrev)
            lPrev->next = rNext;
         else
            head = rNext;
        rNode->next = NULL;
    }
}

void absolute() {
   struct Node *curr = head;

   while(curr->next!=NULL) 
    curr=curr->next;

   cout << abs(head->data - curr->data)<<"\n";
}
void display() 
{
    struct Node *tmp = head;
    while (tmp!=NULL) {
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
}
int main() {

    long long num=0,queries=0,temp=0;
    long long i,j;
    long long op,left,right;


    cin>>num>>queries;

    for (i=0;i<num;i++) {
        cin >> temp;
        insert(temp);
    }

    for(i=0;i<queries;i++) {
        cin >> op >> left >> right;
        operate(op,left,right,num);
    }
    absolute();
    display();
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

