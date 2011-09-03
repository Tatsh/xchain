    .section    __TEXT,__cstring,cstring_literals
    .zerofill   __DATA__, __common, .objc_class_name_HelloApplication, 4, 2

@ old-style macro
.macro foo
    add r0,r0,$0
.endm

@ new-style macro with 1 arg
    .macro bar a
    add r0,r0,\a
.endm

@ new-style macro with 5 args
.macro baz a b c d, e
    add \a,\c,\d
.endm

@ new-style macro with 1 arg and default
.macro boo a=r0
    add \a,r1,\a
.endm

@ new-style macro with 5 args and some defaults
.macro wibble a=r0,b,c=r3 d=r5,e=r9
    add \a, \d, \c, lsl \e
    add \a, \d, \c, lsl\e
.endmacro

.macro wobble a=r0
.rept 12
    add \a,\a,#50
.endr
.endm

.text
nop
nop
nop
nop

.ifc "foo","bar"
bkpt 0
.else
mov r12,r0
.endif

.ifc "foo","foo"
mov r0,r12
.else
bkpt 0
.endif

.set shifter, 31
.rept 32
mov r1,r2,lsl #shifter
.set shifter, shifter - 1
.endr

wobble

.rept 5
add r0,r0,#1
.endr

wibble r0 r1 r2 r3 r4
foo r1
bar r2
baz e=r1,a=r3,b=r4,d=r5,c=r6
baz r3,r4,r6, r5,r1
boo
boo r4 
wibble e=r1,a=,b=r4,d=r5,c=r6
wibble ,r1,,, 

    b 14f
14: mov r0,#42
    mov r0,#19
    mov r4,#30
    b 14b

