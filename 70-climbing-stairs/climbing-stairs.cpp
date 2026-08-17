class Solution {
public:
    int climbStairs(int n) {
       vector<int>arr(n + 1);
        if(n == 1) return 1;
        if(n == 0)return 0;
        int a = 0;
        int b = 1;
        int next;
        for(int i = 1; i <= n; i++){
            next = a + b;
            a = b;
            b = next;
        }
        return b;
    }
};