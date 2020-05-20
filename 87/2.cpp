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
//	fastIO
	ll t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		ll n1 = -1;
		ll n2 = -1;
		ll n3 = -1;
		ll ans = inf;
		ll n = s.length();
		rep(i, n){
			if(s[i] == '1'){
				if(n3 != -1 and n2 != -1){
					if(ans > max( i - n2 + 1, i - n3 + 1))
						ans = max( i - n2 + 1, i - n3 + 1);
				}
				n1 = i;
			}
			if(s[i] == '2'){
				if(n1 != -1 and n3 != -1){
					if(ans > max( i - n1 + 1, i - n3 + 1))
						ans = max( i - n1 + 1, i - n3 + 1);
				
				}
				n2 = i;
			}
			if(s[i] == '3'){
				if(n1 != -1 and n2 != -1){
					if(ans > max( i - n2 + 1, i - n1 + 1))
						ans = max( i - n2 + 1, i - n1 + 1);
				}
				n3 = i;
			}
		}
		if(ans == inf) ans = 0;
		cout<<ans<<endl;
	}	
    return 0;
}

