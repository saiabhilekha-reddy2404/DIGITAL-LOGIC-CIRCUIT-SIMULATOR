
#include <stdio.h>
#include <string.h>
#include "project.h"

int main(void)
{
    int inputs[MAX_INPUTS];
    Gate gates[MAX_GATES];

    int input_count, gate_count;
    int a, b, i;

    char gate_name[MAX_NAME];

    printf("DIGITAL LOGIC CIRCUIT SIMULATOR\n");
    printf("--------------------------------\n");

    printf("Enter number of primary inputs and gates: ");

    if (scanf("%d %d", &input_count, &gate_count) != 2)
    {
        printf("Error: Invalid input.\n");
        return 1;
    }

    if (input_count < 1 || input_count > MAX_INPUTS ||
        gate_count < 1 || gate_count > MAX_GATES)
    {
        printf("Error: Input or gate limit exceeded.\n");
        return 1;
    }

    printf("\nEnter primary input values (0 or 1):\n");

    for (i = 0; i < input_count; i++)
    {
        printf("%c: ", 'A' + i);

        if (scanf("%d", &inputs[i]) != 1 ||
            !validate_binary(inputs[i]))
        {
            printf("Error: Inputs must be 0 or 1.\n");
            return 1;
        }
    }

    printf("\nEnter gate definitions:\n");
    printf("Format: GATE INPUT1 INPUT2\n");
    printf("For NOT gate, use NONE as INPUT2.\n\n");

    for (i = 0; i < gate_count; i++)
    {
        printf("Gate G%d: ", i + 1);

        if (scanf("%15s %15s %15s",
                  gate_name,
                  gates[i].input1,
                  gates[i].input2) != 3)
        {
            printf("Error: Invalid gate definition.\n");
            return 1;
        }

        gates[i].type = parse_gate_type(gate_name);

        if (gates[i].type == GATE_INVALID)
        {
            printf("Error: Unsupported logic gate.\n");
            return 1;
        }

        if (gates[i].type == GATE_NOT)
        {
            if (strcmp(gates[i].input2, "NONE") != 0)
            {
                printf("Error: NOT gate requires NONE as input2.\n");
                return 1;
            }
        }
        else if (strcmp(gates[i].input2, "NONE") == 0)
        {
            printf("Error: Second input required.\n");
            return 1;
        }

        if (!resolve_source(
                gates[i].input1,
                inputs,
                input_count,
                gates,
                i,
                &a))
        {
            printf("Error: Invalid first input source.\n");
            return 1;
        }

        b = 0;

        if (gates[i].type != GATE_NOT)
        {
            if (!resolve_source(
                    gates[i].input2,
                    inputs,
                    input_count,
                    gates,
                    i,
                    &b))
            {
                printf("Error: Invalid second input source.\n");
                return 1;
            }
        }

        gates[i].output = evaluate_gate(
            gates[i].type, a, b
        );

        if (gates[i].output < 0)
        {
            printf("Error: Gate evaluation failed.\n");
            return 1;
        }
    }

    printf("\nCIRCUIT SIMULATION RESULTS\n");
    printf("--------------------------\n");

    for (i = 0; i < gate_count; i++)
    {
        printf("G%d Output = %d\n",
               i + 1,
               gates[i].output);
    }

    printf("\nFinal Circuit Output = %d\n",
           gates[gate_count - 1].output);

    return 0;
}
