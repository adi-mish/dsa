#include <iostream>

using namespace std;

/* You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order,
and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            if (l1) carry += l1->val, l1 = l1->next;
            if (l2) carry += l2->val, l2 = l2->next;
            p->next = new ListNode(carry % 10);
            carry /= 10;
            p = p->next;
        }
        return dummy->next;
    }
};

int main() {
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(9);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    l2->next->next->next = new ListNode(9);

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    while (result) {
        cout << result->val;
        result = result->next;
        if (result) {
            cout << "->";
        }
    }
    cout << endl;

    return 0;
}
