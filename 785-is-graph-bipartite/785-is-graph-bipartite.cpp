class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> bfs;
        vector<int> coloring(graph.size(),-1);
        
       
        int currcolor;
        for(int k=0;k<graph.size();k++)
        {  if(coloring[k]==-1) 
            {
                bfs.push(k);
                coloring[k]=currcolor+2;
                while(!bfs.empty())
                {
                    int t = bfs.front();
                    bfs.pop();
                    currcolor = coloring[t];
                    for(auto i:graph[t])
                    {
                        if(coloring[i]!=-1 && coloring[i]==coloring[t])
                            return false;

                        if(coloring[i]==-1)
                        {
                            coloring[i]=coloring[t]+2;

                            bfs.push(i);
                        }

                    }
                }
            }
                
        
        }
        return true;
    }
};