#include <bits/stdc++.h>
using namespace std;
// remove loop of the circular linked list;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data" << value << endl;
    }
};

void insertnode(node *&tail, int element, int d)
{
    // assuming that the element is present indthe list

    // empty list
    if (tail == NULL)
    {
        node *newnode = new node(d);
        tail = newnode;
        newnode->next = newnode;
    }

    else
    {
        // non empty list
        // assuming element present
        node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        // element found -> curr is representing element of node

        node *temp = new node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(node *tail)
{
    node *temp = tail;

    // empty list
    if (tail == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

node *floyd(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *slow = head;
    node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if (slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}

node *getstart(node *&head)
{
    if (head == NULL)
    {
        return NULL;
    }

    node *inter = floyd(head);
    if(inter == NULL){
        return NULL;
    }
    node *start = head;

    while (inter != start)
    {
        inter = inter->next;
        start = start->next;
    }
    return start;
}

void removeloop(node* &head){
    if(head==NULL){
        return ;
    }

    node* start=getstart(head);
    node* temp=start;

    while(temp->next!=start){
        temp=temp->next;
    }
    temp->next=NULL;

}

void printf(node* tail){
    node* temp=tail;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    node *tail = NULL;

    insertnode(tail, 5, 31);
    insertnode(tail, 31, 6);
    insertnode(tail, 6, 7);
    insertnode(tail, 7, 9);
    insertnode(tail, 31, 5);
    insertnode(tail, 31, 4);
    print(tail);
    removeloop(tail);
    printf(tail);

    return 0;
}