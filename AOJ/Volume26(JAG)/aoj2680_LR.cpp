// D - LR
// Problem Statement
// JAG Kingdom will hold a contest called ICPC (Interesting Contest for Producing Calculation).

// At the contest, you are given a string composed of ?s and usable characters. You should replace all ?s in the string with the usable characters to make the string valid mathematical expression, before submitting it. The usable characters are L, R, (, ), ,, 0, 1, 2, 3, 4, 5, 6, 7, 8, and 9.

// For example, suppose that you are given the string "R(??3,??1?78??1?)?", then you can submit "R(123,L(1678,213))" as an example.

// The submitted string will be scored as follows.

// Let $L$ and $R$ be functions defined by $L(x,y)=x$, $R(x,y)=y$, where $x$ and $y$ are non-negative integers.
// The submitted string will be regarded as a mathematical expression, whose value will be the score. For example, the score of the string "R(123,L(1678,213))" is $R(123,L(1678,213)) = R(123,1678) = 1678$.
// If the string cannot be evaluated as a mathematical expression about the functions $L$ and $R$, the string will be rejected. For example, "R", "R(3)", "R(3,2", "R(3,2,4)" and "LR(3,2)" are all invalid.
// And strings that contain numbers with extra leading zeros, will be rejected. For example, "R(04,18)" is invalid, while "R(0,18)" is valid.
// The winner of the contest will be the person getting the highest score. Your friend Jagger, who is going to join the contest, wants to be the winner. You are asked by Jagger to make the program finding the possible highest score for the input string.

// Input
// The input contains one string in a line, whose length $N$ is between $1$ and $50$, inclusive.

// You can assume that each element in the string is one of L, R, (, ), ,, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, or ?.

// Output
// Display the possible highest score in a line for the given string.

// If it's impossible to get valid strings for the input string, print "invalid" in a line.

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (int)(a); (i) < (int)(b); (i)++)
#define rrep(i, a, b) for (int i = (int)(b) - 1; (i) >= (int)(a); (i)--)
#define all(v) v.begin(), v.end()

typedef long long ll;
template <class T> using V = vector<T>;
template <class T> using VV = vector<V<T>>;

/* 提出時これをコメントアウトする */
// #define LOCAL true

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

string s;
int N;
const string bad = "invalid";
VV<string> rec(52, V<string>(52));
VV<bool> ok(52, V<bool>(52));

string equation(int f, int t);
string number(int f, int t);

void chmax(string& a, string b) {
    if (a == bad) a = b;
    if (b.size() > a.size()) a = b;
    else if (b.size() == a.size() && b > a) a = b;
}

string number(int f, int t) {
    if (ok[f][t]) return rec[f][t];

    if (t - f <= 0) {
        ok[f][t] = 1;
        return rec[f][t] = bad;
    }

    // 1桁の場合
    if (t - f == 1) {
        if (s[f] == '?') {
            return rec[f][t] = "9";
        } else {
            if (s[f] >= '0' && s[f] <= '9') {
                return rec[f][t] = s[f];
            } else {
                return bad;
            }
        }
    }

    // 2桁以上の場合
    if (s[f] == '0') return bad;
    string ret = s.substr(f,t-f);
    for (auto& c: ret) {
        if (c == '?') c = '9';
        else if (c < '0' || c > '9') return rec[f][t] = bad;
    }

    return rec[f][t] = ret;
}

string equation(int f, int t) {
#ifdef LOCAL
    cerr << f << " " << t << endl;
#endif
    if (ok[f][t]) return rec[f][t];
    
    string ret = bad;
    // 数字の場合
    ret = number(f,t);
    if (ret != bad) {
        ok[f][t] = 1;
        return rec[f][t] = ret;
    }

    
    // 等式の場合
    if (t - f < 6) {
        ok[f][t] = 1;
        return rec[f][t] = bad; // bad equation
    }
    int simbol = s[f];
    int leftb = s[f+1];
    int rightb = s[t-1];

    if (simbol != 'L' && simbol != 'R' && simbol != '?') {
        ok[f][t] = 1;
        return rec[f][t] = bad;
    }
    if (leftb != '(' && leftb != '?') {
        ok[f][t] = 1;
        return rec[f][t] = bad;
    }
    if (rightb != ')' && rightb != '?') {
        ok[f][t] = 1;
        return rec[f][t] = bad;
    }

    for (int mid = f+3; mid <= t-3; mid++) {
        if (s[mid] != ',' && s[mid] != '?') continue;
        string left = equation(f+2,mid);
        string right = equation(mid+1,t-1);
        if (left == bad || right == bad) continue;
        if (simbol == 'L' || simbol == '?') {
            chmax(ret, left);
        }
        if (simbol == 'R' || simbol == '?') {
            chmax(ret, right);
        }
    }

#ifdef LOCAL
    cerr << s.substr(f,f-t) << " " << ret << endl;
#endif
    ok[f][t] = 1;
    return rec[f][t] = ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    cin >> s;
    N = s.size();

    cout << equation(0, s.size()) << endl;
    
#ifdef LOCAL
    cerr << "----------" << endl;
    rep(i,0,N+1) {
        rep(j,i+1,N+1) {
            if (ok[i][j])
                cout << i << " " << j << " (" << rec[i][j] << ")" << (ok[i][j]?"ok":"") << endl;
        }
    }
#endif
    return 0;
}