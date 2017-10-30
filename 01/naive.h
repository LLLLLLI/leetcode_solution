class Solution {
	//O(n^2)
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