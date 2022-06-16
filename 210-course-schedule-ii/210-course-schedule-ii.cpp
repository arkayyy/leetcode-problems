class Solution {
public:

    void dfs(int v, unordered_map<int,vector<int>>& adj, vector<bool>& visited, stack<int>& st)
    {
        visited[v] = true;
        for(auto a: adj[v])
        {
            if(!visited[a])
                dfs(a,adj,visited,st);
        }
        st.push(v);
    }
    
    bool hasCycle(int n, unordered_map<int,int>& pos, unordered_map<int,vector<int>>& adj)
    {   
       for (int i = 0; i < n; i++) {
        for (auto a : adj[i]) {
 
            // If parent vertex
            // does not appear first
            if (pos[i] > pos[a]) {
 
                // Cycle exists
                return true;
               }
            }
        }
 
        // Return false if cycle
        // does not exist
        return false;
    }
    
    bool isCyclic(int v, unordered_map<int,vector<int>>&adj, vector<int>&visited, int n, stack<int>&st)
	{
	    if(visited[v]==1) return true;
	    
	    if(visited[v]==0)
	    {
	        visited[v] = 1;
	        for(auto a: adj[v])
	            if(isCyclic(a,adj,visited,n,st)) 
	            return true;
	    }
	    if(visited[v]!=2)st.push(v);
	    visited[v] = 2;
	    return false;
	}

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        
//         if(ans.size()!=numCourses) return {};
        
//         return ans;
        
        
        //-------------------------APPROACH - 2: Topo sort using DFS -------------------------------------//
        //TC:O(N) SC:O(2N)
        //Additional step in DFS: Cycle checking (done by first storing index of all nodes in topoligical sorted order, then verifying if any node appears before its parent does in the topo sorted order)
        
        // pos tores the position of
        // vertex in topological order
//         unordered_map<int, int> pos;
        
//         vector<bool> visited(numCourses,false);
        stack<int> st;
//         for(int i = 0; i<numCourses; i++)
//             if(!visited[i])
//                 dfs(i,adj,visited,st);
        
//         int idx = 0; //for index in topological order
//         while(!st.empty())
//         {
//             pos[st.top()] = idx++; 
//             ans.push_back(st.top());
//             st.pop();
//         }
        
        
//         if(hasCycle(numCourses,pos,adj))
//             return {};
        
        
        //DFS Approach 2 - Cycle Detection and Visited array method:-
       vector<int> visited(numCourses,0);
	   for(int i = 0; i<numCourses; ++i)
	    if(!visited[i] && isCyclic(i,adj,visited,numCourses,st))
	        return {};
    while(!st.empty()) {ans.push_back(st.top());st.pop();}
	   return ans;

    }
};