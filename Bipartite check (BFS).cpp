///this works for a connected graph

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

#include<bits/stdc++.h>
#include<cmath>
#include<cstdlib> //for qsort
#include<cstdio>

#define rep(x,a,b) for(x=a;x<b;x++)
#define reptill(x,a,b) for(x=a;x<=b;x++)

#define scani(x) scanf("%d",&x)
#define scan2i(x,y) scanf("%d %d",&x,&y)
#define scan3i(x,y,z) scanf("%d %d %d",&x,&y,&z)

#define scanfl(x) scanf("%f",&x)
#define scanc(x) scanf("%c",&x)
#define scand(x) scanf("%lf",&x)

#define scanll(x) scanf("%lli",&x)
#define scan2ll(x,y) scanf("%lli %lli",&x,&y)
#define scan3ll(x,y,z) scanf("%lli %lli %lli",&x,&y,&z);

#define scanl(x) scanf("%ld",&x)
#define scans(x) scanf("%s",x)
#define printi(x) printf("%d\n",x)
#define printl(x) printf("%ld\n",x)
#define printll(x) printf("%lli\n",x)
#define printd(x) printf("%lf\n",x)
#define printfl(x) printf("%f\n",x)
#define printc(x) printf("%c\n",x)
#define prints(x) printf("%s\n",x);
#define sloop(x) loop(i,0,strlen(x)-1)
#define newl cout<<"\n"
#define FILL(A,value) memset(A,value,sizeof(A))


#define whole(x) x.begin(),x.end()
#define pb push_back
#define in insert
#define mp make_pair
#define get(tp_name,x) (get<x>(tp_name))   ///to access tuple(i)
#define umap unordered_map



using namespace std;


#define F first
#define S second



///Optional

///vector< vector<int> > costs(N, vector<int>(M, 0));   //NxM 2d preinitialized(0) vector

 ///comparator class for ordering on the basis of 'Second'
/*
class CompareDist
{
	public:				///pairType doesn't name a type ,its just to show type of pair object passed in operatorfunction

    bool operator()( pairType p1, pairType p2) {
        return p1.S>p2.S;
    }
};
*/

typedef pair<int,int> II;
typedef pair<ll,ll> LL;
typedef vector<II> VII;
typedef vector<LL> VLL;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<ll> VL;
typedef vector< VI > VVI;
typedef vector< VL > VVL;
typedef vector<string> VS;

inline bool inc_range(int x,int y,int z) { return ((x>=y)&&(x<=z)); }
inline bool ex_range(int x,int y,int z) { return ((x>y)&&(x<z)); }
inline bool is_either(int x,int y,int z) { return ((x==y)||(x==z)); }

//maths
#define PI acos(-1)

#define INTmax numeric_limits<int>::max()
#define LLmax numeric_limits<ll>::max()
#define ULLmax numeric_limits<ull>::max()

#define INTmin numeric_limits<int>::min()


typedef priority_queue<II,vector<II>, greater<II> > P_Queue;             ///priority queue contianing II (having vector<II> as underlying container) with greater as functor
																		///		heapify on the basis of comparisons of  II.first  values

template<typename type>
void get_arr(type a[],type n) {for(type i=0;i<n;i++) cin>>a[i];}

template<typename type>
void show_arr(type a[],type n=1) {for(type i=0;i<n;i++) cout<<a[i]<<" ";}

template<typename type>
inline type max3(type a,type b,type c){	 return max(max(a,b),c);}

template<typename type>
inline type min3(type a,type b,type c){	 return min(a,min(b,c));}

template<typename type>
inline type min4(type a,type b,type c,type d){	 return min(a,min3(b,c,d));}


template<typename type>
type modpowIter(type a, type b, type c) { type ans=1;  while(b != 0){ if(b%2 == 1) ans=(ans*a)%c;  a=(a*a)%c; b /= 2; } return ans; }

template<typename type>
type phi(type n){ type result = n;  for (type p=2; p*p<=n; ++p) { if (n % p == 0){ while (n % p == 0)   n /= p; result -= result / p; } }
if (n > 1) result -= result / n; return result;
}



template<class type>
type ncr(type n,type r)
{  	assert(n>=r);
	type ans=1,i;
	if(n==r) return 1; if(r==1) return n; if(r>(n-r)) r=n-r;
	reptill(i,0,r-1) ans=ans*(n-i)/(i+1);
	return ans;
}
template<typename type>  unsigned long long fact(type x){ ull ans=1; for(type i=1;i<=x;i++){ ans*=i;        /*ans%=MOD;   /Optional*/ } return ans; }

template<typename type>
int Digs(type n){ return (n >= 10) ? 1 + Digs(n/10): 1; }


inline void FAST_IO(){ios_base::sync_with_stdio(false);}



#define SIZE (int(2e3)+1)
#define MOD
#define debug
#define MAX1
#define MAX2

//#define Online_judge

class Graph
{
    int n;    // No. of vertices

    VVI adj;

    VI color;	///vector storing color of each vertex initially ,(all uncolored)
	VB visited;

	public:
    // Constructor and destructor
    Graph(int n)
    {
		this->n = n;
		color = VI(n+1,-1);
		visited= VB(n+1,false);

		adj= VVI(n+1);

    }
	///I don't know how to create a destructor for the objects of this class,if someone reads this code ,kindly tell me.
    // function to add an edge to graph
    void addEdge(int v, int w);
	bool isBipartiteBFS(int source);
	bool isBipartiteDFS(int node,int par);

};


void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected
}

bool Graph::isBipartiteBFS(int source)
{
	queue<int> q;

	q.push(source);
	visited[source]=true;
	color[source]=0;

	while(!q.empty())
	{
		int u= q.front();

		q.pop();

		for(int j=0;j<adj[u].size();j++)
		{
                int ver= adj[u][j];

				if(color[ver]!=-1 and color[ver]==color[u])
                 return false;

				if(color[ver]==-1) color[ver]= !color[u];		///means vertex ver hasn't been coloured yet

				if(!visited[ver])
				{
					q.push(ver);
					visited[ver]=true;	///is at  absolutely correct place
				}
		}
	}
	return true;

}




///valid for connected graph`
bool Graph::isBipartiteDFS(int node,int par)
{
	color[node]=( par!=-1 ? (!color[par]) : 0) ;

	visited[node]=true;

	for(int j=0;j<adj[node].size();j++)
    {
		int u= adj[node][j];

		if(color[u]!=-1 and color[u]==color[node])
		return false;

		if(!visited[u])
		{

			if(!isBipartiteDFS(u,node) )
				return false;
		}
	}
	return true;
}


int main()
{

	ifstream cin("/home/aditya/Documents/ip");
	int n;
	//cout<<"Enter no of vertices\n";

	cin>>n;

	Graph G(n);		///Constructs a graph having n vertices

	int e,x,y;
	//cout<<"Enter no of edges\n";
	cin>>e;

	while(e--)
	{
		cin>>x>>y;
		G.addEdge(x,y);
	}

	cout<<	( G.isBipartiteDFS(1,-1) ? "Yes is bipartite":"Non bipartite");
	newl;

}
