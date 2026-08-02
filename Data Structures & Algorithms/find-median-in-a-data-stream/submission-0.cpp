class MedianFinder {
    priority_queue<int, vector<int>, greater<>> low;
    priority_queue<int, vector<int>> high;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(low.empty()) low.push(num);
        else if(num >= low.top()) low.push(num);
        else high.push(num);

        while(abs((int)high.size() - (int)low.size()) > 1){
            int l = low.size();
            int h = high.size();

            if(l < h){
                low.push(high.top());
                high.pop();
            }
            else{
                high.push(low.top());
                low.pop();
            }
        }
    }
    
    double findMedian() {
        int l = low.size();
        int h = high.size();
        // cout<<h<<" "<<l<<endl;
        if((l+h) % 2){
            if(l > h) return low.top();
            else return high.top();
        }
        else return ((float)low.top() + (int)high.top()) / 2;
    }
};
