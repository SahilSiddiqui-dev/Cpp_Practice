class Solution {
public:
    void solve (int l, int r, int n, string&s, vector<string>&ans) {
        if(l + r == 2*n){
            ans.push_back(s);
            return;
        }
        if(l < n){
            s.push_back('(');
            solve(l+1, r, n, s, ans);
            s.pop_back();
        }
        if(r < l){
            s.push_back(')');
            solve(l, r+1, n, s, ans);
            s.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        int l = 0;
        int r = 0;
        solve(0, 0, n, s, ans);

        return ans;        
    }
};