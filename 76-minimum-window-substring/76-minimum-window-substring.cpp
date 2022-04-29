class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(256,0);
        for(auto ch:t) ++freq[ch]; //marking all characters that need to be found in s
        int start = 0, end = 0, minLength = INT_MAX, head = start, counter = t.length();
        //counter denotes the no. of characters from t that are not there in the current window substring of s
        while(end<s.size())
        {
            if(freq[s[end++]]-- > 0) counter--; //taking one more letter in the current window
            while(counter==0) //if all characters of t are present in current window substring
            {
                if(end-start<minLength) minLength = end-(head=start); //minimising the length of such a window
                if(freq[s[start++]]++ == 0) counter++; //removing the character from begin index, thereby to move the window forward
            }
        }
        return minLength==INT_MAX?"":s.substr(head,minLength);
    }
};