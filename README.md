# push_swap
Push swap is a 42 algorithm challenge to order an array of integers using limited operation possibilities on stack a and stack b.

## Goal
To order an array of integers using the smallest number os operations possible.

## Allowed operations
swap: swap the first and second elements from the same stack (sa/sb/ss);

push: push the first element from one stack to another (pa/pb);

rotate: rotate the first element to the last position (ra/rb/rr);

reverse rotate: rotate the last element to the first position (rra/rrb/rrr);

## Usage
1. Prerequisites

  - POSIX-compatible shell (bash/zsh)

  - GCC/clang

3. Clone the repository.
```bash
git clone git@github.com:CLMartello/push_swap.git
```
3. Command "make" to compile mandatory part.
```bash
make
```
4. Command "make bonus" to compile bonus part.
```bash
make bonus
```
5. Run executable ./push_swap followed by arguments.
```bash
./push_swap 5 2 1 4 3
```
6. Run the executable ./checker followed by arguments either alone or after pipeline.
```bash
ARG="5 2 1 4 3"; ./push_swap $ARG | ./checker $ARG
```

## License
This project is licensed under the MIT License — see the LICENSE file.
