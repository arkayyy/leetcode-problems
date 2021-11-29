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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    pair<ListNode *, ListNode *> findMid(ListNode *head)
    {
        if (!head)
            return {NULL, NULL};

        ListNode *slo = head;
        ListNode *fast = head;
        ListNode *prev = slo;

        while (fast && fast->next)
        {
            prev = slo;
            slo = slo->next;
            fast = fast->next->next;
        }

        //from this fn, we are returning the middle node (stored in slo), along with the node that comes just before it.

        return {prev, slo};
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (!head)
            return NULL;

        if (!head->next)
            return new TreeNode(head->val);

        pair<ListNode *, ListNode *> mid = findMid(head);
        TreeNode *node = new TreeNode(mid.second->val);

        mid.first->next = NULL;

        //this is because, for a sorted linked list, if a BST node is made with the middle element, the left subtree can only contain the nodes in the list that lie before the middle element (i.e. nodes from head upto prev).
        //and the right subtree will only contain the nodes which lie after the middle element. (from mid->next to the last node of the LL)

        node->left = sortedListToBST(head);
        node->right = sortedListToBST(mid.second->next);

        return node;
    }
};