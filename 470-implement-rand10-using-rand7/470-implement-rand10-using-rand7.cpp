// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    //EXPLANATION: https://leetcode.com/problems/implement-rand10-using-rand7/discuss/150301/Three-line-Java-solution-the-idea-can-be-generalized-to-%22Implement-RandM()-Using-RandN()%22
    int rand10() {
        int res = 40;
        while(res>=40)
        {
            res = 7*(rand7()-1) + (rand7()-1);
        }
        return res%10 + 1;
    }
};