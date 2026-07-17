/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        for (ListNode* list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }

        ListNode dummy(0);
        ListNode* current = &dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            current->next = node;
            current = current->next;

            if (node->next != nullptr) {
                pq.push(node->next);
            }
        }

        return dummy.next;
    }

private:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
};