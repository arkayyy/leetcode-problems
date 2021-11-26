class Solution
{
public:
    string toHex(int num)
    {
        if (num == 0)
            return "0";
        unordered_map<int, char> mp;

        mp[10] = 'a';
        mp[11] = 'b';
        mp[12] = 'c';
        mp[13] = 'd';
        mp[14] = 'e';
        mp[15] = 'f';

        string ans = "";

        unsigned int n = num;

        while (n)
        {
            //just like for a decimal number, in order to extract its digits from the last,
            //we modulo it with 10 (thats the last digit) and divide with 10 simultaneously.
            int rem = n % 16; //here for hex we are modulo with 16

            if (rem > 9)
                ans += mp[rem];
            else
                ans += to_string(rem);
            n /= 16; //and also dividing by 16
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};