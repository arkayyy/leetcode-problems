class Solution {
public:
    bool util(int i, vector<int>& arr, vector<bool>&visited, vector<int>& dp)
    {
        if(i>=arr.size() || i<0 ||  visited[i] ) return false;
        
        if(arr[i]==0) {dp[i] = true; return true;}
        
        if(dp[i]!=-1) return dp[i];
        
        visited[i] = true;
        
        bool ans = util(i+arr[i],arr,visited,dp)||util(i-arr[i],arr,visited,dp);
        
        visited[i] = false;
        
        if(ans) dp[i] = 1;
        else dp[i] = 0;
        
        return ans;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int> dp(arr.size(),-1);
        vector<bool> visited(arr.size(),false);
        return util(start,arr,visited,dp);
    }
};