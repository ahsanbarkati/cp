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
bool cmp(vll a, vll b){
	return (a.size() > b.size());
}

int main(){	
	//fastIO

	ll t;
	cin>>t;

	while(t--){
		ll n,k;
		cin>>n>>k;
		vll v(n);
		vll a(n);
		map<ll, ll> mp;
		rep(i,n){
			cin>>v[i];
			a[i] = v[i];
			mp[v[i]] = i;
		}
		vector<vll> cycles;
		ll len = 0;
		for(int i=0;i<n;i++){
			int j = i;
			vll tmp;
			if(v[i] == 0 or v[i]-1 == i)continue;
			while(v[j]){
				tmp.pb(j);
				ll r = v[j];
				v[j] = 0;
				j = r - 1;
			}
			len+= tmp.size()-1;
			cycles.pb(tmp);
		}
		dbug(cycles);
		vector<vll> ans;
		sort(cycles.begin(), cycles.end(), cmp);
		if(len%2){
			cout<<-1<<endl;
			continue;
		}
		vector<vll> c2;
		for (auto c: cycles){
			if(c.size()>2)
			for(int i=0;i+2<c.size();i+=2){
				ans.pb({c[0], c[i+1], c[i+2]});
			}

			//else if(c.size()==2)c2.pb(c);
			if(c.size()%2==0)c2.pb({c[0], c[c.size()-1]});
		}

		dbug(c2);
		dbug(ans);
		for(int i=0;i+1<c2.size();i+=2){
			ans.pb({c2[i][0], c2[i+1][1], c2[i][1]});
			ans.pb({c2[i+1][0], c2[i+1][1], c2[i][1]});
		}
		dbug(ans);
		if(k>=ans.size()){
			cout<<ans.size()<<endl;
			for(auto u:ans)
				cout<<u[0]+1<<" "<<u[1]+1<<" "<<u[2]+1<<endl;
		}
		else{
			cout<<-1<<endl;
			continue;
		}
		dbug(ans);

	}
    return 0;
}

