#include <raylib.h> // Include the raylib library header file
#include <iostream>
#include <cmath>

using namespace std;

// Dimensions of the window
const int win_width = 1500;
const int win_height = 900;

int main(){

    InitWindow(win_width, win_height, "Test window"); // Create the window instance
    SetTargetFPS(60); // 60 FPS

    int rope_len = 100;
    int rope_x = win_width/2;
    int rope_y = win_height/4;
    int rope_end_x = rope_x;
    int rope_end_y = rope_len + rope_y;

    int radius = 25;
    int circle_x = (win_width/2)+rope_len;
    int circle_y = rope_y;
    const float mass = 1;
    const float gravity = .0981;
    float force = 0;


    float theta = asin(circle_x/rope_len);

    
    
    // top = 0
    // bottom = win_size - height of object
    while(!WindowShouldClose()){ // While the window remains open

        BeginDrawing();// Being drawing sequence
            ClearBackground(RAYWHITE); // Clear the background
            DrawCircle(circle_x, circle_y, radius, BLUE);
            DrawLine(rope_x, rope_y, rope_end_x, rope_end_y, RED);
        EndDrawing(); // End drawing sequence

        // If the square has reached either side, change direction of increment
        //cout << "limit : " << (win_height - y) << endl;
         if(circle_y < ((rope_y+rope_len) - radius)){
            cout << "circle_y position : " << circle_y << endl;
            force += mass*gravity;
            circle_y += force;
            rope_end_y = circle_y;
            rope_end_x = circle_x;
        }
        if(circle_x < ((rope_x+rope_len) - radius)){
            //cout << "circle_y position : " << circle_y << endl;
            force += mass*gravity;
            circle_x += force;
            rope_end_y = circle_y;
            rope_end_x = circle_x;
        }
        if(circle_y > ((rope_y+rope_len) + radius)){
            circle_y = ((rope_y+rope_len) + radius); 

        }

        if(circle_x > ((rope_x+rope_len) + radius)){
            circle_x = ((rope_x+rope_len) + radius); 

        }

        /*if(circle_x == 0 || circle_x == 550){
            increment *= -1;
        }
        if(circle_y == 0 || circle_y == 550){
            //increment *= -1;
        }
        // Add increment
        circle_x += increment;
        circle_y += increment;*/

    }

    CloseWindow(); // Ensure that the window is closed
    return 0;
}