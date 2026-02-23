class Solution {
public:
    bool hasAllCodes(string s, int k) {

        if(s.length() < k) return false;

        set<int> se;

        int result = 0;

        // build first window
        for(int i = 0; i < k; i++){
            result = (result << 1) | (s[i] - '0');
        }

        se.insert(result);

        int mask = (1 << k) - 1;

        for(int end = k; end < s.length(); end++){
            result = ((result << 1) & mask) | (s[end] - '0');
            se.insert(result);
        }

        return se.size() == (1 << k);
    }
};