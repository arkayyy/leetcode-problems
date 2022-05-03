class Solution {
public:
    //INTUITION: Similar to problems like Reverse Pairs, which can all be solved using Merge Sort.
    vector<int> ans;
    vector<pair<int,int>> temp;
    void merge(int l, int m, int r, vector<pair<int,int>>& nums)
    {
        if(l>=r) return;
        int i = l, j = m+1;
        int k = l;
        int cnt = 0;
        while(i<=m && j<=r)
        {
            if(nums[i].first<=nums[j].first)
                {
                ans[nums[i].second]+=cnt;
                temp[k++] = nums[i++];  }
            else 
                { 
                cnt++;
                temp[k++] = nums[j++];}
        }
        while(i<=m)
        {
            ans[nums[i].second]+=cnt;
            temp[k++] = nums[i++];
        }
        while(j<=r)
            temp[k++] = nums[j++];
        
        for(int t = l; t<=r; t++) nums[t] = temp[t];
    }
    void mergeSort(int l, int r, vector<pair<int,int>> & nums)
    {
        if(l>=r) return;
        int mid = (l+r)/2;
        mergeSort(l,mid,nums);
        mergeSort(mid+1,r,nums);
        merge(l,mid,r,nums);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> inp;
        for(auto i = 0; i<nums.size();i++) inp.push_back({nums[i],i});
        
        temp = vector<pair<int,int>> (nums.size());
        ans = vector<int> (nums.size(),0);
        mergeSort(0,nums.size()-1,inp);
        for(auto n: ans) cout<<n<<" ";
        return ans;
    }
};