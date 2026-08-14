class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        unordered_map<int,int>m;
         int total=0;
         int ps=0;
         m[0]=1;

         for (int i =0;i<nums.size();i++){
        
             if(nums[i]%2==1){
                ps++;
             }
              if(m.count(ps-k)){
                total+=m[ps-k];
              }
              m[ps]++;
         }
         return total;
    }
};