class KthLargest {
private:
priority_queue<int, vector<int>, greater<>> heap;
int lim;
public:
    KthLargest(int k, vector<int>& nums) {
        lim = k;
        for(int num: nums){
            if(heap.size() < k) heap.push(num);
            else{
                if(heap.top() < num){
                    heap.pop();
                    heap.push(num);
                }
            }
        }
    }
    
    int add(int val) {
        if(heap.size() < lim) heap.push(val);
        else{
            if(heap.top() < val){
                heap.pop();
                heap.push(val);
            }
        }

        return heap.top();
    }
};
