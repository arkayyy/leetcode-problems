class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int m = version1.length(), n = version2.length();
        while(i<m && j<n)
        {
            int curr1 = 0;
            while(i<m && version1[i]!='.')
                {curr1 = curr1*10 + (version1[i]-'0'); ++i;}
            int curr2 = 0;
            while(j<n && version2[j]!='.')
                {curr2 = curr2*10 + (version2[j]-'0'); ++j;}
            
            if(curr1>curr2) return 1;
            if(curr1<curr2) return -1;
            
            i++,j++;
        }
        while(i<m)
        {
            if(version1[i]!='.' && version1[i]!='0')
                return 1;
            i++;
        }
        while(j<n)
        {
            if(version2[j]!='.' && version2[j]!='0')
                return -1;
            j++;
        }
        return 0;
    }
};