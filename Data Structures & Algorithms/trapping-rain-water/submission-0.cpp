class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int lmax = 0, rmax = 0;
        for(int i = 0; i < height.size(); i++){
            int idx = (n-1) - i;

            if(lmax > height[i]) left[i] = lmax;
            lmax = max(lmax, height[i]);

            if(rmax > height[idx]) right[idx] = rmax;
            rmax = max(rmax, height[idx]);
        }

        int total = 0;
        for(int i = 0; i < n; i++){
            int curr = min(left[i], right[i]) - height[i];
            if(curr >= 0) total += curr;
        }

        for(int i = 0; i < n; i++) cout<<left[i]<<" ";
        cout<<endl;
        for(int i = 0; i < n; i++) cout<<right[i]<<" ";
        cout<<endl;
        
        return total;
    }
};
