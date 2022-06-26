class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> ans;
        vector<int> leftDecreasing(security.size(),0), rightIncreasing(security.size(),0);
        int decr = 1;
        leftDecreasing[0] = 1;
        for(int i = 1; i<security.size(); ++i)
        {
            if( security[i]<=security[i-1]) ++decr;
            else decr = 1;
            leftDecreasing[i] = decr;
        }
        int incr = 1;
        rightIncreasing[security.size()-1] = 1;
        for(int i = security.size()-2; i>=0; --i)
        {
            if(security[i]<=security[i+1]) ++incr;
            else incr = 1;
            rightIncreasing[i] = incr;
        }
        for(int i = 0; i<security.size(); ++i)
            if(leftDecreasing[i]-1>=time && rightIncreasing[i]-1>=time) 
                ans.emplace_back(i);
        
        return ans;
    }
};