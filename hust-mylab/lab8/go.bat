ML /c /coff /I"C:\masm32\include" exp_8.asm
RC STU_RC.RC
CVTRES /machine:ix86 STU_RC.RES
link /subsystem:windows /libpath"C:\masm32\lib" exp_8.obj STU_RC.obj
