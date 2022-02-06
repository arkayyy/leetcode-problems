class Solution {
public:
    int minimumTime(string s) {
        int n = s.size();
        vector<int> sequentialCostFromRight(n+1);//contains cost if sequentially moved and removed illegal cars from the right end
        for(int i = n-1; i>=0; i--)
        {
            if(s[i]=='1')
                sequentialCostFromRight[i] = n-i;
            else
                sequentialCostFromRight[i] = sequentialCostFromRight[i+1];
        }
        int ans = INT_MAX;
        vector<vector<int>> dp(2, vector<int>(n+1));
        
        for(int i = 1; i<=n; i++)
        {
            //Sequential moving ->>>
            dp[0][i] = dp[0][i-1]+1; //if we move sequentially from previous index (i.e. by removing one car from the left pointer) 
            
            //Non-sequential moving (i.e. removing illegal car from middle)->>>
            if(s[i-1]=='1')
                dp[1][i] = min(dp[0][i-1],dp[1][i-1]) + 2; //signifies effect of removing current index car from the middle(non-sequentially) if it is illegal
            else
                dp[1][i] = min(dp[0][i-1],dp[1][i-1]);
            
            //computing best answer =  (best possible min. no. of moves upto i index) + only (sequential moves to the right of index i)
            ans = min(ans, min(dp[0][i],dp[1][i])+sequentialCostFromRight[i]);
        }
        
        return ans;
    }
};