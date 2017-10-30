class Solution {
	//先排序 锁定一个数，然后从开头和结尾遍历，注意避免重复
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> result;
        if(nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
        int target = 0;
        int start, end = 0;
        for(int i = 0; i < nums.size()-2; i++){
            target = -nums[i];
            if(i>0 && nums[i] == nums[i-1]) continue;
            start = i + 1;
            end = nums.size() - 1;
            while(start < end){
                if(nums[start]+nums[end] < target) start++;
                else if(nums[start] + nums[end] > target) end--;
                else{
                    vector<int> adder;
                    adder.push_back(nums[i]);
                    adder.push_back(nums[start++]);
                    adder.push_back(nums[end--]);
                    result.push_back(adder);
                    while(nums[start] == adder[1] && nums[end] == adder[2]){   //这个重复的开始没想到，若与上一个一样就一直加
                        start++;
                        end--;
                    }
                }
            }
        }
        return result;
    }
};