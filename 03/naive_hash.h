class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        unordered_map<char, int> hash;
        int l = 0;
        int j = 0;
        for(int i = 0; i < s.length()-longest;)
        {
            l = 0;
            j = 0;
            for(j = i; j < s.length() && hash.find(s[j]) == hash.end(); j++)
            {
                l++;
                hash.insert(make_pair(s[j], j));
            }
            if(l > longest)
                longest = l;
            if(j < s.length())
                i = hash.find(s[j])->second + 1;
            else
                break;
            hash.clear();
        }
        return longest;
    }
};