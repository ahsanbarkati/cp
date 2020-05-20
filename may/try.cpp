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

clock_t time_p=clock();
void oktime(){
	time_p = clock() - time_p;
	cerr<<"Time Taken: "<<(float)(time_p)/CLOCKS_PER_SEC<<endl;
}

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

int main(){	
	//fastIO
	ll t;
	cin>>t;
	while(t--){
		ll x,y,l,r;
		cin>>x>>y>>l>>r;
		if(x*y==0)
			cout<<0<<endl;
		else
		cout<<(x|y)<<endl;
	}	
    return 0;
}

