#include "raylib.h"

int main() {
    InitWindow(800, 600, "Battle of Legends: Rock vs Paper vs Scissors");
    SetTargetFPS(60);

    Rectangle rockBtn = { 100, 350, 150, 80 };
    Rectangle paperBtn = { 325, 350, 150, 80 };
    Rectangle scissorsBtn = { 550, 350, 150, 80 };
    int playerChoice = -1;
    int computerChoice = -1;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BEIGE);

        DrawText("Choose your weapon, hero!", 200, 50, 30, DARKBLUE);

        // Buttons
        DrawRectangleRounded(rockBtn, 0.3f, 10, (playerChoice == -1) ? DARKGRAY : GRAY);
        DrawRectangleRounded(paperBtn, 0.3f, 10, (playerChoice == -1) ? DARKGRAY : GRAY);
        DrawRectangleRounded(scissorsBtn, 0.3f, 10, (playerChoice == -1) ? DARKGRAY : GRAY);
        DrawText("ROCK", 130, 375, 20, BLACK);
        DrawText("PAPER", 355, 375, 20, BLACK);
        DrawText("SCISSORS", 565, 375, 20, BLACK);

        // Player input
        if (playerChoice == -1 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mouse = GetMousePosition();
            if (CheckCollisionPointRec(mouse, rockBtn)) playerChoice = 0;
            else if (CheckCollisionPointRec(mouse, paperBtn)) playerChoice = 1;
            else if (CheckCollisionPointRec(mouse, scissorsBtn)) playerChoice = 2;

            if (playerChoice != -1)
                computerChoice = GetRandomValue(0, 2);
        }

        // Results
        if (playerChoice != -1) {
            const char* choices[3] = { "ROCK", "PAPER", "SCISSORS" };
            DrawText(TextFormat("You chose: %s", choices[playerChoice]), 100, 150, 28, DARKGREEN);
            DrawText(TextFormat("Computer chose: %s", choices[computerChoice]), 400, 150, 28, MAROON);

            if (playerChoice == computerChoice) {
                DrawText("It's a draw!", 300, 100, 30, BLUE);
            }
            else if ((playerChoice == 0 && computerChoice == 2) ||
                (playerChoice == 1 && computerChoice == 0) ||
                (playerChoice == 2 && computerChoice == 1)) {
                DrawText("You win!", 320, 100, 30, GREEN);
            }
            else {
                DrawText("You lose!", 320, 100, 30, RED);
            }

            // Restart button
            Rectangle restartBtn = { 300, 470, 200, 50 };
            DrawRectangleRounded(restartBtn, 0.3f, 10, ORANGE);
            DrawText("Play Again", 330, 485, 20, BLACK);

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                Vector2 mouse = GetMousePosition();
                if (CheckCollisionPointRec(mouse, restartBtn)) {
                    playerChoice = -1;
                    computerChoice = -1;
                }
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
