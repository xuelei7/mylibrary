// from
// aoj0011, aoj0016, aoj0026, aoj0032, aoj0034, aoj0038, aoj0042, aoj0045, aoj0061
// aoj0065
// split string s by character c and return all the integer elements
vector<int> split_string_to_int(string s, char c) {
    vector<int> v;
    int left_side = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            bool minus_f = false;
            if (s[left_side] == '-') minus_f = true;
            int num = stoi(s.substr(left_side + minus_f, i-left_side-minus_f));
            if (minus_f) num *= -1;
            v.push_back(num);
            left_side = i + 1;
        }
        if (i == s.size() - 1) {
            bool minus_f = false;
            if (s[left_side] == '-') minus_f = true;
            int num = stoi(s.substr(left_side + minus_f, i+1-left_side-minus_f));
            if (minus_f) num *= -1;
            v.push_back(num);
        }
    }
    return v;
}

// from
// aoj0035
// split the string by a character to real numbers
vector<double> split_string_to_double (string s, char c) {
    for (int i = 0; i < s.size(); i++) if (s[i] == c) s[i] = ' ';
    stringstream ss(s);
    vector<double> ret;
    double num;
    while (ss >> num) {
        ret.push_back(num);
    }
    return ret;
}

// from
// aoj0017, aoj0049
// split the string by a character to substrings
vector<string> split_string(string s, char c) {
    vector<string> v;
    int left_side = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            v.push_back(s.substr(left_side, i-left_side));
            left_side = i+1;
        }
        if (i == s.size() - 1) {
            v.push_back(s.substr(left_side, i-left_side+1));
        }
    }
    return v;
}

// from
// aoj0020
string toUpper(string s) {
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') s[i] = toupper(s[i]);
    }
    return s;
}