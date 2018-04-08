cl /nologo /GS- ^
ResolveRawMain.c resolve.c beelib.c ^
/link /map /entry:rawmain /nodefaultlib /subsystem:console ^
kernel32.lib user32.lib ws2_32.lib libcmt.lib vcruntime.lib