class MinStack {
private:
    stack<pair<int, int>> st;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(st.size() == 0){
            st.push({val, val});
            return;
        }
        int num = min(val, st.top().second);
        st.push({val, num});
        // cout<<"Current state is "<<st.top().first<<" "<<st.top().second<<endl;
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
