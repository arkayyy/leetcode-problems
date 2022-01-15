class Solution {
public:
    
    // XXXXXX  --  DFS APPROACH DOESN'T WORKKKKKK (not even with DP), explanation: https://leetcode.com/problems/jump-game-iv/discuss/1316467/Jump-Game-iv-or-Why-DFS-will-not-work-Explained
    
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> elems;
        
        for(int i = 0; i<arr.size();i++)
            elems[arr[i]].push_back(i);

        vector<bool> visited(arr.size(),false);
        visited[0] = true;
        
        int steps = 0;
        //Doing BFS (level order traversal):-
        //Contents of the upcoming level: i-1, i+1 and all indexes that have equal element as i and are unvisited
        queue<int> q;
        q.push(0);
        
        while(!q.empty())
        {
            int len = q.size();
            for(int i=0;i<len;i++)
            {
                int idx = q.front(); q.pop();
                if(idx==arr.size()-1) //if we have reached end of the array
                    return steps;
                
                vector<int>& next = elems[arr[idx]]; //taking a reference to the vector of indexes of all elements equal to arr[idx] stored in the map
                next.push_back(idx-1); next.push_back(idx+1); // adding for idx-1 and idx+1 index
                for(auto j: next)
                {
                    if(j>=0 && j<arr.size() && !visited[j])
                    {
                        visited[j] = true; q.push(j);
                    }
                }
                next.clear(); //important step so that already looked up indices are removed from the map, so reduces overall complexity. Reduces complexity from O(N^2) to O(N)
                //explanation: https://leetcode.com/problems/jump-game-iv/discuss/502699/JavaC%2B%2B-BFS-Solution-Clean-code-O(N)
            }
            steps++;
        }
        
        return steps;
    }
};