#include <types.h>

void printf(char *str)
{
    static uint16_t *VideoMemory = (unsigned short *)0xb8000;

    for (int i = 0; str[i] != '\0'; ++i)
        VideoMemory[80 * y + x] = (VideoMemory[80 * y + x] & 0xFF00) | str[i];
}

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
    for (constructor *i = &start_ctors; i != &end_ctors; i++)
        (*i)();
}

extern "C" void kernelMain(void *multiboot_structure, unsigned int magicnumber)
{
    printf("prem");

    while (1)
        ;
}