class Solution {
public:
    int countSetBits(int n)
    {
        int cnt = 0;
        while(n)
        {
            n = (n&(n-1));
            cnt++;
        }
        return cnt;
        
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i =0; i<=n; i++)
        {
            ans[i] = countSetBits(i);
        }
        return ans;
    }
};