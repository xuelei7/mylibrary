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
    int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int ret = 0;
    ret += (y - 1) * 365 + (y - 1) / 400 - (y - 1) / 100 + (y - 1) / 4;
    for (int i = 1; i < m; i++) {
        ret += month[i];
    }
    if (m > 2 && (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))) ret++;
    return ret + d;
}

// from
// aoj0117, aoj0144, aoj2005
void WarshallFloyd() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

//------------------------------
// from
// aoj0156, aoj2332, aoj2608
typedef pair<int,int> P;
struct edge{int to, cost;};
const int INF = 1e9;
int V;
const int MAX_V = 1e5;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s, int *d, vector<edge> *G, int V) {
  priority_queue<P, vector<P>, greater<P>> que;
  fill(d, d + V, INF);
  d[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v] < p.first) continue;
    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

// from
// aoj0167
void BubbleSort(int n, int* a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j+1]) {
                swap(a[j],a[j+1]);
            }
        }
    }
}

// from
// aoj1275
int takeStones(int n, int m, int k) {
    int a[n+1], b[n+1];
    m--;
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
    int now = m;
    for (int cnt = n; cnt > 1; cnt--) {
        // cout << a[now%cnt]+1 << endl;
        for (int i = 0; i < cnt - 1; i++) {
            b[i] = a[(now+1+i)%cnt];
            // cout << b[i]+1 << " ";
        }
        // cout << endl;
        for (int i = 0; i < cnt - 1; i++) {
            a[i] = b[i];
        }
        now = k-1;
    }
    return a[0]+1;
}

class Dice{
private:
  int ue, st, me, usr, hdr, mg;
public:
  Dice (int a, int b, int c, int d, int e, int f) {
    ue = a;
    me = b;
    mg = c;
    hdr = d;
    usr = e;
    st = f;
  }
  void Roll (char c);
  bool operator==(const Dice& b) const {
    return (ue == b.ue && st == b.st && me == b.me && usr == b.usr && hdr == b.hdr && mg == b.mg);
  }
};

  void Dice::Roll (char c) {
    int t1 = ue;
    int t2 = me;
    int t3 = mg;
    int t4 = hdr;
    int t5 = usr;
    int t6 = st;
    if (c == 'S') {
      ue = t5;
      st = t2;
      me = t1;
      usr = t6;
      hdr = t4;
      mg = t3;
    } else if (c == 'N') {
      ue = t2;
      st = t5;
      me = t6;
      usr = t1;
      hdr = t4;
      mg = t3;
    } else if (c == 'W') {
      ue = t3;
      st = t4;
      me = t2;
      usr = t5;
      hdr = t1;
      mg = t6;
    } else if (c == 'E') {
      ue = t4;
      st = t3;
      me = t2;
      usr = t5;
      hdr = t6;
      mg = t1;
    } else {
      ue = t1;
      st = t6;
      me = t3;
      usr = t4;
      hdr = t2;
      mg = t5;
    }
  }

bool IsSame(Dice d1, Dice d2) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (d1 == d2) {
        return 1;
      }
      d2.Roll('R');
    }
    d2.Roll('W');
  }
  d2.Roll('N');
    for (int j = 0; j < 4; j++) {
      if (d1 == d2) {
        return 1;
      }
      d2.Roll('R');
    }
  d2.Roll('N');
  d2.Roll('N');
    for (int j = 0; j < 4; j++) {
      if (d1 == d2) {
        return 1;
      }
      d2.Roll('R');
    }
  return 0;
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
// void dijkstra
// void takeStones(n個の石がある円，始点m，間隔kでとり，残った石の番号を返す)
// class Dice (サイコロを扱うクラス)