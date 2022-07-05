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
    bool circularArrayLoop(vector<int>& nums) {
        if(nums.size()==1) return false;
        // bool ans = false;
        // vector<int> visited(nums.size(),0);
        // for(int i = 0; i<nums.size();++i)
        // {
        //     cout<<"loop from "<<i<<endl;
        //     ans = ans || util(i,(nums[i]>0),nums,visited);
        //     cout<<endl;
        // }
        // return ans;
        
        unordered_map<int,vector<int>> adj;
        for(int i = 0; i<nums.size(); ++i)
        {
            int next = i + nums[i];
            
            if(next<0)
            {
                next = nums.size() - (abs(next)%nums.size());
            }
            else
            {
                next = next % nums.size();
            }
            cout<<i<<" "<<next<<endl;
            if(next!=i && ((nums[next]>0 && nums[i]>0) || (nums[next]<0 && nums[i]<0)))
                adj[i].emplace_back(next);
        }
        
        // for(auto a: adj)
        // {cout<<a.first<<"->";
        //     for(auto ad: a.second) cout<<ad<<" ";
        //     cout<<endl;
        // }
            
            
        vector<int> visited(nums.size(),0);
        
        for(int i = 0; i<nums.size(); i++)
        {
            //fill(visited.begin(),visited.end(),0);
            if(!visited[i] && isCyclic(i,visited,adj))
                return true;
        }
            
        
        return false;
    }
};