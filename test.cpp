#pragma GCC optimize("Ofast") 
#include <bits/stdc++.h>
using namespace std;
using ll = long long int ;
using P = pair<ll,ll>;
using Graph= vector<vector<ll>>;
struct edge{ll to ; ll cost ;} ;
using graph =vector<vector<edge>> ;
#define rep(i,n) for (ll i=0; i < (n); ++i)
#define rep2(i,n,m) for(ll i=n;i<=m;i++)
#define rep3(i,n,m) for(ll i=n;i>=m;i--)
#define pb push_back 
#define eb emplace_back 
#define ppb pop_back 
#define mpa make_pair 
#define fi first  
#define se second  
#define set20 cout<<fixed<<setprecision(20) ;  
const ll INF=1e18 ;   
inline void chmax(ll& a,ll b){a=max(a,b);}  
inline void chmin(ll& a,ll b){a=min(a,b);} 
long double pi=acos(-1) ;  
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}  
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;} 
ll dx[4] {1,0,-1,0} ;
ll dy[4] {0,1,0,-1} ;

struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n,-1) {}
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
};


ll dp(ll x, Graph & g){
  vector<ll> A ;
  for(auto v : g[x]){
   A.pb(dp(v,g)) ;
  }
  sort(A.rbegin(),A.rend()) ;
  ll ans=0 ;
  ll k= A.size() ;
  rep(i,k){
    chmax(ans,i+1+A[i]) ;
  }
  return ans ;
}

int main(){
  ios::sync_with_stdio(false) ;
  cin.tie(nullptr) ;
  ll a,b ; 
  while(cin>>a>>b){
  ll c=a+b ;
  ll ans = 0 ;
  while(c>0){
    c/=10 ;
    ans++ ;
  }
  cout<<ans<<endl ;
  }
  return 0 ;
}


