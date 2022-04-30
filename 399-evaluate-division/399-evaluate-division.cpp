class Solution {
public:
    //INTUITION: a/b can also be expressed as => a/c * c/b. So it means we go through the c factor in middle.
    //SO indirectly its like traversing from a vertex to b vertex in a graph through multiple vertices, since all ways will lead to same result. IT'S MATHS!
    
    //ALGO: Doing simple DFS+hashing. We store the provided equation results between variables in our hash table to use them during DFS.
    //We use a visited array just to not take any middle factor/variable multiple times.
    //e.g.if a/b = a/c*c/b. Taking c factor in middle once more will give a/c*c/c*c/b = a/b which was the original required expression.
    
    double util(string s1, string s2, unordered_map<string, unordered_map<string,double>> &mp, unordered_set<string> &visited)
    {
        if(mp.find(s1)!=mp.end() && mp[s1].find(s2)!=mp[s1].end()) return mp[s1][s2];
        
        for(auto m:mp[s1])
        {
            if(visited.find(m.first)==visited.end())
                {
                visited.insert(m.first);
                double m2 = util(m.first,s2, mp, visited);
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