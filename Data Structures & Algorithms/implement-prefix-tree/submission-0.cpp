class PrefixTree {
private:
    PrefixTree* child[26];
    bool isEnd;
public:
    PrefixTree() {
        isEnd = false;
        fill(child, child+26, nullptr);
    }
    
    void insert(string word) {
        if(word == ""){
            isEnd = true;
            return;
        }
        char a = word[0];
        if(child[a-'a']) child[a-'a']->insert(word.substr(1, word.size()-1));
        else{
            child[a-'a'] = new PrefixTree();
            child[a-'a']->insert(word.substr(1, word.size()-1));
        }
    }
    
    bool search(string word) {
        if(word  == "") return isEnd;
        char a = word[0];
        if(child[a-'a']) return child[a-'a']->search(word.substr(1, word.size()-1));
        else return false;
    }
    
    bool startsWith(string prefix) {
        if(prefix  == "") return true;
        char a = prefix[0];
        if(child[a-'a']) return child[a-'a']->startsWith(prefix.substr(1, prefix.size()-1));
        else return false;
    }
};
