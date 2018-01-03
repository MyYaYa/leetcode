class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> beginList;
        unordered_set<string> endList;
        unordered_set<string> rest;
        for (int i = 0; i < wordList.size(); i++)   rest.insert(wordList[i]);
        if (rest.find(endWord) != rest.end()) {
            rest.erase(endWord);
        } else {
            return 0;
        }
        int depth = 2;
        beginList.insert(beginWord);
        endList.insert(endWord);
        while (!beginList.empty() && !endList.empty()) {
            unordered_set<string>* pb;
            unordered_set<string>* pe;
            if (beginList.size() < endList.size()) {
                pb = &beginList;
                pe = &endList;
            } else {
                pe = &beginList;
                pb = &endList;
            }
            unordered_set<string> tmp;
            for (unordered_set<string>::iterator it = pb->begin(); it != pb->end(); it++) {
                string w = *it;
                for (int i = 0; i < w.length(); i++) {
                    char c = w[i];
                    for (int j = 0; j < 26; j++) {
                        w[i] = 'a' + j;
                        if (w[i] == c) continue;
                        if (pe->find(w) != pe->end()) {
                            return depth;
                        }
                        if (rest.find(w) != rest.end()) {
                            tmp.insert(w);
                            rest.erase(w);
                        }
                    }
                    w[i] = c;
                }
            }
            depth++;
            *pb = tmp;
        }
        return 0;
    }
};