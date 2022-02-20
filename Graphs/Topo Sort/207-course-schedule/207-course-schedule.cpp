class Solution {
public:
    
    bool isCyclic(int v, vector<int>& visited, unordered_map<int,vector<int>>& adj)
    {
        if(visited[v]==1) return true; //cycle exists because a node whose adj is being traversed using DFS currently is visited again in a loop
        if(visited[v]==0) //if not already visited and adjacents not traversed using DFS
        {
            visited[v]= 1; //starting DFS traversals of all adjacents of node v
            for(auto a: adj[v])
                if(isCyclic(a,visited,adj))
                    return true;
        }
        visited[v] = 2; //after DFS traversal of adj nodes of v
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        
        //----------------------APPROACH - 1: Topo sort using BFS (Kahn's Algorithm) -------------------//
        //Using topological sort with BFS (Kahn's Algo):- TC:O(N) SC: O(2N)
        
        unordered_map<int,vector<int>> adj;
//         queue<int> q;
//         vector<int> inDegree(numCourses);
        for(auto e: prerequisites)
        {
            //inDegree[e[0]]++;
            adj[e[1]].push_back(e[0]);
        }
        
//         for(int i = 0; i<numCourses; i++)
//             if(inDegree[i]==0)
//             {q.push(i);}
        
//         while(!q.empty())
//         {
//             int t = q.front();
//             q.pop();
//             ans.push_back(t);
//             for(auto a: adj[t])
//                 if((--inDegree[a])==0)
//                     q.push(a);
//         }
        
//         if(ans.size()!=numCourses) return false;
        
//         return true;
        
        
        //-------------------------APPROACH - 2: Topo sort using DFS (Coloring algo) -------------------------------------//
        //Intuition: We color the node according to its status:
        // 0 - not visited
        // 1 - visited and its adj nodes are currently in process being DFS traversed one by one 
        // 2 - visited and all adjacents also traversed
        
        //So if a node is visited again while its adjacent's DFS traversal is in progress(i.e.its colored 1), a loop exists.
        
        vector<int> visited(numCourses);
        
        for(int i = 0; i<numCourses; i++)
            if(!visited[i] && isCyclic(i,visited,adj))
                return false;
        
        return true;
    }
};