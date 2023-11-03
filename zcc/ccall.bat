@echo off
cls

rem erase latest rom
erase *.sms

rem clear
erase *.o
erase *.bin

rem Compile banks
zcc +sms -c -clib=new --constsegBANK_02 bank2.c
zcc +sms -c -clib=new --constsegBANK_03 bank3.c
zcc +sms -c -clib=new --constsegBANK_04 bank4.c
zcc +sms -c -clib=new --constsegBANK_05 bank5.c
zcc +sms -c -clib=new --constsegBANK_06 bank6.c
zcc +sms -c -clib=sdcc_iy --constsegBANK_07 fixedbank.c

rem Compile game source
zcc +sms  -DUSE_ZCC -c -clib=sdcc_iy main.c
zcc +sms  -DUSE_ZCC -c -clib=sdcc_iy --codesegsmc_user mikgamesstage.c
zcc +sms  -DUSE_ZCC -c -clib=sdcc_iy --codesegsmc_user introstage.c
zcc +sms  -DUSE_ZCC -c -clib=sdcc_iy --codesegsmc_user titlestage.c
zcc +sms  -DUSE_ZCC -c -clib=sdcc_iy --codesegsmc_user jukeboxstage.c
zcc +sms  -DUSE_ZCC -c -clib=sdcc_iy --codesegsmc_user gameoverstage.c
zcc +sms  -DUSE_ZCC -c -clib=sdcc_iy playstage.c
zcc +sms  -DUSE_ZCC -c -clib=sdcc_iy --codesegsmc_user aboutstage.c
zcc +sms  -DUSE_ZCC -c -clib=sdcc_iy stoppedstage.c
zcc +sms  -DUSE_ZCC -c -clib=sdcc_iy functions.c
zcc +sms  -DUSE_ZCC -c -clib=sdcc_iy vars.c
zcc +sms  -DUSE_ZCC -c -clib=sdcc_iy explosion.c
zcc +sms  -DUSE_ZCC -c -clib=sdcc_iy player.c
zcc +sms  -DUSE_ZCC -c -clib=sdcc_iy map.c
zcc +sms  -DUSE_ZCC -c -clib=sdcc_iy barrom.c
zcc +sms  -DUSE_ZCC -c -clib=sdcc_iy enemyslot.c
zcc +sms  -DUSE_ZCC -c -clib=sdcc_iy shoot.c
zcc +sms  -DUSE_ZCC -c -clib=sdcc_iy enemy.c
zcc +sms  -DUSE_ZCC -c -clib=sdcc_iy playershoot.c
zcc +sms  -DUSE_ZCC -c -clib=sdcc_iy enemyshoot.c
zcc +sms  -DUSE_ZCC -c -clib=sdcc_iy goodie.c
zcc +sms  -DUSE_ZCC -c -clib=sdcc_iy platform.c
zcc +sms  -DUSE_ZCC -c -clib=sdcc_iy updatefunctions.c
zcc +sms  -DUSE_ZCC -c -clib=sdcc_iy enemies.c
zcc +sms  -DUSE_ZCC -c -clib=sdcc_iy shop.c
zcc +sms  -DUSE_ZCC -c -clib=sdcc_iy balout.c

rem Link
zcc +sms  -lm -DUSE_ZCC -m -startup=16 -pragma-define:CRT_MODEL=2 -clib=sdcc_iy main.o balout.o player.o platform.o map.o barrom.o shoot.o explosion.o jukeboxstage.o mikgamesstage.o titlestage.o gameoverstage.o playstage.o stoppedstage.o introstage.o functions.o vars.o enemyslot.o enemy.o playershoot.o enemyshoot.o goodie.o updatefunctions.o enemies.o shop.o aboutstage.o bank2.o bank3.o bank4.o bank5.o bank6.o fixedbank.o -o space -pragma-include:zpragma.inc -create-app

rem clear
erase *.bin

rem run
java -jar ..\tools\emulicious\emulicious.jar

