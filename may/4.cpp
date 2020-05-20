#include<bits/stdc++.h>
#include<stdio.h>
#include<iostream>

using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define trav(a,x) for(auto &a:x)
#define rep(i,n) for(long i=0;i<(n);i++)
#define repA(i,j,n) for(long i=(j);i<=n;++i)
#define repD(i,j,n)   for(long i=(j);i>=(n);--i)
#define fillz(a)  memset(a, 0, sizeof (a))
#define pb push_back
#define mpr make_pair
#define F first
#define S second
#define endl "\n"

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
typedef vector<ll> vll;
typedef vector<ld> vld;

#ifdef DEBUG
#include "/home/ash/.vim/debug.h"
#else
    #define dbug(args...)
#endif

void add( map<ll,ll> &m, ll x,ll cnt=1){
    auto jt=m.find(x);
    if(jt==m.end())	m.insert({x,cnt});
    else	jt->S += cnt;
}
 
void del( map<ll,ll> &m, ll x,ll cnt=1){
    auto jt=m.find(x);
    if(jt->S<=cnt)	m.erase(jt);
    else jt->S -= cnt;
}

ll powr(ll x, ll y, ll p) { 
    ll res = 1;x = x % p; 
    while (y > 0){
    	if (y & 1) res = (res*x) % p; 
        y = y>>1;x = (x*x) % p;} 
    return res; 
}


const ll inf = 0xFFFFFFFFFFFFFFFL;
const ll mod = 1000000007L;
ll mo = 998244353;
int main(){	
//	fastIO
	ll m, n, q;
	cin>>m>>n>>q;
	vll a(n);
	rep(i,n)
		cin>>a[i];
	ll ways[m][n];
	memset(ways, 0, m * sizeof(ways[0]));
	rep(i,m)
		ways[i][0] = powr(a[0], i+1, mo);

	ways[0][0] = a[0];
	repA(j, 1, n-1)
		ways[0][j] = (a[j] * ways[0][j-1])%mo;

	repA(i, 1, m-1){
		repA(j, 1, n-1){
			ways[i][j] = (a[j] * (ways[i-1][j] + ways[i][j-1]) % mo)%mo;
		}
	}
//	rep(i,m){
//		rep(j,n)
//			cout<<ways[i][j]<<" ";
//		cout<<endl;
//	}

	ll ans = 1;
	while(q--){
		ans = 0;
		ll k;
		cin>>k;
		cout<<ways[k-1][n-1]<<endl;
	}	
    return 0;
}

