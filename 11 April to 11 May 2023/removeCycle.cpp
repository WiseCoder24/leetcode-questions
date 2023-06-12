// Detect and Remove Loop
/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/

Node *removeLoop(Node *head)
{
    // Write your code here.
    if(head==NULL) return NULL;
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL){
        fast = fast->next;
        if(fast!= NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(slow==fast){      
            slow = head; break;
        }
        
    }
    if(fast==NULL && slow!=fast){
        return head;
    }
    while(slow!=fast){
        fast = fast->next;
        slow = slow->next; 
    }
    Node* temp = slow;
    while(temp->next!=fast){
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}