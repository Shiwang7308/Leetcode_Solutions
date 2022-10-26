

    // solution start form here
    
    class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        
        bool ans=false;
        int sum=0;
        mp[0]=-1;// for tracking those sum whose remainder comes 0 first time
        // because initailly also remainder is 0 , so it also makes an subarray
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int rem=sum%k;  // to find the remainder of prefix array if we encounter the same remainder then for sure subarray sum divisible by k is present get my currentInd - previously stored ind in map
            if(mp.find(rem)==mp.end())
                mp[rem]=i;
            else
            {
                int prevIndex=mp[rem];
                int ind=i;
                if((ind-prevIndex)>1)
                {
                    ans=true;
                    break;
                }
            }
        }
        return ans;
    }
    // for more reference and follow up(handle -ve number as well) see vedio of pepcoding just by copy pasting the problem statement on youtube
};
