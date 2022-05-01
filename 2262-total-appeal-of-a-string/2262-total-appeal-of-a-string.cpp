class Solution {
public:
    //INTUITION: If we store the previous occurence index of each character, we can ensure that the substring between those two indexes will contain all unique letters.
    //ALGO: We keep on adding the length of these substrings
    long long appealSum(string s) {
    long long res = 0, cur = 0, prev[26] = {};
    for (int i = 0; i < s.size(); ++i) {
        cur += i  - prev[s[i] - 'a'] + 1; //length of substring b/w ith index and the index of previous occurence of same character at ith index
        prev[s[i] - 'a'] = i + 1; //marking the current occurence of this character as previous occurence index for the next occuring same character
        res += cur;
    }
    return res;
    }
};