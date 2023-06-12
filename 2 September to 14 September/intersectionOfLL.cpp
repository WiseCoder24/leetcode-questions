/*
160. Intersection of Two Linked Lists
Easy

Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL){
            return NULL;
        }
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        int a=0; int b=0;
        while(temp1!=NULL){
            a++;
            temp1 = temp1->next;
        }
        while(temp2!=NULL){
            b++;
            temp2 = temp2->next;
        }
        int k = abs(a-b);
        if ( b > a ) {
            //if the size of B > A, then b becomes b->next till the difference a-b becomes zero
            while(k--) {
                headB = headB -> next;
            }
        }
        else {
            //if the size of B < A, then a becomes a->next till the difference a-b becomes zero
            while(k--) {
                headA = headA -> next;
            }
        }
        while(headA!=headB && headA->next!=NULL && headB->next!=NULL){
            headA=headA->next;
            headB=headB->next;
        }
        if(headA!=headB)
            return NULL;
        return headA;
    }
};