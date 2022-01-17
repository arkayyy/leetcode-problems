class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int steps = 0;
        while(target && maxDoubles)
        {
            if(target%2==0) //we apply greedy, so we divide by 2 as soon as we find the biggest number divisible by 2
            {target/=2; maxDoubles--;}
            else 
            {target--;}
            steps++;
        }
        return steps+target-1; // -1 is done because our last number needs to be 1 always
    }
};