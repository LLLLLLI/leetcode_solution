class Solution {
	//就是个栈
public:
    bool isValid(string s) {
        stack<char> r;
        map<char,char> hash;
        hash[']'] = '[';
        hash['}'] = '{';
        hash[')'] = '(';
        for(int i = 0; i < s.size(); i++){
            if(r.size() > 0 && hash[s[i]] == r.top())
                r.pop();
            else
                r.push(s[i]);
        }
        return r.size() == 0;
    }
};