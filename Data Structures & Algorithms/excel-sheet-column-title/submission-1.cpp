class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        stack<char> st;
        while(columnNumber){
            // cout<<columnNumber<<endl;
            st.push('A' + (((columnNumber - 1) % 26)));
            (columnNumber) -= 1;
            columnNumber /= 26;
        }

        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        return res;
    }
};