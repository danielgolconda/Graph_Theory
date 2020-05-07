#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MAXN = 1e6+1;
vector <int> adj[MAXN];
vector <int> vis(MAXN);
int timer;
int low[MAXN],in[MAXN];
set <int> AP; // Articulation Points
void c_p_c()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
void dfs(int s,int par)
{
	vis[s] = 1;
	int child = 0;
	low[s] = in[s] = timer++;
	for(int u:adj[s])
	{
		if(u == par) continue;
		if(vis[u] == 1)
		{
			// Back Edge
			low[s] = min(low[s],in[u]);
		}
		else
		{
			// Forward Edge
			child++;
			dfs(u,s);
			low[s] = min(low[s],low[u]); 
			if(low[u] >= in[s] && par != -1) // Not Root and AP
			{
				AP.insert(s);
			}

		}
	}
	if(par == -1 && child > 1) // IF parent and child > 1
	{
		AP.insert(s);
	}
}
int32_t main()
{
  c_p_c();
  while(1)
  {
  	timer = 0;
  	int n,m;
  	cin >> n >> m;
  	if(n == 0 && m == 0)
  	{
  		break;
  	}
	  for(int i=1;i<=m;i++)
	  {
	  	adj[i].clear();
	  	vis[i] = 0; low[i] = 0,in[i] = 0;
	  }
	  for(int i=0;i<m;i++)
	  {
	  	int x,y;
	  	cin >> x >> y;
	  	adj[x].push_back(y);
	  	adj[y].push_back(x);
	  }
	  for(int i=1;i<=n;i++)
	  {
	  	if(vis[i] == 0)
	  	{
	  		dfs(i,-1);
	  	}
	  }
	  cout<<AP.size()<<endl;
	  AP.clear();
  }
  return 0;
}

