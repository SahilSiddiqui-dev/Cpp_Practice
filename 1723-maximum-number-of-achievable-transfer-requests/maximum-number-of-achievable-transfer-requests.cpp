class Solution {
public:
    int result = INT_MIN;
    int m;
    void backtrack(int i, int n, int count, vector<vector<int>>& requests, vector<int>&resultant) {
        if(i >= m) {
            bool flag = true;
            for(int x : resultant){
                if(x != 0){
                    flag = false;
                    break;
                }
            }
            if(flag == true) {
                result = max(result, count);
            }
            return;
        }
        int from = requests[i][0];
        int to = requests[i][1];
        resultant[from]--;
        resultant[to]++;
        backtrack(i + 1, n, count + 1, requests, resultant);
        resultant[from]++;
        resultant[to]--;
        backtrack(i + 1, n, count, requests, resultant);
        
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>resultant(n, 0);
        m = requests.size();
        backtrack(0, m, 0, requests, resultant);
        return result;
    }
};