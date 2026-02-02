
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

#define READ_CMD 1
#define WRITE_CMD 2
#define RESET_CMD 3

struct Read_data
{
    int address;
    int len;
};

struct Write_data
{
    int address;
    int value;
};

union Command_Args
{
    struct Read_data read;
    struct Write_data write;
};

typedef void (*Command_Handler)(union Command_Args *data);
void read_func(union Command_Args *data)
{
    printf("Reading from address %X\n", data->read.address);
    printf("Length = %d\n", data->read.len);
}

void write_func(union Command_Args *data)
{

    printf("writing value %d\n", data->write.value);
    printf("Address %X\n", data->write.address);
}

void reset_func(union Command_Args *args)
{
    (void)args;
    printf("Device reset done\n");
}



int main(void)
{
    int cmd_id;
    Command_Handler func = NULL;
    union Command_Args data;
    printf(" Enter 1 to READ \n Enter 2 to WRITE \n Enter 3 to RESET \n");
    scanf("%d", &cmd_id);
    while (1)
    {
        scanf("%d", &cmd_id);
        switch (cmd_id)
        {
        case READ_CMD:
            data.read.address = 0x100;
            data.read.len = 4;
            func = read_func;
            break;

        case WRITE_CMD:
            data.write.address = 0x200;
            data.write.value = 99;
            func = write_func;
            break;

        case RESET_CMD:
            func = reset_func;
            break;

        default:
            printf("Invalid command\n");
            return 1;
        }

        func(&data);
    }

    return 0;
}