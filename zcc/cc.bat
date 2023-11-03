@echo off

zcc +sms --opt-code-size -DUSE_ZCC -c -clib=sdcc_iy -SO3 --max-allocs-per-node200 %1.c
