class Solution {
	//在AC代码的基础上考虑到二分从中间定位应该更快，改成两部分，一部分向前一部分向后
	//快乐3ms beat94%
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        if(s.size()==1) return s;
        int begin = 0;
        int end = 0;
        int longest = 0;
        int max_begin = 0;
        int len = 0;
        for(int i = s.size()/2-1; s.size()-i>longest/2;){
            begin = i;
            end = i;
            while(end < s.size()-1 && s[end+1] == s[end]) end++;
            while(begin > 0 && s[begin-1] == s[begin]) begin--;
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
        for(int i = s.size()/2; i>longest/2;){
            begin = i;
            end = i;
            while(begin > 0 && s[begin-1] == s[begin]) begin--;
            while(end < s.size()-1 && s[end+1] == s[end]) end++;
            i = begin-1;
            while(begin > 0 && s[end+1] == s[begin-1]){
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