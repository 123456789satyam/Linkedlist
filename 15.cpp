#include <bits/stdc++.h>
using namespace std;
// Reverse LL in "K group"  - 2 ;
// 8 7 6 5 3 7 8 9 ;
// 7 8 5 6 7 3 9 8 ;

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

void insert(node *&head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

node *key(node *&head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *next = NULL;
    node *curr = head;
    node *prev = NULL;
    int c = 0;
    while (curr != NULL && c < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        c++;
    }
    if (next != NULL)
    {
        head->next = key(next, k);
    }
    return prev;
}

int main()
{
    node *ram = new node(5);
    node *head = ram;
    insert(head, 32);
    insert(head, 33);
    insert(head, 34);
    insert(head, 35);
    insert(head, 36);
    insert(head, 37);
    insert(head, 38);
    insert(head, 39);
    insert(head, 30);
    print(head);

    head = key(head, 3);
    print(head);

    return 0;
}