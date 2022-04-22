class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.length()!=s2.length()) return false;
        if(s1==s2) return true;
        char c1,c2,c3,c4;
        int cntDiff = 0;
        for(int i = 0; i<s1.length(); i++)
        {
            if(s1[i]!=s2[i]) 
            {   cntDiff++;
                if(cntDiff==1) {c1 = s1[i], c2 = s2[i]; }
                if(cntDiff==2) {c3 = s1[i], c4 = s2[i]; }
            }
        }
        if(cntDiff!=2) return false;
        return (c1==c4 && c2==c3);
    }
};