class Solution {
	//没啥意思 可以用result是不是对的值来验证是否溢出
public:
    int reverse(int n) {
        int result = 0;
        int x = n;
        bool neg = false;
        if(x < 0){
            neg = true;
            x = -x;
        }
        for(; x != 0 && result < 214748364;){
            result = result*10;
            result += (x % 10);
            x /= 10;
        }
        if((result == 214748364 && x >= 8)||(result > 214748364&&x!=0)||n == -2147483648)
            return 0;
        else if(result == 214748364 && x < 8 && x > 0)
            if(neg)
                return -(result*10+x);
            else
                return result*10+x;
        if (!neg)
            return result;
        else 
            return -result;
    }
};