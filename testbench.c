
#include <stdio.h>
#include "project.h"

int main(void)
{
    int passed = 0;
    int total = 0;

    struct TestCase {
        GateType gate;
        int a;
        int b;
        int expected;
        const char *name;
    };

    struct TestCase tests[] = {
        {GATE_AND,  1, 1, 1, "AND"},
        {GATE_AND,  1, 0, 0, "AND"},
        {GATE_OR,   0, 0, 0, "OR"},
        {GATE_OR,   1, 0, 1, "OR"},
        {GATE_NOT,  0, 0, 1, "NOT"},
        {GATE_NOT,  1, 0, 0, "NOT"},
        {GATE_NAND, 1, 1, 0, "NAND"},
        {GATE_NOR,  0, 0, 1, "NOR"},
        {GATE_XOR,  1, 0, 1, "XOR"},
        {GATE_XOR,  1, 1, 0, "XOR"},
        {GATE_XNOR, 1, 1, 1, "XNOR"},
        {GATE_XNOR, 1, 0, 0, "XNOR"}
    };

    total = sizeof(tests) / sizeof(tests[0]);

    printf("DIGITAL LOGIC SIMULATOR TESTING\n");
    printf("--------------------------------\n");

    for (int i = 0; i < total; i++)
    {
        int result = evaluate_gate(
            tests[i].gate,
            tests[i].a,
            tests[i].b
        );

        if (result == tests[i].expected)
        {
            printf("PASS: %s Gate\n", tests[i].name);
            passed++;
        }
        else
        {
            printf("FAIL: %s Gate\n", tests[i].name);
        }
    }

    printf("\nTotal Tests: %d\n", total);
    printf("Passed: %d\n", passed);
    printf("Failed: %d\n", total - passed);

    if (passed == total)
        printf("All tests passed successfully!\n");

    return (passed == total) ? 0 : 1;
}
