class Solution {
public:
    //INTUITION: gcd always gives the largest number that can divide both numbers. So we take gcd of all frequencies in order to find a number of which length all groups can be formed.
    //if array is 1,1,2,2,2,2...we can find that the frequency of 1 is 2, and that of 2 is 4. We can choose 2 length groups of both 1 and 2,i.e. [1,1][2,2][2,2]
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> freq;
        for(auto card: deck)
        {
            freq[card]++;
        }
        int gcdAll = -1;
        for(auto f: freq)
        {
            if(gcdAll == -1) gcdAll = f.second;
            else gcdAll = gcd(gcdAll, f.second);
        }
        return gcdAll>=2;
    }
};