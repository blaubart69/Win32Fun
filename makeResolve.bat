cl /nologo /GS- /Os ^
ResolveMain.c resolve.c beelib.c cmdline.c ^
/link /map /entry:rawmain /nodefaultlib /subsystem:console ^
/out:resolve.exe ^
kernel32.lib user32.lib ws2_32.lib libcmt.lib vcruntime.lib