class Solution {
public:
    string removeDuplicateLetters(string s) {

        unordered_map<char, int> lastIndex;
        for (int i = 0; i < s.size(); ++i) {
            lastIndex[s[i]] = i;
        }

        stack<char> st;
        unordered_set<char> seen;

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];

            if (seen.count(c))
                continue;

            while (!st.empty() && c < st.top() && lastIndex[st.top()] > i) {
                seen.erase(st.top());
                st.pop();
            }

            st.push(c);
            seen.insert(c);
        }

        string result;
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};