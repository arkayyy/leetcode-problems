class Solution {
public:
    int addDigits(int num) {
        if(num<10) return num;
        
        int copy = num;
        int sum = 0;
        while(copy)
        {
            sum+= copy%10;
            copy /= 10;
        }
        
        return addDigits(sum);
    }
};