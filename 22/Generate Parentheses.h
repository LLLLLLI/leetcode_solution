class Solution {
	//满足如下规则：
	//(1)左括号的个数大于等于右括号的个数。
	//(2)假设在位置k我们还剩余left个左括号和right个右括号，如果left>0，则我们可以直接打印左括号，而不违背规则。
	//(2)验证left和right的值，如果left>=right，则不能,否则可以打印右括号。如果left和right均为零，则完成一个合法排列，可以将其打印出来。
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(n, n, "", result);
        return result;
    }
    
    void generate(int leftNum,int rightNum,string s,vector<string> &result)  
    {  
        if(leftNum==0&&rightNum==0)  
        {  
            result.push_back(s);  
        }  
        if(leftNum>0)  
        {  
            generate(leftNum-1,rightNum,s+'(',result);  
        }  
        if(rightNum>0&&leftNum<rightNum)  
        {  
            generate(leftNum,rightNum-1,s+')',result);  
        }  
    }  
};