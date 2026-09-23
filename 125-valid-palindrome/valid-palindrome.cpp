
class Solution {
public:
    bool check(string ans){
        int i = 0;
        int j = ans.size() - 1;
        while(i < j) {
            if(ans[i] == ans[j]){
                i++;
                j--;
            }
            else {
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), [](unsigned char c){
            return tolower(c);
        });
        string ans;
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z' ){
                ans.push_back(s[i]);
            }
            if(s[i] >= '0' && s[i] <= '9'){
                ans.push_back(s[i]);
            }
        }
        return check(ans);
        
    }
};