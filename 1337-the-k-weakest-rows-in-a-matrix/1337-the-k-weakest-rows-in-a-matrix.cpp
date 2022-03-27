class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<vector<int>> arr;
        for(int i = 0; i<mat.size(); i++)
        {
            int s = 0;
            for(auto m: mat[i])
                s+=(m==1);
            arr.push_back({s,i});
        }
        sort(arr.begin(),arr.end());
        vector<int> ans;
        for(int i = 0; i<k; i++)
            ans.push_back(arr[i][1]);
        
        return ans;
    }
};