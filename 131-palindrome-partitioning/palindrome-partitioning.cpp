class Solution {
public:
    bool isPalin(string part){
        int n = part.size();
        int s = 0;
        int e = n - 1;
        while(s < e){
            if(part[s] == part[e]){
                s++;
                e--;
            }
            else {
                return false;
            }
        }
        return true;
    }
    void solve (string s, vector<string>&partition, vector<vector<string>>&ans) {
        if(s.size() == 0) {
            ans.push_back(partition);
            return;
        }
            for(int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i + 1);
            if(isPalin(part)){
                partition.push_back(part);
                solve(s.substr(i + 1), partition, ans);
                partition.pop_back();
            }
            
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string>partition;
        vector<vector<string>>ans;
        int n = s.size();
        solve(s, partition, ans);
        return ans;
    }
};