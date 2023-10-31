#include <bits/stdc++.h>
using namespace std;
// insertion in linked list;
// deletion at position;
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

    ~node()
    {
        int value = this->data;

        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
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

void deletenode(int position, node *&head)
{
    if (position == 1)
    {
        node *temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
    }

    else
    {
        node *curr = head;
        node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
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

    deletenode(5, head);
    print(head);

    cout << "head" << head->data << endl;
    cout << "tail" << tail->data << endl;

    return 0;
}