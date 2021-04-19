// Problem D Hidden Anagrams
// An anagram is a word or a phrase that is formed by rearranging the letters of another. For instance, by rearranging the letters of "William Shakespeare," we can have its anagrams "I am a weakish speller," "I'll make a wise phrase," and so on. Note that when $A$ is an anagram of $B$, $B$ is an anagram of $A$.

// In the above examples, differences in letter cases are ignored, and word spaces and punctuation symbols are freely inserted and/or removed. These rules are common but not applied here; only exact matching of the letters is considered.

// For two strings $s_1$ and $s_2$ of letters, if a substring $s'_1$ of $s_1$ is an anagram of a substring $s'_2$ of $s_2$, we call $s'_1$ a hidden anagram of the two strings, $s_1$ and $s_2$. Of course, $s'_2$ is also a hidden anagram of them.

// Your task is to write a program that, for given two strings, computes the length of the longest hidden anagrams of them.

// Suppose, for instance, that "anagram" and "grandmother" are given. Their substrings "nagr" and "gran" are hidden anagrams since by moving letters you can have one from the other. They are the longest since any substrings of "grandmother" of lengths five or more must contain "d" or "o" that "anagram" does not. In this case, therefore, the length of the longest hidden anagrams is four. Note that a substring must be a sequence of letters occurring consecutively in the original string and so "nagrm" and "granm" are not hidden anagrams.

// Input
// The input consists of a single test case in two lines.

// $s_1$
// $s_2$
// $s_1$ and $s_2$ are strings consisting of lowercase letters (a through z) and their lengths are between 1 and 4000, inclusive.

// Output
// Output the length of the longest hidden anagrams of $s_1$ and $s_2$. If there are no hidden anagrams, print a zero.

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (int)(a); (i) < (int)(b); (i)++)
#define rrep(i, a, b) for (int i = (int)(b) - 1; (i) >= (int)(a); (i)--)
#define all(v) v.begin(), v.end()

typedef long long ll;
template <class T> using V = vector<T>;
template <class T> using VV = vector<V<T>>;

/* 提出時これをコメントアウトする */
#define LOCAL true

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

const int MAX = 500000, MS = 2;
const long long mod[] = {999999937LL, 1000000007LL}, base = 9973;

auto solve (string S, string T) -> int {

    int n = S.size();
    int m = T.size();

    rrep(i,1,min(m,n)+1) { // 長さ
        V<int> cnt(26,0);
        set<V<int>> st;

        // Sの構築
        rep(j,0,i) {
            cnt[S[j] - 'a']++;
        }
        st.insert(cnt);
        rep(j,i,n) {
            cnt[S[j-i]-'a']--;
            cnt[S[j]-'a']++;
            st.insert(cnt);
        }

        // Tの探索
        rep(i,0,26) cnt[i] = 0;
        rep(j,0,i) {
            cnt[T[j] - 'a']++;
        }
        if (st.count(cnt)) return i;
        rep(j,i,m) {
            cnt[T[j-i]-'a']--;
            cnt[T[j]-'a']++;
            if (st.count(cnt)) return i;
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    string s1,s2;
    cin >> s1 >> s2;
    auto ans = solve(s1,s2);
    cout << ans << endl;
    
    
    return 0;
}