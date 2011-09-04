    .set PCRELV2, (LJTI30_0_0-(LPCRELL2+8))
LPCRELL2:
    add r2, pc, #PCRELV2
    ldr pc, [r2, +r3, lsl #2]
LJTI30_0_0:
    .long    4

