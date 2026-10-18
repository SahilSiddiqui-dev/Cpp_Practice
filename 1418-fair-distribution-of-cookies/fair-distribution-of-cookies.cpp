class Solution {
public:
    int result = INT_MAX;
    void backtrack(int i, int k, vector<int>&cookies, vector<int>&current) {
         

        if(i >= cookies.size()) {
            int unfairness = *max_element(begin(current), end(current));
            result = min(result, unfairness);
            return;

        }
        int cookie = cookies[i];
        for(int j = 0; j < k; j++) {
            current[j] += cookie;
            backtrack(i + 1, k, cookies, current);
            current[j] -= cookie;
        }
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>current(k, 0);
        backtrack(0, k, cookies, current);
        return result;
    }
};