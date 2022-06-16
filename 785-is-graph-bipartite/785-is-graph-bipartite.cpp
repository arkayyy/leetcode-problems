class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //INTUITON: To check if all nodes can be colored using only 2 colors, with no 2 adjacent nodes having the same color.
        
        vector<int> color(graph.size(),0);
        queue<int> q;
        for(int i = 0; i<graph.size(); ++i) //running loop to ensure all disconnected components are also checked
        {   if(color[i]!=0)continue;
            q.push(i);
            color[0] = 1;
            while(!q.empty())
            {
                int t = q.front(); q.pop();
                for(auto a:graph[t])
                {        if(color[a] && color[a]==color[t]) return false; //if both adjacent nodes and colored the same color before
                        else if(color[a]==0) {color[a] = color[t]==1?2:1; q.push(a);} //if uncolored adjacent is found
                }
            }
        }
        return true;
    }
};