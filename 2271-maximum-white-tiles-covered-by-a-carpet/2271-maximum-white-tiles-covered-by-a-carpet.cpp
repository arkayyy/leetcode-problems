class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(),tiles.end());
        int ans = 0;
        int i = 0, j = 0, covered = 0;
        while(ans<carpetLen && i<tiles.size())
        {
            if(tiles[j][0] + carpetLen > tiles[i][1])
            {
                covered += tiles[i][1] - tiles[i][0] + 1;
                ans = max(ans,covered);
                ++i;
            }
            else
            {
                int partialCovered = max(0,tiles[j][0] - tiles[i][0] + carpetLen);
                ans = max(ans, covered + partialCovered);
                covered -= tiles[j][1]-tiles[j][0] +1;
                ++j;
            }
        }
        return ans;
    }
};