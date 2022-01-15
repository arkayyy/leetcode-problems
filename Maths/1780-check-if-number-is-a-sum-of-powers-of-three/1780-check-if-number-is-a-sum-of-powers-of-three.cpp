class Solution {
public:
    bool util(int n, int p) {
    if (n == 0)
        return true;
    if (p > n)
        return false;
    return util(n, p * 3) || util(n - p, p * 3);
}
    bool checkPowersOfThree(int n) {
        
        return util(n,1);
    }
};