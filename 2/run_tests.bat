(mingw32-make || make) 2> make_error.txt
(start /B main.exe 1> tests_output.txt 2>&1) || (./main.exe 1> tests_output.txt 2>&1)