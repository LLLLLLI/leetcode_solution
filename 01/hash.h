class Solution {
//O(n)维护hash表，若没找到则放入hash表，hash表查找时间为常数
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++)
        {
            int toBeFind = target - nums[i];
            for(int j =i+1; j < nums.size(); j++)
                if(nums[j] == toBeFind)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
        }
    }
    
};