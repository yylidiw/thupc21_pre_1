#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <assert.h>
#define MAXN 500010
#define MAXM 1000010
#define inf 1000000000

using namespace std;

int n , m , a[ MAXN ] , B = 1000 , exist[ MAXN ] , cnt[ MAXN ];
int memory_pool[ MAXN * 2 ] , now_pos;

inline int * get_memory( int x )
{
	now_pos += x;
	return memory_pool + now_pos - x;
}

struct Vector
{
	int * a , * b , * p;
	int lim;
	inline void assign( int c )
	{
		p = a = b = get_memory( lim = c + 1 );
		* a = inf;
	}
	inline void push_back( int x )
	{
		* ++b = x;
	}
	inline void pop_back()
	{
		b--;
	}
	inline int size()
	{
		return b - a;
	}
} pos[ MAXN ];

typedef long long i64;
i64 ans[ MAXM ];

i64 bit[2][MAXN];
void add(i64*f,int w,i64 a){
	assert(w>0);
	for(;w<=n+1;w+=w&-w)f[w]+=a;
}
i64 sum(i64*f,int w){
	assert(w<=n+1);
	i64 s=0;
	for(;w;w-=w&-w)s+=f[w];
	return s;
}

struct Q{
	int x,y,id,sgn;
	bool operator<(const Q&e)const{return y<e.y;}
	void run1(){
		i64 s=sum(bit[0],x);
		ans[id]+=s;
	}
	void run2(int k){
		i64 s0=sum(bit[0],x);
		i64 s1=sum(bit[1],x);
		ans[id]+=sgn*(s0+s1*k);
	}
}qs[ MAXM*2 ];

struct ev{
	int x,y,w0,w1;
	bool operator<(const ev&e)const{return y<e.y;}
	void run(){
		add(bit[0],x,w0);
		if(w1)add(bit[1],x,w1);
	}
}es[ MAXN*2 ];

int ep,qp;

struct Modify{
	int x,l,r;
	void t1(){
		es[ep++]=(ev){n+1-(x-r),x+r,r+1,0};
		if(l>=0)
		es[ep++]=(ev){n+1-(x-l),x+l,-(l+1),0};
	}
	void t2(){
		es[ep++]=(ev){x-r,x*2,x,1};
		if(l>=0)
		es[ep++]=(ev){x-l,x*2,-x,-1};
	}
	void t3(){
		es[ep++]=(ev){n+1-(x+r),-x*2,-x,1};
		if(l>=0)
		es[ep++]=(ev){n+1-(x+l),-x*2,x,-1};
	}
}ms[MAXN];

int mp=0;

struct Query{
	int l,r;
	void t1(int i){
		qs[qp++]=(Q){n+1-l,r,i,1};
	}
	void t2(int i){
		if(!l)return;
		qs[qp++]=(Q){l-1,l+r-1,i,1};
		qs[qp++]=(Q){l-1,l*2-1,i,-1};
	}
	void t3(int i){
		qs[qp++]=(Q){n+1-(r+1),-(l+r),i,1};
		qs[qp++]=(Q){n+1-(r+1),-(r*2+1),i,-1};
	}
}qs0[MAXM];

void clr(){
	std::sort(qs,qs+qp);
	std::sort(es,es+ep);
	for(int i=0;i<2;++i)memset(bit[i],0,sizeof(bit[i][0])*(n+2));
}

namespace IO{
const int BUF_SZ=1e5;
char ib[BUF_SZ],*ip=ib+BUF_SZ,ob[1<<22],*op=ob;
int read(){
	size_t n=ib+BUF_SZ-ip;
	if(n<100){
		memcpy(ib,ip,n);
		fread(ib+n,1,BUF_SZ-n,stdin)[ib+n]=0;
		ip=ib;
	}
	int x=0;
	while(*ip<48)++ip;
	while(*ip>47)x=x*10+*ip++-48;
	return x;
}
void print(long long x){
	char ss[20];
	int sp=0;
	do ss[sp++]=x%10+48;while(x/=10);
	while(sp)*op++=ss[--sp];
	*op++=10;
}
}
using IO::read;
using IO::print;

inline int abs( int x )
{
	return x > 0 ? x : -x;
}

inline void new_range( int x , int l , int r )
{
	//[x-r,x-l] x [x+l,x+r]
	ms[mp++]=(Modify){x,l-1,r};
}

inline void insert( int x )
{
	exist[ ++cnt[ x ] ]++;
}

inline void erase( int x )
{
	exist[ cnt[ x ]-- ]--;
}

int l = 1 , r = 0;

inline void trans( int x , int y )
{
	while( l > x ) insert( a[ --l ] );
	while( r < y ) insert( a[ ++r ] );
	while( l < x ) erase( a[ l++ ] );
	while( r > y ) erase( a[ r-- ] );
}

inline void calc()
{
	memset( cnt , 0 , sizeof( cnt ) );
	int P0 = 1 , P1 = n , D = 0;
	for( int j = B ; ( j - B ) * 2 <= n ; j += B ) //枚举块大小 
	{
		//[t-D,t-1] t [t+1,t+D] 
		int P2 = P0 , P3 = P1 , flag = ( j / B ) & 1;
	  	for( int i = flag ? P2 : P3 ; flag ? i <= P3 : i >= P2 ; flag ? i++ : i-- ) //奇偶排序 
	  	{
	  		if( 1 <= i - j && i + j <= n )
				D = j;
			else
			{
		  		int d = min( j , min( i - 1 , n - i ) );
		  		if( i - j < 1 ) P0++;
		  		else P1--;
		  		D = d;
		  	}
			trans( i - D , i + D );
	  		loop: 
	  		if( pos[i].size() && * pos[i].b <= D ) //最小的元素在块内 
	  		{
	  			if( * ( pos[i].b - 1 ) <= D ) //第二小的元素在块内，要处理掉块内最小元素 
	  			{
	  				int L = i - ( * ( pos[i].b - 1 ) - 1 ) , R = i + ( * ( pos[i].b - 1 ) - 1 ); //从第二小的元素的距离-1位置开始往里面跑
					trans( L , R );
					while( exist[ cnt[i] + 1 ] && ( r - l ) / 2 > ( * pos[i].b ) ) //不是众数，注意下界 
					{
						erase( a[ l++ ] );
						erase( a[ r-- ] );
					}
					if( !exist[ cnt[i] + 1 ] )
						new_range( i , * pos[i].b , ( r - l ) / 2 );
					pos[i].pop_back();
	  				goto loop;
	  			}
	  			trans( i - D , i + D ); //归位 
			  	if( exist[ cnt[i] + 1 ] ) //中心不是众数，在这个块内解决掉 
			  	{
			  		int z = cnt[i] + 1;
					while( exist[z] && ( r - l ) / 2 > ( * pos[i].b ) ) //不是众数，注意下界 
					{
						erase( a[ l++ ] );
						erase( a[ r-- ] );
					}
					if( !exist[ cnt[i] + 1 ] )
						new_range( i , * pos[i].b , ( r - l ) / 2 );
					pos[i].pop_back();
				}
			}
		}
	}
	for( int i = 1 ; i <= n ; i++ )
		if( pos[i].size() )
			new_range( i , * pos[i].b , min( i - 1 , n - i ) );
}

int main()
{
	//freopen( "test.in" , "r" , stdin );
	//freopen( "test.out" , "w" , stdout );
	n = read() , m = read();
	for( register int i = 1 ; i <= n ; i++ )
	{
		a[i] = read();
		cnt[ a[i] ]++;
	}
	for( register int i = 1 ; i <= n ; i++ ) 
		pos[i].assign( cnt[i] );
	for( register int i = 1 ; i <= n ; i++ )
		if( abs( i - a[i] ) <= min( a[i] - 1 , n - a[i] ) )
			pos[ a[i] ].push_back( abs( i - a[i] ) );
	memset( cnt , 0 , sizeof( cnt ) );
	for( int i = 1 ; i <= n ; i++ )
	{
		for( int * j = pos[i].a + 1 ; j <= pos[i].b ; j++ )
			if( !cnt[ * j ] )
				cnt[ * j ] = 1;
			else
				* j = -1;
		for( int * j = pos[i].a + 1 ; j <= pos[i].b ; j++ )
			if( * j != -1 )
				cnt[ * j ] = 0;
		sort( pos[i].a + 1 , pos[i].b + 1 );
		reverse( pos[i].a + 1 , pos[i].b + 1 );
		while( * pos[i].b == -1 ) pos[i].pop_back();
	}
	calc();
	
	for( int i = 0 ; i < m ; i++ ){
		qs0[i].l=read();
		qs0[i].r=read();
	}
	//cerr << clock() << " ms" << endl;
	qp=ep=0;
	for(int i=0;i<m;++i)qs0[i].t1(i);
	for(int i=0;i<mp;++i)ms[i].t1();
	clr();
	for(int i=0,p=0;i<qp;++i){
		for(;p<ep&&es[p].y<=qs[i].y;es[p++].run());
		qs[i].run1();
	}
	
	qp=ep=0;
	for(int i=0;i<m;++i)qs0[i].t2(i);
	for(int i=0;i<mp;++i)ms[i].t2();
	clr();
	for(int i=0,p=0;i<qp;++i){
		for(;p<ep&&es[p].y<=qs[i].y;es[p++].run());
		qs[i].run2(-(qs0[qs[i].id].l-1));
	}
	
	qp=ep=0;
	for(int i=0;i<m;++i)qs0[i].t3(i);
	for(int i=0;i<mp;++i)ms[i].t3();
	clr();
	for(int i=0,p=0;i<qp;++i){
		for(;p<ep&&es[p].y<=qs[i].y;es[p++].run());
		qs[i].run2(qs0[qs[i].id].r+1);
	}
	
	for( int i = 0 ; i < m ; i++ )
		print( ans[i] );
	fwrite(IO::ob,1,IO::op-IO::ob,stdout);
	return 0;
}
