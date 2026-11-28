
#include "project.h"

int evaluate_gate(GateType type, int a, int b)
{
    switch (type)
    {
        case GATE_AND:
            return a && b;

        case GATE_OR:
            return a || b;

        case GATE_NOT:
            return !a;

        case GATE_NAND:
            return !(a && b);

        case GATE_NOR:
            return !(a || b);

        case GATE_XOR:
            return a ^ b;

        case GATE_XNOR:
            return !(a ^ b);

        default:
            return -1;
    }
}
