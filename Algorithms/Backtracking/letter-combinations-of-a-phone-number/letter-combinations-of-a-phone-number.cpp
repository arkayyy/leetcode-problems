class Solution {
public:
    void util(string curr, int idx,string digits, unordered_map<int,vector<char>>& mp, vector<string>& ans)
    {
        if(idx==digits.length()) {ans.push_back(curr);return;}
        
        for(auto i: mp[digits[idx]-'0'])
        {
            util(curr+i, idx+1, digits,mp,ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
        unordered_map<int, vector<char>> mp;
        vector<string> ans;
        
        mp[2] = {'a','b','c'};
        mp[3] = {'d','e','f'};
        mp[4]={'g','h','i'};
        mp[5] = {'j','k','l'};
        mp[6] = {'m','n','o'};
        mp[7] = {'p','q','r','s'};
        mp[8] = {'t','u','v'};
        mp[9] = {'w','x','y','z'};
        
        util("",0,digits,mp,ans);
        
        return ans;
    }
};