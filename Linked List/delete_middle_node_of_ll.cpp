#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteMiddle(ListNode *head)
{
    if (head == nullptr)
    {
        return head;
    }
    if (head->next == nullptr)
    {
        return nullptr;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow->next != nullptr)
    {
        slow->val = slow->next->val;
        slow->next = slow->next->next;
    }
    else
    {
        ListNode *temper = head;
        while (temper->next != slow)
        {
            temper = temper->next;
        }
        temper->next = nullptr;
    }
    return head;
}

int main()
{
    ListNode *root = new ListNode(1);
    root->next = new ListNode(3);
    root->next->next = new ListNode(4);
    root->next->next->next = new ListNode(7);
    root->next->next->next->next = new ListNode(1);
    root->next->next->next->next->next = new ListNode(2);
    root->next->next->next->next->next->next = new ListNode(6);
    cout << " Before Deleting the middle node:" << endl;
    ListNode *temp = root;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << " After Deleting the middle node:" << endl;
    ListNode *result = deleteMiddle(root);
    temp = result;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}

// Input:
// Before Deleting the middle node:
// 1 3 4 7 1 2 6 
// Output:
// After Deleting the middle node:
// 1 3 4 1 2 6 