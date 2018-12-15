#This is a comment!
#This is the start of my program
#Should count from 5 to 0 and then stop.
lw  1, 0, a
lw  2, 1, 2
start:  add     1, 1, 2
        beq     0, 1, 1
        beq     0, 0, start
done:   halt
a:          .fill 10
b:          .fill -1
startAddr:  .fill start