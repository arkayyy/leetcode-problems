class Solution {
public:
    string frequencySort(string s) {
        vector<int> cnt(256,0);
        for(auto c: s) cnt[(int)c]++;
        priority_queue<pair<int,char>> pq;
        for(int i = 0; i<256; i++)
            pq.push({ cnt[i],(char)(i)});
        string res = "";
        while(!pq.empty())
        {
            int f = pq.top().first;
           char ch = pq.top().second;
            pq.pop();
            for(int i = 0; i<f; i++) 
                res += ch;
        }
        return res;
    }
};