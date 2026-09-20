class Solution {
public:
    int reverseDegree(string s) {
        vector<char>alpha;
        // for(char c = 'z'; c >= 'a'; c--){
        //     alpha.push_back(c);
        // }
        int sum = 0;
        for(int i = 0; i < s.size(); i++){
            //auto it = find(alpha.begin(), alpha.end(), s[i]);
            //if(it != alpha.end()){
                //int index = distance(alpha.begin(), it);
            int index = 'z' - s[i];
            sum += ((index + 1) * (i + 1));
            //}
        }
        return sum;
    }
};