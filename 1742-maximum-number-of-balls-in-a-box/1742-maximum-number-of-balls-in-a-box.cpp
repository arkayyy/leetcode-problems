class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        //INTUITION: The highLimit can go upto 99999, so the max sum of digits can be 45
        
        //ALGO: We make a count array of 46 size, and increase the count of each sum of digits occured. At last returning the frequency of sum that occured the most times
        
        int cnt[46] = {0};
        
        for(int i = lowLimit; i<=highLimit; i++)
        {
            int s = 0, n = i;
            while(n)
            {
                s+=n%10;
                n/=10;
            }
            ++cnt[s];
        }
        
        return *max_element(begin(cnt), end(cnt));
    }
};