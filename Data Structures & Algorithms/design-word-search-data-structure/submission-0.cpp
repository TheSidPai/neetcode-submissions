class WordDictionary {
WordDictionary* lett[26];
bool isEnd;

public:
    WordDictionary() {
        isEnd = false;
        fill(lett, lett+26, nullptr);
    }
    
    void addWord(string word) {
        if(word.size() == 0){
            isEnd = true;
            return;
        }

        char a = word[0];
        if(!lett[a-'a']) lett[a-'a'] = new WordDictionary();

        lett[a-'a']->addWord(word.substr(1, word.size()-1));
    }
    
    bool search(string word) {
        if(word == "") return isEnd;

        char a = word[0];
        if(a != '.'){
            if(!lett[a - 'a']) return false;
            else return lett[a - 'a']->search(word.substr(1, word.size()-1));
        }else{
            bool res = false;
            for(int i = 0; i < 26; i++){
                if(lett[i]) res = lett[i]->search(word.substr(1, word.size()-1));
                if(res) return res;
            }
        }
        return false;
    }
};
