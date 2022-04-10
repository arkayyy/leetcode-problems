class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> pts;
        for(auto op: ops)
        {
            if(op[0]=='C')
            {
                pts.pop_back();
            }
            else if(op[0]=='D')
            {
                pts.push_back(pts.back()*2);
            }
            else if(op[0]=='+')
            {
                pts.push_back( *(pts.rbegin()) + *(pts.rbegin()+1));
            }
            else
            {
                int n = 0;
                for(auto d:op)
                {
                    if(d=='-') continue;
                    n = n*10 + (d-'0');
                }
                pts.push_back(op[0]=='-'?(0-n):n);
            }
        }
        
        return accumulate(pts.begin(), pts.end(),0);
    }
};