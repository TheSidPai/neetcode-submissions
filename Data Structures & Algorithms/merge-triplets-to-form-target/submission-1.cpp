class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> res = {-1, -1, -1};

        for(auto t: triplets){
            int flag = 0;
            for(int i = 0; i < 3; i++){
                if(t[i] > target[i]) flag = 1;
            }

            if(!flag){
                for(int i = 0; i < 3; i++){
                    res[i] = max(res[i], t[i]);
                }
            }
        }

        for(int i = 0; i < 3; i++) cout<<res[i]<<" ";
        cout<<endl;
        for(int i = 0; i < 3; i++) if(res[i] != target[i]) return false;

        return true;
    }
};
