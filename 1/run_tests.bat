(make || mingw32-make) 2> make_error.txt
(start /B test.exe 1> test.txt 2>&1) || (./test.exe 1> test.txt 2>&1)