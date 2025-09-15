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
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto i:lists){
            ListNode * demo=i;
            while (demo!=NULL){
                minHeap.push(demo->val);
                demo=demo->next;
            }
        }
        if(minHeap.empty())return nullptr;
        ListNode* ans=new ListNode(minHeap.top());
        ListNode* temp=ans;
        minHeap.pop();
        while(!minHeap.empty()){
            temp->next=new ListNode(minHeap.top());
            temp=temp->next;
            minHeap.pop();
        }
        return ans;
    }
};