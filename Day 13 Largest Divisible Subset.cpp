/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:
Si % Sj = 0 or Sj % Si = 0.
If there are multiple solutions, return any subset is fine.

Example 1:
Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)

Example 2:
Input: [1,2,4,8]
Output: [1,2,4,8]
*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==0){
            return nums;
        }
        sort(nums.begin(),nums.end());
        int flag=1;
        if(nums[0]==1){
            flag=0;
        }
        else{
            nums.push_back(1);
            flag=1;
        }
        sort(nums.begin(),nums.end());
        int i,j;
        int dp[nums.size()][2];
        for(i=nums.size()-1;i>=0;i--){
            dp[i][0]=0;
            dp[i][1]=i;
            for(j=i+1;j<nums.size();j++){
                if((nums[j]%nums[i])==0){
                    if(dp[j][0]>dp[i][0]){
                        dp[i][0]=dp[j][0];
                        dp[i][1]=j;
                    }
                }
            }
            dp[i][0]++;
        }
        i=0;
        vector<int> t;
        t.push_back(nums[i]);
        while(dp[i][1]!=i){
            i=dp[i][1];
            t.push_back(nums[i]);

        }
        if(flag==1){
            t.erase(t.begin());
        }
        return t;

    }
};
