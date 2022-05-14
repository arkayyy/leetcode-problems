class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(),tiles.end());
        int ans = 0, overlap = 0, j = 0, prevRight = 0;
        for(int i = 0; i<tiles.size(); i++)
        {
            int left = tiles[i][0];
            int right = left+carpetLen-1;
            if(i>0) overlap -= (min(prevRight, tiles[i-1][1])-tiles[i-1][0]+1);
            if (j > 0 && tiles[j-1][1] > prevRight) overlap += (min(right, tiles[j-1][1]) - prevRight);
            while (j < tiles.size() && tiles[j][0] <= right) 
            {
                overlap += (min(right, tiles[j][1]) - tiles[j][0] + 1);
                ++j;
            }
            
            prevRight = right;
            ans = max(overlap,ans);
        }
        return ans;
    }
};