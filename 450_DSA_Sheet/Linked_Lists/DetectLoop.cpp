#include <iostream>
using namespace std;

struct Node{
    Node* next = NULL;
    int data = 0;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

bool detectLoop(Node *head)
{
    // your code here
    Node *p1 = head, *p2 = head->next;
    while (p2)
    {
        if (p1 == p2)
            return 1;
        p1 = p1->next;
        p2 = p2->next;
        if (p2)
            p2 = p2->next;
    }
    return 0;
}

int main()
{
    int n, cyclePoint;
    // cyclePoint specifies the node to which last node will form a cycle with
    cin >> n >> cyclePoint;
    int value;
    cin >> value;
    Node* head = new Node(value);
    Node* curr = head;
    for(int i = 1; i < n; i++)
    {
        cin >> value;
        curr->next = new Node(value);
        curr = curr->next;
    }

    Node* cycleNode = head;
    while(cyclePoint == 1)
    {
        cycleNode = cycleNode->next;
        cyclePoint--;
    }
    
    curr->next = cycleNode;
    if(cyclePoint < 1)
        curr->next = NULL;
    bool ans = detectLoop(head);
    cout << (ans ? "Loop Exists": "Loop does not exist");
}