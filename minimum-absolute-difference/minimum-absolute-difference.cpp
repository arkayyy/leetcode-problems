class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        
        int minDiff = INT_MAX;
        
        for(int i=0;i<arr.size()-1;i++)
        {
            minDiff = min(minDiff, abs(arr[i]-arr[i+1]));
        }
        
        for(int i = 0;i<arr.size()-1;i++)
        {
            if(abs(arr[i]-arr[i+1])==minDiff)
                ans.push_back({arr[i],arr[i+1]});
        }
        
        
        return ans;
    }
};