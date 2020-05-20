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


ll lcm(ll a, ll b){
	return a*b / __gcd(a,b);
}
int main(){	
	//fastIO
	
	ll n;
	cin>>n;
	vll a(n);
	rep(i,n)cin>>a[i];
	
	map<ll, vll> mp;
	rep(i,n){
		ll c = 0;
		ll m = a[i];
		while(m % 2 == 0){
			m/=2;
			c++;
		}
		mp[2].pb(c);
		for(ll d = 3; d <= sqrt(a[i]); d+=2){
			c = 0;
			while(m % d == 0){
				m/=d;
				c++;
			}
			mp[d].pb(c);
		}
		if(m>2)
			mp[m].pb(1);
	}

	ll ans = 1;
	for(auto m: mp){
		vll temp = m.S;
		sort(temp.begin(), temp.end());
		if(temp.size() == n){
			ans *= pow(m.F, temp[1]);
		}
		else if(temp.size() == n-1) ans *= pow(m.F, temp[0]);

	}
	cout<<ans<<endl;
	


    return 0;
}

