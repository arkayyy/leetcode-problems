class Solution {
public:
    bool canChange(string start, string target) {
        int lcnt = count(start.begin(),start.end(),'L');
        int rcnt = count(start.begin(),start.end(),'R');
        int lcnt1 = count(target.begin(),target.end(),'L');
        int rcnt1 = count(target.begin(),target.end(),'R');
        if(lcnt!=lcnt1 || rcnt!=rcnt1) return false;
        int sum = 0;
        vector<int>larr(start.size()), rarr(start.size());
        for(int i = start.size()-1; i>=0; --i)
        {
            if(start[i]=='R') sum = 0;
            sum+=start[i]=='L';
            larr[i] = sum;
        }
        sum = 0;
        for(int i = 0; i<start.size(); ++i)
        {
            if(start[i]=='L') sum = 0;
            sum+=start[i]=='R';
            rarr[i] = sum;
        }

        for(int i = 0; i<target.size(); ++i)
        {
            if(target[i]=='L')
                {if(!larr[i]) return false;}
            else if(target[i]=='R')
                {if(!rarr[i]) return false;}
        }
        
        return true;
    }
};