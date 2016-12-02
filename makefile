all:
	echo 'Not implemented yet!'

path:
	gcc ./src/path.c -o ./build/path.exe

path.exe:
	./build/path.exe

krask:
	gcc ./src/Krask.c -o ./build/krask.exe

krask.exe:
	./build/krask.exe