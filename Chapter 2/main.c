#include "pico/stdlib.h"
#include <stdio.h>

int main_program()
{

    const char *helloworld = "main_program: Hello World %d\n";
    int counter = 0;

    while (1)
    {
        // Print "Hello World" with an incrementing counter
        printf(helloworld, counter++);
        sleep_ms(1000); // Add a delay for visibility in the output
    }

    return 0;
}
