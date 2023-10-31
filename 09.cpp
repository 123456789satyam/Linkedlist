#include <bits/stdc++.h>
using namespace std;
// circular linked list;
// from singly linked list
// insertion
// trivarsal
// deletion

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

void deletenode(node *&tail, int value)
{
    // empty list
    if (tail == NULL)
    {
        cout << "list is empty, please check again" << endl;
        return;
    }

    else
    {
        // non empty
        //  assuming that value is present in linked list

        node *prev = tail;
        node *curr = prev->next;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        // 1 node linked list
        if (curr == prev)
        {
            tail = NULL;
        }

        //>2 node linkde list
        else if (tail == curr)
        {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}

bool iscircular(node *&head)
{
    if (head == NULL)
    {
        return true;
    }
    node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    node *tail = NULL;

    insertnode(tail, 5, 3);
    print(tail);
    insertnode(tail, 3, 6);
    print(tail);
    insertnode(tail, 6, 7);
    print(tail);
    insertnode(tail, 7, 9);
    print(tail);
    insertnode(tail, 3, 5);
    print(tail);
    insertnode(tail, 3, 4);
    print(tail);

    deletenode(tail, 3);
    print(tail);
    deletenode(tail, 7);
    print(tail);
    deletenode(tail, 9);
    print(tail);

    cout << iscircular(tail);

    return 0;
}