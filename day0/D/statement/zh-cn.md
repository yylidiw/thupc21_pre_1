{{ self.title() }}

{{ s('background') }}

给定一个长为 $n$ 的序列 $a$，定义 $x$ 为区间 $[l,r]$ 的众数当且仅当不存在 $y$ 使得 $y$ 在区间 $[l,r]$ 中的出现次数大于 $x$ 在区间 $[l,r]$ 中的出现次数。

有 $m$ 次询问，每次询问给出 $l,r$，求有多少二元组 $(l',r')$ 满足 $l \le l' \le r' \le r$ ，且 $[l',r']$ 的区间长度为奇数，且 $(l'+r')/2$ （注意这里是下标而不是下标对应的值）是区间 $[l',r']$ 中的众数。

{{ s('input format') }}

{{ self.input_file() }}

输入的第一行包含两个数 $n$ $m$。

之后一行 $n$ 个数表示这个序列。

之后 $m$ 行，每行两个数 $l$ $r$ 表示一次询问。

其中 $1\le n\le 5\cdot 10^5，1\le m\le 10^6$，所有数值为整数。

{{ s('output format') }}

{{ self.output_file() }}

输出共 $m$ 行，表示每个询问对应的答案。

{{ s('sample', 1) }}

{{ self.sample_text() }}

上面是自动读入样例 `1.in/ans`（存储在 `down` 文件夹内） 然后渲染到题面中；如果只有一组样例，则去掉 `1` 或将其替换成空串，样例仍然保存成 `1.in/ans`。上面的 `1` 可以是字符串。

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