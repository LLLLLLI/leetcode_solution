class Solution {
public:
    int threeSumClosest(vector<int>& nums, int tar) {
        int result = nums[0] + nums[1] + nums[2];
        if(nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
        int s1 = 0;
        int start, end = 0;
        for(int i = 0; i < nums.size()-2; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            start = i + 1;
            end = nums.size() - 1;
            while(start < end){
                s1 = nums[start]+nums[end] + nums[i];
                if(ab(s1-tar) < ab(result-tar)) result = s1;
                if(s1 == tar){
                    return tar;
                }
                if(s1 < tar) start++;
                else if(s1 > tar) end--;
            }
        }
        return result;
    }
    
    int ab(int a){
        if(a < 0) return -a;
        return a;
            
    }
};