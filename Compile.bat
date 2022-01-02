@echo off
CALL "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
cd %~dp0
REM MSBuild.exe Client/Client.sln /p:Configuration=Release /p:Platform=x86 /maxcpucount
REM MSBuild.exe Server/Server.sln /p:Configuration=Release /p:Platform=x86 /maxcpucount
MSBuild.exe Client/Client.sln /p:Configuration=Release /p:Platform=x64 /maxcpucount
MSBuild.exe Server/Server.sln /p:Configuration=Release /p:Platform=x64 /maxcpucount
pause
