#include <bits/stdc++.h>
using namespace std;
// insertion in linked list;
// insert at tail;
class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

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

int main()
{
    node *node1 = new node(10);

    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    node *tail = node1;
    node *head = node1;
    print(head);

    insertattail(tail, 12);

    print(head);

    insertattail(tail, 15);

    print(head);

    insertattail(tail, 19);

    print(head);

    return 0;
}