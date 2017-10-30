class Solution {
	//没啥难度 从两边往中间走，由于宽度变窄，所以必须高度更高才有可能，遍历一遍即可
public:
    int maxArea(vector<int>& height) {
        int contain = 0;
        int l = 0;
        int r = height.size() - 1;
        int k = 0;
        bool change = true;
        while(l < r && change){
            contain = max(min(height[l], height[r])*(r-l), contain);
            change = false;
            if(height[l] < height[r]){
                k = l;
                while(k < r){
                    k++;
                    if(height[k] > height[l]){
                        l = k;
                        change = true;
                        break;
                    }
                }
            }
            else{
                k = r;
                while(k > l){
                    k--;
                    if(height[k] > height[r]){
                        r = k;
                        change = true;
                        break;
                    }
                }
            }
        }
        return contain;
    }
};