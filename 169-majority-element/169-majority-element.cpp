class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Moore's voting algorithm:-
        
        //INTUITION: since the major element is present more than half length of array, its net count will always be more than all the other elements count combined...
        
        //AALGO: We start with the first element and count as 1, as soon as a dissimilar element is found we decrease the count...
        //...as our count reaches 0, we reset the count to 1 and set the new element as candidate
        int major = -1, freq = 0;
        for(auto n: nums)
        {
            if(!freq) major = n, freq = 1;
            else freq += n==major?1:-1;
        }
        return major;
    }
};