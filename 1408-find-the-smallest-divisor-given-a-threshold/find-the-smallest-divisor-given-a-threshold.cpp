class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int st=1,end=0,mid,ans,n=nums.size();

        for(int i=0;i<n;i++){
            end=max(end,nums[i]);
        }

        while(st<=end){
            mid=st+(end-st)/2;
             long long sum=0;
            for(int i=0;i<n;i++){
                sum+=nums[i]/mid;
                if(nums[i]%mid!=0){
                    sum++;
                }

            }
            if(sum>threshold){
                st=mid+1;
            }
            else{
                ans=mid;
                end=mid-1;
            }
        }
        return ans;
    }
};