{{ self.title() }}

{{ s('background') }}

给定长度为 $n$ 的序列 $a_1,a_2,\dots,a_n$；
共 $m$ 组询问，每次询问给出 $d,p_1,p_2$，求

$$\sum\limits_{i=0}^{d-1}\sum\limits_{j=0}^{d-1}\sum\limits_{k=0}^{d-1}a_{p_1+d\cdot i+j}a_{p_2+d\cdot j+k}$$；

{{ s('input format') }}

{{ self.input_file() }}

输入的第一行包含一个数 $n$。

之后一行 $n$ 个数，表示 $a$ 这个序列。

之后一行一个数 $m$。

之后 $m$ 行，每行三个数 $d,p_1,p_2$ 表示一次询问。

$1\le n,m,a_i\le 2\times 10^5$，所有数值为 $[1,10^9]$ 以内的整数，询问保证 $a$ 的下标在 $[1,n]$ 内。

{{ s('output format') }}

{{ self.output_file() }}

输出共 $m$ 行，表示每个询问对应的答案，答案对 $2^{32}$ 取模。

{{ s('sample', 1) }}

{{ self.sample_text() }}