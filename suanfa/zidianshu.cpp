struct Trie {
    bool isEnd;
    vector<Trie*> children;
    Trie() : isEnd(false), children(26, NULL){}
};

string searhPrefix(Trie* root, const string& word) {
    Trie* cur = root;
    string res;
    for (char c : word) {
        if (cur->children[c - 'a'] == NULL) {
            return "isNotMatch";
        }
        res += c;
        cur = cur->children[c - 'a'];
        if (cur->isEnd == true) return res;
    }
    return "isNotMatch";
}

    // 构建前缀树Trie
void buildTree() {
    Trie* root = new Trie();
    for (string& str : dictionary) {
        Trie* cur = root;
        for (char c : str) {
            if (cur->children[c - 'a'] == NULL) {
                cur->children[c - 'a'] = new Trie();
            }
            cur = cur->children[c - 'a'];
        }
        cur->isEnd = true;
    }
}
