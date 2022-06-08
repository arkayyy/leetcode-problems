class Solution {
public:
    bool isPalin(string& s)
    {
        int i = 0, j = s.size()-1;
        while(j>=i)
            {if(s[i]!=s[j]) return false;
            ++i,--j;}
        return true;
    }
    int removePalindromeSub(string s) {
        // int i = 0, j=0;
        // int ans = 0;
        // while(i<s.size())
        // {
        //     char c = s[i];
        //     j = s.size()-1;
        //     while(j>=i)
        //     {
        //         if(s[i]==s[j])
        //         {
        //             string t = s.substr(i,j-i+1);
        //             if(isPalin(t)) {cout<<"between "<<i<<" and "<<j<<endl;++ans; i = j; break;}
        //         }
        //         --j;
        //     }
        //     ++i;
        // }
        // return ans;
        
        return 2-isPalin(s);
    }
};