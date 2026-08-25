*This project has been created as part of the 42 curriculum by seraydin, ugpolat.*

# push_swap

## Description

`push_swap` sorts a stack of unique integers using two stacks and a limited set of operations. The program implements four sorting strategies with different operation-complexity targets and can select a strategy according to the initial disorder of the input.

Available operations are: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, and `rrr`.

## Instructions

Compile the project:

```sh
make
```

Run with the default adaptive strategy:

```sh
./push_swap 4 67 3 87 23
```

Force a strategy:

```sh
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```

Enable benchmark information on standard error:

```sh
./push_swap --bench 5 4 3 2 1
```

Check the generated operations:

```sh
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG
```

Other Makefile rules:

```sh
make clean
make fclean
make re
```

## Algorithms

### Simple — O(n²)

The simple strategy repeatedly locates the smallest element in stack A, moves it to the top using the shortest rotation direction, and pushes it to stack B. After processing every element, the values are pushed back to A.

At most O(n) rotations are required for each of n elements, giving an O(n²) upper bound in push_swap operations.

### Medium — O(n√n)

Values are normalized into indexes from `0` to `n - 1` and divided into chunks of approximately `√(5n)` elements.

Chunks are processed from the highest index range to the lowest. The elements belonging to the current range are pushed from stack A to stack B. The largest index in B is then brought to the top using the shortest rotation direction and pushed directly back to A.

Extracting the largest values first constructs each chunk in ascending order. Because higher chunks are processed before lower chunks, every following chunk is placed above the previously sorted values. This removes the need to rotate A after every `pa`.

There are O(√n) chunks. Locating and pushing each chunk requires a complete scan of stack A, producing O(n√n) operations in total. Sorting the elements inside the chunks also requires O(n√n) operations, so the complete strategy respects the O(n√n) operation bound.

### Complex — O(n log n)

The complex strategy uses binary LSD radix sort on normalized indexes. For each bit, elements are either rotated in A or pushed to B. All elements in B are then pushed back to A.

There are O(log n) bits and every bit processes n elements, giving O(n log n) push_swap operations.

### Adaptive

Before performing any operation, the program calculates disorder using the ratio of inverted pairs to all possible pairs.

Inputs containing two to five elements are handled by specialized small-stack sorting routines. For larger inputs, the strategy is selected according to the initial disorder:

| Condition | Selected strategy | Complexity |
|---|---|---|
| `2-5 elements` | Specialized Sort | O(1) |
| `disorder < 0.2` | Simple | O(n²) |
| `0.2 ≤ disorder < 0.5` | Medium | O(n√n) |
| `disorder ≥ 0.5` | Complex | O(n log n) |

Low-disorder inputs use selection-based sorting, medium-disorder inputs use chunk partitioning, and highly disordered inputs use binary radix sort.

The stacks require O(n) memory. Indexes and counters use constant additional memory per node.

## Quoted-input documentation

Since quoted arguments are now supported, you can add this under Instructions:

Numbers can be supplied separately or as whitespace-separated quoted arguments:

```sh
./push_swap 4 67 3 87 23
./push_swap "4 67 3 87 23"
./push_swap --medium "4 67 3 87 23"
```

## Benchmark Mode

With `--bench`, the program prints the following information to standard error:

- Initial disorder percentage
- Selected strategy and complexity
- Total operation count
- Individual counts for all eleven operations

The operation sequence remains exclusively on standard output.

## Contributions

- **seraydin:** Project integration, flag and configuration handling, radix sort, index assignment, rotations, utilities, benchmark and disorder integration.
- **ugpolat:** Argument parsing and validation, selection and chunk-based sorting, stack operations, push/swap operations, testing and integration.

Both contributors reviewed the complete project and understand all implemented algorithms.

## Resources

- 42 `push_swap` subject
- [Radix sort](https://en.wikipedia.org/wiki/Radix_sort)
- [Selection sort](https://en.wikipedia.org/wiki/Selection_sort)
- [Inversion counting](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics))
- [Big O notation](https://en.wikipedia.org/wiki/Big_O_notation)

AI tools were used for discussing algorithm design, identifying edge cases, debugging, test planning, reviewing subject compliance, and improving documentation. All resulting suggestions were reviewed, tested, and understood by the contributors.,
