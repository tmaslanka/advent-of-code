### [Lobby](https://adventofcode.com/2025/day/3)

## Stage 1
We're given list of digit sequences. The goal is to find 2 digits subsequence
in each sequence, such that digits of subsequence represent a maximum possible
number. Digits can not be reordered.
```
987654321111111
811111111111119
234234234234278
818181911112111
```
max 2 digit subsequences:
```
98
89
78
92
```
Then we have to sum all 2 digit maximum numbers of each sequence.

Summing is trivial. Let's figure out how to find maximum 2 digit number from
given sequence.

Let's consider `12345` sequence. Obviously the answer is `45` we can not reorder
digits. The brute force solution is to check all possible digits pairs:
```
12, 13, 14, 15,
    23, 24, 25,
        34, 35,
            45,
```
Thus brute force solution time cost is `O(n^2)`, where n is the sequence length.

# O(n) solution
To maximise 2 digit number we have to maximise the 1st digit, this should be
obvious for reader. Then we recursively maximise the second digit.
Find first max digit first index `m` in range `[0, n-1]`,
then do the same for range `[m_idx+1, n]`
it will produce second digit index `k`. Then return sequence[m] sequence[k] as
two digit number. Time cost `O(n-1) + O(n-1) = O(n)`.
E.g., in sequence `14343` we first find `4` at `m = 1` then `4` at `k = 3`, thus
the max 2 digit number is `44`.


## Stage 2
# O(k * n) solution
Now we're asked to find `12` digits maximum numbers in each sequence. We can
reuse solution from `Stage 1` and just generalise it a bit to `k` digits max
number. So we have to find max digits indexes (`k=12`) `[m0, m1, m2, ..., m11]` in ranges
respectively [0, n-12], [m1+1, n-11], ..., [m10+1, n-1].
Time cost `k * O(n) = O(k * n)`.

# O(n) solution:
Let's create digits indexes stacks.
```
143432222222

[
1: [0],
2: [11, 10, 9, 8, 7, 6, 5],
3: [4, 2],
4: [3, 1],
5: [],
6: [],
7: [],
8: [],
9: [],
]

```
Then `k` times we have to pick the largest possible digit from indexes at top
of our stacks.

Let's define last picked number index as `idx=-1`.
Then for `i in [k, 1]` times let's probe digit `d` in range `[9, 1]`
(from biggest to lowest).
Now we look for next digit to pick index.
We can throw away all indexes of digits before last choosen digit `<= idx`.
Our new digit index must be less or equal to `n - i`.
Then on each step there is max 9 checks. Also we're have `n` digits in our
stacks in total, and we're pop'ing each digit exactly once. So the time cost is
`O(n) + k * 9 = O(n + k)`, where 9 is digit number (1 to 9).
However we know that `k <= n`, thus `O(n + k) = O(2n) = O(n)`.
