    .text
    ldc p4,cr12,[r6,#-12]
    ldccsl p6,cr5,[r0,#32]!
    stcgel p1,cr0,[r15],#+16
    ldc   p11,cr0,[r0],{0x21}
    fldmiax r0, {d0-d15}
    stc   p11,cr0,[r0],{0x21}
    fstmiax r0, {d0-d15}

