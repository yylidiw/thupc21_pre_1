#include <bits/stdc++.h>
#define ll long long
#define inf 666623333
#define MAXN 500010
#define MAXD ((MAXN>>9)+1)
using namespace std;
//出现次数超过sqrt(n)：对于每个中心点，有O(n)的做法
//出现次数不超过sqrt(n):
//对于1-sqrt(n)，可以处理出所有众数出现次数>=k的区间 
//已知[l..r]区间中出现次数为k，则对于所有<=(l+r)/2的中心c，t1[c,k]与r取min 
//                               对于所有>=(l+r)/2的中心c，t2[c,k]与l取max 
//t1[c,k]:以c为中心, 众数出现次数为k的最小右端点 
//t2[c,k]:以c为中心，众数出现次数为k的最大左端点 
const int MAXBUF=20000005;
char B[MAXBUF],*Si=B,*Ti=B;
inline char getc()
{if (Si==Ti) Ti=(Si=B)+fread(B,1,MAXBUF,stdin);
if (Si==Ti) return 0;
return *Si++;
}
template <class T>
inline void read(T &a)
{static char c;
while ((c=getc())<'0'||c>'9');a=c-'0';
while ((c=getc())>='0'&&c<='9') a=(a<<3)+(a<<1)+c-'0';
}
char Buff[MAXBUF],*sti=Buff;
template <class T>
inline void write(T a)
{if (a==0) {*sti++='0';*sti++='\n';return;}
int t[21],cnt=0;
while (a) t[++cnt]=a%10,a/=10;
for (int i=cnt;i>=1;i--) *sti++='0'+t[i];
*sti++='\n'; 
}

int a[MAXN],b[MAXN],rnk[MAXN],num,n,mode[MAXD][MAXD],memory_pool[MAXN],now_pos,cnt[MAXN];

inline int * get_memory( int x )
{
	now_pos += x;
	return memory_pool + now_pos - x;
}

struct Vector
{
	int * a , * b;
	inline void assign( int c )
	{
		b = a = get_memory( c );
	}
	inline int & operator[]( int i )
	{
		return a[i];
	}
	inline void push_back( int x )
	{
		* b++ = x;
	}
	inline int size()
	{
		return b - a;
	}
} V[ MAXN ];

unordered_map <int,int> rec[MAXN+5];

inline int find( int l , int r )
{
	if (rec[l][r]) return rec[l][r];
	
	int L = l - 1 >> 9 , R = r - 1 >> 9;
	if( L + 1 > R - 1 )
	{
		int ans = 0;
		for( int i = l ; i <= r; i++ )
			if( ++cnt[ a[i] ] > ans )
				ans = cnt[ a[i] ];
		for( int i = l ; i <= r ; i++ ) cnt[ a[i] ] = 0;	
		rec[l][r]=ans;
		return ans;
	}
	else
	{
		int ans = mode[L + 1][R - 1];
		for( int i = ( L + 1 ) << 9 ; i >= l ; i-- )
			if( rnk[i] + ans < V[ a[i] ].size() )
				if( V[ a[i] ][ rnk[i] + ans ] <= r )
					ans++;
		for( int i = R << 9 | 1 ; i <= r ; i++ )
			if( rnk[i] >= ans )
				if( V[ a[i] ][ rnk[i] - ans ] >= l )
					ans++;
		rec[l][r]=ans;
		return ans;
	}
}

inline void init_block()
{
	for( register int i = 1 ; i <= n ; i++ ) rnk[i]=a[i];
	sort( rnk + 1 , rnk + n + 1 );
	num = unique( rnk + 1 , rnk + n + 1 ) - rnk - 1;
	for( register int i = 1 ; i <= n ; i++ ) a[i] = lower_bound( rnk + 1 , rnk + num + 1 , a[i] ) - rnk;
	memset( rnk , 0 , sizeof( rnk ) );
	for( register int i = 1 ; i <= n ; i++ ) rnk[ a[i] ]++;
	for( register int i = 1 ; i <= n ; i++ ) V[i].assign( rnk[i] );
	for( register int i = 1 ; i <= n ; i++ )
		V[ a[i] ].push_back( i ) , rnk[i] = V[ a[i] ].size() - 1;
	for( int i = 0 ; i <= n >> 9 ; i++ )
	{
		for( int j = i << 9 | 1 , k = i , ans = 0 ; j <= n ; j++ )
		{
			if( ++cnt[ a[j] ] > ans ) ans = cnt[ a[j] ];
			if( !( j & 511 ) )
				mode[i][k++] = ans;
		}
		for( register int i = 1 ; i <= num ; i++ ) cnt[i] = 0;
	}
}

const int N=500005;
const int M=1000005;
unordered_map <int,int> mp;
int t[N*2+5],s[N*2+5],m,cot,tot=0;
int t1[N+5],t2[N+5],w[N+5];
vector <int> vec[N*2+5];//每个元素的出现位置 
struct node
{int id,t,l,r;
}q[M+5];
struct nd
{int p1,p2,c,k;
};
inline bool cmp(node a,node b)
{return a.t<b.t;}
inline bool cp(nd a,nd b)
{return a.p1<b.p1;}
struct BIT
{ll ans[M+5],t[N+5];
int s[N+5];
nd w[2*N+5];
int cnt;
inline void init(){cnt=0;}
inline void _add(int _c,int _k)
{cnt++;w[cnt].c=_c;w[cnt].k=_k;} 
inline void add(int pos,int w)
{while (pos<=n)
{t[pos]+=w;s[pos]++;pos+=(pos&(-pos));}
}
inline pair<ll,int> query(int pos)
{ll s1=0;
int s2=0;
while (pos) {s1+=t[pos];s2+=s[pos];pos-=(pos&(-pos));}
return make_pair(s1,s2);
}
inline void solve()
{int i,j,pos;
pair <ll,int> tp;
for (i=1;i<=cnt;i++)
{w[i].p1=w[i].c+w[i].k;
w[i].p2=w[i].c-w[i].k;
}
for (i=1;i<=m;i++) q[i].t=q[i].r;
sort(w+1,w+cnt+1,cp);
sort(q+1,q+m+1,cmp);
ll tot=0;
for (pos=1,i=1;i<=m;i++)
{while (pos<=cnt&&w[pos].p1<=q[i].t)
{add(w[pos].p2,w[pos].k+1);tot+=(w[pos].k+1);pos++;}
ans[q[i].id]+=(tot-query(q[i].l-1).first);
}
memset(t,0,sizeof(t));
memset(s,0,sizeof(s));
for (i=1;i<=cnt;i++)
{w[i].p1=w[i].c-w[i].k+1;
w[i].p2=w[i].c;
}
for (i=1;i<=m;i++) q[i].t=q[i].l;
sort(w+1,w+cnt+1,cp);
sort(q+1,q+m+1,cmp);
for (pos=1,i=1;i<=m;i++)
{while (pos<=cnt&&w[pos].p1<=q[i].t)
{add(w[pos].p2,w[pos].c);pos++;}
int mid=(q[i].l+q[i].r)>>1;
tp=query(mid);
ans[q[i].id]+=(tp.first-1ll*tp.second*(q[i].l-1));
tp=query(q[i].l-1);
ans[q[i].id]-=(tp.first-1ll*tp.second*(q[i].l-1));
}
memset(t,0,sizeof(t));
memset(s,0,sizeof(s));
for (i=1;i<=cnt;i++)
{w[i].p1=n+2-(w[i].c+w[i].k);
w[i].p2=w[i].c;
}
for (i=1;i<=m;i++) q[i].t=n+1-q[i].r;
sort(w+1,w+cnt+1,cp);
sort(q+1,q+m+1,cmp);
for (pos=1,i=1;i<=m;i++)
{while (pos<=cnt&&w[pos].p1<=q[i].t)
{add(w[pos].p2,w[pos].c);pos++;}
int mid=(q[i].l+q[i].r)>>1;
tp=query(q[i].r);
ans[q[i].id]+=(1ll*tp.second*(q[i].r+1)-tp.first);
tp=query(mid);
ans[q[i].id]-=(1ll*tp.second*(q[i].r+1)-tp.first);
}
}
}T1,T2;
inline void add(int c,int l,int r)
{T1._add(c,r);
if (l) T2._add(c,l-1);
}
inline void sol()
{int i,j,l,r;
for (i=1;i<=n;i++)
{if (t[i]<=0) continue;
int pos=t[i]+1;
for (j=1;j<=t[i];j++)
{if (vec[i][j]>i) {pos=j;break;}
}
int p1=pos-1,p2=pos,cot=0;
while (p1>=1||p2<=t[i])
{int m1=((p1>=1)?(i-vec[i][p1]):inf);
int m2=((p2<=t[i])?(vec[i][p2]-i):inf);
if (m1<m2) {w[++cot]=m1;p1--;}
else {w[++cot]=m2;p2++;}
}
w[++cot]=min(i-1,n-i)+1;
for (j=1;j<=cot;j++) w[j]=min(w[j],w[cot]);
for (j=1;j<cot;j++)
{if (w[j]>=w[j+1]) continue;
if (find(i-w[j],i+w[j])>j) continue;
if (find(i-(w[j+1]-1),i+(w[j+1]-1))==j)
{add(i,w[j],w[j+1]-1);continue;}
int l=w[j]+1,r=w[j+1]-2;
while (l<=r)
{int mid=(l+r)>>1;
if (find(i-mid,i+mid)==j) {l=mid+1;}
else {r=mid-1;}
}
add(i,w[j],r);
}
}
}
int main (){
	//freopen ("1.in","r",stdin);
	//freopen ("1.out","w",stdout); 
	int i,j,k,mx=0;
	T1.init();
	T2.init();
	read(n);read(m);cot=n;
	for (i=1;i<=n;i++)
	{read(a[i]);
	if (a[i]<1||a[i]>n)
	{if (!mp[a[i]]) mp[a[i]]=++cot;
	a[i]=mp[a[i]];
	}
	t[a[i]]++;
	}
	for (i=1;i<=cot;i++) vec[i].resize(t[i]+1);
	for (i=1;i<=n;i++) vec[a[i]][++vec[a[i]][0]]=i;
	for (i=1;i<=n;i++) b[i]=a[i];
	init_block();
	sol();
	for (i=1;i<=m;i++)
	{read(q[i].l);
	read(q[i].r);
	q[i].id=i;
	}
	//cerr << clock() << " ms" << endl;
	T1.solve();
	//cerr << clock() << " ms" << endl;
	T2.solve();
	//cerr << clock() << " ms" << endl;
	for (i=1;i<=m;i++) write(T1.ans[i]-T2.ans[i]);
	fwrite(Buff,1,sti-Buff,stdout);
	return 0;
}
