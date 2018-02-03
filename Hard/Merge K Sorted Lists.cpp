/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct cmpNode {
    bool operator()(ListNode* p, ListNode* q) const {
        return p -> val > q -> val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;

        priority_queue<ListNode*, vector<ListNode*>, cmpNode> q;

        for (auto list : lists) {
            if (list != NULL) {
                q.push(list);
            }
        }

        while (!q.empty()) {
            head -> next = q.top(); q.pop();
            head = head -> next;
            if (head -> next) {
                q.push(head -> next);
            }
        }

        return dummy -> next;
    }
};
