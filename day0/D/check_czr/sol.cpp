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
const int N=500005;
const int T=300;
map <int,int> mp;
int a[N+5],t[N*2+5],s[N*2+5],n,m,cnt,tot=0;
int t1[N+5],t2[N+5],num[N*2+5],w[N+5];
vector <int> vec[N*2+5];//每个元素的出现位置 
vector <int> pl[N+5];//以c为中心，众数出现次数发生更新的位置 

struct node
{int c,l,r;
}p[2*N+5];
inline void add(int c,int l,int r)
{p[++tot].c=c;p[tot].l=l;p[tot].r=r;}
inline bool cmp(node a,node b)
{return a.c<b.c;}

inline int find1(int o)
{int l=1,r=tot;
while (l<=r)
{int mid=(l+r)>>1;
if (p[mid].c<o) {l=mid+1;}
else {r=mid-1;}
}
return l;
}
inline int find2(int o)
{int l=1,r=tot;
while (l<=r)
{int mid=(l+r)>>1;
if (p[mid].c<=o) {l=mid+1;}
else {r=mid-1;}
}
return r;
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
if (cnt<mx&&lst!=-1) add(i,lst,len-1);
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
int m2=((p2<=t[i])?(vec[i][p2]-t[i]):inf);
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
	int i,j,k,mx=0;
	scanf ("%d%d",&n,&m);cnt=n;
	for (i=1;i<=n;i++)
	{scanf ("%d",&a[i]);
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
	/*
	sort(p+1,p+tot+1,cmp);
	while (m--)
	{int l,r;
	scanf ("%d%d",&l,&r);
	int ls=find1(l),rs=find2(r);
	ll ans=0;
	for (i=ls;i<=rs;i++)
	{int ml=min(p[i].c-l,r-p[i].c);
	ans+=max(0,(min(ml,p[i].r)-p[i].l+1));
	}
	printf ("%lld\n",ans);
	}
	*/
	return 0;
}
