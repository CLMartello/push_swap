# push_swap
Push swap is a 42 algorithm challenge to order an array of integers using limited operation possibilities on stack a and stack b.

## Goal
To order an array of integers using the smallest number os operations possible.

## Allowed operations
swap: swap the first and second elements from the same stack;

push: push the first element from one stack to another;

rotate: rotate the first element to the last position;

reverse rotate: rotate the last element to the first position;

## Usage
1. Clone the repository.
```bash
git clone git@github.com:CLMartello/push_swap.git
```
3. Command "make" to compile mandatory part.
```bash
make
```
5. Command "make bonus" to compile bonus part.
```bash
make bonus
```
7. Run executable ./push_swap followed by arguments.
```bash
./push_swap 5 2 1 4 3
```
9. Run the executable ./checker followed by arguments either alone or after pipeline.
```bash
ARG="5 2 1 4 3"; ./push_swap $ARG | ./checker $ARG
```
