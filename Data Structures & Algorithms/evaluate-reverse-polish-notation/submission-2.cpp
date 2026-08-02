class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string t: tokens){
            char c = t[0];
            if(t.size() == 1 && (c == '/' || c == '+' || c == '-' || c == '*')){
                int two = st.top();
                st.pop();
                int one = st.top();
                st.pop();
                int res = 0;
                if(c == '/') res = one / two;
                else if(c == '*') res = one * two;
                else if(c == '-') res = one - two;
                else res = one + two;
                st.push(res);
                cout<<res<<endl;

            } else st.push(stoi(t));
        }

        // cout<<st.size();
        // return 1;
        return st.top();
    }
};
