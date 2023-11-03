@echo off

zcc +sms -SO3 --max-allocs-per-node200000 --opt-code-speed -DUSE_ZCC -c -clib=sdcc_iy -SO3 --max-allocs-per-node200 %1.c
