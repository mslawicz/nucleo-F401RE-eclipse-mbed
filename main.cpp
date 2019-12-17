#include "mbed.h"
#include "platform/mbed_debug.h"
#include "platform/mbed_error.h"

void print_char(char c = '*')
{
    printf("%c", c);
    fflush(stdout);
}

Thread thread;

DigitalOut led1(LED1);

void print_thread()
{
    while (true) {
        wait(1);
        print_char();
    }
}

int main()
{
    printf("\n\n*** RTOS basic example ***\n");
    debug("this is a debug text\r\n");
    error("error\r\n");

    thread.start(print_thread);

    while (true) {
        led1 = !led1;
        wait(0.2);
    }
}
