class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, open = 0;
        for (char& c: s) {
            if (c == '(')
                ans = max(ans, ++open);
            else if (c == ')')
                --open;
        }
        return ans;
    }
};