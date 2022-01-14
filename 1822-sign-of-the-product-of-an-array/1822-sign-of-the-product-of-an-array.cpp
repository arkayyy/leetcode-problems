class Solution {
public:
    int arraySign(vector<int>& nums) {
        int countNegative = 0;
        bool hasZero = 0;
        for(auto n: nums)
        {
            if(n==0){hasZero = true; break;}
            if(n<0) countNegative++;
        }
        if(hasZero) return 0;
        
        if(countNegative&1) return -1; //if the array has odd number of negative nos. the product would be negative too
        
        return 1; 
    }
};