class Solution {
public:
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