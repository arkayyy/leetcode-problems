class Solution {
public:
    int minOperations(vector<string>& logs) {
        int folds = 0;
        for(auto log: logs)
        {
            if(log=="./")
            {
                continue;
            }
            else if(log=="../")
            {
                if(folds==0) continue;
                --folds;
            }
            else
            {
                folds++;
            }
        }
        
        return folds;
    }
};