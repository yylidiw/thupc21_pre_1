{{ self.title() }}

{{ s('background') }}

给定长度为 $n$ 的序列 $a_1,a_2,\dots,a_n$；
共 $m$ 组询问，每次询问给出 $d,p_1,p_2$，求$\sum\limits_{i=0}^{d-1}\sum\limits_{j=0}^{d-1}\sum\limits_{k=0}^{d-1}a_{p_1+d\cdot i+j}a_{p_2+d\cdot j+k}$；

{{ s('input format') }}

{{ self.input_file() }}

输入的第一行包含一个数 $n$。

之后一行 $n$ 个数，表示 $a$ 这个序列。

之后一行一个数 $m$。

之后 $m$ 行，每行三个数 $d,p_1,p_2$ 表示一次询问。

$1\le n,m,a_i\le 2\cdot 10^5$，所有数值为 $[1,10^9]$ 以内的整数，询问保证$a$的下标在$[1,n]$内。

{{ s('output format') }}

{{ self.output_file() }}

输出共 $m$ 行，表示每个询问对应的答案，答案对 $4294967296$，即 $2^{32}$ 取模。

{{ self.title_sample_description() }}

这是第一组数据的样例说明。

{{ s('sample', 2) }}

{{ self.sample_file() }}

上面是只提示存在第二组样例，但不渲染到题面中。

{{ s('subtasks') }}

不要使用markdown原生的表格，使用下列方式渲染一个表格，其中表格存放在试题目录的 `tables` 子目录下。

{{ tbl('data') }}

{{ tbl('table', width = [1, 6]) }}

原理上用一个二维的 json 表格或 python 表格存储，`null` 表示和上一行合并，不支持横向合并。建议用 python 的格式写，如例子中的 `data.pyinc`，这样可以根据数据生成；跟数据无关的表格则可以像 `table.json` 那样存储。

{{ s('scoring') }}

这是评分方法，如果有必要的话。

{{ s('hint') }}

这里是一个非常温馨的提示。