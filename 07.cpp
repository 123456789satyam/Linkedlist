#include<bits/stdc++.h>
using namespace std;
//doubly linked list;
//NULL 

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

void insertathead(node* &tail,node* &head,int d){

    if(head == NULL){
        node* temp = new node(d);
        head = temp;
        tail = temp;
    }

    else{
    node* temp = new node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
    }
}

void insertattail(node* &tail,node* &head,int d){

    if(tail == NULL){
        node* temp = new node(d);
        tail = temp;
        head = temp;
    }

    else{
    node* temp = new node(d);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
    }
}

void insertatposition(node* &tail,node* &head,int position,int d){

    if(position == 1){
        insertathead(tail,head,d);
        return ;
    }

    node* temp = head;
    int cnt = 1 ;

    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }

    if(temp -> next ==NULL){
        insertattail(tail,head,d);
        return ;
    }

    node* nodetoinsert = new node(d);

    nodetoinsert -> next = temp -> next;
    temp -> next -> prev = nodetoinsert;
    temp -> next = nodetoinsert;
    nodetoinsert -> prev = temp;

}

int main(){
    node* head = NULL;
    node* tail = NULL;

    print(head);
    cout<<getlength(head)<<endl;

    insertathead(tail,head,34);
    print(head);
    insertathead(tail,head,44);
    print(head);
    insertathead(tail,head,54);
    print(head);

    insertattail(tail,head,88);
    print(head);

    insertatposition(tail,head,4,55);
    print(head);
    insertatposition(tail,head,1,5);
    print(head);
    insertatposition(tail,head,7,99);
    print(head);

    return 0;
}