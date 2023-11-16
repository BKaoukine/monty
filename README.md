# Monty Scripting Language

Monty is a powerful scripting language that compiles into Monty Byte Codes, akin to Python. It features a distinctive stack with specific instructions tailored for stack manipulation. The `monty` interpreter is designed to execute Monty Byte Code files seamlessly.

## About Monty Language

Monty is a language designed for manipulating data structures such as stacks or queues. Each instruction, referred to as an "opcode," is executed line by line. Files containing Monty Byte Codes typically use the `.m` extension.

For example (in `file.m`):

```bash
$ cat file.m
# Pushing element to the stack
push 0
push 1
push 2
# Printing all elements
pall
push 3
push 4
pop
# Rotating the stack to the bottom
rotr
pall
rotl
# Setting FIFO
queue
push 5
# Setting LIFO
stack
push 5
$
```

## Technologies

- The interpreter is implemented in C language.
- C files are compiled using `gcc 4.8.4`.
- C files adhere to the C90 standard.
- Tested on Ubuntu 20.04 LTS.

## Usage

To compile all files:

```bash
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
$
```

The interpreter can be invoked using:

```bash
$ ./monty [filename]
$
```

To run the interpreter:

```bash
$ ./monty file.m
2
1
0
0
3
2
1
$
```

## Features

### Supported Opcodes

`monty` interpreter supports the following opcodes:

| Opcode | Description |
| ------ | ----------- |
| `push` | Pushes an element onto the stack |
| `pall` | Prints all values in the stack |
| `pint` | Prints the top value of the stack |
| `pop`  | Removes the top element from the stack |
| `swap` | Swaps the top two elements in the stack |
| `queue`| Sets the data format as a queue (FIFO) |
| `stack`| Sets the data format as a stack (LIFO) |
| `nop`  | No operation |
| `add`  | Adds the top two elements in the stack |
| `sub`  | Subtracts the top element from the second top element |
| `mul`  | Multiplies the second top element with the top element |
| `div`  | Divides the second top element by the top element |
| `mod`  | Computes the remainder of division |
| `pchar`| Prints the character at the top of the stack |
| `pstr` | Prints the string starting from the top of the stack |
| `rotl` | Rotates the stack to the top |
| `rotr` | Rotates the stack to the bottom |

Comments, indicated by `#`, are ignored during execution.

For non-existent opcodes, the interpreter displays an error message and halts:

```bash
$ cat errorfile.m
push 1
pint
pcx
$ ./monty errorfile.m
1
L3: unknown instruction pcx
```

### Return Value

`monty` returns `EXIT_SUCCESS` upon successful execution. In case of errors, it returns `EXIT_FAILURE`.
