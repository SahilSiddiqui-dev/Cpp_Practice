class Solution {
public:
    bool checkDivisibility(int n) {
        int a = n;
        int sum = 0;
        int multi = 1;
        while(n){
            sum += n%10;
            multi *= n%10;
            n /= 10; 
        }
        int x = sum + multi;
        if(a%x == 0){
            return true;
        }
        return false;
    }
};