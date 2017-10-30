class Solution {
	//直接维护一个字母为索引的数组而不用hashtable
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        int table[128];
        for(int i = 0; i < 128; i++)
            table[i] = 0;
        int begin = 0;
        int end = 0;
        while(end < s.length())
        {
            if(table[s[end]] == 1){
                longest = longest>(end-begin)?longest:(end-begin);
                while(table[s[end]] == 1 && begin<end)   //begin更新到end的字母时停止
                    table[s[begin++]] = 0;
            }
            table[s[end++]] = 1;
        }
        longest = longest>(end-begin)?longest:(end-begin);
        return longest;
    }
};