class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string pre;
        if(strs.size() == 0) return pre;
        for(int pos = 0; pos < strs[0].size(); pos++)
        {
            for(int k = 1; k < strs.size(); k++)
            {
                if(strs[k].size() == pos || strs[k][pos] != strs[0][pos])
                    return pre;
            }
            pre.push_back(strs[0][pos]);
        }
        return pre;
    }
};