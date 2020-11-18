// from
// aoj0011
vector<int> split_string(string s, char c) {
    vector<int> v;
    int left_side = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            v.push_back(stoi(s.substr(left_side, i-left_side)));
            left_side = i + 1;
        }
        if (i == s.size()) {
            v.push_back(stoi(s.substr(left_side, i-left_side+1)));
        }
    }
    return v;
}