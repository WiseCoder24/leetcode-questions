/*
Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
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
    ListNode* reverseLL(ListNode* head){
        if(head==NULL) return NULL;
        // if(head->next==NULL) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp = curr->next;
        while(curr!=NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1 = reverseLL(l1);
        // l2 = reverseLL(l2);
        int carry = 0;

        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        while(l1!=NULL && l2!=NULL){
            int sum = l1->val + l2->val + carry;
            int digit = sum%10;
            carry = sum/10;
            ListNode* newNode = new ListNode(digit);
            if(ansHead==NULL){
                ansHead = newNode;
                ansTail = newNode;
            }
            else{
                ansTail->next = newNode;
                ansTail = newNode;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL){
            int sum = l1->val+carry;
            int digit = sum%10;
            carry = sum/10;
            ListNode* newNode = new ListNode(digit);
            ansTail->next = newNode;
            ansTail = newNode;
            l1 = l1->next;
        }
        while(l2!=NULL){
            int sum = l2->val+carry;
            int digit = sum%10;
            carry = sum/10;
            ListNode* newNode = new ListNode(digit);
            ansTail->next = newNode;
            ansTail = newNode;
            l2 = l2->next;
        }
        //If carry is still not 0
        while(carry!=0){
            int sum = carry;
            int digit = sum%10;
            carry = sum/10;
            ListNode* newNode = new ListNode(digit);
            ansTail->next = newNode;
            ansTail = newNode;
        }
        // ansHead = reverseLL(ansHead);
        return ansHead;
    }
};

////////////////////////////////////////////////////////
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return dummyHead->next;
    }
};