/*
234. Palindrome Linked List
Given the head of a singly linked list, return true if it is a palindrome.
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
    bool checkPalindrome(ListNode* &head){
        //Finding middle of the linked list
        if(head==NULL) return true;
        if(head->next==NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        //reversing the linked list from the middle
        ListNode* reverseHead = reverseLL(slow->next);
        slow->next = reverseHead;
        ListNode* temp1 = head;
        ListNode* temp2 = reverseHead;
        while(temp2!=NULL){
            if(temp1->val!=temp2->val){
                return false;
            }
            else{
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        return checkPalindrome(head);
    }
};