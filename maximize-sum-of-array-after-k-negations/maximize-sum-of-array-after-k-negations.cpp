class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int negc = 0,mini=INT_MAX;
        vector<int> neg;
        
        int sum = 0;
        
        for(auto i:nums)
        {
            if(i<0) {neg.emplace_back(abs(i)); negc++;}
         
            mini = min(mini,abs(i));
            sum+=i;
        }
        
        sort(neg.begin(),neg.end(),greater<int>());
        
        int i=0;
        while((i<negc) && (k>0))
        {
            sum += (2*neg[i]);
            i++;
            k--;
        }
        
        if(k)
        {
            if((k&1)==1)
            {
                sum -= (2*(mini));
            }
        }
        
        return sum;
    }
};