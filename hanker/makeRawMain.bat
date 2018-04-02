cl /nologo /GS- ^
hankerRawMain.c HankerProgram.c ^
/link /map /entry:rawmain /nodefaultlib /subsystem:console ^
kernel32.lib user32.lib