class Solution {
    void prefix(vector<int>& freq_words2, vector<int>& freq) {
        for(int i = 0; i < freq_words2.size(); i++) {
            freq_words2[i] = max(freq_words2[i], freq[i]);
        }        
    }

    bool isuni(vector<int>& words1, vector<int>& words2) {
        for(int i = 0; i < 26; i++) {
            if(words1[i] < words2[i]) 
                return false;            
        }
        return true;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq_word(26, 0);  // To store max frequency of each character across words2
        for(string word : words2) {
            vector<int> freq(26, 0);
            for(char c : word) 
                freq[c - 'a']++;
            prefix(freq_word, freq);
        }

        vector<string> uni;
        for(string word : words1) {
            vector<int> freq_word1(26, 0);
            for(auto c : word) 
                freq_word1[c - 'a']++;
            if(isuni(freq_word1, freq_word)) 
                uni.push_back(word);
        }

        return uni;
    }
};
