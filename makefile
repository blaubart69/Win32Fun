cflags=/nologo
cc=cl.exe
ln=link.exe /nologo
out=out\$(PROCESSOR_ARCHITECTURE)

all: create_dirs \
	$(out)\HelloWorld_rawmain_printf.exe \
	$(out)\HelloWorld_win32.exe

# create output directories
create_dirs:
 @if not exist $(out) mkdir $(out)

$(out)\HelloWorld_rawmain_printf.exe: $(out)\HelloWorld_rawmain_printf.obj
	$(ln) /nologo $(out)\HelloWorld_rawmain_printf.obj /OUT:$(out)\HelloWorld_rawmain_printf.exe  /entry:rawmain /subsystem:console /map /nodefaultlib kernel32.lib libcmt.lib libucrt.lib libvcruntime.lib

$(out)\HelloWorld_win32.exe: $(out)\HelloWorld_win32.obj
	$(ln) /nologo $(out)\HelloWorld_win32.obj /OUT:$(out)\HelloWorld_win32.exe /entry:rawmain /subsystem:console /map /nodefaultlib kernel32.lib



$(out)\HelloWorld_win32.obj: HelloWorld_win32.c
	$(cc) $(cflags) /c /GS- /Fo:$(out)\HelloWorld_win32.obj HelloWorld_win32.c

$(out)\HelloWorld_rawmain_printf.obj: HelloWorld_rawmain_printf.c
	$(cc) $(cflags) /c /GS- /Fo:$(out)\HelloWorld_rawmain_printf.obj  HelloWorld_rawmain_printf.c
 
