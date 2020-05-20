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
	ll t;
	cin>>t;
	while(t--){
		ll n;cin>>n;
		vll a(n);
		rep(i,n)
			cin>>a[i];
		sort(a.begin(), a.end());
		map<ll, ll> sz;
		ll cnt = 0;
		ll cur = 0;
		for(ll i = 0;i<n;i++){
			dbug(i, cur);
			while(cur < a[i]){
				cur++;
				break;
			}
			dbug(i, cur, cnt);
			if(cur >= a[i]){
				cnt++;
				cur = 0;
			}
		}
		cout<<cnt<<endl;
	}	
    return 0;
}

