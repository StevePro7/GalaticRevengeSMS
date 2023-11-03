@echo off

rem erase latest rom
erase *.sms

rem Link
zcc +sms -lm -DUSE_ZCC -m -startup=16 -pragma-define:CRT_MODEL=2 -clib=sdcc_iy main.o balout.o player.o platform.o map.o barrom.o shoot.o explosion.o jukeboxstage.o mikgamesstage.o titlestage.o gameoverstage.o playstage.o stoppedstage.o introstage.o functions.o vars.o enemyslot.o enemy.o playershoot.o enemyshoot.o goodie.o updatefunctions.o enemies.o shop.o aboutstage.o bank2.o bank3.o bank4.o bank5.o bank6.o fixedbank.o -o space -pragma-include:zpragma.inc -create-app

rem clear
erase *.bin

rem run
java -jar ..\tools\emulicious\emulicious.jar

