#include <bits/stdc++.h>
using namespace std;
// reverse the singly linked list;
// recursion2;

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

node *reverse1(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *chotahead = reverse1(head->next);

    head->next->next = head;
    head->next = NULL;

    return chotahead;
}

node *revese(node *&head)
{
    return reverse1(head);
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

    insertattail(tail, 31);

    print(head);

    revese(head);

    print(tail);

    return 0;
}