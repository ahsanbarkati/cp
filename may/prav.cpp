#define INF LLONG_MAX
#define ll long long int
 
#include<bits/stdc++.h>
using namespace std;
 
void input(ll a[], ll n)
{
    for(ll i = 1; i <= n; i++)
        cin >> a[i];
}

void print(ll a[], ll n)
{
    for(ll i = 1; i <= n; i++)
        cout << a[i] << ' ';
    cout << '\n';
}

void print(vector<ll> a, ll n)
{
    for(ll i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << '\n';
}

void DFS(vector<ll> adj[], ll color[], ll n, ll u, ll col)
{
    ll k = adj[u].size();
    for(ll i = 0; i < k; i++)
    {
        ll v = adj[u][i];
        if(color[v])
            continue;
        color[v] = col;
        DFS(adj, color, n, v, col);
    }
}

void swap(ll p[], ll pos[], ll i, ll j)
{
    ll temp = p[i];
    p[i] = p[j];
    p[j] = temp;
    pos[p[i]] = i;
    pos[p[j]] = j;
}

void solve()
{
    ll n, m, x, y;
    cin >> n >> m;
    ll p[n + 1], pos[n + 1];
    for(ll i = 1; i <= n; i++)
    {
        cin >> p[i];
        pos[p[i]] = i;
    }
    // print(pos, n);
    vector<ll> adj[n + 1];
    for(ll i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    // for(ll i = 1; i <= n; i++)
    // {
    //     ll k = adj[i].size();
    //     print(adj[i], k);
    // }
    ll color[n + 1] = {0};
    vector<ll> nwc[n + 1];
    for(ll i = 1; i <= n; i++)
    {
        if(color[i])
            continue;
        DFS(adj, color, n, i, i);
    }
    // print(color, n);
    for(ll i = 1; i <= n; i++)
        nwc[color[i]].push_back(i);
    // for(ll i = 0; i <= n; i++)
    //     print(nwc[i], nwc[i].size());
    ll k = nwc[0].size(), ans = 0;
    for(ll i = 0; i < k; i++)
    {
        ll q = nwc[0][i];
        if(p[q] != q)
        {
            swap(p, pos, q, pos[q]);
            ans++;
        }
    }
    // print(p, n);
    // cout << ans << '\n';
    // for(ll i = 1; i <= n; i++)
    // {
    //     if(color[p[i]] != color[i])
    //     {
    //         k = nwc[color[p[i]]].size();
    //         for(ll j = 0; j < k; j++)
    //         {
                
    //         }
    //     }
    //     // print(p, n);
    //     // cout << ans << '\n';
    // }
    for(ll i = 1; i <= n; i++)
    {
        ll c = color[p[i]];
        if(c == color[i])
            continue;
        ll flag = 0;
        for(ll j = 1; j <= n; j++)
        {
            if(color[i] == color[p[j]] && c == color[j])
            {
                swap(p, pos, i, j);
                ans++;
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            // print(p, n);
            // cout << ans << '\n';
            continue;
        }
        for(ll j = 1; j <= n; j++)
        {
            if(color[i] == color[p[j]] && color[p[j]] != color[j])
            {
                swap(p, pos, i, j);
                ans++;
                break;
            }
        }
        // print(p, n);
        // cout << ans << '\n';
    }
    // print(p, n);
    cout << ans << '\n';
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t;
    cin >> t;
    while(t--)
        solve();
    
    return 0;
}
