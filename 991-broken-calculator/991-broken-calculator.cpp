class Solution {
public:

    int brokenCalc(int startValue, int target) {
        //ALGO: Greedy approach, we move reverse from target to startValue.
        //So applying reverse logic, at every step we can:
        //(i) divide target / 2 if target is even
        //(ii) add target by 1 if target is odd, in order to make it even
        int targ = target;
        int steps = 0;
        while(targ>startValue)
        {
            if((targ&1)==1)
                ++targ;
            else
                targ/=2;
            steps++;
        }
        return steps+(startValue-targ); //adding startValue-target, to handle the case if target stops at a value less than startValue, then we have to add 1 that many times
    }
};