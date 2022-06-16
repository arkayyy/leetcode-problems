// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	class disjoint_set
	{
	  public:
	  vector<int> parent, rank;
	  disjoint_set(int n)
	  {
	      parent = vector<int>(n); rank = vector<int>(n,0);
	      for(int i = 0; i<n; ++i) parent[i] = i;
	  }
	  int findParent(int v)
	  {
	      if(parent[v]==v) return v;
	      return parent[v] = findParent(parent[v]);
	  }
	  void unionBoth(int u, int v)
	  {
	      u = findParent(u), v = findParent(v);
	      if(u==v) return;
	      if(rank[u]<rank[v]) {
	          parent[u] = v;
	      }
	      else if(rank[u]>rank[v])
	      parent[v] = u;
	      else
	        parent[v] = u, ++rank[u];
	  }
	};
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // bitset<1000> mst;
        // vector<int> dist(V,INT_MAX);
        // vector<int> parent(V);
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        // pq.push({0,0}); //dist,node
        // parent[0] = -1;
        // dist[0] = 0;
        // while(!pq.empty())
        // {
        //     int u = pq.top().second; pq.pop();
        //     mst[u] = 1;
        //     for(auto a: adj[u])
        //     {
        //         int v = a[0], w = a[1];
        //         if(!mst[v] && w<dist[v])
        //         {
        //             parent[v] = u;
        //             dist[v] = w;
        //             pq.push({dist[v],v});
        //         }
        //     }
        // }
        // int ans = 0;
        // for(int i = 0; i<V; ++i)
        //     ans+= dist[i];
        // return ans;
        
        vector<vector<int>> edges;
        for(int i = 0; i<V;++i)
        {
            for(auto a: adj[i])
                edges.push_back({a[1],i,a[0]});
        }
            
        sort(edges.begin(),edges.end());
        disjoint_set d(V);
        int sumWeightsMST = 0;
        for(auto e: edges)
        {
            int u = e[1], v = e[2], w = e[0];
            if(d.findParent(u)==d.findParent(v)) continue;
            d.unionBoth(u,v);
            sumWeightsMST+=w;
        }
        return sumWeightsMST;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends