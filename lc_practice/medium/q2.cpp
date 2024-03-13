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
        long long num1 = 0;
        long long num2 = 0;
        while (l1) {
            num1 = num1 * 10 + l1->val;
            l1 = l1->next;
        }
        while (l2) {
            num2 = num2 * 10 + l2->val;
            l2 = l2->next;
        }
        long long sum = num1 + num2;
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        do {
            ListNode *node = new ListNode(sum % 10);
            if (!head) {
                head = tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
            sum /= 10;
        } while (sum > 0);
        return head;
    }
};

int main() {
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

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
