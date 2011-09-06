clz r2,r11

msr cpsr_cxsf,#10
msr cpsr_c,r10
msr spsr_xfs,#10
mrs r10,cpsr
mrs r10,spsr

blx wibble
wibble:    blxne r1

sub sp, sp, #1, 22

strh r1, [sp, #+118]
ldrh r1, [sp, #+118]

strh r0, [r1, #25]
strh r0, [r1, #-25]
strh r0, [r1, +r2]
strh r0, [r1, -r2]
strh r0, [r1, r2]
strh r0, [r1, #25]!
strh r0, [r1, +r2]!
strh r0, [r1], #25
strh r0, [r1], #-25
strh r0, [r1], -ip
strh r0, [r1]

ldrh r0, [r1, #+25]
ldrh r0, [r1, #-25]
ldrh r0, [r1, +r2]
ldrsb r0, [r1, -r2]
ldrsb r0, [r1, r2]
ldrsb r0, [r1, #25]!
ldrsh r0, [r1, +r2]!
ldrsh r0, [r1], #25
ldrsh r0, [r1], #-25
ldrh r0, [r1], -ip
ldrsb r0, [sp]

