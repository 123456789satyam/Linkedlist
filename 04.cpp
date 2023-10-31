#include <bits/stdc++.h>
using namespace std;
// insertion in linked list;
// insert at position;
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

void insertathead(node *&head, int d)
{
    node *temp = new node(d);

    temp->next = head;
    head = temp;
}

void insertattail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}

void insertatposition(node *&tail, node *&head, int position, int d)
{
    if (position == 1)
    {
        insertathead(head, d);
        return;
    }
    node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        insertattail(tail, d);
        return;
    }

    node *nodetoinsert = new node(d);

    nodetoinsert->next = temp->next;

    temp->next = nodetoinsert;
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

    node *head = node1;
    node *tail = node1;

    print(head);

    insertathead(head, 12);

    print(head);

    insertathead(head, 15);

    print(head);

    insertathead(head, 19);

    print(head);

    insertatposition(tail, head, 5, 22);

    print(head);

    cout << "head" << head->data << endl;
    cout << "tail" << tail->data << endl;

    return 0;
}