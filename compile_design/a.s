.data
.globl main
.text

main:
  li $4,0
  addi $4,$5,$6
  move $4,$5
  li $4,0
  move $v0,$4
  jr $ra
