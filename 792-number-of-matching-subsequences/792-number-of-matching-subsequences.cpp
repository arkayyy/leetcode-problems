class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,vector<int>> mp;
        vector<bool> visited(s.size(),false);
        for(int i = 0; i<s.size(); i++)
        {
            mp[s[i]].push_back(i);
        }
        int cnt = 0;
        for(auto w: words)
        {
            bool flag = false; //willl turn true if all characters of this word are not available in s for subsequence
            fill(visited.begin(), visited.end(),false);
            int lastIndex = -1; //used to store the index in s used for previous character of the subsequence at every step
            for(auto ch: w)
            {
                bool f = false; //will turn true if the an index for the current character of w is available for being considered (in s)
                for(auto i: mp[ch])
                    if(!visited[i] && i>lastIndex) //if the index is not visited and the index is greater than the index used in s by previous character of the subsequence
                    {
                        visited[i] = true;
                        f = true;
                        lastIndex = i;
                        break;
                    }
                if(!f) {flag = true; break;}
            }
            if(!flag) cnt++; 
        }
        
        return cnt;
    }
};