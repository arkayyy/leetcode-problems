class Solution {
public:
    //NOTE: Seeing the time complexity constraints, we can't do a O(N^2) complexity soln by processing all substrings.
    
    //INTUITON: We can check the string for every pair of character, because the largest variance can always be in between any two characters only, not more than that.
    //ALGO: For every pair of character, we can find the maximum difference in frequency (max. variance) by using a cumulative frequency method, wherein we increase the recurring frequency for one character and decrease it for another.
    //So at any point, the maximum value of this recurring frequency will be updated with our answer
    int largestVariance(string s) {
        // int ans = 0;
        // set<char> chars(s.begin(), s.end());
        // for(auto ch1: chars)
        //     for(auto ch2: chars)
        //     {
        //         int curr = 0, presentCh2 = false, firstCh2 = false;
        //         for(auto ch:s)
        //         {
        //             //we increase the curr freq if current character == ch1, and decrease it if current character == ch2
        //             curr = max(curr,-1) + (ch==ch1); //minimum the difference in frequency can go is -1
        //             if(ch==ch2)
        //             {
        //                 presentCh2 = true;
        //                 if(firstCh2 && curr>=0) firstCh2 = false;
        //                 else if(--curr<0) firstCh2 = true; //if recurring frequency goes negative, means we can't include any more ch2's as part of the current substring, we can only include ch1 next. 
        //                 //Or if we include next ch2, we'd have to do this as a part of the next considered substring.
        //             }
        //             ans = max(ans,(presentCh2?curr:0));
        //         }
        //     }
        // return ans;
        
        
        //=================Alternative: by counting frequency of both characters separately==========================//
        set<char> chars(s.begin(),s.end());
        int ans = 0;
        for(auto ch1: chars)
            for(auto ch2: chars)
            {
                int freqCh1 = 0, freqCh2 = 0, prevCh2 = 0;
                for(auto ch:s)
                {
                    if(ch==ch1) ++freqCh1; if(ch==ch2) ++freqCh2;
                    if(freqCh2>0) {ans = max(ans, freqCh1 - freqCh2); } //to consider variance there should be both characters present
                    else if(freqCh2==0 && prevCh2) { //if previously occured ch2 can be considered as a part of current variance calculation
                        ans = max(ans,freqCh1 - freqCh2 - 1); //freqCh2==0 so effectively freqCh1 - 1
                    }
                    if(freqCh2 > freqCh1) //variance can't be more than -1..so once freqCh2 = freqCh1 + 1, the variance becomes -1 and so can't move any further without resetting the frequencies of both characters
                    {
                        freqCh1 = freqCh2 = 0;
                        prevCh2 = true;//current ch2 can also be a part of the next substring variance calculation
                    }
                }
            }
        return ans;
    }
};