class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        //INTUITION: Ants colliding and changing direction doesn't really matter because all ants are moving at the same speed
        //e.g. say the left boundary is at 0 and right at 5. One ant was moving towards right and one towards left, and they collide at 2.
        //Even then, one ant would still be moving towards right boundary from 2 and one towards the left boundary.
        //This is because all ants are identical, so it doesn't matter even if they collide and change directions with each other.
        
        
        //ALGO: Find the maximum time that any ant would take to reach the left boundary and right boundary. Return this maximum time.
        int ans = 0;
        for(auto i: left)
            ans = max(ans,i);
        for(auto i: right)
            ans = max(ans, n-i);
        
        return ans;
    }
};