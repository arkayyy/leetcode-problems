class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        ans.push_back({1});
        if(numRows==1) return ans;
        ans.push_back({1,1});
        if(numRows==2) return ans;
        int size = 3;
        numRows-=2;
        vector<int> prev({1,1});
        while(numRows--)
        {
            vector<int> curr;
            curr.reserve(size++); //every row the number of elements increases by 1. Reserving only that much space to save space
            curr.push_back(1);
            for(int i = 0; i<prev.size()-1;i++)
                curr.push_back(prev[i]+prev[i+1]);
            curr.push_back(1);
            prev = curr;
            ans.push_back(curr);
        }
        
        return ans;
        
    }
};