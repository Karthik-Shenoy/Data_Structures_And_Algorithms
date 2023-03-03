#include <iostream>
using namespace std;

struct node{
    node* next = NULL;
    int data = 0;
    node(int data)
    {
        this->data = data;
    }
};


struct node *reverse(struct node *head, int k)
{
    // Complete this method
    node *prev_tail = NULL, *curr_tail = head, *ret = NULL;
    node *p1 = NULL, *p2 = head, *p3 = head->next;
    int val = 1, first = 1;
    while (p2)
    {
        if (val % k == 0 & first)
        {
            first = 0;
            prev_tail = curr_tail;
            curr_tail = p3;
            ret = p2;
        }
        else if (val % k == 0)
        {
            node *curr_head = p2;
            if (prev_tail)
                prev_tail->next = curr_head;
            prev_tail = curr_tail;
            curr_tail = p3;
        }
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        if (p3)
            p3 = p3->next;
        val++;
    }
    prev_tail->next = NULL;
    if (curr_tail)
    {
        prev_tail->next = p1;
        curr_tail->next = NULL;
    }
    return ret;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int value;
    cin >> value;
    node* head = new node(value);
    node* curr = head;
    for(int i = 1; i < n; i++)
    {
        cin >> value;
        curr->next = new node(value);
        curr = curr->next;
    }
    curr->next = NULL;
    node* ans = reverse(head, k);
    while(ans)
    {
        cout << ans->data << ' ';
        ans = ans->next;
    }
}