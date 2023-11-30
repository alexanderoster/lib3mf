@echo off

set base_path=%~dp0
echo %base_path%
cd %base_path%

if not exist "..\Libraries\" (mkdir "..\Libraries")


REM updating the cpp-base64 library
set lib_name="cpp-base64"
set lib_path_src="%base_path%%lib_name%\"

cd %lib_name%
set "tag="
for /f %%i in ('git describe --contains HEAD') do set "tag=%%i"

cd %base_path%
REM delete the destination library folder when updating
RD /S /Q "..\Libraries\%lib_name%"
set lib_path_dest="..\Libraries\%lib_name%\"
mkdir %lib_path_dest%

mkdir "%lib_path_dest%Include"
mkdir "%lib_path_dest%Source"
copy %lib_path_src%base*.h "%lib_path_dest%Include" /Y
copy  %lib_path_src%base*.cpp "%lib_path_dest%Source" /Y

echo %tag% >"%lib_path_dest%%lib_name%_%tag%.txt"



REM updating the zlib library
set lib_name="zlib"
set lib_path_src="%base_path%%lib_name%\"

cd %lib_name%
set "tag="
for /f %%i in ('git describe --contains HEAD') do set "tag=%%i"

cd %base_path%
REM delete the destination library folder when updating
RD /S /Q "..\Libraries\%lib_name%"
set lib_path_dest="..\Libraries\%lib_name%\"
mkdir %lib_path_dest%

mkdir "%lib_path_dest%Include"
mkdir "%lib_path_dest%Source"
copy %lib_path_src%*.h "%lib_path_dest%Include" /Y
copy  %lib_path_src%*.c "%lib_path_dest%Source" /Y

echo %tag% >"%lib_path_dest%%lib_name%_%tag%.txt"


REM updating the libzip library
set lib_name=libzip
set lib_path_src=%base_path%%lib_name%\
cd %lib_name%
set "tag="
for /f %%i in ('git describe --contains HEAD') do set "tag=%%i"

cd %base_path%
REM delete the destination library folder when updating
RD /S /Q "..\Libraries\%lib_name%"
set lib_path_dest=..\Libraries\%lib_name%\
mkdir %lib_path_dest%

mkdir "%lib_path_dest%Include"
mkdir "%lib_path_dest%Source"
REM when copying files for libzip exclude external lib files aes, crypto, xz, zstd, bzip2 
robocopy *.h %lib_path_src%lib\ "%lib_path_dest%Include" /XF *crypto*
robocopy *.c %lib_path_src%lib\ "%lib_path_dest%Source" /XF *crypto* *aes* *bzip2* *xz* *zstd* *win32* *unix* *stdio_named* *uwp*

REM copy windows specific files to win and unix specific files to unix folders
mkdir "%lib_path_dest%Source\win"
mkdir "%lib_path_dest%Source\unix"
robocopy *win32*.c %lib_path_src%lib\ "%lib_path_dest%Source\win"
robocopy *unix*.c *stdio_named*.c  %lib_path_src%lib\ "%lib_path_dest%Source\unix"

cd %lib_name%
mkdir build
cd build
cmake .. -DZLIB_INCLUDE_DIR="../../zlib" -DZLIB_LIBRARY=zlibstatic -DENABLE_COMMONCRYPTO=OFF -DENABLE_GNUTLS=OFF -DENABLE_MBEDTLS=OFF -DENABLE_OPENSSL=OFF -DENABLE_WINDOWS_CRYPTO=OFF

cd ..
robocopy *.h %lib_path_src%build ..\%lib_path_dest%Include
RD /S /Q build
cd %base_path%

REM generate autogenerated file using cmake script run
cd %lib_path_dest%Source\
cmake -DPROJECT_SOURCE_DIR=%lib_path_src% -P %lib_path_src%cmake\GenerateZipErrorStrings.cmake
cd %base_path%
echo %tag% >"%lib_path_dest%%lib_name%_%tag%.txt"


REM updating the googletest library
set lib_name=googletest
set lib_path_src=%base_path%%lib_name%\googletest\
cd %lib_name%
set "tag="
for /f %%i in ('git describe --contains HEAD') do set "tag=%%i"

cd %base_path%
REM delete the destination library folder when updating
RD /S /Q "..\Libraries\%lib_name%"
set lib_path_dest=..\Libraries\%lib_name%\
mkdir %lib_path_dest%

mkdir "%lib_path_dest%Include"
mkdir "%lib_path_dest%Source"
REM when copying files for libzip exclude external lib files aes, crypto, xz, zstd, bzip2 
robocopy *.h %lib_path_src%include\gtest\ "%lib_path_dest%Include\gtest" /E
robocopy *.h %lib_path_src%src\ "%lib_path_dest%Include\src"
robocopy *.cc %lib_path_src%src\ "%lib_path_dest%Source" /XF *main* *all*

echo %tag% >"%lib_path_dest%%lib_name%_%tag%.txt"