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
const int MAXN = 1e5+1;
vector <pair<int,int>> adj[MAXN];

void c_p_c()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
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
  	for(int i=0;i<=n;i++) adj[i].clear();
  	for(int i=0;i<m;i++)
  	{
  		int x,y,w;
  		cin >> x >> y >> w;
  		adj[x].push_back({y,w});
  		adj[y].push_back({x,y});
  	}
  	int src,dest;
  	cin >> src >> dest;
  	vector <int> dist(n+1,inf);
  	priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minh;
  	minh.push({0,src});
  	dist[src] = 0;
  	while(!minh.empty())
  	{
  		int k = minh.size();
  		while(k--)
  		{
  			int d = minh.top().first;
  			int f = minh.top().second;
  			minh.pop();
  			if(d > dist[f]) continue;
  			for(pair<int,int> u:adj[f])
  			{
  				if(d+u.second < dist[u.first])
  				{
  					dist[u.first] = d+u.second;
  					minh.push({dist[u.first],u.first});
  				}
  			}
  		}
  	}
  	if(dist[dest] == inf)
  	{
  		cout<<"NO"<<endl;
  	}
  	else
  	{
  		cout<<dist[dest]<<endl;
  	}
  }
  return 0;
}

