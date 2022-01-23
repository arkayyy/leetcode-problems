class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        for(int i = 1; i<=9; i++)
            q.push(i);
        
        vector<int> ans;
        
        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            if(t>high) break;
            
            if(t>=low) ans.push_back(t);
            
            int lastDigit = t%10;
            if(lastDigit<9)
                q.push((t*10)+(lastDigit+1));
        }
        
        return ans;
    }
};