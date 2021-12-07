class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int cnt[] = {0,0};
        for(auto i:position)
            cnt[(i&1)]++;
        //since moving 2 positions takes no cost, we would try to stack up all odd and all even position coins together. 
        //and then whichever stack (even or odd) has less coins, coins from that stack will be transported to the other.
        return min(cnt[0],cnt[1]);
    }
};