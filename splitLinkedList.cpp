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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr=head;
        int l=0;
        while(curr){
            l++;
            curr=curr->next;
        }
        int eachbucketnode=l/k;
        int remaining=l%k;
        vector<ListNode*> result(k,nullptr);
        curr=head;
        ListNode* prev=nullptr;
        for(int i=0;i<k;i++){
            result[i]=curr;
            for(int j=1;j<=eachbucketnode+(remaining>0?1:0);j++){
                prev=curr;
                curr=curr->next;
            }
            if(prev!=NULL){
            prev->next=NULL;}
            remaining--;
        }
        return result;
    }
};
