class Solution {
	//回溯
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0) return res;
        string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.push_back("");
        for (int i = 0; i < digits.size(); i++)
        {
            vector<string> temp;
            for (int c = 0; c < charmap[digits[i] - '0'].size();c++)    //digits[i] - '0'返回asc码的差值
                for (int j = 0; j < res.size();j++)
                    temp.push_back(res[j]+charmap[digits[i] - '0'][c]);  
            res = temp;   //可以直接用等号赋值
        }
        return res;
    }
};