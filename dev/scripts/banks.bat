@echo off
cls

cd ..

REM Banks conversion
cd banks
::folder2c bank2 bank2 2
::folder2c bank3 bank3 3
::folder2c bank4 bank4 4
::folder2c bank5 bank5 5
::folder2c bank6 bank6 6
::folder2c bank7 bank7 7


REM Compile banks
sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK2 bank2.c
sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK3 bank3.c
sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK4 bank4.c
sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK5 bank5.c
sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK6 bank6.c
sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK7 bank7.c


del *.asm > nul; del *.lst > nul; del *.sym > nul
cd ..
cd scripts