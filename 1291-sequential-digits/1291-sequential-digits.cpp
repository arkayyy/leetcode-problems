class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> curr({12,23,34,45,56,67,78,89});
        int idx = 1;
        int tenss = 100;
        vector<int> ans;
        for(auto n: curr)
            if(n>=low && n<=high)
                ans.push_back(n);
        bool flag =  false;
        while(idx<curr.size())
        {
            int j = idx;
            int tens = tenss;
            int m = 1;
            while(j<curr.size()) 
            {   
                curr[j] = (curr[j]+(tens*(m++)));
                if(curr[j]>=low && curr[j]<=high)
                    ans.push_back(curr[j]);
                if(curr[j]>high)
                {flag = true; break;}
                j++;
            }
            if(flag) break;
            idx++;
            tenss*=10;
            
        }
        return ans;
    }
};