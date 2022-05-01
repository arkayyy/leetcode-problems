class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //after sorting, the strings at beginning and end of the array will be the two most lexicographically different strings
        sort(strs.begin(),strs.end());
        int i = 0;
        string ans = "";
        while(i<min(strs[0].size(),strs.back().size()))
        {
            if(strs[0][i]!=strs.back()[i])
                break;
            ans+=strs[0][i], ++i;
        }
        return ans;
    }
};