class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        
            
        map<int, int> m;
        for (auto &t : trips)
            m[t[1]] += t[0], m[t[2]] -= t[0]; //adding number of passengers to the source, and removing that many no. of passengers from the destination
        for (auto &v : m)
            if ((capacity -= v.second) < 0) //decreasing capacity everytime for every location point(in km) and if at any time, capacity goes less than 0, we know it's not possible
                return false;
        return true;
    
        
    }
};