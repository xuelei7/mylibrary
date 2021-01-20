// from
// aoj0020
string toUpper(string s) {
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') s[i] = toupper(s[i]);
    }
    return s;
}

// menu
// vector<int> split_string_to_int(string s, char c)
// vector<double> split_string_to_double (string s, char c)
// vector<string> split_string(string s, char c)
// string toUpper(string s)
