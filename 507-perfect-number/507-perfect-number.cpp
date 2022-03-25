class Solution {
public:
    bool checkPerfectNumber(int num) {
        unordered_set<int> s = {6, 28, 496, 8128, 33550336};
        return s.count(num);
    }
};