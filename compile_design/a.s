main:
  or $fp,$sp,$0
  addi $sp,$sp,-8
  addi $sp,$fp,-0
  lw $2,$sp
  addi $sp,$fp,-0
  lw $3,$sp
  add $0,$2,$3
  or $4,$0
  addi $sp,$fp,-0
  sw $4,$sp
  li $4,0
  move $v0,$4
  jr $ra

