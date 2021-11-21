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
        if(!headA || !headB)
            return NULL;
        
        //Brute force by calculating length difference:-
        
//         ListNode* h1 = headA;
//         ListNode* h2 = headB;
        
//         int l1 = 0, l2 = 0;
//         while(h1)
//         {
//             h1 = h1->next; 
//             l1++;
//         }
//         while(h2)
//         {
//             h2 = h2->next;
//             l2++;
//         }
        
//         int diff = abs(l2-l1);
        
//         if(l2>l1) 
//         {
//             while(diff--)
//                 headB = headB->next;
//         }
//         else
//         {
//              while(diff--)
//                 headA = headA->next;
//         }
        
//         while(headA && headB)
//         {
//             if(headA==headB)
//                 return headA;
//             headA = headA->next; headB = headB->next;
//         }
//         return NULL;
        
        
        
        //A bit optimal approach is to use hash set and check if any node is already visited in another LL traversal, print that
        
        
        //MOST OPTIMAL APPROACH: 2 pointers
        ListNode* h1 = headA;
        ListNode* h2 = headB;
        
        while(1>0) //loop will run infinitely
        {
            if(!h1 && !h2) //whenever both h1 and h2 go NULL, it means no intersection poiunt is present
                return NULL;
            
            if(h1==h2) return h1; //if both h1==h2 (not NULL), then means that intersection pt is reached
            
            if(!h1) h1 = headA; //if first LL pointer reaches end, it is reset to the head of first LL
            else if(!h2) h2 = headB;//if second LL pointer reaches end, it is reset to the head of second LL
            
            else{ //otherwise moving both pointers ahead by a node
                h1 = h1->next;
                h2 = h2->next; 
            }
            
        }
        
        return NULL;
        
    }
};