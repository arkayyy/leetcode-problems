// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find number of strongly connected components in the graph.

    void dfs(int v, vector<int> adj[], vector<bool> &visited, stack<int> &st)
    {
        visited[v] = true;

        for (auto i : adj[v])
        {
            if (!visited[i])
                dfs(i, adj, visited, st);
        }
        st.push(v);
    }

    void dfsUtil(int v, map<int, vector<int>> &mp, vector<bool> &visited)
    {
        visited[v] = true;

        for (auto i : mp[v])
        {
            if (!visited[i])
                dfsUtil(i, mp, visited);
        }
    }

    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> st;
        vector<bool> visited(V, false);

        //doing DFS and storing all elements in stack. so the element that is visited at the very last appears on top of the stack
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                dfs(i, adj, visited, st);
        }

        //reversing all the edges of the graph (transpose of the graph)
        map<int, vector<int>> mp;

        for (auto i = 0; i < V; i++)
        {
            for (auto j : adj[i])
            {
                mp[j].push_back(i);
            }
        }

        fill(visited.begin(), visited.end(), false);
        int cnt = 0;

        //doing DFS on the reversed graph, starting from the elements popped from the stack.
        while (!st.empty())
        {
            int v = st.top();
            st.pop();
            if (!visited[v])
            {
                cnt++;
                dfsUtil(v, mp, visited);
            }
        }

        return cnt;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends