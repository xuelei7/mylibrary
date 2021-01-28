// ボウリング
// クラスのレクリエーションとしてボウリングを行うことになりました。参加者ごとの投球情報を入力とし、得点の高い順に成績情報を出力するプログラムを作成してください。なお、同点の場合は学籍番号の若い順に出力してください。ただし参加者は 3 名以上 40 名以下とし、1人当たり1ゲームずつ投球しているものとします。

// ボウリングとは、プレイヤーに対して頂点を向けて正三角形に並べられた、10 本のピンをめがけてボールを転がし、ピンを倒すスポーツです。 1 回目の投球ですべて転倒した場合をストライクと言い、その投球のみで次のフレームに進みます。ストライクでない場合は、残ったピンをそのままにして 2 回目の投球を行います。2 回目の投球ですべて転倒した場合をスペアと言います。2 回目の投球終了後、次のフレームに進みます。

// 1 ゲームは 10 のフレームから構成され、第 1 から第 9 の各フレームは 2 回投球できます。各フレームの開始時点では、10 本のピンがすべて立った状態で用意されます。第 10 フレームは、ストライクもしくはスペアが出た場合には計 3 回の投球を、それ以外の場合は 2 回の投球を行い、ゲーム終了となります。

// スコア例１


// スコア例２（最高得点300点の場合）


// スコア計算の方法

// 各フレームにおいてスペア、ストライクがない場合は、 2 回の投球で倒したピンの本数がそのフレームの得点となります。（スコア例１の第 4 フレームと第 8 フレーム）
// スペアを出した場合、倒した本数である 10 点に加え、次の投球で倒したピンの本数がこのフレームの得点に加算されます。（スコア例１の第 1 フレームと第 2 フレームの関係など）スコア例１の第 1 フレームでは第 2 フレームの 1 投で倒した 10 本（点）を加えた 20 点が得点となります。第 3 フレームも同様の計算方法です。
// ストライクを出した場合、倒した本数である 10 点に加え、続く 2 回の投球で倒したピンの本数が加算されます。（スコア例１の第 2 フレームと第 3 フレームの関係など）もちろん続く 2 投中にストライクの場合があります。（スコア例１の第 5 フレームと第 6、7 フレームの関係など）
// 第 10 フレームのみ、スペア、ストライクを出した場合、3 投して倒したピンの総数が第 10 フレームの得点として加算されます。
// 各フレームの得点の合計が 1 ゲームの得点となり、最高得点は 300 点となります。
// Input
// 複数のデータセットの並びが入力として与えられます。入力の終わりはゼロひとつの行で示されます。 各データセットは以下の形式で与えられます。

// m
// score1
// score2
// :
// scorem
// 1行目に参加者数 m （3 ≤ m ≤ 40）、続くm 行にi 人目の参加者情報 scorei が与えられます。各参加者情報は１行ずつ次の形式で与えられます。

// id s1 s2 ... sn
// 先頭に学籍番号id (0 ≤ id ≤ 9999)、続いて第 j 投の転倒ピン数 sj (0 ≤ sj ≤ 10) が与えられます。総投球数 n は、12 以上 21 以下であり、得点計算に必要なピン数が過不足なく与えられるものとします。

// Output
// 入力データセットごとに、学籍番号と得点を、得点の高い順（同点の場合は学籍番号の若い順）に出力します。学籍番号と得点を１つの空白で区切って１行に出力してください。

#include <bits/stdc++.h>
using namespace std;

int solve() {
    int score = 0;
    bool st[22] = {}, sp[22] = {};
    int fr = 1, th = 1, bf = 0, third = 0;
    vector<int> v;
    for (int i = 0; i < 21; i++) {
        int num;
        cin >> num;
        // cout << fr << ":" << th << " " << num << " " << bf << endl;
        v.push_back(num);
        score += num;
        if ((int)v.size() - 2 >= 0 && sp[v.size()-2]) {
            score += num;
            // cout << "Spare plus " << num << endl;
        }
        if ((int)v.size() - 2 >= 0 && st[v.size()-2]) {
            score += num;
            // cout << "Strike 1 plus " << num << endl;
        }
        if ((int)v.size() - 3 >= 0 && st[v.size()-3]) {
            score += num;
            // cout << "Strike 2 plus " << num << endl;
        }
        if (fr == 10) {
            if (th == 1) {
                bf = num;
                if (num == 10) third = 1;
                th++;
                continue;
            } else if (th == 2 && (num == 10 || num + bf == 10 || third)) {
                th++;
                continue;
            } else {
                break;
            }
        }
        if (th == 1 && num == 10) {
            st[v.size()-1] = 1;
            fr++;
            th = 1;
            bf = 0;
            // cout << "Strike" << endl;
        } else if (th == 1 && num != 10) {
            bf = num;
            th++;
        } else if (th == 2 && num + bf == 10) {
            sp[v.size()-1] = 1;
            fr++;
            th = 1;
            bf = 0;
            // cout << "Spare" << endl;
        } else {
            fr++;
            th = 1;
            bf = 0;
        }
        // cout << score << endl;
    }
    return score;
}

struct Score {
    int id, score;
    Score(int id=0, int score=0):id(id),score(score) {}
    bool operator < (const Score& s) const {
        if (score != s.score) return score > s.score;
        return id < s.id;
    }
};

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<Score> v;
        for (int i = 0; i < n; i++) {
            int id;
            cin >> id;
            int score = solve();
            v.push_back(Score(id,score));
        }
        sort(v.begin(),v.end());
        for (int i = 0; i < n; i++) {
            cout << v[i].id << " " << v[i].score << endl;
        }
    }
    return 0;
}