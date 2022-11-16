class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        while(i<haystack.size())
        {
            if(needle[j]==haystack[i])
            {
                int last = -1;
                while(i<haystack.size() && j<needle.size() && needle[j]==haystack[i])                           {if(j!=0 && last ==-1 && haystack[i]==needle[0]) last= i; 
                   ++i,++j;}
                if(j==needle.size()) return i-needle.size();
                else {j=0; 
                if(last!=-1)i = last; //setting value of i to the firsmost index of 0th character of needle that was encountered during current matching. 
                      //This step is done for cases like: inp = "mississippi" and needle="issi"
                     }
            }
            else ++i;
        }
        return -1;
    }
};