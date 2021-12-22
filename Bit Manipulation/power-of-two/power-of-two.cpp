class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        // neg number can't be a power of 2
        if (n <= 0)
            return false;

        int cnt = 0;
        // counting number of bits in number
        while (n)
        {
            cnt++;
            n = (n & (n - 1));
        }
        // if number of bits in the binary representation of the number is 1, then it has to be a power of 2
        return (cnt == 1 ? true : false);
    }
};