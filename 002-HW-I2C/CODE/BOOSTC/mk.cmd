

"C:\Program Files (x86)\SourceBoost\boostc++_pic16.exe" -v -t PIC12F683  -idx 1 -obj Debug -d _DEBUG SRC\hello.c

"C:\Program Files (x86)\SourceBoost\boostlink_picmicro.exe" -idx 1  /ld "C:\Program Files (x86)\SourceBoost\lib" libc.pic16.lib Debug\hello.obj /t PIC12F683 /d "Debug" /p Wombat
