//Sort linked list of 0s 1s 2s
/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/
// Solution 1
Node* sortList(Node *head)
{
    // Write your code here.
    int zero = 0;
    int one = 0;
    int two = 0;
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data==0) zero++;
        else if(temp->data==1) one++; 
        else if(temp->data==2) two++;
        temp = temp->next;  
    }
    Node* ans = head;
    while(zero--){
        ans->data = 0;
        ans = ans->next;
    }
    while(one--){
        ans->data = 1;
        ans = ans->next;
    }
    while(two--){
        ans->data = 2;
        ans = ans->next;
    }
    return head;
}

// Solution 2
/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/

Node* sortList(Node *head)
{
    // Write your code here.
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    // traverse the original linked list
    Node* curr = head;
    while(curr!=NULL){
        if(curr->data==0){
            //Take the node of 0
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            //Append in zeroHead
            zeroTail->next = temp;
            zeroTail = temp;

        }
        else if(curr->data==1){
            //Take the node of 1
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            //Append in oneHead
            oneTail->next = temp;
            oneTail = temp;
        }
        else if(curr->data==2){
            //Take the node of 2
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            //Append in twoHead
            twoTail->next = temp;
            twoTail = temp;
        }
        
    }
    //Join the linked lists
    Node* temp = oneHead;
    oneHead = oneHead->next;
    temp->next = NULL;
    delete temp;

    temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;

    if(oneHead!=NULL){
        zeroTail->next = oneHead;
        if(twoHead!=NULL){
            oneTail->next = twoHead;
        }
    }
    else{
        if(twoHead!=NULL){
            zeroTail->next = twoHead;
        }
    }
    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;

    return zeroHead;
}
