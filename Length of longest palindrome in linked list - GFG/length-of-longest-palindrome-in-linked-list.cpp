//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
int maxPalindrome(Node *);


/* Driver program to test above function*/
int main()
{
    int T,n,l;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
      

       cout << maxPalindrome(head)<<endl;
    }
    return 0;
}



// } Driver Code Ends

//APPROACH: We start traversing from starting of LL and keep on reversing the LL till where we reach
//We run one pointer leftwards in the reversed part on the left, and one pointer rightwards on the right intact part
//and we count how many elements are same...!! XD

int countSame(Node* leftwardsPtr, Node* rightwardsPtr)
{
    int cntSame = 0;
    while(leftwardsPtr && rightwardsPtr && (leftwardsPtr->data == rightwardsPtr->data))
        ++cntSame, leftwardsPtr = leftwardsPtr->next, rightwardsPtr = rightwardsPtr->next;
    return cntSame;
}

int maxPalindrome(Node *head)
{
    Node* curr = head, *prev = NULL, *next = NULL;
    int ans = 0;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        ans = max(ans, 2*countSame(curr,next)); //for even length palindrome
        ans = max(ans, 2*countSame(prev,next) + 1); //for odd length palindrome
        prev = curr;
        curr = next;
    }
    return ans;
}