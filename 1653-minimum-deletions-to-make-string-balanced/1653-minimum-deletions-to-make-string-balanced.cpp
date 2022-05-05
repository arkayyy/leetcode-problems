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
        vector<int> dp(s.size()+1);
        int b = 0;
        for(int i = 0; i<s.size(); i++)
        {
            if(s[i]=='a')
            {
                dp[i+1] = min(1+dp[i],b);
            }
            else
            {
                dp[i+1] = dp[i], ++b;
            }
        }
        return dp[s.size()];
    }
};