#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<utility>
#include<functional>
#include<iomanip>
#include<sstream>
#include<ctime>
#include<cassert>
using namespace std;
#define y0 y0z
#define y1 y1z
#define yn ynz
#define j0 j0z
#define j1 j1z
#define jn jnz
#define tm tmz
#define buli(x) (__builtin_popcountll(x))
#define bur0(x) (__builtin_ctzll(x))
#define bul2(x) (63-__builtin_clzll(x))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fil(a,b) memset((a),(b),sizeof(a))
#define cl(a) fil(a,0)
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)
#define forg(i,gu) for (int i=gu;~i;i=e[i].next)
#define pw(x) ((ll(1))<<(x))
#define upmo(a,b) (((a)=((a)+(b))%mo)<0?(a)+=mo:(a))
#define mmo(a,b) (((a)=1ll*(a)*(b)%mo)<0?(a)+=mo:(a))
void getre(){int x=0;printf("%d\n",1/x);}
void gettle(){int res=1;while(1)res<<=1;printf("%d\n",res);}
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
template<typename T,typename S>inline bool upmin(T&a,const S&b){return a>b?a=b,1:0;}
template<typename T,typename S>inline bool upmax(T&a,const S&b){return a<b?a=b,1:0;}
template<typename N,typename PN>inline N flo(N a,PN b){return a>=0?a/b:-((-a-1)/b)-1;}
template<typename N,typename PN>inline N cei(N a,PN b){return a>0?(a-1)/b+1:-(-a/b);}
template<typename N>N gcd(N a,N b){return b?gcd(b,a%b):a;}
template<typename N>inline int sgn(N a){return a>0?1:(a<0?-1:0);}
#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
#define lld "%I64d"
#else
#define lld "%lld"
#endif
inline void gn(long long&x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=-1,x=0):(x=c-'0');
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;
}
inline void gn(int&x){long long t;gn(t);x=t;}
inline void gn(unsigned long long&x){long long t;gn(t);x=t;}
inline void gn(double&x){double t;scanf("%lf",&t);x=t;}
inline void gn(long double&x){double t;scanf("%lf",&t);x=t;}
inline void gs(char *s){scanf("%s",s);}
inline void gc(char &c){while((c=getchar())>126 || c<33);}
inline void pc(char c){putchar(c);}
#ifdef JCVB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
typedef long long ll;
typedef double db;
inline ll sqr(ll a){return a*a;}
inline db sqrf(db a){return a*a;}
const int inf=0x3f3f3f3f;
//const ll inf=0x3f3f3f3f3f3f3f3fll;
const db pi=3.14159265358979323846264338327950288L;
const db eps=1e-6;
//const int mo=0;
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}

int n,m;//<=300
int a[333];
int mark[333];

int sol[333][333];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void out() {
	rep(i,1,n+1) {
		rep(j,1,m+1)printf("%d",sol[i][j]);
		printf("\n");
	}
	rep(j,1,m+1) {
		int su=0;
		rep(i,1,n+1) {
			if(sol[i][j]==1) {
				su++;
				rep(k,0,4)assert(sol[i+dx[k]][j+dy[k]]==0);
			}
		}
		assert(su == a[j]);
	}

}

void work1(int l,int r) {
	if(l>=1) for (int i=1;i<=n;i+=2)sol[i][l]=1;
	if (r<=m) for (int i=1;i<=n;i+=2)sol[i][r]=1;

	if(l==0 && (r-l)%2!=0)l=-1;

	for (int j=l+1;j<r;j++) {
		for (int k=0,st=(j-l)%2+1;k<a[j];k++,st+=2) {
			sol[st][j]=1;
		}
	}
}
int work2(int l,int r) {
	if(l>=1) for (int i=1;i<=n;i+=2)sol[i][l]=1;
	if (r<=m) for (int i=1;i<=n;i+=2)sol[i][r]=1;
	for (int j=l+1;j<=r-1;j++) {
		int bt,top;
		if((j-l)%2==1) {
			bt=n;
			top=2;
		} else {
			bt=n-1;
			top=1;
		}
		int rem=a[j];
		for (int i=bt;rem>0 && i>=1 && sol[i][j-1]!=1;i-=2,rem--) {
			sol[i][j]=1;
		}
		for (int i=top;rem>0;i+=2,rem--) {
			sol[i][j]=1;
		}
	}
	for (int i=1;i<=n;i++)if(sol[i][r-1]==1 && sol[i][r]==1) return 0;
	return 1;
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(m);
	assert(n<=300 && n>=1);
	assert(m<=300 && m>=1);
	rep(j,1,m+1){
		gn(a[j]);
		assert(a[j]>=0 && a[j] <= n);
		if(a[j]>(n+1)/2) {
			printf("No\n");
			return 0;
		}
		if(a[j]==(n+1)/2) mark[j]=1;
	}
	if(n%2==0) {
		rep(j,1,m+1) {
			rep(i,1,a[j]+1) {
				if(j%2==0)sol[i*2-1][j]=1;
				else sol[i*2][j]=1;
			}
		}
	}else {
		int las=0;
		rep(j,1,m+1)if(mark[j]) {
			if(las==0 || (j-las)%2==0) work1(las,j);
			else {
				if(!work2(las,j)) {
					printf("No\n");
					return 0;
				}
			}
			las=j;
		}
		if(las!=m) work1(las,m+1);
	}
	printf("Yes\n");
	out();


#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}


