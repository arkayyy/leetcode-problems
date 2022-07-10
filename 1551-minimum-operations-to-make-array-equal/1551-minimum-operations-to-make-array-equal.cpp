class Solution {
public:
    int minOperations(int n) {
        int mid = (1+(2*(n-1)+1))/2;
        int steps = 0;
        for(int i = 1; i<mid; i+=2)
            steps+=(mid-i);
        return steps;
    }
};