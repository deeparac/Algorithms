/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    struct cmp {
        bool operator()(const ListNode* lhs, const ListNode* rhs) const {
            return lhs -> val > rhs -> val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;

        priority_queue<ListNode*, vector<ListNode*>, cmp> q;

        for (const auto& list : lists) {
            if (list != nullptr) {
                q.push(list);
            }
        }

        while (!q.empty()) {
            ListNode* curr = q.top(); q.pop();
            head -> next = curr;
            head = head -> next;
            curr = curr -> next;
            if (curr != nullptr) {
                q.push(curr);
            }
        }

        return dummy -> next;
    }
};
