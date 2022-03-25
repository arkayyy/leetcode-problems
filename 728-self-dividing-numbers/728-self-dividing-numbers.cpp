class Solution {
public:
    bool check(int num)
    {
        int n = num;
        while(n)
        {
            if(n%10==0 || num%(n%10)!=0)
                return false;
            n/=10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i<=right; i++)
            if(check(i))
                ans.push_back(i);
        return ans;
    }
};