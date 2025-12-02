## Gift Shop

### Stage 1

We're given inclusive ID ranges like `11-22, 95-115, 998-1012`, and we have to
find IDs/numbers in every range that are essentially doubles of digit subsequences
in that range, each subsequence starts from first digit of number.

The brute force solution is to for every range `R` iterate over numbers
`num` in `R` and check whether `num` length is even, and `num` is doubled
subsequence of [0, num length / 2) indexes.

Observations:
 * we can skip whole subrange of numbers which length % 2 != 0 e.g. 100 - 999
 * `first` and `last` even length numbers of range determine search space e.g.
    `998-1012`: `first: 1000`, `last: 1012`. Thus in range (1000 - 1012) we find
    all prefixes of length 2: `["10"]` then we construct solution by doubling
    prefixes list -> [`1010`]. E.g. for range `95-115` we get
    `first: 95, last: 99`, `prefixes: [9]` -> `solution: ['99']`
 * from the input.txt seems that simple brute force for stage 1 is sufficient.


### Stage 2

We also have to count invalid IDs, but this time invalid ID is specified as
number that is build from repetitive sequence of at least one digit.
E.g.
 * `1212` where repeated part is `12`,
 * `11` where repeated part is `1`,
 * `123456123456` where repeated part is `123456,
 * 123123123` where part `123` is repeated 3 times.

Observations:
 * number can be a * b  digits in size, where a is repetitions cout and
   b is subsequence length. Since a >= 2 and b >= 1 the num length is
   not a prime number. (Not useful).
 * max subsequence length is in range `[1, num length/2]`.
 * We might start with brute force checking by sequence lengths in the above
   range. That would give us solution of
   `n * 1 + n/2 * 2 + n/3 * 3 + ... 2 * n/2 = O(n^2)` where n is `num length`.
