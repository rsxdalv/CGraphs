all:
	echo 'Not implemented yet!'

Dijkstra:
	gcc ./src/Dijkstra.c -o ./build/Dijkstra.exe

Dijkstra.exe:
	./build/Dijkstra.exe

Kruskal:
	gcc ./src/Kruskal.c -o ./build/Kruskal.exe

Kruskal.exe:
	./build/Kruskal.exe

Prim:
	gcc ./src/Prim.c -o ./build/Prim.exe

Prim.exe:
	./build/Prim.exe