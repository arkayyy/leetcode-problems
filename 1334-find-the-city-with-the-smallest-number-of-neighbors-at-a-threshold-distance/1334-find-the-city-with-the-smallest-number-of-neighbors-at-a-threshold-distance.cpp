class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //Floyd warshall to find shortest distance between every pair of vertex in the graph
        vector<vector<int>> graph(n,vector<int>(n,INT_MAX));
        for(int i = 0; i<n; ++i) graph[i][i] = 0;
        for(auto e: edges)
            graph[e[0]][e[1]] = e[2], graph[e[1]][e[0]] = e[2];
        for(int k = 0; k<n; ++k)
            for(int i = 0; i<n; ++i)
            {
                for(int j = 0; j<n; ++j)
                {
                    if(graph[i][k]==INT_MAX || graph[k][j]==INT_MAX) continue;
                    if(graph[i][j]>graph[i][k]+graph[k][j])
                        graph[i][j] = graph[i][k]+graph[k][j];
                }
            }
                
        int minCnt = INT_MAX, ans = -1;
        for(int i = n-1; i>=0; --i) //Going from n-1 to 0 because given in the ques:  If there are multiple such cities, return the city with the greatest number.
        {
            int cnt =0 ;
            for(int j = 0; j<n; ++j)
                { if(i!=j && graph[i][j]<=distanceThreshold) ++cnt; }
            if( cnt<minCnt)
                {minCnt = cnt; ans = i;}
        }
        return ans;
    }
};