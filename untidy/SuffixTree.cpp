#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
const int MAXN = 1000010 * 2;
int n;
int s[MAXN];
pair<int,ll> p[MAXN];
int tsz = 1;
string str;

struct node{
    int l, r, parent;
    int link;
    map<int,int> next;
    node (int l = 0, int r = 0, int parent = 0): l(l), r(r), parent(parent) {
        link = -1;
        next.clear();
    }
} t[MAXN];

struct state{
    int v, len;
    state(int v = 0, int len = 0): v(v), len(len) {}
} ptr;

int len(int k) {
    return t[k].r - t[k].l;
}

state go(state st, int l, int r) {
    while (l < r) {
        if (st.len == len(st.v)) {
            if (!t[st.v].next.count(s[l])) return state(-1,-1);
            st = state(t[st.v].next[s[l]], 0);
        } else {
            if (s[t[st.v].l + st.len] != s[l]) return state(-1,-1);
            int d = min(len(st.v) - st.len, r - l);
            l += d;
            st.len += d;
        }
    }
    return st;
}

int split(state st) {
    if (st.len == 0) return t[st.v].parent;
    if (st.len == len(st.v)) return st.v;
    int cur = tsz++;
    t[cur] = node(t[st.v].l, t[st.v].l + st.len, t[st.v].parent);
    t[cur].next[s[t[st.v].l + st.len]] = st.v;
    t[t[st.v].parent].next[s[t[st.v].l]] = cur;
    t[st.v].parent = cur;
    t[st.v].l += st.len;
    return cur;
}

int link(int v) {
    int& ans = t[v].link;
    if (ans != -1) return ans;
    if (v == 0) return ans = 0;
    int p = t[v].parent;
    int nextp = link(p);
    state pos = go(state(nextp, len(nextp)), t[v].l + (p == 0), t[v].r);
    int ret = split(pos);
    return ans = ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> str;
    n = str.size();
    for (int i = 0; i < n; i++) {
        while (1) {
            state next = go(ptr,i,i+1);
            if (next.v != -1) {
                ptr = next;
                break;
            }
            int mid = split(ptr);
            int cur = tsz++;
            t[cur] = node(i,n,mid);
            t[mid].next[s[i]] = cur;
            if (mid == 0) break;
            ptr = state(link(mid), len(link(mid)));
        }        
    }
    return 0;
}