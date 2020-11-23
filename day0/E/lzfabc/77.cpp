#include<bits/stdc++.h>
//#pragma gcc optimize(3)
#define gc getchar()
//char buf[100000],*buff = buf + 100000;
//#define gc ((buff == buf + 100000 ? (fread(buf,1,100000,stdin),buff = buf) : 0),*(buff++))
#define pc putchar
//char bfu[10000000],*bfuu = bfu;
//#define pc(x) (*(bfuu++) = x)
#define li long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define md int mid = l + r >> 1
#define ls q << 1
#define rs q << 1 | 1
#define ln ls,l,mid
#define rn rs,mid + 1,r
using namespace std;
//const int mo = 998244353;
//const int mo = 1000000007;
inline li read(){
	li x = 0;
	int y = 0,c = gc;
	while(c < '0' || c > '9') y = c,c = gc;
	while(c >= '0' && c <= '9') x = x * 10 + c - '0',c = gc;
	return y == '-' ? -x : x;
}
inline void prt(li x){
	if(x >= 10) prt(x / 10);
	pc(x % 10 + '0');
}
inline void print(li x){
	if(x < 0) pc('-'),x = -x;
	prt(x);
}
inline void file(char *s){
	char c[50];
	sprintf(c,"%s.in",s);
	freopen(c,"r",stdin);
	sprintf(c,"%s.out",s);
	freopen(c,"w",stdout);
}
li s1 = 19260817,s2 = 23333333,s3 = 998244853,srd;
inline li rd(){
	return srd = (srd * s1 + s2 + rand()) % s3;
}
int n,a[200510],m,sq;
li s[200510],p[450][200510]; 
int main(){
	srand(time(0));rd();
	//file("77");
	int i,j,d,p1,p2;
	n = read();sq = sqrtl(n);
	for(i = 1;i <= n;++i) a[i] = read(),s[i] = s[i - 1] + a[i];
	for(i = 1;i <= sq;++i){
		for(j = 1;j <= i;++j) p[i][j] = a[j];
		for(j = i + 1;j <= n;++j) p[i][j] = p[i][j - i] + a[j];
	}
	m = read();
	for(i = 1;i <= m;++i){
		d = read();p1 = read();p2 = read();int q1 = p1,q2 = p2;
		li ans = 0;
		for(j = 0;j < d;++j,++p1,p2 += d) ans += (p[d][p1 + d * (d - 1)] - (p1 > d ? p[d][p1 - d] : 0)) * (s[p2 + d - 1] - s[p2 - 1]);
		//print(d);pc(' ');print(q1);pc(' ');print(q2);pc(' ');
		print(ans);pc('\n');
	}
	//fwrite(bfu,1,bfuu - bfu,stdout);
	//cerr<<clock();
	return 0;
}

