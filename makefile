all: HelloWorld_rawmain_printf.exe HelloWorld_win32.exe

cflags=/nologo
cc=cl.exe
ln=link.exe /nologo
out=out

HelloWorld_rawmain_printf.exe: HelloWorld_rawmain_printf.obj
	$(ln) $(out)\HelloWorld_rawmain_printf.obj /OUT:$(out)\HelloWorld_rawmain_printf.exe  /entry:rawmain /subsystem:console /map /nodefaultlib kernel32.lib libcmt.lib libucrt.lib libvcruntime.lib

HelloWorld_win32.exe: HelloWorld_win32.obj
	$(ln) $(out)\HelloWorld_win32.obj /OUT:$(out)\HelloWorld_win32.exe /entry:rawmain /subsystem:console /map /nodefaultlib kernel32.lib



HelloWorld_win32.obj: HelloWorld_win32.c
	$(cc) $(cflags) /c /GS- /Fo:$(out)\HelloWorld_win32.obj HelloWorld_win32.c

HelloWorld_rawmain_printf.obj: HelloWorld_rawmain_printf.c
	$(cc) $(cflags) /c /GS- /Fo:$(out)\HelloWorld_rawmain_printf.obj  HelloWorld_rawmain_printf.c
 
