class Solution {
public:
    //INTUITION: We store and process all edges in greedy fashion, trying to eliminate the one with most dist. at first (to create Minimum Spanning Tree)
    int getParent(vector<int>& parents, int idx){
        if(parents[idx]==idx){
            return idx;
        }
        parents[idx] = getParent(parents, parents[parents[idx]]);
        return parents[idx];
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
         int n = points.size();
        vector<int> parents(n);        
        for(int i = 0; i<n;i++) parents[i] = i;//initially storing parent of every node as itself to avoid error
        int ans = 0;
        int edges = 0;
        priority_queue<vector<int>> pq;
        //pushing all n-1 edges into max heap in form of (edge distance, node1, node2)
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(i!=j){
                     pq.push({-1*(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])), i, j});
                }
            }
        }
        
        while(edges!=n-1){ //until all n-1 edges are processed
            vector<int> edge = pq.top(); //GREEDY...getting the edge with most distance, trying to eliminate that first so that we can minimise the most unnecessary distance
            int p1 = getParent(parents, edge[1]);
            int p2 = getParent(parents, edge[2]);
            if(p1!=p2){
                ans += -1*edge[0]; //subracting dist between the 2 points, since it had already been added...
                //we basically only keep the distance from edge[1] to its parent p1 and that of edge[2] to its parent p2, thereby eliminating the dist b/w edge[1] and edge[2]
                parents[p1] = p2; 
                edges++;
            }
            pq.pop();
        }
        return ans;
    }
};