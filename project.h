
#ifndef PROJECT_H
#define PROJECT_H

#define MAX_INPUTS 8
#define MAX_GATES 50
#define MAX_NAME 16

typedef enum {
    GATE_AND,
    GATE_OR,
    GATE_NOT,
    GATE_NAND,
    GATE_NOR,
    GATE_XOR,
    GATE_XNOR,
    GATE_INVALID
} GateType;

typedef struct {
    GateType type;
    char input1[MAX_NAME];
    char input2[MAX_NAME];
    int output;
} Gate;

GateType parse_gate_type(const char *name);

int evaluate_gate(GateType type, int a, int b);

int resolve_source(
    const char *name,
    const int inputs[],
    int input_count,
    const Gate gates[],
    int gate_count,
    int *value
);

int validate_binary(int value);

#endif
