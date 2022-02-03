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
            bool flag = false;
            fill(visited.begin(), visited.end(),false);
            int lastIndex = -1;
            for(auto ch: w)
            {
                bool f = false;
                for(auto i: mp[ch])
                    if(!visited[i] && i>lastIndex)
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