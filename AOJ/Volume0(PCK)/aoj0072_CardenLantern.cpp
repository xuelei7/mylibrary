// 灯篭
// 会津若松市は「歴史の町」として知られています。今から約 400 年前、蒲生氏郷により城下町の骨格が作られましたが、その後、徳川三代将軍家光公の異母弟「保科正之」公を藩祖とする会津藩 23 万石の中心都市として発展しました。今でも市内のいたるところに史跡や昔日の面影が残っているため、毎年、全国から多くの観光客が訪れています。

// 今年は、ＮＨＫ大河ドラマで「新選組！」が放送されているため、新選組ゆかりの地(*1)として、大幅に観光客が増加しています。そこで市では、市内に点在する史跡を結ぶ通り沿いに 100 m 間隔で灯篭を設置して飾りたてることにしました。灯篭を飾ってある通りを辿れば市内の全ての史跡に到達できるように設置することが条件ですが、一筆書きでたどれる必要はありません。しかし、予算が限られているので設置する灯篭の数を最小限にする必要があります。

// 史跡と史跡を結ぶ通りのデータを読み込んで、必要最小限の灯篭の数を出力するプログラムを作成して下さい。ただし、史跡と史跡の間の距離は 200 m 以上で、100 の倍数で与えられます。おのおのの史跡から一番近い灯篭までの距離は 100 m で、市内の史跡は 100 箇所以内です。史跡自身には灯篭を設置する必要はありません。



// (*1) 新選組は会津藩御預という形で発足、白虎隊の悲劇で知られる会津戊辰戦争に参戦、市内天寧寺に土方歳三が近藤勇の墓を建立

// Input
// 複数のデータセットが与えられます。各データセットは以下の形式で与えられます。

// n
// m
// a1,b1,d1
// a2,b2,d2
// :
// am,bm,dm
// 各データセットの最初の 1 行には史跡の箇所数 n が与えられます。続いて史跡と史跡を結ぶ通りの数 m が与えられます。続く m 行に カンマで区切られてた3 つの数数 ai, bi, di が与えられます。ai, bi は史跡の番号です。史跡の番号は 0 番から n - 1 番まで振られています。ai bi はそれらを結ぶ通りがあることを示し、di は ai bi 間の道路の距離を表します。

// n が 0 のとき入力の最後とします。データセットの数は 20 を超えません。

// Output
// 各データセットに対して、必要最小限の灯篭の数を１行に出力して下さい。

// from string, to utils(union find)

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;
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
int main() {
    int n,m;
    while (cin >> n) {
        if (n == 0) break;
        cin >> m;
        init(n);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for (int i = 0; i < m; i++) {
            string s;
            cin >> s;
            vector<int> v = split_string_to_int(s,',');
            pq.push({v[2]/100-1, {v[0],v[1]} });
        }
        int ans = 0;
        while (!pq.empty()) {
            pair<int,pair<int,int>> tp = pq.top();
            pq.pop();
            int len = tp.first;
            int from = tp.second.first;
            int to = tp.second.second;
            if (fd(from) != fd(to)) {
                ans += len;
                unite(from,to);
            }
        }
        cout << ans << endl;
    }
    return 0;
}