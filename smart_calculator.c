// ✅ 5) Smart Calculator With Union Input

// Create a calculator where input can be:

// integer

// float

// struct Complex {real, imag}
// Use:

// union to hold operand types

// struct Operation { opName; function_pointer execute; union operands }

// Execute operations like ADD, SUB, MUL dynamically using function pointers.

#include <stdio.h>
typedef struct
{
    float real;
    float imag;
} Complex;

typedef union
{
    int I;
    float F;
    Complex C;
} operand;
typedef void (*Operation_Handler)(operand a, operand b);

typedef struct
{
    char name[10];
    Operation_Handler execute;
    operand op1;
    operand op2;
} Operation;

void add_int(operand a, operand b)
{
    printf("Interger Addition = %d\n", a.I + b.I);
}

void sub_int(operand a, operand b)
{
    printf("Interger subtraction = %d\n", a.I - b.I);
}

void mul_int(operand a, operand b)
{
    printf("Interger multiplication = %d\n", a.I * b.I);
}

void add_flaot(operand a, operand b)
{
    printf("Float Addition = %.2f\n", a.I + b.I);
}

void sub_flaot(operand a, operand b)
{
    printf("Float Subtraction = %.2f\n", a.I - b.I);
}

void mul_flaot(operand a, operand b)
{
    printf("Float Multiplication = %.2f\n", a.I * b.I);
}

void add_complex(operand a, operand b)
{
    Complex r;
    r.real = a.C.real + b.C.real;
    r.imag = a.C.imag + b.C.imag;

    printf("COMPLEX ADD = %.2f + %.2fi\n", r.real, r.imag);
}

void sub_complex(operand a, operand b)
{
    Complex r;
    r.real = a.C.real - b.C.real;
    r.imag = a.C.imag - b.C.imag;

    printf("COMPLEX SUB = %.2f - %.2fi\n", r.real, r.imag);
}

void mul_complex(operand a, operand b)
{
    Complex r;
    r.real = a.C.real * b.C.real;
    r.imag = a.C.imag * b.C.imag;

    printf("COMPLEX MUL = %.2f * %.2fi\n", r.real, r.imag);
}

int main()
{
    Operation ops[] =
        {
            {"ADD", add_int, .op1.I = 10, .op2.I = 5},
            {"SUB", sub_flaot, .op1.F = 5.5f, .op2.F = 10.3f},
            {"MUL", add_complex, .op1.C = {1.2f, 2.3f}, .op2.C = {3.2f, 4.5f}}};

    for (int i = 0; i < 3; i++)
    {
        ops[i].execute(ops[i].op1, ops[i].op2);
    }
}
