// ✅ 10) Hardware Register Access Abstraction Layer

// Create a HAL layer where each register can be:

// 8-bit register

// 16-bit register

// 32-bit register
// Use:

// union register value (u8/u16/u32)

// struct Register { address; size; function pointers for read/write; union value }

// Simulate read/write operations via function pointer abstraction.
#include <stdio.h>
#include <stdint.h>

typedef union
{
    uint8_t u8;
    uint16_t u16;
    uint32_t u32;
} Register_value;

struct Register;
typedef void (*Reg_read)(struct Register *reg);
typedef void (*Reg_write)(struct Register *reg);
typedef struct Register
{
    uint32_t address;
    uint8_t size;

    Reg_read read;
    Reg_write write;
    Register_value value;
} Register;

void read8_bit(Register *reg)
{
    printf("READ 8-bit from address 0x%X value = %u\n", reg->address, reg->value.u8);
}

void write8_bit(Register *reg)
{
    printf("write 8-bit to address 0x%X value = %u\n", reg->address, reg->value.u8);
}

void read16_bit(Register *reg)
{
    printf("READ 16-bit from address 0x%X value = %u\n", reg->address, reg->value.u16);
}

void write16_bit(Register *reg)
{
    printf("write 16-bit to address 0x%X value = %u\n", reg->address, reg->value.u16);
}

void read32_bit(Register *reg)
{
    printf("READ 32-bit from address 0x%X value = %u\n", reg->address, reg->value.u32);
}

void write32_bit(Register *reg)
{
    printf("write 32-bit to address 0x%X value = %u\n", reg->address, reg->value.u32);
}

int main()
{
    Register regs[] = {
        {0x100, 8, read8_bit, write8_bit, .value.u8 = 12},
        {0x200, 16, read16_bit, write16_bit, .value.u16 = 1234},
        {0x300, 32, read32_bit, write32_bit, .value.u32 = 12345678}};

    for (int i = 0; i < 3; i++)
    {
        regs[i].write(&regs[i]);
        regs[i].read(&regs[i]);
        printf("\n");
    }
}