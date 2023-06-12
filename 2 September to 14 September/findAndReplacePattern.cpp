// 890. Find and Replace Pattern
// Medium

// Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

// A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

// Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        ans.resize(0);
        codex.clear();
        cipher = pattern;
        for (int i = 0; i < pattern.size(); i++)
            cipher[i] = translate(cipher[i]);
        for (auto& word : words) compare(word);
        return ans;
    }
private:
    vector<string> ans;
    unordered_map<char, char> codex;
    string cipher;
    char translate(char& c) {
        if (codex.find(c) == codex.end())
            codex[c] = (char)(97 + codex.size());
        return codex[c];
    }
    void compare(string& word) {
        codex.clear();
        for (int i = 0; i < word.length(); i++)
            if (translate(word[i]) != cipher[i]) return;
        ans.push_back(word);
    }
};