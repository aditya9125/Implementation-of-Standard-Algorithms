
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
#define scan3ll(x,y) scanf("%lli %lli %lli",&x,&y,&z);

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
#define get(tp_name,x) (get<x>(tp_name))   ///to access tuple(i)
#define umap unordered_map



using namespace std;


#define F first
#define S second



///learning corner

///vector< vector<int> > costs(N, vector<int>(M, 0));   //NxM 2d preinitialized(0) vector



typedef pair<int,int> ii;
typedef vector<ii> vii;



inline bool inc_range(int x,int y,int z) { return ((x>=y)&&(x<=z)); }
inline bool ex_range(int x,int y,int z) { return ((x>y)&&(x<z)); }
inline bool is_either(int x,int y,int z) { return ((x==y)||(x==z)); }

//maths
#define PI acos(-1)

#define INTmax numeric_limits<int>::max()
#define LLmax numeric_limits<ll>::max()
#define ULLmax numeric_limits<ull>::max()

#define INTmin numeric_limits<int>::min()


typedef priority_queue<ii,vector<ii>, greater<ii> > P_Queue;             ///priority queue contianing ii (having vector<ii> as underlying container) with greater as functor
																		///		heapify on the basis of comparisons of  ii.first  values

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
type fastpow(type a, type b, type c) { type ans=1;  while(b != 0){ if(b%2 == 1) ans=(ans*a)%c;  a=(a*a)%c; b /= 2; } return ans; }

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

inline void FAST_IO(){ios_base::sync_with_stdio(false);}



#define SIZE int(2e3)+1
#define MOD
#define debug
#define MAX1
#define MAX2

//#define Online_judge
struct Trie_node
{

	//bool is_end=false;
	Trie_node* childs[2];
	ll value;

	Trie_node() 		///constructor
	{
		//is_end=false;
		value=0;
		childs[0]=nullptr;
		childs[1]=nullptr;
	}


}*root;

void insrt(Trie_node *tmp,ll item)
{

	for(int i=31;i>=0;i--)
	{

		bool curr_bit=(1<<i) & item;

		if(! tmp->childs[curr_bit])
		{
			tmp->childs[curr_bit]=new Trie_node();
		}

		tmp=tmp->childs[curr_bit];

	}

	tmp->value=item;
	//tmp->is_end=true;
	//cout<<"hello\n";
}

ll query(ll maxwith)
{
    Trie_node *tmp=root;


	for(int i=31;i>=0;i--)
	{
		bool curr_bit= maxwith & (1<<i);


		if(tmp->childs[!curr_bit])
		{
			tmp=tmp->childs[!curr_bit];
		}
		else if(tmp->childs[curr_bit])
			tmp=tmp->childs[curr_bit];
	}
	//if(tmp->is_end)
	// assert(tmp!=nullptr);
	return maxwith^(tmp->value);
}


ll Mxor(vector<ll> & v)
{
	ll maxsofar=0,pxor=0,i=0;


	rep(i,0,v.size())
	{

		pxor=pxor^(v[i]);

		insrt(root,pxor);

		maxsofar=max(maxsofar,query(pxor));
		//cout<<i<<" "<<pxor<<" "<<maxsofar<<endl;
	}

	return maxsofar;

}

vector< vector<ll> > arr;

int main()
{
	FAST_IO();

	ifstream cin("ip");
//	ofstream cout("op");
	ll n,i,m,j;

	cin>>n>>m;

	root=new Trie_node();

	ll val;


	//cout<<"Hello\n";

	rep(i,0,n)
	{
		vector<ll> tempv;

		rep(j,0,m)
		{
			cin>>val;
			tempv.pb(val);
		}

		arr.pb(tempv);
	}

	insrt(root,0);


	ll l=0,r=0,maxor=0;

	vector<ll> aux(n,0);

	rep(l,0,m)
	{
		//fill(whole(aux),0);

		rep(r,l,m)
		{
			rep(i,0,n)
			{
				aux[i]=aux[i]^arr[i][r];
			}
			//cout<<"max xor of \n";
			//rep(i,0,n)
			  //cout<<aux[i]<<" ";
			maxor=max(maxor,Mxor(aux));
		}
		aux.clear();

	}







	/*
	rep(i,0,n)
	{
			cin>>arr[i];
	//		cout<<"Hellp\n";
			pxor=pxor^(arr[i]);
			insrt(root,pxor);
			maxsofar=max(maxsofar,query(pxor));
			//cout<<i<<" "<<pxor<<" "<<maxsofar<<endl;
	}
	*/
	cout<<maxor<<"\n";


}

