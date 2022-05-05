class Solution {
public:

    int minimumDeletions(string s) {
        
        //============================Tabulation DP Approach O(N) Time O(N) Space==============================//
//         vector<int> dp(s.size()+1);
//         int b = 0;
//         dp[0] = 0;
//         for(int i = 1; i<=s.size(); i++)
//         {
//             if(s[i-1]=='a')
//             {
//                 dp[i] = min(1+dp[i-1],b); //if current character is 'a', we can either remove all b's that have appeared before it OR we can remove the current character 'a' itself
//             }
//             else
//             {
//                 dp[i] = dp[i-1], ++b; //we can consider 'b' in any case, doesn't matter if 'a' or 'b' have appeared before or not...we just count b at every occurence
//             }
//         }
//         return dp[s.size()];
        
        
        //========================Space Optimized DP O(N) Time O(1) Space =================================//
        //Since we are only using current and previous state of the dp array...!
        int prev = 0, curr = 0;
        int b = 0;
        for(int i = 1; i<=s.size(); i++)
        {
            if(s[i-1]=='a')
            {
                curr = min(1+prev,b); //if current character is 'a', we can either remove all b's that have appeared before it OR we can remove the current character 'a' itself
            }
            else
            {
                curr = prev, ++b; //we can consider 'b' in any case, doesn't matter if 'a' or 'b' have appeared before or not...we just count b at every occurence
            }
            prev = curr;
        }
        
        return curr;
    }
};