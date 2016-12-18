.data
.globl main
.text

main:
  li $4,0
  li $4,0
  jal add
  move $4,$v0
  j label2
label1:
  li $4,1
label2:
  li $4,0
  move $v0,$4

add:
  li $4,0
  move $4,$5
  li $5,40
  mul $4,$5,$6
  addi $4,$5,$6
  li $5,4
  mul $4,$5,$6
  addi $4,$5,$6
  li $4,0
  bgt $4,$5,label3
  j label4
label3:
  li $4,1
label5:
  move $4,$5
  li $5,40
  mul $4,$5,$6
  addi $4,$5,$6
  li $5,4
  mul $4,$5,$6
  addi $4,$5,$6
label7:
label6:
  li $4,2
  j label5
label7:
  j label8
label4:
  li $4,0
label8:
  addi $4,$5,$6
  move $v0,$4

