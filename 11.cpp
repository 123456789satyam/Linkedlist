#include<bits/stdc++.h>
using namespace std;
// reverse the singly linked list;

// HW -> reverse the doubly linded list;

class node{
     public:
     int data;
     node *next;
     node(int data){
        this -> data = data ;
        this -> next = NULL;
     }
};

node* revese(node *&head){
    if(head == NULL || head -> next == NULL){
        return head;
    }

    node* prev = NULL;
    node* curr = head ;
    node* forward = NULL;

    while(curr != NULL){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

void insertattail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}

void print(node *&head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    node *node1 = new node(10);
    node *tail = node1;
    node *head = node1;

    print(head);

    insertattail(tail, 3);

    print(head);

    insertattail(tail, 8);

    print(head);

    insertattail(tail, 13);

    print(head);

    insertattail(tail, -31);

    print(head);

    revese(head);

    print(tail);

    return 0;
}


