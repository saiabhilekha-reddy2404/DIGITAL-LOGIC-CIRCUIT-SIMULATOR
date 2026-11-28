
# Digital Logic Circuit Simulator

## Description

A Digital Logic Circuit Simulator developed using C programming language to simulate basic logic gates such as AND, OR, NOT, NAND, NOR, XOR and XNOR. It evaluates digital circuit operations using binary inputs, displays intermediate gate outputs, and helps students understand Boolean logic, digital electronics, and fundamental circuit behavior through a simple command-line interface.

## Features

- Supports seven fundamental logic gates.
- Accepts binary inputs (0 and 1).
- Supports connections between multiple gates.
- Displays intermediate gate outputs.
- Calculates the final circuit output.
- Includes test cases for verifying gate operations.
- Simple command-line interface.

## Technologies Used

- Programming Language: C
- Compiler: GCC
- Concepts: Boolean Algebra, Digital Electronics
- Tools: VS Code, Git, GitHub

## Repository Structure

```text
Digital-Logic-Circuit-Simulator/
│
├── src/
│   ├── main.c
│   ├── algorithm.c
│   ├── utilities.c
│   └── project.h
│
├── tests/
│   └── test.c
│
├── data/
│   ├── sample_input.txt
│   └── sample_output.txt
│
├── docs/
│   └── working_principle.md
│
├── README.md
└── Makefile
```

## Working Principle

The Digital Logic Circuit Simulator operates based on Boolean algebra and fundamental logic gate operations. It accepts binary inputs (0 and 1) from the user and allows multiple logic gates such as AND, OR, NOT, NAND, NOR, XOR, and XNOR to be connected in sequence. Each gate processes its input signals according to its Boolean expression, and the simulator calculates and stores the corresponding output. Finally, it displays the intermediate gate outputs and the final circuit output, helping users understand and analyze basic digital logic circuit behavior.

## Logic Gates Supported

| Gate | Operation |
|------|-----------|
| AND  | A & B |
| OR   | A \| B |
| NOT  | !A |
| NAND | !(A & B) |
| NOR  | !(A \| B) |
| XOR  | A ^ B |
| XNOR | !(A ^ B) |

## Scope

1. Simulates fundamental digital logic gates and evaluates their Boolean operations using binary inputs.
2. Provides intermediate and final circuit outputs to help understand digital electronics and logic circuit behavior.

## Limitations

1. Supports only basic digital logic gates such as AND, OR, NOT, NAND, NOR, XOR, and XNOR.
2. Does not support sequential circuits such as flip-flops, counters, and registers.
3. Does not provide graphical circuit design or visual simulation.
4. Supports a limited number of primary inputs and logic gates.
5. Does not simulate real-world electrical characteristics, propagation delays, or hardware faults.

## Compilation and Execution

### Step 1: Clone the Repository

```bash
git clone https://github.com/your-username/Digital-Logic-Circuit-Simulator.git
```

### Step 2: Open the Project Folder

```bash
cd Digital-Logic-Circuit-Simulator
```

### Step 3: Compile the Program

```bash
make
```

### Step 4: Run the Program

```bash
./simulator
```

### Step 5: Run Using Sample Input

```bash
./simulator < data/sample_input.txt
```

## Testing

Compile and execute the test program:

```bash
make test
./test
```

## Sample Input

```text
3 4
1 0 1
AND A B
NOT C NONE
XOR G1 G2
OR G3 A
```

## Sample Output

```text
G1 Output = 0
G2 Output = 0
G3 Output = 0
G4 Output = 1

Final Circuit Output = 1
```

## Applications

- Learning digital electronics.
- Understanding Boolean algebra.
- Practicing logic gate operations.
- Designing basic combinational circuits.
- Academic projects and laboratory experiments.

## Author
SaiAbhilekha Reddy

## Language
C Programming language

## Domain
Electronics and Communication Engineering(ECE)

## License
Released under the MIT License.see LICENSE
