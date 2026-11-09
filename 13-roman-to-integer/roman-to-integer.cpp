class Solution {
public:
    int switcher(char c) {
        switch(c) {
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
            default : return 0;
        }
    }

    int romanToInt(string s) {
        int ans = 0;
        int n = s.size();
        int j = 1;
        if(n == 1) return switcher(s[0]);
        for(int i = 0; i < n; i++) {
            int a = switcher(s[i]);
            int b = switcher(s[j]);
            if(a >= b) {
                ans += a;

            }
            else {
                ans -= a;
            }
            j++;
        }
        return ans;
    }
};