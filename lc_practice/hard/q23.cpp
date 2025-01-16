#include <queue>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        auto cmp = [](ListNode* l, ListNode* r) {
            return l->val > r->val;
        };
        
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pq(cmp);
        
        for (auto list : lists) {
            if (list) {
                pq.push(list);
            }
        }
        
        ListNode *dummy = new ListNode(0);
        ListNode *current = dummy;
        
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            
            current->next = node;
            current = current->next;
            
            if (node->next) {
                pq.push(node->next);
            }
        }

        ListNode* result = dummy->next;

        delete dummy;
        
        return result;
    }
};