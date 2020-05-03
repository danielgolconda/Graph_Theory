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
vector <int> vis(MAXN,0);
vector <int> comp(MAXN,0);
int cc;
void c_p_c()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
void dfs(int s)
{
	vis[s] = 1;
	comp[s] = cc;
	for(int u:adj[s])
	{
		if(!vis[u])
		{
			dfs(u);
		}
	}
	return ;
}

int32_t main()
{
  c_p_c();
  int tc;
  cin >> tc;
  while(tc--)
  {
  	int n,m;
  	cin >> n >> m;
  	vector <pair<int,int>> v;
  	for(int i=0;i<m;i++)
  	{
  		int x,y;
  		string eq,h="=";
  		cin >> x >> eq >> y;
  		if(eq == h)
  		{
  			adj[x].push_back(y);
  			adj[y].push_back(x);
  		}
  		else
  		{
  			v.push_back({x,y});
  		}
  	}
  	cc = 0;
  	for(int i=1;i<=n;i++)
  	{
  		if(!vis[i])
  		{
  			cc++;
  			dfs(i);
  		}
  	}
  	int flag = 0;
  	for(int i=0;i<v.size();i++)
  	{
  		if(comp[v[i].first] == comp[v[i].second])
  		{
  			flag = 1;
  			break;
  		}
  	}
  	if(flag)
  	{
  		cout<<"NO"<<endl;
  	}
  	else
  	{
  		cout<<"YES"<<endl;
  	}
  	for(int i=1;i<=n;i++) adj[i].clear();
  	fill(vis.begin(),vis.end(),0);
  	fill(comp.begin(),comp.end(),0);
  }
  return 0;
}

