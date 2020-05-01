#include<bits/stdc++.h>
using namespace std;
 
#define ff              first
#define ss              second
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
#define int             long long
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
//#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1e5+1;
vector <int> adj[MAXN];
vector <int> vis(MAXN);
int len,node;
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


void dfs(int s,int h)
{
  //cout<<h<<endl;
  vis[s] = 1;
  if(h > len)
  {
    len = h;
    node = s;
  }
  for(int u:adj[s])
  {
    if(!vis[u])
    {
      dfs(u,h+1);
    }
  }
  return ;
}
int32_t main()
{
 c_p_c();
  fill(vis.begin(),vis.end(),0);
 int n;
  cin >> n;
  for(int i=0;i<n-1;i++)
  {
    int x,y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  len = INT_MIN,node = 0;
  dfs(1,0);
  fill(vis.begin(),vis.end(),0);
  dfs(node,0);
  cout<<len<<endl;
 return 0;  
}
