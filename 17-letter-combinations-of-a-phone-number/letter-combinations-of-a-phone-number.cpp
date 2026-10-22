class Solution {
public:
    void solve(int i, int n, vector<string>&s, string&current, vector<string>&ans) {
        if(current.size() == n){
            ans.push_back(current);
            return;
        }

        if(i >= s.size()){
            return;
        }

        for(int j = 0; j < s[i].size(); j++) {
            current.push_back(s[i][j]);
            solve(i + 1, n, s, current, ans);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string>mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string>s;
        vector<string>ans;
        int n = digits.size();
        for(int i = 0; i < n; i++) {
            s.push_back(mp[digits[i]]);
        }
        string current = "";
        solve(0, n, s, current, ans);
        return ans;
    }
};