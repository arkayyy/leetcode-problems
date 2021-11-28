class Solution
{
public:
    string multiply(string num1, string num2)
    {

        if (num1 == "0" || num2 == "0")
            return "0";
        int m = num1.length(), n = num2.length();
        vector<int> result((m * n) + 1, 0);

        string n1 = num1, n2 = num2;

        if (m > n)
        {
            n1 = num1, n2 = num2;
            m = n1.length();
            n = n2.length();
        }
        else
        {
            n1 = num2, n2 = num1;
            m = n1.length();
            n = n2.length();
        }
        reverse(n1.begin(), n1.end());
        reverse(n2.begin(), n2.end());

        int p = 0;

        for (int i = 0; i < n; i++)
        {
            int carry = 0;

            int j;
            for (j = 0; j < m; j++)
            {
                if (isZero && n1[j] != '0')
                    isZero = false;
                int t = (result[p + j] + ((n2[i] - '0') * (n1[j] - '0')) + carry);
                int d = t % 10;
                carry = t / 10;
                result[p + j] = d;
            }
            if (carry) //if carry is still left(not zero), then attaching it up to our result
                result[p + j] = carry;

            p++;
        }

        string ans = "";

        bool firstBit = false;

        for (int i = (m * n); i >= 0; i--)
        {
            if (result[i] == 0 && !firstBit)
            {
                continue;
            }
            else
                firstBit = true;

            ans += (char)(result[i] + '0');
        }

        return ans;
    }
};