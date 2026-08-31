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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> nodes;

        ListNode* temp=head->next;
        ListNode* prev=head;
        int index=1;

        while(temp->next!=NULL){
            if(prev->val>temp->val && temp->next->val>temp->val){
                nodes.push_back(index);
            }
            if(prev->val<temp->val && temp->next->val<temp->val){
                nodes.push_back(index);
            }

            index++;
            temp=temp->next;
            prev=prev->next;
        }

        int minDist=INT_MAX;
        int maxDist=-1;
        if(nodes.size()>=2){
            for(int i=1;i<nodes.size();i++){
                minDist=min(minDist,nodes[i]-nodes[i-1]);
            }
            maxDist=nodes.back()-nodes[0];
            return {minDist,maxDist};
        }

        return {-1,-1};
    }
};