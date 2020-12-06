{{ self.title() }}

{{ s('description') }}

有一个 $n$ 行 $m$ 列的棋盘，共有 $nm$ 个格子。请你在格子内放入棋子（每个格子可以放入至多一个棋子），使得对于所有 $1\le i\le m$，第 $i$ 列里恰好包含 $a_i$ 个棋子。另外，棋盘上的任意两颗棋子都不能边相邻。

请判断是否存在一种合法方案。如果存在，请输出任意一个合法方案。

{{ s('input format') }}

{{ self.input_file() }}

输入的第一行包含两个正整数 $n,m$，保证 $n \le {{ tl.hn(args['n']) }},  m \le {{ tl.hn(args['m']) }}$。

输入的第二行包含 $m$ 个非负整数 $a_1,a_2,\dots,a_m$，保证 $0 \le a_i \le n$。

{{ s('output format') }}

{{ self.output_file() }}

如果无解，输出一个字符串 `No`。

如果有解，第一行输出一个字符串 `Yes`，接下来 $n$ 行每行输出一个长度为 $m$ 的字符串，表示你构造的棋盘方案。其中 `0` 表示空格，`1` 表示放入棋子的格子。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ s('sample', 2) }}

{{ self.sample_text() }}

