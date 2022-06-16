class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
//         queue<int> bfs;
//         vector<int> coloring(graph.size(),-1);
        
       
//         int currcolor;
//         for(int k=0;k<graph.size();k++)
//         {  if(coloring[k]==-1) 
//             {
//                 bfs.push(k);
//                 coloring[k]=currcolor+2;
//                 while(!bfs.empty())
//                 {
//                     int t = bfs.front();
//                     bfs.pop();
//                     currcolor = coloring[t];
//                     for(auto i:graph[t])
//                     {
//                         if(coloring[i]!=-1 && coloring[i]==coloring[t])
//                             return false;

//                         if(coloring[i]==-1)
//                         {
//                             coloring[i]=coloring[t]+2;

//                             bfs.push(i);
//                         }

//                     }
//                 }
//             }
                
        
//         }
//         return true;
        
        vector<int> color(graph.size(),0);
        queue<int> q;
        for(int i = 0; i<graph.size(); ++i) 
        {   if(color[i]!=0)continue;
            q.push(i);
            color[0] = 1;
            while(!q.empty())
            {
                int t = q.front(); q.pop();
                for(auto a:graph[t])
                {        if(color[a]!=0 && color[a]==color[t]) return false;
                        else if(color[a]==0) {color[a] = color[t]==1?2:1; q.push(a);}
                }
            }
        }
        return true;
    }
};