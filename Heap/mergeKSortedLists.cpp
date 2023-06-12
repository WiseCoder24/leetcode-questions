/*
23. Merge k Sorted Lists
Hard

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
*/
class compare{
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        int k=lists.size();
        if(k==0) return NULL;

        // Add first element of every list in minHeap
        for(int i=0;i<k;i++){
            if(lists[i] != NULL){
                minHeap.push(lists[i]);
            }
        }
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(!minHeap.empty()){
            ListNode* temp = minHeap.top();
            minHeap.pop();
            // temp may or may not be the first element of the answer linked list
            if(head==NULL){
                // temp is the first element of ans LL
                head=temp;
                tail=temp;
                
            }
            else{
                // temp is not the first element
                tail->next = temp;
                tail = temp;
               
            }
            // This step is common for both above cases. It means if the next element of the list is not null then it is pushed in the min heap
            if(tail->next!=NULL){
                    minHeap.push(tail->next);
                }
        }
        return head;
    }
};