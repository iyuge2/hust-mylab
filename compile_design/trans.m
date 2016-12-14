DEC gv1 808
DEC gv2 40

FUNCTION add :
PARAM v1 4
PARAM v2 4
DEC v3 2400
DEC v4 4
DEC v5 40
t1 := &v3
t2 := #5 * #200
t3 := t2 + t1
t4 := #8 * #40
t5 := t4 + t3
t6 := #0 * #4
t7 := t6 + t5
t8 := &gv1
t9 := t8 + #804
*t7 := *t9
v4 := #0
IF v1 > #10 GOTO label1
GOTO label2
LABEL label1 :
t10 := &gv1
t11 := t10 + #804
t12 := &v5
t13 := *t11 * #4
t14 := t13 + t12
v1 := *t14
IF v1 == #1 GOTO label3
GOTO label4
LABEL label3 :
t15 := v1 + #10
v2 := t15
LABEL label4 :
v1 := #1
GOTO label5
LABEL label2 :
v1 := #0
LABEL label5 :
LABEL label6 :
IF v2 && #1 || !v2 GOTO label7
GOTO label8
LABEL label7 :
v1 := #0
LABEL label9 :
IF v1 GOTO label10
GOTO label11
LABEL label10 :
v1 := #1
GOTO label9
LABEL label11 :
GOTO label6
LABEL label8 :
t16 := &v5
t17 := v1 * #4
t18 := t17 + t16
RETURN *t18

FUNCTION main :
DEC v6 4
DEC v7 4
ARG v6
ARG v7
t19 := CALL add
v6 := t19
RETURN #0

