#include<bits/stdc++.h>
using namespace std;
// middle of a linked list;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data= data;
        this->next= NULL;
    }
};

int getl(node* head){
    node* temp=head;
    int c=0;
    while(temp!=NULL){
        c++;
        temp=temp->next;
    }
    return c;
}

node* middle(node* &head){
    node* temp=head;
    int l=getl(head);
    int ans=(l/2);
    int c=0;
    while(c<ans){
        temp=temp->next;
        c++;
    }
    return temp;
}

void insert(node * &head,int data){
    node *temp=new node(data);
    temp->next=head;    
    head=temp;
}

void print(node* &head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<< " ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node* ram=new node(4);
    node* head=ram;
    insert(head,50);
    insert(head,51);
    insert(head,53);
    insert(head,54);
    insert(head,55);
    insert(head,56);
    insert(head,57);
    insert(head,58);
    insert(head,59);
    cout<<getl(head)<<endl;
    print(head);

    cout<<middle(head)->data;

    return 0;
}