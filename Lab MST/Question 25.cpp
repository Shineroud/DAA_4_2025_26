class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*current= head;
        int count =0;
        while (current && count < k) {
            current= current->next;
            count++;
        }
        if (count== k) {
            current= reverseKGroup(current, k);
            while (count--) {
                ListNode*temp = head->next;
                head->next=current;
                current=head;
                head=temp;
            }
            head=current;
        }
        return head;
    }
};