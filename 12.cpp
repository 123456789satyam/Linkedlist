#include <bits/stdc++.h>
using namespace std;
// reverse the singly linked list;
// recursion;

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

void revers(node *&head, node *curr, node *prev)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    node *forward = curr->next;
    revers(head, forward, curr);
    curr->next = prev;
}

node *revese(node *&head)
{
    node *curr = head;
    node *prev = NULL;
    revers(head, curr, prev);
    return head;
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

int main()
{
    node *node1 = new node(10);
    node *tail = node1;
    node *head = node1;

    insertattail(tail, 3);

    insertattail(tail, 8);

    insertattail(tail, 13);

    insertattail(tail, -31);

    print(head);

    revese(head);

    print(tail);

    return 0;
}