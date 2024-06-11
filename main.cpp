#include <raylib.h>


#define WindowWidth 900
#define WindowHeight 900
#define SizeBoard 3
#define BgColor LIGHTGRAY
const int Thickness = ((WindowWidth+WindowHeight)/2)*0.02;
void CreateZero(int x, int y, int thickness , Color color){
	DrawCircle( x, y , (WindowWidth/2)/SizeBoard-Thickness, color);
	DrawCircle(x, y , (WindowWidth/2)/SizeBoard-Thickness*2, BgColor);  
	
}


int main() {
	InitWindow(WindowWidth, WindowHeight, "File Manager");
	SetTargetFPS(60);
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BgColor);
		int cell_width = WindowWidth / SizeBoard;
		int cell_height = WindowHeight / SizeBoard;

		for (int i = 1; i < SizeBoard; i++){
			Vector2 start= {0, i * cell_height};
			Vector2 end={WindowWidth, i*cell_height};
        		DrawLineBezier(start, end, Thickness, BLACK);
		}
		for (int i = 1; i < SizeBoard; i++){
			Vector2 start= { i * cell_width, 0};
			Vector2 end={ i*cell_width, WindowHeight};
        		DrawLineBezier(start, end, Thickness,  BLACK);
		}
		CreateZero(450, 450, 20, RED);
		EndDrawing();
	}
	CloseWindow();

	return 0;
}

