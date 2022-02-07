class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        
        //Using topological sort with BFS (Kahn's Algo):-
        unordered_map<int,vector<int>> adj;
        queue<int> q;
        vector<int> inDegree(numCourses);
        for(auto e: prerequisites)
        {
            inDegree[e[0]]++;
            adj[e[1]].push_back(e[0]);
        }
        
        for(int i = 0; i<numCourses; i++)
            if(inDegree[i]==0)
            {q.push(i);}
        
        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            ans.push_back(t);
            for(auto a: adj[t])
                if((--inDegree[a])==0)
                    q.push(a);
        }
        
        if(ans.size()!=numCourses) return {};
        
        return ans;
    }
};