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
    ListNode* swapNodes(ListNode* head, int k) {
        int len=0;
        ListNode* temp1=head;
        while(temp1!=NULL){
            len++;
            temp1=temp1->next;
        }
        temp1=head;
        ListNode* temp2=head;

        int num=len-k;
        while(k-1){
            temp1=temp1->next;
            k--;
        }
        while(num){
            temp2=temp2->next;
            num--;
        }

        swap(temp1->val,temp2->val);
        return head;
    }
};