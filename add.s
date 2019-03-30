.file "add.s"
.globl add
.globl add_array_asm_plus
.globl add_array_asm_minus

add:
    add     3, 3, 4
    blr


add_array_asm_plus:
    li      0, 32767
    mtctr   0
    mr      9, 3
    xor     3, 3, 3
    xor     10, 10, 10

    lwzx    0, 9, 10
    add     3, 3, 0
    addi    10, 10, 4
    bdnz+   -0xc

    blr


add_array_asm_minus:
    li      0, 32767
    mtctr   0
    mr      9, 3
    xor     3, 3, 3
    xor     10, 10, 10

    lwzx    0, 9, 10
    add     3, 3, 0
    addi    10, 10, 4
    bdnz-   -0xc

    blr

