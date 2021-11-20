class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> ans(n+1,0);
        
        for(int i=0;i<=n;i++)
        {
            int n1 = i;
            while(n1)
            {
                n1 &= (n1-1);
                ans[i]++;
            }
        }
        
        return ans;
    }
};