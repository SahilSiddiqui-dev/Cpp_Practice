class Solution {
public:
    int findComplement(int num) {
        string temp = "";
        while(num > 0){
            temp.push_back(num%2 + '0');
            num = num/2;
        }
        int i = 0;
        int j = temp.size()- 1;
        while(i < j){
            swap(temp[i], temp[j]);
            i++;
            j--;
        }
        for(int c = 0; c < temp.size(); c++){
            if(temp[c] == '1'){
                temp[c] = '0';
            }
            else{
                temp[c] = '1';
            }
        }
        int sum = 0;
        int n = temp.size();
        for(int k = 0; k < n; k++){
            int x = temp[k] - '0';
            sum += pow(2, n - 1 - k) * x;
        }
        return sum;
    }
};