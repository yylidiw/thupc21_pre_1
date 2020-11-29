#include <bits/stdc++.h>
#define ll long long
#define inf 666623333 
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
const int N=500005;
const int M=1000005;
const int T=300;
map <int,int> mp;
int a[N+5],t[N*2+5],s[N*2+5],n,m,cnt,tot=0;
int t1[N+5],t2[N+5],num[N*2+5],w[N+5];
vector <int> vec[N*2+5];//每个元素的出现位置 
vector <int> pl[N+5];//以c为中心，众数出现次数发生更新的位置 
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
inline void sol1()
{int i,j,l,r;
for (i=1;i<=n;i++)
{if (t[i]<=T) continue;
for (j=1;j<=cnt;j++) s[j]=0;
int mx=1,cnt=0,len,lst=-1;
s[a[i]]++;
if (a[i]==i) cnt++;
if (cnt==mx) lst=0;
for (l=i-1,r=i+1,len=1;l>=1&&r<=n;l--,r++,len++)
{s[a[l]]++;s[a[r]]++;
if (s[a[l]]>mx) mx=s[a[l]];
if (s[a[r]]>mx) mx=s[a[r]];
if (a[l]==i) cnt++;
if (a[r]==i) cnt++;
if (cnt==mx&&lst==-1) lst=len;
if (cnt<mx&&lst!=-1) {add(i,lst,len-1);lst=-1;}
}
if (lst!=-1) add(i,lst,len-1);
}
}
inline void sol2()
{int i,j,l,r;
for (i=1;i<=n;i++)
{if (t[i]<=0||t[i]>T) continue;
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
int bd=min(i-1,n-i);
for (j=1;j<=t[i];j++) 
{w[j]=min(w[j],bd+1);
pl[i][j+1]=min(pl[i][j+1],bd+1);
if (w[j]<=pl[i][j+1]-1) add(i,w[j],pl[i][j+1]-1);
}
}
}
int main (){
	//freopen ("1.in","r",stdin);
	//freopen ("1.out","w",stdout); 
	int i,j,k,mx=0;
	T1.init();
	T2.init();
	read(n);read(m);cnt=n;
	for (i=1;i<=n;i++)
	{read(a[i]);
	if (a[i]<1||a[i]>n)
	{if (!mp[a[i]]) mp[a[i]]=++cnt;
	a[i]=mp[a[i]];
	}
	t[a[i]]++;
	}
	for (i=1;i<=cnt;i++) vec[i].resize(t[i]+1);
	for (i=1;i<=n;i++) pl[i].resize(t[i]+2);
	for (i=1;i<=n;i++) vec[a[i]][++num[a[i]]]=i;
	for (i=1;i<=n;i++)
	{if (t[i]<=T) mx=max(mx,t[i]);
	}
	for (j=1;j<=mx+1;j++)
	{for (i=0;i<=n+1;i++)
	{t1[i]=inf;t2[i]=-inf;}
	for (i=1;i<=cnt;i++)
	{if (!t[i]) continue;
	for (k=j;k<=t[i];k++)
	{int l=vec[i][k-j+1],r=vec[i][k];
	int m1=(l+r)>>1,m2=((l+r+1)>>1);
	t1[m1]=min(t1[m1],r);
	t2[m2]=max(t2[m2],l);
	}
	}
	for (i=1;i<=n;i++) t2[i]=max(t2[i-1],t2[i]);
	for (i=n;i>=1;i--) t1[i]=min(t1[i+1],t1[i]);
	for (i=1;i<=n;i++)
	{if (t[i]>T) continue;
	if (j>t[i]+1) continue;
	pl[i][j]=min(t1[i]-i,i-t2[i]);
	}
	}
	sol1();//对于出现次数大于T=sqrt(n)的
	sol2();//对于出现次数不超过T=sqrt(n)的
	for (i=1;i<=m;i++)
	{read(q[i].l);read(q[i].r);
	q[i].id=i;
	}
	cerr << clock() << " ms" << endl;
	T1.solve();
	cerr << clock() << " ms" << endl;
	T2.solve();
	cerr << clock() << " ms" << endl;
	for (i=1;i<=m;i++) write(T1.ans[i]-T2.ans[i]);
	fwrite(Buff,1,sti-Buff,stdout);
	return 0;
}
