#include <stdint.h>

typedef struct {
    uint32_t *psp;
} TCB_t;

__attribute__((unused)) volatile static TCB_t *current_tcb;

void SysTick_Handler(void) {
    // Context switching handler
}
