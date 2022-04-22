class Solution {
public:
    bool hasZero(int n)
    {
        while(n)
        {
            int d = n%10;
            if(d==0) return true;
            n = n/10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        int n1 = 1;
        int n2 =  n-1;
        while((hasZero(n1) || hasZero(n2)))
            --n2,++n1;
        return {n1,n2};
    }
};