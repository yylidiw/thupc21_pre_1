all : std.exe bf.exe
	
run : gen.py
	python gen.py

std.exe : std.cpp
	g++ std.cpp -O2 -o std.exe -std=c++11 -Wall -Wextra

bf.exe : bf.cpp
	g++ bf.cpp -O2 -o bf.exe -std=c++11 -Wall -Wextra
	
gen.exe : gen.cpp
	g++ gen.cpp -O2 -o gen.exe -std=c++11 -Wall -Wextra
clean :
	del *.exe
