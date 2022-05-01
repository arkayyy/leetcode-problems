class Solution {
public:
    //INTUITION: Marking the last occurence of each number. Because only if the current index and last element having the same number is included
    //it will give the min. length of consecutive cards
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> mp;
        int ans = INT_MAX;
        for(int i = 0; i<cards.size(); i++)
        {
            if(mp.find(cards[i])!=mp.end())
            {ans = min(ans, i-mp[cards[i]]+1); }
         mp[cards[i]] = i;
        }
        return ans==INT_MAX?-1:ans;
    }
};