class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,vector<int>> adj;
        vector<int> ans;  
        
        //---------------APPROACH 1 - Using BFS (Kahn's Algo) TC:O(N) SC:O(N)-------------------------------------------//
        vector<int> inDegree(numCourses);
        for(auto p: prerequisites)
        {
            adj[p[1]].push_back(p[0]);
            inDegree[p[0]]++;
        }
        
        queue<int> q; //for bfs
        
        for(int i = 0; i<numCourses; i++)
            if(inDegree[i] == 0)
                q.push(i);
        
        while(!q.empty())
        {
            int v = q.front();
            q.pop();
            ans.push_back(v);
            for(auto a: adj[v])
                if(--inDegree[a]==0)
                    q.push(a);
        }
        
        if(ans.size()==numCourses) return true;
        
        return false;
        
    }
};