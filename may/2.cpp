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

ll fun(ll x, ll y, ll z){
	return (x & z) * (y & z);
}
int main(){	
	
	ll t;cin>>t;
	while(t--){
		ll x,y,l,r, ans = 0;
		cin>>x>>y>>l>>r;
		if(x*y == 0){ 
			cout<<l<<endl;
			continue;
		}
		ll pr = fun(x,y,r);
		ll rn =  r;
		ll maxz = r;
		ll maxp = pr;
		ll cand = r;
		ll canadd;
		while(cand){
			ll mask = pow(2, floor(log2(cand))) - 1;
			cand = r&mask;
			dbug(mask & (x|y), r-(mask+1), (r&mask));
			ll z = r - (mask+1) - (r&mask) + (( x | y ) & mask);
			dbug(z);
			
					
			canadd = (mask & z) ^ mask; 
			
			dbug(canadd, z,  ((ll)(pow(2, floor(log2(r^z))) - 1 ) & z));	
			if(z + canadd < l){
				dbug("continue");
				continue;	
			}

			if(z < l){
				dbug("lesser than l");
				//ll rmask = pow(2, floor(log2(r))) - 1;
				// ll zmask = ((ll)(pow(2, floor(log2(r^z)) + 1) - 1 ) & r);

				// ll canadd = zmask & z;
					
				dbug(z, zmask, canadd);
				
				while(z < l and canadd){
					dbug(z, canadd);
					while(canadd and canadd - pow(2, floor(log2(canadd))) + z >= l){
						canadd -= pow(2, floor(log2(canadd)));
						dbug(canadd);
					}
					z += pow(2, floor(log2(canadd))); 
					canadd -= pow(2, floor(log2(canadd)));
					dbug(z, canadd);
				}
				
			}
			
			if(fun(x,y,z) == maxp and z < maxz){
				maxz = z;
			}
			
			if(fun(x,y,z) > maxp){
				maxp = fun(x,y,z);
				maxz = z;
			}
			ll prod = fun(x,y,z);
			dbug(z, prod, canadd, maxp, maxz, z + canadd);
		}
		
		ll lastadded = 0;
		dbug(maxz, maxp);
		if(maxp == 0)
			maxz = l;

		//if(r >= 2*max(x,y)){
		//	maxz = (x|y);
		//}
		

		maxz = max(maxz, l);
		cout<<maxz<<endl;
	}
    return 0;
}


