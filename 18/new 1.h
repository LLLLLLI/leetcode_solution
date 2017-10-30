class Solution {
	//与3sum一样 连注意的点都一样
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tar) {
        vector<vector<int>> result;
        if(nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        int target = 0;
        int start, end = 0;
        for(int j = 0; j < nums.size()-3; j++){
            if(j>0 && nums[j] == nums[j-1]) continue;
            bool hasadd = false;
            for(int i = j+1; i < nums.size()-2; i++){
                target = tar-nums[i]-nums[j];
                if(i>1 && nums[i] == nums[i-1]&&hasadd) continue;
                start = i + 1;
                end = nums.size() - 1;
                while(start < end){
                    if(nums[start]+nums[end] < target) start++;
                    else if(nums[start] + nums[end] > target) end--;
                    else{
                        result.push_back(vector<int>({nums[j],nums[i],nums[start++],nums[end--]}));
                        while(nums[start] == result[result.size()-1][2] && nums[end] == result[result.size()-1][3]){   //这个重复的开始没想到
                            start++;
                            end--;
                        }
                        hasadd = true;
                    }
                }
            }
        }
        return result;
    }
};