class Solution {
public:
    //INTUITION: We travel from right storing the elements along with their indexes, and maintain an ascending order
    //For every element we calculate diff b/w it and index of just greater element encountered before
    
    //ALGO: We maintain the ascending order using a monotonic increasing stack
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st; //maintaining a monotonic stack, ascending order from top to bottom
        vector<int> ans(temperatures.size(),-1);
        for(int i = temperatures.size()-1; i>=0; i--)
        {
            while(!st.empty() && st.top().first<=temperatures[i])
                st.pop(); //popping all smaller elements in order to maintain an ascending order in stack
            if(st.empty()) {ans[i] = 0; }//no greater elements found
            else ans[i] = st.top().second - i; //diff between curr index and index of just greater element
            st.push({temperatures[i],i}); //storing element along with their indices
        }
        return ans;
    }
};