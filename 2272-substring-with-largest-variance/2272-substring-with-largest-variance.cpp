class Solution {
public:
    int largestVariance(string s) {
        int ans = 0;
        set<char> chars(s.begin(), s.end());
        for(auto ch1: chars)
            for(auto ch2: chars)
            {
                int curr = 0, presentCh2 = false, firstCh2 = false;
                for(auto ch:s)
                {
                    curr = max(curr,-1) + (ch==ch1);
                    if(ch==ch2)
                    {
                        presentCh2 = true;
                        if(firstCh2 && curr>=0) firstCh2 = false;
                        else if(--curr<0) firstCh2 = true;
                    }
                    ans = max(ans,(presentCh2?curr:0));
                }
            }
        return ans;
    }
};