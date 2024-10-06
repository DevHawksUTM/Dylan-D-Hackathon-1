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

    float rope_len = 250;
    float rope_x = win_width/2;
    float rope_y = win_height/4;
    float rope_end_x = rope_x;
    float rope_end_y = rope_len + rope_y;

    float radius = 25;
    float circle_x = (win_width/2)+rope_len;
    float circle_y = rope_y;
    const float mass = .1;
    const float gravity = .981;
    float force = mass * gravity;
    float energy = 5;
    float damp = .9870;
    int cycle = 0;
    int reducer = 0;
    int direction = 1;
    float thetaD = 0;
    float thetaR = thetaD * M_PI /180.0;
    float period = 2* M_PI * sqrt(rope_len/9.81);
    //float damp = -(force/rope_len) * thetaD;
    // top = 0
    // bottom = win_size - height of object
    while(!WindowShouldClose()){ // While the window remains open

        BeginDrawing();// Being drawing sequence
            ClearBackground(RAYWHITE); // Clear the background
            DrawCircle(rope_end_x, rope_end_y, radius, BLUE);
            DrawLine(rope_x, rope_y, rope_end_x, rope_end_y, RED);
            
        EndDrawing(); // End drawing sequence

        
        // If the square has reached either side, change direction of increment
        //cout << "limit : " << (win_height - y) << endl;
       //  if(circle_y < ((rope_y+rope_len) - radius)){
        if(thetaD > 90-reducer || thetaD < -90-reducer){
            direction *= -1;
            cycle++;
            if(cycle == 2){
                reducer += 1;
                cycle = 0;
            }
        }
        if (true == true){
        thetaD += (energy * direction);
        thetaR = thetaD * M_PI /180.0;
        rope_end_x = (rope_len*(sin(thetaR))+ rope_x);
        rope_end_y = (rope_len*(cos(thetaR))+ rope_y);
        energy *= damp;
        }
       /*
        if(true == true){
            rope_end_x += (rope_len*(sin(thetaR))+ rope_x);
            rope_end_y += (rope_len*(cos(thetaR))+ rope_y);
            cout << "X pos: " << rope_end_x << " Y pos: " << rope_end_y << endl; 
            thetaR += force;
            //force *= damp;
            //thetaD *= -(.981/rope_len)*sin(thetaR);
            //thetaR = (thetaD * (M_PI /180.0));
        }
        */


            //thetaD += period;
            //cout << "circle_y position : " << circle_y << endl;
            //force += mass*gravity;
            //circle_y += force;
            //rope_end_y = circle_y;
            //rope_end_x = circle_x;
        
        //if(circle_x < ((rope_x+rope_len) - radius)){
            //cout << "circle_y position : " << circle_y << endl;
            //force += mass*gravity;
            //circle_x += force;
            //rope_end_y = circle_y;
            //rope_end_x = circle_x;
        //}
        //if(circle_y > ((rope_y+rope_len) + radius)){
            //circle_y = ((rope_y+rope_len) + radius); 

        //}

        //if(circle_x > ((rope_x+rope_len) + radius)){
            //circle_x = ((rope_x+rope_len) + radius); 

        //}



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