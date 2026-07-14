class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int count = 0;
        unordered_map<char, int> freq;
        for(char i: tasks) freq[i]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>> heap;
        for(auto [a, b]: freq) heap.push({b, 0});

        queue<pair<int, int>> q;
        while(!heap.empty() || !q.empty()){
            while(!q.empty() && q.front().second <= count){
                heap.push({q.front().first, q.front().second});
                q.pop();
            }

            if(!heap.empty()){
                auto [a, b] = heap.top();
                heap.pop();
                a--;
                if(a) q.push({a, b+n+1});
            }
            
            count++;
        }

        return count;
    }
};
