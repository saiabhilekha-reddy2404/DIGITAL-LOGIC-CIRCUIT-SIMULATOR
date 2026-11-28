
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "project.h"

GateType parse_gate_type(const char *name)
{
    if (strcmp(name, "AND") == 0)
        return GATE_AND;

    if (strcmp(name, "OR") == 0)
        return GATE_OR;

    if (strcmp(name, "NOT") == 0)
        return GATE_NOT;

    if (strcmp(name, "NAND") == 0)
        return GATE_NAND;

    if (strcmp(name, "NOR") == 0)
        return GATE_NOR;

    if (strcmp(name, "XOR") == 0)
        return GATE_XOR;

    if (strcmp(name, "XNOR") == 0)
        return GATE_XNOR;

    return GATE_INVALID;
}

int validate_binary(int value)
{
    return (value == 0 || value == 1);
}

int resolve_source(
    const char *name,
    const int inputs[],
    int input_count,
    const Gate gates[],
    int gate_count,
    int *value)
{
    /* Check primary inputs A, B, C, etc. */
    if (name[0] >= 'A' &&
        name[0] < 'A' + input_count &&
        name[1] == '\0')
    {
        *value = inputs[name[0] - 'A'];
        return 1;
    }

    /* Check previous gate outputs G1, G2, etc. */
    if (name[0] == 'G')
    {
        char *end;
        long index = strtol(name + 1, &end, 10);

        if (*end == '\0' &&
            index >= 1 &&
            index <= gate_count)
        {
            *value = gates[index - 1].output;
            return 1;
        }
    }

    return 0;
}
