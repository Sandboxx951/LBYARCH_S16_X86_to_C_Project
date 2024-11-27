section .text
bits 64
default rel
global asmGetDistance

asmGetDistance:
    
    subss xmm0, xmm1
    subss xmm2, xmm3
    
    mulss xmm0, xmm0
    mulss xmm2, xmm2
    
    addss xmm0, xmm2
    
    sqrtss xmm0, xmm0
    
    xor rax, rax
    ret