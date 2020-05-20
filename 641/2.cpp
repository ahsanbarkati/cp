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

vector <ll> facts(ll a){
	set <ll> st;
	st.insert(1);
	ll n=a;
	vector < pair<ll,ll>> pf;
	ll c = 0;
	while(a%2==0){
		a = a/2;
		c++;
	}
	if(c)
		pf.pb(make_pair(2,c));
	
	for(ll i = 3;i<=sqrt(n); i+=2){
		ll c = 0;
		while( a%i==0){
			a = a/i;
			c++;
		}
		if(c)
			pf.pb(make_pair(i,c));
	}
	if(a>2)
		pf.pb(make_pair(a,1));

	//rep(i, pf.size())
	//	cout<<pf[i].first<<"-"<<pf[i].second<<" ";

	for(ll i=0;i<pf.size();i++){
		pair<ll,ll> p = pf[i];
		ll f = p.first;
		ll c = p.second;
		vector<ll>inss;
		for( ll j=0;j<=c;j++)
			inss.pb(pow(f,j));
		vector<ll> ne;
		rep(i, inss.size())
			for( auto itr = st.begin(); itr!= st.end();itr++){
				ll ins = (*itr) *inss[i];
				ne.pb(ins);
			}
			rep(k,ne.size())
				st.insert(ne[k]);
		
	}


	vector <ll> ans;
	for(auto itr = st.begin(); itr!= st.end();++itr)
		ans.pb(*itr);
	return ans;
}


int main(){	
	fastIO
	
	ll t;
	cin>>t;	
	while(t--){
		ll n;
		cin>>n;
		vll a(n);
		rep(i,n)
			cin>>a[i];

		vll dp(n+1);
		//memset(dp, 0, sizeof(dp));
		rep(i,n+1)
			dp[i] = 1;
		dp[1] = 1;

		repA(i, 2, n){
			vll divs = facts(i);
			for(auto d: divs)
				if(i%d == 0 and a[i-1] > a[d-1] and dp[i] < dp[d] + 1)
					dp[i] = dp[d] + 1;
		}

		dbug(dp);

		ll ans = *max_element(dp.begin(), dp.end());
		cout<<ans<<endl;

	}	
    return 0;
}

