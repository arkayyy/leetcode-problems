class Solution {
public:
    //SIMPLE MATHS
    int totalMoney(int n) {

        int sumOf7 = 28;
        int ans = 28;
        int toDecrease = 0;
        int toIncrease = 7;
        int prevWeekSaving = 28;
        
        int weeks = n/7;
        
        for(int i=1;i<weeks+1;i++)
        {
            int temp = (prevWeekSaving - (++toDecrease) + (++toIncrease));
            ans += temp;
            prevWeekSaving = temp;
        }
        
        if((n%7)==0)
            return (ans-prevWeekSaving);
        
        int rem = 7-(n%7);
        while(rem--)
            ans -= (toIncrease--);
        
        return ans;
        
    }
};