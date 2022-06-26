class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> pre(security.size()), suf(security.size());
        
        int decr = 0;
        for(int i = 0;i<security.size(); ++i)
        {
            if(i-1>=0 && security[i-1]>=security[i]) ++decr;
            else decr = 1;
            pre[i] = decr;
        }
        
        int incr = 0;
        for(int i = security.size()-1; i>=0; --i)
        {
            if(i+1<security.size() && security[i]<=security[i+1]) ++incr;
            else incr = 1;
            suf[i] = incr;
        }
        vector<int> ans;
        for(int i = 0; i<security.size(); ++i)
            if(pre[i]-1>=time && suf[i]-1>=time)
                ans.emplace_back(i);
        
        return ans;
    }
};