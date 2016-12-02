all:
	echo 'Not implemented yet!'

path:
	gcc ./src/path.c -o ./build/path.exe

path.exe:
	./build/path.exe

krask:
	g++ ./src/Krask.cpp -o ./build/krask.exe

krask.exe:
	./build/krask.exe