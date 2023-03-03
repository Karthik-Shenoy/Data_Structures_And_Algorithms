#include <iostream>
using namespace std;

struct Node
{
    Node *next = NULL;
    int data = 0;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int detectCycle(Node *head)
{
    if (!head)
        return NULL;
    Node *s = head, *f = head->next;
    Node *meetNode = NULL, *ptr = head;
    while (f)
    {
        if (f == s)
        {
            meetNode = f;
            break;
        }
        s = s->next;
        f = f->next;
        if (f)
            f = f->next;
    }
    int flag = 0;
    if (meetNode)
    {
        int index = 0;
        meetNode = meetNode->next;
        while (ptr != meetNode)
        {
            ptr = ptr->next;
            meetNode = meetNode->next;
            index++;
            if (index > (int)(1e4 + 1))
                return 0;
        }
        return index;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int n, cyclePoint;
    // cyclePoint specifies the node to which last node will form a cycle with
    cin >> n >> cyclePoint;
    int value;
    cin >> value;
    Node *head = new Node(value);
    Node *curr = head;
    for (int i = 1; i < n; i++)
    {
        cin >> value;
        curr->next = new Node(value);
        curr = curr->next;
    }

    Node *cycleNode = head;
    while (cyclePoint > 1)
    {
        cycleNode = cycleNode->next;
        cyclePoint--;
    }

    curr->next = cycleNode;
    if (cyclePoint < 1)
        curr->next = NULL;
    int ans = detectCycle(head);
    cout << (ans >= 0 ? "Loop Exists at "  : "Loop does not exist ") << ans;
}