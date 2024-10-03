class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {   

        int target=0;

        for(auto i:nums){
            target+=i;
        }
        target=target%p;
        unordered_map<int,int>mp;
        int curr_sum=0;
        mp[0]=1;
        for (int i=0;i<nums.size();i++){
            curr_sum+=curr_sum;

            int val=(curr_sum-target+p)%p;

            if(mp.find(val)!=mp.end()){
                return i-mp[val]+1;
            }
            else 
            mp[val]=i;
        }

        return -1;
    }
};
