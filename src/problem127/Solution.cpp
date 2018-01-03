class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        queue<string> nextWord;
        bfs(beginWord, wordList, nextWord);
        int result = 2;
        while (!nextWord.empty()) {
            int l = nextWord.size();
            for (int i = 0; i < l; i++) {
                string word = nextWord.front();
                nextWord.pop();
                if (word == endWord)    return result;
                bfs(word, wordList, nextWord);
            }
            result++;
        }

        return 0;
    }

    void bfs(string word, vector<string>& wordList, queue<string>& nextWord) {
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            for (int j = 0; j < 26; j++) {
                word[i] = 'a' + j;
                if (find(wordList.begin(), wordList.end(), word) != wordList.end()) {
                    nextWord.push(word);
                    wordList.erase(find(wordList.begin(), wordList.end(), word));
                }
            }
            word[i] = c;
        }
    }
};