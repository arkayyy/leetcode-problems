class Solution {
public:
    int util(int i, bool aOccured, bool bOccured, string s)
    {
        if(i==s.length()) { if(!aOccured && !bOccured) return INT_MAX-1; else return 0;}
        int res1,res2;
        if(s[i]=='a')
        {
            if(bOccured) res1 = 1+util(i+1,aOccured,bOccured,s);
            //(aOccured) res1 =  1+util(i+1,aOccured,bOccured,s);
            else res1 = min(1+util(i+1,aOccured,bOccured,s), util(i+1,true,bOccured,s));
        }
        else
        {
            // if(!aOccured) res2 = 1+util(i+1, aOccured, bOccured,s);
            // else if(bOccured) res2 =  1+util(i+1, aOccured, bOccured,s);
            //else 
            res2 = min(1+util(i+1,aOccured, bOccured, s), util(i+1, aOccured, true, s));
        }
        
        return min(res1,res2);
    }
    int minimumDeletions(string s) {
        // return util(0,false,false,s);
        
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