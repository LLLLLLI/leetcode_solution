class Solution {
	//没什么 就按照回文的规则来回走就行了
public:
    string convert(string s, int numRows) {
        if(s.length() <= numRows || numRows == 1) 
            return s;
        vector<string> con(numRows);
        int row=0,step=1;
        for(int i = 0; i < s.length(); i++){
            con[row].push_back(s[i]);
            
            if(row == 0) step = 1;
            else if(row == numRows - 1) step = -1;
            
            row += step;
        }
        string result;
        for(int i = 0; i < numRows; i++)
            result.append(con[i]);
        return result;
    }
    
    
};