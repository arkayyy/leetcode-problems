class Solution {
public:
    int lis(vector<int> &arr)
    {
        if(arr.size()<=1) return arr.size();
        vector<int> dp;
        for(auto a: arr)
        {
            auto it = upper_bound(dp.begin(),dp.end(),a);
            if(it==dp.end()) dp.push_back(a);
            else *it = a;
        }
       
        return dp.size();
    }
    int kIncreasing(vector<int>& arr, int k) {
       int ans = 0; 

        //INTUITION: for every k separated subsequence in the array we calculate the lis and subtract it from size of the subsequence in order to get the min no. of changes to be done to make the array non-decreasing
        for(int i = 0; i<k; i++)
        {
            vector<int> curr;
            int j = i;
            while(j<arr.size())
            {
                curr.push_back(arr[j]);
                j+=k;
            }
            cout<<lis(curr)<<endl;
            ans += curr.size()-lis(curr);
        }
        return ans;
    }
};