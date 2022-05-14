class Solution {
public:
    //INTUITION: It is logical to count the length beginning from the start of an white tile interval only. Because say the interval is (5,8) and the carpet length is 2. So if we start at 5 or 6 the effect would be same. 
    // and say (5,7) is white tiles and 8th is not, and again 9th is white. Now say the carpet length is 4. Now if we consider the carpet to cover 5,6,7,8 (3 white 1 gap) or 6,7,8,9 (3 white 1 gap). That's also same effect even with non-white gaps in the middle.
    
    //ALGO: We consider every interval's staring pt as a starting point for putting the carpet and keep updating the number of white tiles covered as found
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(),tiles.end());
        int ans = 0, whiteTilesCovered = 0, j = 0, prevRight = 0; //prevRight = previous carpet covering's rightmost index
        for(int i = 0; i<tiles.size(); i++)
        {
            int left = tiles[i][0];
            int right = left+carpetLen-1; //max index till which the carpet can cover if started from the current index (current index = starting point of current white tile interval)
            
            if(i>0) whiteTilesCovered -= (min(prevRight, tiles[i-1][1])-tiles[i-1][0]+1); //removing the previosly considered carpet covering
            if (j > 0 && tiles[j-1][1] > prevRight) whiteTilesCovered += (min(right, tiles[j-1][1]) - prevRight); //adding current carpet covering (appearing before currently considered interval only)
            while (j < tiles.size() && tiles[j][0] <= right) 
            {
                whiteTilesCovered += (min(right, tiles[j][1]) - tiles[j][0] + 1); //adding carpet covering for the currently considered interval
                ++j;
            }
            
            prevRight = right; 
            ans = max(whiteTilesCovered,ans); //updating max carpet covering of white tiles
        }
        return ans;
    }
};