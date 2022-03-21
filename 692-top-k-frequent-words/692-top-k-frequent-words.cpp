class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int, string>> pq;
        
        unordered_map<string,int> mp;
        
        for(auto w: words)
        {
            mp[w]++;
        }
        
        for(auto m: mp)
        {
            pq.push(make_pair(m.second, m.first));
        }
        vector<string> ans;
        int i = 0;
        while(i<k)
        {
            int freq = pq.top().first;
            int start = ans.size();
            int len = 0;
            
            stack<string> st;
            
            while( !pq.empty() && pq.top().first == freq)
                { len++; st.push(pq.top().second); pq.pop();}
            while(i<k && !st.empty())
                {i++; ans.push_back(st.top()); st.pop();}
        }
        
        return ans;
    }
};