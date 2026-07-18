class Solution {
public:
    bool checkValidString(string s) {
        stack<pair<int, int>> one;
        stack<int> extra;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') one.push({i, 1});
            else if(s[i] == ')'){
                // if(one.empty() && extra.empty()) return false;
                if(!one.empty() && one.top().second == 1) one.pop();
                else one.push({i, 2});
            }
            else extra.push(i);
        }

        while(!one.empty()){
            // cout<<one.size()<<" "<<extra.size()<<endl;
            if(extra.empty()) return false;
            
            auto o = one.top();
            int idx = extra.top();

            if(o.second == 1){
                if(o.first > idx) return false;
                one.pop();
                extra.pop();
            }
            else{
                if(o.first < idx) extra.pop();
                else{
                    extra.pop();
                    one.pop();
                }
            }
           
        }

        return true;
    }
};
