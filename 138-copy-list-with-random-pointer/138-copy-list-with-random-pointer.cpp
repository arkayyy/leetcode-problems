/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    //INTUITION & ALGO: Say the LL given to us is 1->2->3->4->NULL
    //If we duplicate each node, it will become: 1->1`->2->2`->3->3`->4->4`->NULL
    //Now for each duplicated node, we can set the random pointer to its original's random pointer's next(which will again be some duplicated node FOR SURE)
    //And finally we can remove all the original nodes to be left with only the duplicated nodes...!!!
    
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        
        Node* curr = head;
        while(curr)
        {
            Node* next = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = next;
            curr = next;
        }
        
        curr = head;
        while(curr)
        {
            if(curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        
        curr = head;
        Node* newHead = head->next;
        Node* curr1 = newHead;
        while(curr1->next)
        {
            curr->next = curr->next->next;
            curr = curr->next;
            curr1->next = curr1->next->next;
            curr1 = curr1->next;
        }
        
        curr->next = curr->next->next;
        
        return newHead;
    }
};