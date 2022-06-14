class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long ans = 0, c1 = 0, c2 = 0;
        for(auto& ch: text)
        {
            if(ch==pattern[1])//NOTE: ch==pattern[1] has to be checked bfore ch==pattern[0], for the edge case where pattern[0]==pattern[1].
                //So that we don't add extra count of patterns.
            { 
                ans+=c1; //because this pattern[1] can form pattern with all the previous pattern[0] encountered in the string
                ++c2; //counting pattern[1]
            }
            if(ch==pattern[0]) ++c1; //coutning pattern[0]
        }
        //If we add pattern[0], it would be the most optimal to add it to be very beginning of the string so that it forms pattern with all pattern[1]'s present after it
        //If we add pattern[1], it would be the most optimal to add it to the very last of the string so that it forms pattern with all pattern[0]'s present before it
        return ans+max(c1,c2); //so whichever has the max count, we add the other character(which has smaller count), so that it can form pattern with the max frequency character for the maximum no of times
    }
};