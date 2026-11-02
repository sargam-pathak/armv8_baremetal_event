ENTRY(Reset_Handler)

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x00000000, LENGTH = 128K
    RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 64K
}

SECTIONS
{
    .text :
    {
        KEEP(*(.isr_vector))
        *(.text*)
        *(.rodata*)
    } > FLASH

    .data : 
    { 
        *(.data*) 
    } > RAM

    .bss : 
    { 
        __bss_start__ = .;
        *(.bss*) 
        *(COMMON)
        __bss_end__ = .;
    } > RAM

    . = ALIGN(8);
    end = .;
    __end__ = .;

    _estack = ORIGIN(RAM) + LENGTH(RAM);
}
