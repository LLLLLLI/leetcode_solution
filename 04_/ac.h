class Solution {
/* O(log(min(m,n)))
二分查找 需要注意除2时能否整除，上下对于奇数的处理要保持一致，都+1或都不加1，输出也要处理。很有意义
思路 利用i j分割两个数组，保证
left_part          |        right_part
A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]
1) len(left_part) == len(right_part)
2) max(left_part) <= min(right_part) 
So
(1) i + j == m - i + n - j (or: m - i + n - j + 1)
    if n >= m, we just need to set: i = 0 ~ m, j = (m + n + 1)/2 - i
(2) B[j-1] <= A[i] and A[i-1] <= B[j]
*/
	public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double r;
        if(nums1.size() > nums2.size()){
            r = findMedianSortedArrays(nums2, nums1);
            return r;
        }
        int m = nums1.size();
        int n = nums2.size();
        int down = 0;
        int up = m;
        int half = (n + m + 1)/2;
        int i,j;
        int maxLeft = 0;
        int minRight = 0;
        while(true)
        {
            i = (down + up)/2;
            j = half - i;
            if(i < m && nums2[j-1] > nums1[i])
                down += 1;   //为什么这样更快？
				//down = i + 1;    // 为了将i右挪,且二分 效率高
            else if(i > 0 && nums1[i-1] > nums2[j])
                up -= 1;
				//up = i - 1;	  // 为了将i左挪
            else
            {
                if(i == 0) maxLeft = nums2[j-1];
                else if(j == 0) maxLeft = nums1[i-1];
                else maxLeft = max(nums1[i-1], nums2[j-1]);
                
                if(i == m) minRight = nums2[j];
                else if(j == n) minRight = nums1[i];
                else    minRight = min(nums1[i], nums2[j]);
                
                if((n+m)%2 == 0)
                    return double(maxLeft+minRight)/2.0;
                else
                    return maxLeft;
            }
        }
    }
    
    int max(int a, int b){
        if(a>b)
            return a;
        else 
            return b;
    }
    
    int min(int a, int b){
        if(a < b)
            return a;
        else
            return b;
    }
};