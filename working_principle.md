
# Working Principle

The Digital Logic Circuit Simulator works based on Boolean algebra and fundamental digital logic operations.

## 1. Input Initialization

The program accepts the number of primary inputs and logic gates.
Each primary input is assigned a binary value (0 or 1).

## 2. Gate Selection

The user selects the required logic gates, including:

- AND
- OR
- NOT
- NAND
- NOR
- XOR
- XNOR

## 3. Signal Connections

Each gate receives signals from primary inputs or previously evaluated gates.
The simulator processes the gates in the order they are provided.

## 4. Boolean Evaluation

The algorithm performs the corresponding Boolean operation for each gate.

- AND produces 1 when both inputs are 1.
- OR produces 1 when at least one input is 1.
- NOT produces the complement of its input.
- NAND produces the complement of AND.
- NOR produces the complement of OR.
- XOR produces 1 when inputs are different.
- XNOR produces 1 when inputs are equal.

## 5. Output Generation

The output of each gate is calculated and stored.
The program displays all intermediate outputs and the final circuit output.

## 6. Result

The simulator helps users understand how different digital logic gates work together to form a digital circuit.
