gamemake: map.c game.c
	gcc objectread.c -o objectread.exe
	objectread
	gcc vertices.c -o vertices.exe
	vertices
	gcc ground.c map.c game.c -Ic:/users/anson/include -Lc:/users/anson/lib -lglfw3 -lfreeglut -lopengl32 -lglu32 -lgdi32 -static-libgcc -static -o c:/users/anson/desktop/game.exe