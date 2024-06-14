#include <raylib.h>
#include <iostream>


#define WindowWidth 900
#define WindowHeight 900
#define SizeBoard 3
#define BgColor LIGHTGRAY
const int Thickness = ((WindowWidth+WindowHeight)/2)*0.02;
void CreateZero(int x, int y, int thickness , Color color){
	DrawCircle( x, y , (WindowWidth/2)/SizeBoard-Thickness, color);
	DrawCircle(x, y , (WindowWidth/2)/SizeBoard-Thickness*2, BgColor);  
	
}
void CreateX(int x , int y, int thickness, Color color){
	Vector2 firstStart={x-WindowWidth/SizeBoard/2+thickness, y-WindowWidth/SizeBoard/2+thickness};
	Vector2 firstEnd={x+WindowWidth/SizeBoard/2-thickness, y+WindowWidth/SizeBoard/2-thickness};
	DrawSplineSegmentLinear(firstStart, firstEnd, thickness, color);

	Vector2 secondStart={x-WindowWidth/SizeBoard/2+thickness, y+WindowWidth/SizeBoard/2-thickness };
	Vector2 secondEnd={x+WindowWidth/SizeBoard/2-thickness, y-WindowWidth/SizeBoard/2+thickness};
	DrawSplineSegmentLinear(secondStart, secondEnd, thickness, color);	
}
void PlayerMove(bool& XToMove, int table[][SizeBoard]){
	int MouseX =GetMouseX();
    int MouseY =GetMouseY(); 
	int CellX= WindowWidth/SizeBoard/MouseX;
	int CellY= WindowHeight/SizeBoard/MouseY;
	//int x = (CellX* (WindowWidth/SizeBoard))- (WindowWidth/SizeBoard/2);
	//int y =(CellY* (WindowHeight/SizeBoard))- (WindowHeight/SizeBoard/2);
	if(XToMove){
		table[CellX-1][CellY-1]=1;
	}else{
		table[CellX-1][CellY-1]=2;
	}
	XToMove!=XToMove;
	
}
void ShowTable(int table[SizeBoard][SizeBoard]){
	for(int i=0;i<SizeBoard;i++){
		for(int j=0;j<SizeBoard;j++){
			if(table[i][j]==1){
				CreateX(i+1*(WindowWidth/SizeBoard)-(WindowWidth/SizeBoard/2), j+1*(WindowHeight/SizeBoard)-(WindowHeight/SizeBoard/2), Thickness, RED);
				std::cout<<i+1*(WindowWidth/SizeBoard)-(WindowWidth/SizeBoard/2)<<std::endl<<j+1*(WindowHeight/SizeBoard)-(WindowHeight/SizeBoard/2)<<std::endl;
			}else if(table[i][j]==2){
				CreateZero(i+1*(WindowWidth/SizeBoard)-(WindowWidth/SizeBoard/2), j+1*(WindowHeight/SizeBoard)-(WindowHeight/SizeBoard/2), Thickness, BLUE);
			}
		}
	}
}

int main() {
	InitWindow(WindowWidth, WindowHeight, "TicTacToe");
	SetTargetFPS(60);
	bool XToMove=true;
	int table[SizeBoard][SizeBoard];
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
		if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT ))PlayerMove(XToMove, table);
		ShowTable(table);
		EndDrawing();
	}
	CloseWindow();

	return 0;
}

