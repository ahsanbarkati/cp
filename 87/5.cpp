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


void add(vll &bit, ll ind, ll val){
	while(ind < bit.size()){
		bit[ind] += val;	
		ind += ind & (-ind);
	}
}

ll sum(vll &bit, ll ind){
	ll ans = 0;
	while(ind > 0){
		ans += bit[ind];
		ind -= ind & (-ind);
	}
	return ans;
}

ll search(vll &bit, ll k, ll low, ll high){
	ll mid;
	while(low <= high){
		mid = low + (high - low)/2;

		if(sum(bit, mid) > k)
			high = mid-1;

		else if(sum(bit, mid) < k)
			low = mid +1; 

		else return mid;	
	}

	return mid;
}
int main(){	
	fastIO
	ll n, q, k;
	cin>>n>>q;
  	vll arr(n+1), bit(n+1);
	rep(i,n+1){
		bit[i] = 0;
	}

	ll tmp;
	rep(i,n){
		cin>>tmp;
		add(bit, tmp, 1);
	}
	dbug(bit);
	
	while(q--){
		cin>>k;
		if(k < 0){	// remove
			k *= -1;
			dbug(search(bit, k, 1,n));
			add(bit, search(bit, k, 1, n), -1);
		}
		else {
			add(bit, search(bit, k, 1, n), 1);
		}
	}
	dbug(bit);
	ll ans = 0;
	rep(i, n+1)
		if(bit[i] != 0){
			ans = i;
			break;
		}

	cout<<ans<<endl;
	return 0;
}

