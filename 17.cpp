#include <bits/stdc++.h>
using namespace std;
// detect weather it is circular linked list or not;
// mapping;
//  TC = O(n) ;
//  SC = O(n) ;

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

bool detect(node *head)
{
    if (head == NULL)
    {
        return false;
    }

    map<node *, bool> visited;

    node *temp = head;

    while (temp != NULL)
    {

        if (visited[temp] == true)
        {
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

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

int main()
{
    node *tail = NULL;

    insertnode(tail, 5, 3);
    insertnode(tail, 3, 6);
    insertnode(tail, 6, 7);
    insertnode(tail, 7, 9);
    insertnode(tail, 3, 5);
    insertnode(tail, 3, 4);
    print(tail);

    cout << detect(tail);

    return 0;
}