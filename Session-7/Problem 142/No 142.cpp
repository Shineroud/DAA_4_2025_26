class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        ListNode* sl = head;
        ListNode* fa = head;
        while (fa && fa->next) {
            sl = sl->next;
            fa = fa->next->next;
            if (sl == fa) {
                ListNode* potr1 = head;
                ListNode* potr2 = sl;
                while (potr1 != potr2) {
                    potr1 = potr1->next;
                    potr2 = potr2->next;
                }
                return potr1; 
            }
        }
        return nullptr;
    }
};