class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
        if(rowIndex == 1) return {1,1};
        
        vector<int> prev({1,1});
        
        int i = 1;
        vector<int> temp;
        while((i++)<rowIndex)
        {
            temp.clear();
            temp.push_back(1);
            for(int j=0; j<prev.size()-1; j++)
                temp.push_back(prev[j]+prev[j+1]);
            temp.push_back(1);
            prev = temp;
        }
        
        return prev;
    }
};