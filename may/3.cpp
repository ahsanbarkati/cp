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

bool pp  = false;
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

vll temp;
vll lens;

void dfs(vll adj[], ll u, ll visited[]){
	temp.pb(u);
	visited[u] = 1;
	for(auto v: adj[u]){
		if(not visited[v])
			dfs(adj, v, visited);
	}
}

bool done = false;

bool dfs_cycle(ll v, ll start, vll ad[], ll vis[], ll sz){
	if(done)
		return false;

	if(pp)
		cout<<"called: "<<v<<" "<<start<<" "<<sz<<endl;
	temp.pb(v);
	dbug(temp);
	
	// cycle found	
	if(vis[v] == 1 and sz == 0 and v == start){ 
		dbug("cycle", temp);
		done = true;
		lens.pb(temp.size()-1);
		rep(i, temp.size() - 1){
			ad[temp[i]][temp[i+1]]--;
		}
		if(temp.size())
			temp.pop_back();
		return true;
	}

	if(sz == 0){
		dbug("deadend");
		temp.pop_back();
		return false;
	}
	
	vis[v] = 1;
	bool found = false;
	rep(i, ad[v].size()){
		// is visitable
		if(ad[v][i] > 0 and vis[i] != 2){
			bool cur = dfs_cycle(i, start, ad, vis, sz-1);
			found = found or cur;
		}
	}
	
	if(temp.size())
		temp.pop_back();

	vis[v] = 2;
	if(found)
		return true;

	return false;
} 

map <pair<ll,ll>, ll > already;
int main(){	
	//aastIO
	ll t;cin>>t;
	while(t--){
		temp.clear();
		lens.clear();
		already.clear();
		ll n,m,len=0;
		cin>>n>>m;
		vll v(n);
		rep(i,n)cin>>v[i];
		vector<pair<ll,ll> >vpr;
		
		vll adj[n];
		rep(i,n)
			dbug(adj[i]);
		rep(i,m){
			ll u,v;
			cin>>u>>v;
			if(already.find(mpr(u,v)) == already.end() and already.find(mpr(v,u)) == already.end()){
			adj[u-1].pb(v-1);
			adj[v-1].pb(u-1);
			already[mpr(u,v)] = 1;
			}

		}
		rep(i,n)
			dbug(i, adj[i]);
		
		map<ll,ll> mp;
		ll visited[n];
		memset(visited, 0, sizeof(visited));
		vector<vll> comps;
		
		rep(i,n){
			temp.clear();
			if(not visited[i])
				dfs(adj, i, visited);
			if(temp.size()){
				sort(temp.begin(), temp.end());
				comps.pb(temp);
				for(auto x:temp){
					mp[x] = comps.size()-1;
				}
			}
		}
		
		rep(i, comps.size())
				dbug(i, comps[i]);

		vll vals;

		rep(rand, 1){
			lens.clear();
			temp.clear();
			ll cn = comps.size();
			vll ad[cn];
			rep(i,cn){
				ad[i].resize(cn);
				rep(k,cn) ad[i][k] = 0;

				for(auto j: comps[i]){
					dbug(j, mp[j], mp[v[j]-1])
					if(mp[j] != mp[v[j]-1]){
						ad[i][mp[v[j]-1]] += 1;
					}
				}
			}
			vll szs;
			repA(i, 2, cn) szs.pb(i);
			// if(rand != 0)
			// random_shuffle(szs.begin(), szs.end());
			for(auto s: szs){
				bool isit = true;
				while(isit){
					done = false;
					isit = false;
					vll verts;
					rep(i, cn) verts.pb(i);
			//		if(rand !=0)
			//		random_shuffle(verts.begin(), verts.end());
					for(auto i: verts){
						ll vis[cn];
						memset(vis, 0, sizeof(vis));
						temp.clear();
						isit = (isit or dfs_cycle(i, i, ad, vis, s));
					}
				}
			}
			ll ans = 0;
			dbug(lens);
			rep(i, lens.size())
				ans+=lens[i]-1;
			if(lens.size())
			vals.pb(ans);

		}
		if(vals.size() == 0)
			vals.pb(0);

		cout<<*min_element(vals.begin(), vals.end())<<endl;


	}	
    return 0;
}

