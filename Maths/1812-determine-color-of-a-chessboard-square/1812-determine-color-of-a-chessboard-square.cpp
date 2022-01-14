class Solution {
public:
    bool squareIsWhite(string coordinates) {
        if((coordinates[0]-'a')&1)
        {
            if((coordinates[1]-'0')&1)
                return true;
            else
                return false;
        }
        else
        {
            if((coordinates[1]-'0')&1)
                return false;
            else
                return true;
        }
    }
};