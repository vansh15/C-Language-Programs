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

ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* temp = head;
        while(temp!=nullptr && temp->next!=nullptr){
            if(temp->next!=nullptr){
                int tor = temp->val;
                temp->val = temp->next->val;
                temp->next->val = tor;
                temp = temp->next->next;
            }
        }
        return head;
    }

int main(){
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(5);

    cout << " Before swapping the nodes:" << endl;
    ListNode *temp = root;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << " After swapping the nodes:" << endl;
    ListNode *result = swapPairs(root);
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
// Before swapping the nodes:
// 1 2 3 4 5 
// Output:
// After swapping the nodes:
// 2 1 4 3 5