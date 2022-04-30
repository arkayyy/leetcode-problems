class Solution {
public:
    double util(string s1, string s2, unordered_map<string, unordered_map<string,double>> &mp, unordered_set<string> &visited)
    {
        if(mp.find(s1)!=mp.end() && mp[s1].find(s2)!=mp[s1].end()) return mp[s1][s2];
        
        for(auto m:mp[s1])
        {
            if(visited.find(m.first)==visited.end())
                {
                visited.insert(m.first);
                double m2 = util(m.first,s2, mp, visited);
                //mp[m.first][s2] = m2;
                if(m2!=-1)  return m.second*m2;
                }
        }
        
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string,double>> mp;
        unordered_set<string> visited;
        vector<double> ans;
        
        for(int i = 0; i<equations.size(); i++)
        {
            mp[equations[i][0]][equations[i][1]] = values[i];
            if(values[i]!=0) mp[equations[i][1]][equations[i][0]] = (1/values[i]);
        }

        for(auto q: queries)
        {
            if(mp.find(q[0])==mp.end() || mp.find(q[1])==mp.end()) {ans.push_back(-1); continue;}
            if(q[0]==q[1]) {ans.push_back(1); continue;}
            visited.clear();
            double res = util(q[0],q[1],mp,visited);
            ans.push_back(res);
        }
        
        return ans;
    }
};