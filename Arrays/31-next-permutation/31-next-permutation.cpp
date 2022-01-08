class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        // ALGO: Find the first non-increasing element starting from the back of the array. Swap the next element of this element, with the
        // just greater element found when moved starting from the back of the array.
        // In general suppose we have a series like 1,2,3,4,5. TO make the next greater permutation, we just swap the last 4 and 5.

        // Essentially we are doung the same thing in this question, except for more broader cases like 1,2,3,6,5,4. We swap 3 and 4 here and sort the...
        //...elements afer the initial position of 3 to give the final answer.

        int marker = INT_MAX; // marker for marking first non-increasing element starting from the back of the array.

        // finding the last increasing pair in the array , e.g. in 1,2,6,5,3 ... 2,6 is the last increasing pair, so keeping marker at 6
        // or if we see alternatively we are finding the first decreasing pair from the backwards of the array.
        // this means starting from the marker position all elements to right of it are in descending order.
        for (int i = nums.size() - 1; i > 0; i--)
        {
            if (nums[i - 1] < nums[i])
            {
                marker = i;
                break;
            }
        }

        // if no such pair found means, the array is in descending order already, so reversing it to make it in ascending order
        if (marker == INT_MAX)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        { // starting from the back of the array we are finding the element that is just greater than the element at (marker-1) position, and swapping these both positions
            for (int i = nums.size() - 1; i >= marker; i--)
            {
                if (nums[i] > nums[marker - 1])
                {
                    swap(nums[marker - 1], nums[i]);
                    break;
                }
            }
            reverse(nums.begin() + marker, nums.end()); // at last reversing the part from marker till end to make all elements after (marker-1) position in ascending order
        }
    }
};