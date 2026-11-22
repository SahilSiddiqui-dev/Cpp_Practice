class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        int i = 0;

        for(int j = 1; j < n; j++) {
            if(s[i] == 'b' && s[j] == 'a' ) {
                return false; 
            }
            i++;
        }
        return true;
    }
};