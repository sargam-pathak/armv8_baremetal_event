#include <stdint.h>

extern uint32_t _estack;

// Declare main so the compiler knows it exists
extern int main(void);

void Reset_Handler(void) {
    // Call main function
    main();
    while (1);
}

void Default_Handler(void) {
    while (1);
}

void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void) __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void) __attribute__((weak, alias("Default_Handler")));

// Cortex-M Vector Table
__attribute__((section(".isr_vector")))
void (*const g_pfnVectors[])(void) = {
    (void (*)(void))(&_estack), // 0: Initial Stack Pointer
    Reset_Handler,             // 1: Reset Handler
    NMI_Handler,               // 2: NMI Handler
    HardFault_Handler,         // 3: Hard Fault Handler
    0, 0, 0,                   // 4-6: Reserved
    0, 0, 0, 0,                // 7-10: Reserved
    SVC_Handler,               // 11: SVCall Handler
    0, 0,                      // 12-13: Reserved
    PendSV_Handler,            // 14: PendSV Handler
    SysTick_Handler            // 15: SysTick Handler
};