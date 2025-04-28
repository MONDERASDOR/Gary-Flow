@echo off
REM Build Gary Flow (C core and Java plugin system) on Windows using MinGW only
if not exist build mkdir build

REM Debug: list all .c files
echo === core ===
dir core\*.c
echo === bridge ===
dir bridge\*.c
echo === protocols ===
dir protocols\*.c

REM Hardcoded list of C source files
set SRC=core\main.c core\session.c core\backend.c core\protocol.c core\event.c bridge\bridge.c protocols\handshake.c

REM Check JAVA_HOME
if not defined JAVA_HOME (
    echo JAVA_HOME is not set. Please set JAVA_HOME to your JDK directory, e.g. C:\Program Files\Java\jdk-17
    exit /b 1
)

set JNI_INCLUDE=-I"%JAVA_HOME%\include" -I"%JAVA_HOME%\include\win32"

REM Add core to the include path for event.h
echo Compiling: %SRC%
gcc %SRC% %JNI_INCLUDE% -Icore -o build\garyflow.exe -lws2_32 -mconsole
if errorlevel 1 exit /b 1

cd java
call mvn package
cd ..
echo Build complete.
