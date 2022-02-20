class Solution {
public:
    //This is an ordinary dfs question, if you use dfs, you will surely hit TLE, then natually adding memoization is the choice. But the tricky part is, if you run following code, you will hit wrong answer. 
    //The commented out part is not the short cut to save the dfs loop, it's the hidden trap of this question. The DFS solution has an assumption: "if b cannot win, then a will win", it's actually a wrong assumption. 
    //There is situation that neither of them can win, which is when desiredTotal is too large that even adding all the numbers within maxChoosableInteger together, it can not be reached. 
    
    bool dfs(int mask,int score, int target, int player,int m, vector<vector<int>>&dp)
    {
        if(dp[player][mask]!=-1) return dp[player][mask];
        
        for(int i = 1; i<=m; i++)
        {
            int newMask = (1<<(i-1)); //setting ith index as set rest as 0
            if((mask & newMask) == 0) //means ith bit has not been set before, therefore (i+1) score has not been included before
            {
                if(score+i>=target || !dfs((mask|newMask),score+i,target,(player^1),m,dp)) return dp[player][mask] = 1;
            }
        }
        return dp[player][mask] = 0;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        vector<vector<int>> dp(2, vector<int>((1<<maxChoosableInteger),-1));
        int mask = 0;
        if(desiredTotal > (maxChoosableInteger*(maxChoosableInteger+1))/2) return false; //if all the integers within the given range can't be added to give the target too
        return dfs(0,0,desiredTotal,0,maxChoosableInteger,dp);
    }
};