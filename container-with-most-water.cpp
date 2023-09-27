//https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        vector<int>A(n),B(n);
        for(int i=0; i<n; i++){
            if(i==0){
                A[i]=height[i];
                B[i]=height[n-i-1];
            }
            else{
                A[i]=max(A[i-1], height[i]);
                B[i]=max(B[i-1], height[n-i-1]);
            }
        }
        int res=0;
        for(int i=0; i<n; i++){
            int idx=lower_bound(B.begin(), B.end(), height[i])-B.begin();
            int ans1=height[i]*(n-idx-(i+1));
            idx=lower_bound(A.begin(), A.end(), height[n-i-1])-A.begin();
            int ans2=height[n-i-1]*(n-idx-(i+1));
            res=max(res, max(ans1, ans2));
        }
        return res;
    }
};
