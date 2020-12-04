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

int n , m ;
int a[333];
void out() {
	printf("%d %d\n",n,m);

	for (int i=1;i<=m;i++) {
		printf("%d",a[i]);
		if(i!=m)printf(" ");
	}
	printf("\n");
}
void gen2() {
	freopen("2.in","w",stdout);

	n=298, m = 291;

	rep(j,1,m+1) a[j]=n/2;
	out();

}
void gen3() {
	freopen("3.in","w",stdout);

	n=300, m = 299;

	rep(j,1,m+1) {
		a[j]=n/2;
		if(rand()%10==0) a[j]=0;
		else if(rand()%3==0) a[j] -= rand()%40;
	}
	out();
}
void gen4() {
	freopen("4.in","w",stdout);

	n=100, m = 290;

	rep(j,1,m+1) {
		a[j]=0;
	}
	a[rand()%100+120] = n/2 + 1;
	out();
}
void gen5() {
	freopen("5.in","w",stdout);

	n=2, m = 291;

	rep(j,1,m+1) {
		a[j]=n/2;
		if(rand()%10==0) a[j]=0;
	}
	out();
}

// odd
void gen6() {
	freopen("6.in","w",stdout);

	n=231, m = 299;

	rep(j,1,m+1) {
		a[j]=n/2;
		if(j%2==1) a[j]++;
	}
	out();
}
void gen7() {
	freopen("7.in","w",stdout);

	n=233, m = 219;

	rep(j,1,m+1) {
		a[j]=n/2;
		if(j%2==0) a[j]++;
	}
	out();
}
void gen8() {
	freopen("8.in","w",stdout);

	n=233, m = 219;

	rep(j,1,m+1) {
		if(j%3==1) a[j] = n/2+1;
		else if (j%3==2) a[j] = rand()% (n/2);
		else if (j%3==0) a[j] = n/2 - a[j-1];
		//a[j]=n/2;
		//if(j%2==0) a[j]++;
	}
	out();
}
void gen9() {
	freopen("9.in","w",stdout);

	n=299, m = 300;

	rep(j,1,m+1) {
		a[j]=0;
	}
	a[233] = n/2+1;
	a[234] = n/4;
	a[235] = n/2 - a[234] + 1;
	a[236] = n/2 +1;
	out();
}
void gen10() {
	freopen("10.in","w",stdout);

	n=299, m = 50;

	rep(j,1,m+1) {
		a[j]=0;
	}
	a[1] = n/2+1;
	rep(j,2,19)a[j] = n/2;

	a[19] = n/2+1;
	a[20] = 123;
	a[21] = n/2-a[20];
	a[22] = n/2+1;
	rep(j,23,50)a[j] = n/2;
	a[50]=n/2+1;
	out();
}
void gen11() {
	freopen("11.in","w",stdout);

	n=1, m = 300;
	rep(j,1,m+1) {
		a[j]=0;
		if(a[j-1]==0) a[j] = rand()%2;
	}
	out();
}

void gen12() {
	freopen("12.in","w",stdout);

	n = 239; m = 300;
	rep(j,1,m+1) {
		a[j]=n/2;
	}
	a[2] = n/2+1;
	a[1 + (n+3)] = n/2+1;
	
	out();
	// yes
}
void gen14() {
	freopen("14.in","w",stdout);

	n = 241; m = 300;
	rep(j,1,m+1) {
		a[j]=n/2;
	}
	a[1]=0;
	a[2] = n/2+1;
	a[1 + (n+3-2)] = n/2+1;
	rep(j,2+(n+3-2),m+1) a[j]=0;
	
	out();
	// no
}
void gen15() {
	freopen("15.in","w",stdout);

	n=19, m = 300;

	rep(j,1,m+1) {
		a[j]=0;
	}
	a[299] = n/2+1;
	a[300] = n/2+1;
	out();
	//no
}


vector<int> par(int sum, int n,int up) {
	assert(up*n>=sum);
	vector<int> ret;
	ret.resize(n); 
	rep(j,0,n)ret[j] = sum/n;
	rep(j,0,sum%n)ret[j]++;
	int xx= int(exp((rand()%1000)/100.0 + 3));
	rep(k,0, xx) {
		int i=rand()%n;
		int j = rand()%n; 
		if(i==j)continue;

		int u = min(up-ret[i], ret[j]);
		int dow = max(-ret[i], -(up-ret[j]));

		int t = rand()%(u-dow+1)+dow;
		if(abs(t - (u+dow)*0.5) < (u-dow)*0.3) {
			t = rand()%(u-dow+1)+dow;
		}

		ret[i]+=t;
		ret[j]-=t;

		assert(ret[i]>=0 && ret[i]<=up);
		assert(ret[j]>=0 && ret[j]<=up);
	}
	return ret;
}
void gen13() {
	freopen("13.in","w",stdout);

	n = 31; m = 300;

	int cur = 1;

	rep(j,1,m+1) {
		a[j]=0;
	}
	while(1) {
		a[cur] = n/2+1;
		int rem = min(n+1, m - cur - 5);
		if(rem<=1)break;
		int len = rand()%(rem-1)+2;
		if(len%2==1)len--;

		int les = (n+1 - len)/2;

		vector<int> pa = par(les, len, n/2);
		rep(j,1,len+1) {
			a[cur+j] = n/2-pa[j-1];
		}
		a[cur+len+1] = n/2+1;
		cur = cur+len+1;
	}
	
	out();
}
void gen16() {
	freopen("16.in","w",stdout);

	n = 9; m = 300;

	int cur = 1;

	rep(j,1,m+1) {
		a[j]=0;
	}
	while(1) {
		a[cur] = n/2+1;
		int rem = min(n+1, m - cur - 5);
		if(rem<=1)break;
		int len = rand()%(rem-1)+2;
		if(len%2==1)len--;

		int les = (n+1 - len)/2;

		vector<int> pa = par(les, len, n/2);
		rep(j,1,len+1) {
			a[cur+j] = n/2-pa[j-1];
		}
		a[cur+len+1] = n/2+1;
		cur = cur+len+1;
	}
	
	out();
}
void gen17() {
	freopen("17.in","w",stdout);

	n = 49; m = 300;

	int cur = 1;

	rep(j,1,m+1) {
		a[j]=0;
	}
	while(1) {
		a[cur] = n/2+1;
		int rem = min(n+1, m - cur - 5);
		if(rem<=1)break;
		int len = rand()%(rem-1)+2;
		if(len%2==1)len--;

		int les = (n+1 - len* (rand()%400/400.0))/2;

		vector<int> pa = par(les, len, n/2);
		rep(j,1,len+1) {
			a[cur+j] = n/2-pa[j-1];
		}
		a[cur+len+1] = n/2+1;
		cur = cur+len+1;
	}
	out();
}
void gen18() {
	freopen("18.in","w",stdout);

	n = 255; m = 300;

	int cur = 1;

	rep(j,1,m+1) {
		a[j]=0;
	}
	while(1) {
		a[cur] = n/2+1;
		int rem = min(n+1, m - cur - 5);
		if(rem<=1)break;
		int len = rand()%(rem-1)+2;
		if(len%2==1)len--;

		int les = (n+1 - len)/2;

		vector<int> pa = par(les, len, n/2);
		rep(j,1,len+1) {
			a[cur+j] = n/2-pa[j-1];
		}
		a[cur+len+1] = n/2+1;
		cur = cur+len+1;
	}
	out();
}
void gen20() {
	freopen("20.in","w",stdout);

	n = 299; m = 100;

	int cur = 1;

	rep(j,1,m+1) {
		a[j]=0;
	}
	while(1) {
		a[cur] = n/2+1;
		int rem = min(n+1, m - cur - 5);
		if(rem<=1)break;
		int len = rand()%(rem-1)+2;
		if(len%2==1)len--;

		int les = (n+1 - len)/2;

		vector<int> pa = par(les, len, n/2);
		rep(j,1,len+1) {
			a[cur+j] = n/2-pa[j-1];
		}
		a[cur+len+1] = n/2+1;
		cur = cur+len+1;
	}
	out();
}
void gen19() {
	freopen("19.in","w",stdout);

	n = 241; m = 300;

	int cur = 1;

	rep(j,1,m+1) {
		a[j]=0;
	}
	while(1) {
		a[cur] = n/2+1;
		int rem = min(n+1, m - cur - 5);
		if(rem<=1)break;
		int len = rand()%(rem-1)+2;
		if(len%2==1)len--;

		int les = (n+1 - len)/2 - 1;

		vector<int> pa = par(les, len, n/2);
		rep(j,1,len+1) {
			a[cur+j] = n/2-pa[j-1];
		}
		a[cur+len+1] = n/2+1;
		cur = cur+len+1;
	}
	
	out();
	// no
}
int main()
{
	srand(time(0));
#ifdef JCVB
	//freopen("1.in","r",stdin);
	int _time_jc=clock();
#endif

	gen2();
	gen3();
	gen4();
	gen5();
	gen6();
	gen7();
	gen8();
	gen9();
	gen10();
	gen11();
	gen12();
	gen13();
	gen14();
	gen15();
	gen16();
	gen17();
	gen18();
	gen19();
	gen20();


#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}


