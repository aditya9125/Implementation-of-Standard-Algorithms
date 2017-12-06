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


using namespace std;


#define F first
#define S second

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

inline void FAST_IO(){ios_base::sync_with_stdio(false);}



#define SIZE int(2e3)+1
#define MOD
#define debug
//#define Online_judge

class Disjoint_set
{
	unordered_map<int,int> ParentInfo;

	public:

		Disjoint_set() 		///constructor //or create set
		{
			int universe[]={1,2,3,4,5,6,7,8};

			for(int x:universe)
			{
				ParentInfo[x]=x;
			}
		}


		int Find(int item)
		{

		//	cout<<"yes\n";
			if(ParentInfo[item]==item)
			 return item;
			else return Find(ParentInfo[item]);
		}


		void Union(int s1,int s2)
		{
			ParentInfo[s1]=s2;
		}
};



int main()
{
	FAST_IO();
//	ifstream cin("ip");
	int n,i,j,x;

	Disjoint_set V;

	cout<<V.Find('2');
}


