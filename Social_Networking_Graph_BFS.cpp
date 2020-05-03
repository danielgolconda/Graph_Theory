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
  int n,e;
  cin >> n >> e;
  vector <int> adj[n+1];
  for(int i=0;i<e;i++)
  {
  	int x,y;
  	cin >> x >> y;
  	adj[x].push_back(y); adj[y].push_back(x);
  }
  vector <int> vis(n+1,0);
  vector <int> num(n+1,0);
  int query;
  cin >> query;
  while(query--)
  {
  	for(int i=0;i<=n;i++) vis[i] = 0,num[i] = 0;
  	int s,dist;
  	cin >> s >> dist;
  	queue <int> q;
  	q.push(s);
  	int l = 0,c = 0;
  	while(!q.empty())
  	{
  		int k = q.size();
  		num[l] = c;
  		c=0;
  		l++;
  		for(int i=0;i<k;i++)
  		{
  			int f = q.front();
  			q.pop();
  			vis[f] = 1;
  			for(int u:adj[f])
  			{
  				if(!vis[u])
  				{
  					c++;
  					vis[u] = 1;
  					q.push(u);
  				}
  			}
  		}
  	}
  	cout<<num[dist]<<endl;
  }
  return 0;
}

