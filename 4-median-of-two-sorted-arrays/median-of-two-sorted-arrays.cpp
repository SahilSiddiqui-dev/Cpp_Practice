class Solution {
public:
   
    vector<int> merge(vector<int>& nums1, vector<int>& nums2){
        vector<int>temp;
        int n = nums1.size();
        int m = nums2.size();
        int i = 0;
        int j = 0;
        while(i < n && j < m){
            if(nums1[i] < nums2[j]){
                temp.push_back(nums1[i]);
                i++;
            }
            else {
                temp.push_back(nums2[j]);
                j++;
            }
        }
        while(i < n){
            temp.push_back(nums1[i]);
            i++;
        }
        while(j < m){
            temp.push_back(nums2[j]);
            j++;
        }
        return temp;
    }
    double solve(vector<int>ans){
        double x;
        int n = ans.size();
        x = n%2==0 ? ((ans[n/2] + ans[(n/2) - 1])/2.0) : ans[n/2];
        return x;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        if(nums1.empty()){
            return solve(nums2);
            
        }
        if(nums2.empty()){
            return solve(nums1);
            
        }
        if(!nums1.empty() && !nums2.empty()){
            ans = merge(nums1, nums2);
            return solve(ans);
            
        }
      return 0.0;
    }
};