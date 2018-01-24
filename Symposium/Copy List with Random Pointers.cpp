/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode* head) {
        // write your code here
        copyList(head);
        copyRandom(head);
        return split(head);
    }

    void copyList(RandomListNode* head) {
        while (head != NULL) {
            RandomListNode* dup = new RandomListNode(head -> label);
            dup -> next = head -> next;
            dup -> random = head -> random;
            head -> next = dup;
            head = head -> next -> next;
        }
    }

    void copyRandom(RandomListNode* head) {
        RandomListNode* prev = NULL;
        while (head != NULL) {
            if (head -> random != NULL) {
                head -> next -> random = head -> random -> next;
            }
            head = head -> next -> next;
        }
    }

    RandomListNode* split(RandomListNode* head) {
        RandomListNode* ret = head -> next;
        while (head != NULL) {
            RandomListNode* p = head -> next;
            head -> next = p -> next;
            head = head -> next;
            if (p -> next != NULL) {
                p -> next = p -> next -> next;
            }
        }

        return ret;
    }
};
