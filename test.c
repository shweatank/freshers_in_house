
// ✅ 1) Device Driver Command Handler

// Design a system where each device command (READ/WRITE/RESET) is represented using:

// struct Command { char name[20]; int id; function_pointer handler; union args; }

// Use a union to store different argument types for different commands
// Example:

// READ → address + length

// WRITE → address + data

// RESET → no args
// Execute command list dynamically using function pointers.

#include <stdio.h>

#define READ 1
#define WRITE 2
#define RESET 3

struct READ_DATA
{
    int address;
    int length;
};

struct WRITE_DATA
{
    int address;
    int data;
};

union Command_args
{
    struct READ_DATA read;
    struct WRITE_DATA write;
};

typedef void (*Command_Handler)(union Command_args *args);

struct Command
{
    char name[20];
    int id;
    Command_Handler handler;
    union Command_args args;
};

void Read_fun(union Command_args *data)
{
    printf("Address pointing is %X\n", data->read.address);
    printf("Length of the data is %d\n", data->read.length);
}

void Write_fun(union Command_args *value)
{
    printf("Address pointing is %X\n", value->write.address);
    printf("data is %d\n", value->write.data);
}

void Reset_fun(union Command_args *args)
{
    (void)args;
    printf("device reset done\n");
}

int main(void)
{
    struct Command cmds[] =
        {
            {"READ", READ, Read_fun, .args.read = {0x1000, 4}},
            {"WRITE", WRITE, Write_fun, .args.write = {0x200, 99}},
            {"RESET", RESET, Reset_fun, {0}}};

    int count = sizeof(cmds) / sizeof(cmds[0]);

    /* Execute command list dynamically */
    for (int i = 0; i < count; i++)
    {
        cmds[i].handler(&cmds[i].args);
        printf("\n");
    }

    return 0;
}