#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/flash.h"
#include "hardware/sync.h"

int main_program()
{

    const char *helloworld = "main_program: Hello World %d\n";
    int counter = 0;

    const uint32_t flash_write_start_addr = 0x00082200;
    const uint8_t data_to_write[256] = "Hello, Flash Memory!"; // Example data

    uint32_t flash_sector = flash_write_start_addr & ~(FLASH_SECTOR_SIZE - 1); // Align down to the nearest sector boundary
    flash_range_erase(flash_sector, FLASH_SECTOR_SIZE);

    uint32_t flash_page = flash_write_start_addr & ~(FLASH_PAGE_SIZE - 1); // Align down to the nearest page boundary
    flash_range_program(flash_page, data_to_write, sizeof(data_to_write));

    while (1)
    {
        // Print "Hello World" with an incrementing counter
        printf(helloworld, counter++);
        sleep_ms(1000); // Add a delay for visibility in the output
    }

    return 0;
}
