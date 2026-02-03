// ✅ 4) Packet Parser Using Function Pointer Table

// Build a packet decoding system:

// Different packet types:

// TYPE1 → int payload

// TYPE2 → float payload

// TYPE3 → string payload
// Use:

// union Payload

// struct Packet { type; union payload; function_pointer decode; }

// Create decode handlers and call based on type using function pointers.

#include <stdio.h>
typedef enum
{
    TYPE1 = 1,
    TYPE2,
    TYPE3
} packeTypes;

typedef union
{
    int int_payload;
    float float_payload;
    char *string_payload;
} Payload;
typedef void (*Decode_Handler)(Payload *payload);

typedef struct
{
    packeTypes types;
    Payload payload;
    Decode_Handler decode;
} Packet;

void Decode_type1(Payload *payload)
{
    printf("TYPE1 packet: int = %d\n", payload->int_payload);
}

void Decode_type2(Payload *payload)
{
    printf("TYPE2 packet: float = %f\n", payload->float_payload);
}

void Decode_type3(Payload *payload)
{
    printf("TYPE3 packet: String = %s\n", payload->string_payload);
}
int main()
{
    Packet packets[] =
        {
            {TYPE1, .payload.int_payload = 23, Decode_type1},
            {TYPE2, .payload.float_payload = 2.14f, Decode_type2},
            {TYPE3, .payload.string_payload = "hello", Decode_type3}};

    for (int i = 0; i < 3; i++)
    {
        packets[i].decode(&packets[i].payload);
    }
}