#include<bits/stdc++.h>
using namespace std;
//doubly linked list;

class node{
    public:
    int data;
    node* prev;
    node* next;

    node(int d){
        this->data=d;
        this->prev =NULL;
        this->next= NULL;
    }
};

void print(node* head){
    node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp= temp -> next;
    }
    cout<<endl;
}

int getlength(node* head){
    int len = 0;
    node* temp = head ;

    while(temp!=NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

void insertathead(node* &head,int d){
    node* temp = new node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

void insertattail(node* &tail,int d){
    node* temp = new node(d);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
}

void insertatposition(node* &tail,node* &head,int position,int d){

    if(position == 1){
        insertathead(head,d);
        return ;
    }

    node* temp = head;
    int cnt = 1 ;

    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }

    if(temp -> next ==NULL){
        insertattail(tail,d);
        return ;
    }

    node* nodetoinsert = new node(d);

    nodetoinsert -> next = temp -> next;
    temp -> next -> prev = nodetoinsert;
    temp -> next = nodetoinsert;
    nodetoinsert -> prev = temp;

}

int main(){
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;

    print(head);
    cout<<getlength(head)<<endl;

    insertathead(head,34);
    print(head);
    insertathead(head,44);
    print(head);
    insertathead(head,54);
    print(head);

    insertattail(tail,88);
    print(head);

    insertatposition(tail,head,4,55);
    print(head);
    insertatposition(tail,head,1,5);
    print(head);
    insertatposition(tail,head,8,99);
    print(head);

    return 0;
}