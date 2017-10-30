class Solution {
	//动态规划/递归
	//".*"可匹配任意长度字符，因该字符串中'*'表示任意长度的'.'
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
        
        f[0][0] = true;
        for (int j = 1; j <= n; j++)
            f[0][j] = j > 1 && '*' == p[j - 1] && f[0][j - 2];   //匹配s是空字符串的情况，因'*'可以匹配0个
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (p[j - 1] != '*')
                    f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);   //普通字符
                else
					//两种情况
					//1.匹配0个 此时f[i][j - 2]
					//2.匹配任意多个 此时(s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j]) 即前一个要对
                    f[i][j] = j > 1 && (f[i][j - 2] || ((s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j]));   
        
        return f[m][n];
    }
};