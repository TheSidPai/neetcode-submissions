class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(string str: strs){
            res += to_string(str.size());
            res += ' ';
            res += str;
        }
        // cout<<res;
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i < s.size()){
            int count = 0;
            int left = i;
            while(s[i] != ' '){
                count++;
                i++;
            }
            i++;
            int len = stoi(s.substr(left, count));
            res.push_back(s.substr(i, len));
            i += len;
        }

        return res;
    }
};
