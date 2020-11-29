#include <bits/stdc++.h>
#define ll long long
using namespace std;
//naive brute force: O(n^2+m)
const int N=10005;
int a[N+5],t[N+5];
int p[N+5][N+5];
int main (){
	int i,j,n,m;
	scanf ("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	{scanf ("%d",&a[i]);}
	for (i=1;i<=n;i++)
	{memset(t,0,sizeof(t));
	int mid=i,mx=1;
	t[a[i]]++;
	if (a[i]==i) p[i][i]++;
	for (j=i+2;j<=n;j+=2)
	{t[a[j]]++;t[a[j-1]]++;mid++;
	if (t[a[j]]>mx) mx=t[a[j]];
	if (t[a[j-1]]>mx) mx=t[a[j-1]];
	if (t[mid]==mx) p[i][j]++;
	}
	}
	for (i=1;i<=n;i++)
	{for (j=1;j<=n;j++)
	{p[i][j]+=(p[i][j-1]+p[i-1][j]-p[i-1][j-1]);}
	}
	while (m--)
	{int l,r,ans;
	scanf ("%d%d",&l,&r);
	ans=p[r][r]-p[l-1][r]-p[r][l-1]+p[l-1][l-1];
	printf ("%d\n",ans);
	}
	return 0;
}
