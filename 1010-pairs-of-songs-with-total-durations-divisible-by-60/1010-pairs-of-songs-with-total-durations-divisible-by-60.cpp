class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        //any number %60 can range from 0 to 59 only.
        vector<int> c(60);
        int res = 0;
        for (int t : time) {
            
            res += c[(540 - t) % 60]; //the number in place of 540 here can be any multiple of 60 above 500, since time[i] can go max upto 500
            c[t % 60] += 1;
        }
        return res;
    }
};