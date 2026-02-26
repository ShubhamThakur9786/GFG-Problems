class Solution {
  public:
    bool areIsomorphic(string &s, string &t) {
        // code here
        if (s.length() != t.length())
        return false;

    unordered_map<char, char> mapST;
    unordered_map<char, char> mapTS;

    for (int i = 0; i < s.length(); i++) {
        char c1 = s[i];
        char c2 = t[i];

        // Check mapping from s to t
        if (mapST.count(c1)) {
            if (mapST[c1] != c2)
                return false;
        } else {
            mapST[c1] = c2;
        }

        // Check mapping from t to s
        if (mapTS.count(c2)) {
            if (mapTS[c2] != c1)
                return false;
        } else {
            mapTS[c2] = c1;
        }
    }

    return true;
    }
};