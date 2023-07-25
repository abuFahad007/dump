#include <raylib.h>
#include <stdbool.h>
#include <stdio.h>

int main() {

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(170, 3, "Ultimatum");

    SetTargetFPS(60);

    //states
    char text[15] = "9: 99 : 99";
    int seconds = 0;
    int minutes = 0;
    int hours   = 0;
    int stop_time = 0;
    int coeff   = 0;
    bool stop   = true;

    while (!WindowShouldClose()) {

        if(!stop) 
            seconds = GetTime() - coeff - stop_time;

        if(stop && seconds >= 0)
            stop_time = GetTime()-seconds-coeff;

        if(seconds > 59) {
            seconds = 0;
            coeff = GetTime();
            stop_time = 0;
            minutes += 1;
        }

        if(minutes > 59) {
            minutes = 0;
            hours += 1;
        }

        if(IsMouseButtonPressed(0)) {
            Vector2 mouse = GetMousePosition();
            if ((mouse.x >= 107 && mouse.x <= 127) && (mouse.y >= 1 && mouse.y <= 21)) {
                seconds = 0;
                minutes = 0;
                hours = 0;
                coeff = GetTime();
                stop_time = 0;
            }

            if ((mouse.x >= 139 && mouse.x <= 159) && (mouse.y >= 1 && mouse.y <= 21)) {
                if(!stop) {
                    stop = true;
                }
                else {
                    stop = false;
                }

            }
        }

        BeginDrawing();
            ClearBackground(BLACK);
            sprintf(text, "%d : %d : %d", hours,minutes,seconds);
            DrawText(text,3,3,20,LIGHTGRAY);
            DrawRectangle(107, 1, 20,20,GREEN);
            DrawRectangle(139, 1, 20,20,RED);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}

