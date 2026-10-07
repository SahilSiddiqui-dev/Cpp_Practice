class Solution {
public:
    bool isPalindrome(string s){
        int i = 0;
        int j = s.size() - 1;
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(string s, vector<string>&partition, vector<vector<string>>&ans) {
        if(s.size() == 0){
            ans.push_back(partition);
            return;
        }


        for(int j = 0; j < s.size(); j++) {
            string part = s.substr(0, j + 1);
            if(isPalindrome(part)){
                partition.push_back(part);
                solve(s.substr(j + 1), partition, ans);
                partition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>partition;
        solve(s, partition, ans);
        return ans;
        
    }
};