DEC gv1 88
DEC gv2 40

FUNCTION main
DEC v3 4
DEC v4 4
v1 := #0
v1 := #0
ARG v1
ARG v1
t1 := CALL add
IF t1 GOTO label1
GOTO label2
LABEL label1 :
v1 := #1
LABEL label2 :
RETURN #0

FUNCTION add
PARAM v1 v4
PARAM v2 v4
DEC v5 800
DEC v6 4
DEC v7 88
v3 := #0
t2 := &v3
t3 := #40 * 0
t4 := t2 + 0
t5 := #4 * 0
t6 := t4 + 0
*t6 := #0
IF 1v3 > #0label3 GOTO label3
GOTO label4
LABEL label3 :
v3 := #1
LABEL label5 :
t7 := &v3
t8 := #40 * 0
t9 := t7 + 0
t10 := #4 * 0
t11 := t9 + 0
IF *t11 GOTO label6
LABEL label7 :
LABEL label6 :
v3 := #2
GOTO label5
LABEL label7 :
GOTO label8
LABEL label4 :
v3 := #0
LABEL label8 :
t12 := v1 + v2
RETURN t12

