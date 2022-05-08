/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> ans;
    int i, n;
    void util(int i, int n, vector<NestedInteger>& nested)
    {
        if(i==n) return;
        
        if(nested[i].isInteger()) ans.push_back(nested[i].getInteger());
        
        else util(0,nested[i].getList().size() , nested[i].getList());
        
        util(i+1, n, nested);
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        util(0, nestedList.size(), nestedList);
        i = 0; n = ans.size();
    }
    
    int next() {
        return ans[i++];
    }
    
    bool hasNext() {
        return !(i==n);
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */