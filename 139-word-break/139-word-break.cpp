class Solution {
public:
    bool canBrk(int start, string& s, unordered_set<string>& wordDict,vector<int>& mem) {
        int n = s.size();
        if(start == n) return 1;
        if(mem[start]!= -1) return mem[start];
        string sub;
        for(int i = start; i<n; i++) 
        {
            sub+=s[i];
            if(wordDict.count(sub) && canBrk(i+1,s,wordDict,mem)) 
                return mem[start] = 1; 
        }
        return mem[start] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        //----------1. Recursion with memoization (optimal) ----------------//
        // vector<int> mem(s.size(),-1);
         unordered_set<string> words(wordDict.begin(), wordDict.end());
        // return canBrk(0,s,words,mem);
        
        //--------2. DP Tabulation (most optimal) ------------------------------//
        int n = s.size();
        vector<bool> dp(n+1);
        dp[n]=1;
        for(int i=n-1;i>=0;i--) {
            string sub = "";
            for(int j=i;j<n;j++) 
            {
                sub+=s[j];
                dp[i] = words.count(sub);
                if (dp[i] && dp[j+1]) 
                    break;
            }
        }
        return dp[0]; 
        
        //----------3. BFS (most optimal) ---------------------------------//
        // queue<int> q({0});
        // unordered_set<int> visited;
        // int n = s.size();
        // while(!q.empty()) {
        //     int start = q.front();
        //     q.pop();
        //     if(visited.count(start)) continue;
        //     visited.insert(start);
        //     string sub = "";
        //     for(int i=start;i<n;i++)
        //     {
        //         sub+=s[i];
        //         if(words.count(sub)) 
        //         {
        //             q.push(i+1);
        //             if(i+1 == n) return 1;    
        //         }
        //     }
        // }
        // return 0;   
    }
};