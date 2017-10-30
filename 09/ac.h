class Solution {
//没啥意思 算其反转的数字，但是不用算完 算到中间就行
public:
    bool isPalindrome(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int rev=0;
        while(x>rev)
        {
            rev = rev*10+x%10;
            x = x/10;
        }
        return (x==rev)||(x==rev/10);
    }

};