class Solution {
public:
    //ALGO: We store the last index of a, b and c. For all 3 letters in this substring, we need to take the minimum of the last indexes of a, b and c.
    //the number of substrings till this index from the min(last indexes of a,b and c) will be = 1+min(last index of a,b and c)
    int numberOfSubstrings(string s) {
        vector<int> lastIdx(3,-1);
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            lastIdx[s[i] - 'a'] = i;
            ans += 1 + min({lastIdx[0], lastIdx[1], lastIdx[2]});
        }
        return ans;
    }
};