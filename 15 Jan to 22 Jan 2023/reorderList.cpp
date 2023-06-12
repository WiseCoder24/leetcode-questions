/*
143. Reorder List
Medium

You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.
*/
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
    void reorderList(ListNode* head) {
        if((!head)||(!head->next)||(!head->next->next)) return;
        stack<ListNode*>st;
        int size=0;
        ListNode* ptr = head;
        while(ptr!=NULL){
            st.push(ptr);
            size++;
            ptr = ptr->next;
        }
        ListNode* temp = head;
        for(int i=0;i<size/2;i++){
            ListNode* temp2 = st.top();
            st.pop();
            temp2->next = temp->next;
            temp->next = temp2;
            temp = temp->next->next;
        }
        temp->next = NULL;
    }
};