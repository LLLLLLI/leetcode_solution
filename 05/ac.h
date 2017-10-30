class Solution {
	//基本思路 找到中间的数字然后向两边拓展（18行）
	//若回文为偶数个字母时先跳过中间肯定重复的两个（16行） 然后再向两边扩展
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        if(s.size()==1) return s;
        int begin = 0;
        int end = 0;
        int longest = 0;
        int max_begin = 0;
        for(int i = 0; s.size()-i>longest/2;){
            begin = i;
            end = i;
            int len = 0;
            while(end < s.size()-1 && s[end+1] == s[end]) end++;
            i = end+1;
            while(end < s.size()-1 && s[end+1] == s[begin-1]){
                end++;
                begin--;
            }
            len = end - begin + 1;
            if(len > longest)
            {
                longest = len;
                max_begin = begin;
            }
        }
        return s.substr(max_begin, longest);
    }
};