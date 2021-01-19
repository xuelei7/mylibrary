// from
// aoj0002
// return the digit number
int digitnum(int k) {
    if (k == 0) return 1;
    int cnt = 0;
    while (k > 0) {
        k /= 10;
        cnt++;
    }
    return cnt;
}

// from
// aoj0027
// return the date of year/month/day
// 0: Sunday 1: Monday ...
int Zeller(int year, int month, int day) {
    if (month == 1 || month == 2) {
        year--;
        month += 12;
    }
    return (year + year/4 - year/100 + year/400 + (13*month+8)/5 + day) % 7;
}

// from
// aoj0038
string poker_hand(vector<int> v) {
    sort(v.begin(), v.end());
    if (v[0] == v[1] && v[1] == v[2] && v[2] == v[3]) return "four card";
    if (v[1] == v[2] && v[2] == v[3] && v[3] == v[4]) return "four card";
    if (v[0] == v[1] && v[2] == v[3] && v[3] == v[4]) return "full house";
    if (v[0] == v[1] && v[1] == v[2] && v[3] == v[4]) return "full house";
    if (v[0] == v[1] - 1 && v[1] == v[2] - 1 && v[2] == v[3] - 1 && v[3] == v[4] - 1) return "straight";
    if (v[0] == 1 && v[1] == 10 && v[2] == 11 && v[3] == 12 && v[4] == 13) return "straight";
    if (v[0] == v[1] && v[1] == v[2]) return "three card";
    if (v[1] == v[2] && v[2] == v[3]) return "three card";
    if (v[2] == v[3] && v[3] == v[4]) return "three card";
    if (v[0] == v[1] && (v[2] == v[3] || v[3] == v[4])) return "two pair";
    if (v[1] == v[2] && v[3] == v[4]) return "two pair";
    if (v[0] == v[1] || v[1] == v[2] || v[2] == v[3] || v[3] == v[4]) return "one pair";
    return "null";
}

// from
// aoj0039
int roman_figure(string s) {
    int ans = 0, biggest = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        int now ;
        if (s[i] == 'I') now = 1;
        else if (s[i] == 'V') now = 5;
        else if (s[i] == 'X') now = 10;
        else if (s[i] == 'L') now = 50;
        else if (s[i] == 'C') now = 100;
        else if (s[i] == 'D') now = 500;
        else if (s[i] == 'M') now = 1000;
        if (now >= biggest) {
            biggest = now;
            ans += now;
        } else {
            ans -= now;
        }
    }
    return ans;
}

// from
// aoj0040
string affine_cipher(string ciphertext, vector<string> keywords, char skip=' ') {
    bool ok = 0;
    for (int a = 1; a < 26; a++) {
        if (__gcd(a,26) != 1) continue;
        for (int b = 0; b < 26; b++) {
            string v = ciphertext;
            for (int i = 0; i < v.size(); i++) {
                if (v[i] == skip) continue;
                v[i] = (char)(((v[i] - 'a') * a + b) % 26 + 'a');
            }
            for (int i = 0; i < keywords.size(); i++) {
                if (v.find(keywords[i]) != -1) ok = 1;
            }
            if (ok) return v;
        }
    }
    return ciphertext;
}

// from
// aoj0041
// given 4 numbers, using +, -, *, (, ) to calculate res, and print out the answer if there is one
int calc(int a, int b, int sign) {
    if (sign == 0) return a + b;
    if (sign == 1) return a - b;
    if (sign == 2) return a * b;
}
bool try_signs(int a, int b, int c, int d, int res) {
    string sign = "+-*";
    for (int i = 0; i < 3*3*3; i++) {
        int tmp = i;
        int f[3];
        for (int j = 0; j < 3; j++) {
            f[j] = tmp % 3;
            tmp /= 3;
        }
        if (calc(calc(calc(a,b,f[0]),c,f[1]),d,f[2]) == res) {
            cout << "((" << a << sign[f[0]] << b << ")" << sign[f[1]] << c << ")" << sign[f[2]] << d << endl;
            return 1;
        }
        if (calc(calc(a,b,f[0]), calc(c,d,f[2]), f[1]) == res) {
            cout << "(" << a << sign[f[0]] << b << ")" << sign[f[1]] << "(" << c << sign[f[2]] << d << ")" << endl;
            return 1;
        }
        if (calc(calc(a,calc(b,c,f[1]),f[0]),d,f[2]) == res) {
            cout << "(" << a << sign[f[0]] << "(" << b << sign[f[1]] << c << "))" << sign[f[2]] << d << endl;
            return 1;
        }
        if (calc(a,calc(calc(b,c,f[1]),d,f[2]),f[0]) == res) {
            cout << a << sign[f[0]] << "((" << b << sign[f[1]] << c << ")" << sign[f[2]] << d << ")" << endl;
            return 1;
        }
        if (calc(a,calc(b,calc(c,d,f[2]),f[1]),f[0]) == res) {
            cout << a << sign[f[0]] << "(" << b << sign[f[1]] << "(" << c << sign[f[2]] << d << "))" << endl;
            return 1;
        }
    }
    return 0;
}

// from
// aoj0042
int dp[1010][1010];
pair<int,int> knapsack(int W, int N, vector<int> v, vector<int> w) {
    for (int i = 0; i < 1010; i++) memset(dp[i],0,sizeof(dp[i]));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if (j + w[i] <= W) {
                dp[i+1][j+w[i]] = max(dp[i+1][j+w[i]], dp[i][j] + v[i]);
            }
        }
    }
    int miw = 1e9, mxv = 0;
    for (int i = 0; i <= W; i++) {
        if (dp[N][i] > mxv) {
            mxv = dp[N][i];
            miw = i;
        }
    }
    if (mxv == 0) miw = 0;
    return {mxv, miw};
}

// from
// aoj0067
// DFS
char maze[12][12];
bool used[12][12];
int dh[4] = {0,0,1,-1};
int dw[4] = {1,-1,0,0};
void dfs(int h, int w) {
    used[h][w] = 1;
    for (int i = 0; i < 4; i++) {
        int th = h + dh[i];
        int tw = w + dw[i];
        if (th < 0 || th >= 12 || tw < 0 || tw >= 12) continue;
        if (maze[th][tw] == '0') continue;
        if (used[th][tw]) continue;
        dfs(th,tw);
    }
}

// from
// aoj0072
// union find
const int MAXN = /* set here */;
int par[MAXN];
int rk[MAXN];
void init (int n) {
  for (int i = 0; i < n; i++) {
    par[i] = i;
    rk[i] = 0;
  }
}
int fd(int x) {
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = fd(par[x]);
  }
}
void unite (int x, int y) {
  x = fd(x);
  y = fd(y);
  if (x == y) return;

  if (rk[x] < rk[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (rk[x] == rk[y]) rk[x]++;
  }
}

// from
// aoj0083, aoj0125
int count_days(int y, int m, int d) {
    int ret = 0;
    for (int i = 1; i < y; i++) {
        if (i % 400 == 0) ret += 366;
        else if (i % 100 == 0) ret += 365;
        else if (i % 4 == 0) ret += 366;
        else ret += 365;
    }
    int cnt[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    for (int i = 1; i < m; i++) {
        ret += cnt[i-1];
    }
    if (m > 2) {
        if (y % 400) ret++;
        else if (y % 100 != 0 && y % 4 == 0) ret++;
    }
    return ret + d;
}

// from
// aoj0117
void WarshallFloyd() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}


// menu
// int digitnum(int k)
// int Zeller(int year, int month, int day) (calculate the date)
// string poker_hand(vector<int> v)
// int roman_figure(string s) (ローマ数字を十進表示にする)
// string affine_cipher(string ciphertext, vector<string> keywords, char skip=' ')
// bool try_signs(int a, int b, int c, int d, int res) (数字に符号とカッコを付けるやつ)
// pair<int,int> knapsack(int W, int N, vector<int> v, vector<int> w)
// void dfs(int h, int w) (典型の島数えるやつ)
// union find
// int count_days(int y, int m, int d)
// void WarshallFloyd
