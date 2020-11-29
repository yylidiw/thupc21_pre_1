#include<bits/stdc++.h>
#define F(i,n) for(int i=0;i<n;++i)
#define F1(i,n) for(int i=1;i<=n;++i)
const int maxn=2e5,N=maxn+7;
int read(int L,int R){
	int x;
	assert(scanf("%d",&x)==1);
	assert(L<=x&&x<=R);
	return x;
}

int n,m;
uint32_t s[450][N+666],a[N];
int main(){
	n=read(1,maxn);
	F1(i,n)a[i]=read(1,maxn);
	for(int i=1;i*i<=n;++i){
		for(int j=n;j;--j)s[i][j]=s[i][j+i]+a[j];
	}
	for(m=read(1,maxn);m;--m){
		int d=read(1,n),p1=read(1,n),p2=read(1,n);
		uint32_t ans=0,*A=s[d]+p1,*Ae=A+d*d,*B=s[1]+p2;
		F(k,d){
			ans+=(A[k]-Ae[k])*(B[0]-B[d]);
			B+=d;
		}
		printf("%u\n",ans);
	}
	return 0;
}
