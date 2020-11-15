#include<bits/stdc++.h>
typedef long long i64;
#define F(i,n) for(int i=0;i<n;++i)
#define F1(i,n) for(int i=1;i<=n;++i)
const int maxn=2e5,N=maxn+7;
int read(int L,int R){
	int x;
	assert(scanf("%d",&x)==1);
	assert(L<=x&&x<=R);
	return x;
}

int n,m,a[N];

int main(){
	n=read(1,maxn);
	F1(i,n)a[i]=read(1,maxn);
	for(m=read(1,maxn);m;--m){
		int d=read(1,n),p1=read(1,n),p2=read(1,n);
		assert(1ll*d*d<=n);
		assert(std::max(p1,p2)+d*d-1<=n);
		i64 ans=0;
		F(i,d)F(k,d)F(j,d)ans+=1ll*a[p1+i*d+k]*a[p2+k*d+j];
		printf("%lld\n",ans);
	}
	return 0;
}