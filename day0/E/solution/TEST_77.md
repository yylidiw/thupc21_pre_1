#### 题目描述
给定长度为$n$的序列$a_1,a_2,\dots,a_n$；
共$m$组询问，每次询问给出$d,p_1,p_2$，求$\sum\limits_{i=0}^{d-1}\sum\limits_{j=0}^{d-1}\sum\limits_{k=0}^{d-1}a_{p_1+d\cdot i+j}a_{p_2+d\cdot j+k}$；

#### 数据范围

$1\le n,m,a_i\le 2\cdot 10^5$，所有数值为整数，询问保证$a$的下标在$[1,n]$内。

#### 输入格式
$n$
$a_1\;a_2\;\dots\;a_n$
$m$
$d_1\;p_{1,1}\;p_{2,1}$
$d_2\;p_{1,2}\;p_{2,2}$
$\dots$
$d_m\;p_{1,m}\;p_{2,m}$

#### 输出格式
共$m$行，表示每个询问对应的答案

题解
$\sum\limits_{i=0}^{d-1}\sum\limits_{j=0}^{d-1}\sum\limits_{k=0}^{d-1}a_{p_1+d\cdot i+j}\cdot a_{p_2+d\cdot j+k}$
$=\sum\limits_{j=0}^{d-1}\left(\sum\limits_{i=0}^{d-1}a_{(p_1+j)+d\cdot i}\right)\cdot\left(\sum\limits_{k=0}^{d-1}a_{(p_2+d\cdot j)+k}\right)$
左边是公差 $d=O(\sqrt n)$ 的等差数列对应位置的区间和，右边是区间和，可以预处理每个公差的前缀和，询问时只需枚举 $j$，时间复杂度 $O\left((n+m)\sqrt n\right)$。