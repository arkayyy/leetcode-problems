//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    Node* newHead = new Node(1);
    Node* dummy = newHead;
    Node* curr1 = head1, *curr2 = head2;
    while(curr1 && curr2)
    {
        while(curr1 && curr2 && curr1->data<curr2->data) curr1 = curr1->next;
        if(curr1 && curr2 && curr1->data==curr2->data) {int currData = curr1->data; dummy->next = new Node(curr1->data); dummy = dummy->next; 
        // while(curr1 && curr2 && curr1->data==curr2->data && curr1->data==currData){curr1 = curr1->next, curr2=curr2->next;} 
            curr1 = curr1->next, curr2=curr2->next;
        }
        while(curr2 && curr1 && curr2->data<curr1->data) curr2 = curr2->next;
        if(curr1 && curr2 && curr1->data==curr2->data) {int currData = curr1->data; dummy->next = new Node(curr2->data); dummy = dummy->next;
        // while(curr1 && curr2 && curr1->data==curr2->data && curr1->data==currData){curr1 = curr1->next, curr2=curr2->next;} //To avoid repeating elements
            curr1 = curr1->next, curr2=curr2->next;
        }
    }
    
    return newHead->next;
}