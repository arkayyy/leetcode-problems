class Solution {
public:
    //INTUITION: Try to visit all rooms and check at last if any room is unvisited, means key is not found anywhere!
    
    //ALGO: Simple BFS
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> keyFound(rooms.size(),false);
        
        queue<int>q;
        q.push(0);
        keyFound[0] = true;
        while(!q.empty())
        {
            int room = q.front();
            q.pop();
            for(auto k: rooms[room])
                if(!keyFound[k])
                   {keyFound[k] = true; q.push(k);}
        }
        for(auto k: keyFound) if(!k) return false;
        
        return true;
    }
};