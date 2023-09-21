#include "wtypes.h"
#include <iostream>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include "resolution.hpp"
using namespace std;

GL_Resolution::GL_Resolution(){
   GetDesktopResolution(displayHorizontal, displayVertical);
   windowHorizontal = 800;
   windowVertical = 600;
}

// Get the horizontal and vertical screen sizes in pixel
void GL_Resolution::GetDesktopResolution(int& horizontal, int& vertical)
{
   RECT desktop;
   const HWND hDesktop = GetDesktopWindow();
   GetWindowRect(hDesktop, &desktop);
   // The top left corner will have coordinates (0,0)
   // and the bottom right corner will have coordinates
   horizontal = desktop.right;
   vertical = desktop.bottom;
}

//Find window Resolution for Current Display
void GL_Resolution::AutomateWindowResolution(){
   //Later
}

glm::vec2 GL_Resolution::GetDisplayResolution(){
   return glm::vec2(displayHorizontal, displayVertical);
}

glm::vec2 GL_Resolution::GetWindowResolution(){
   return glm::vec2(windowHorizontal, windowVertical);
}

void GL_Resolution::SetWindowResolution(int h, int v){
   windowHorizontal = h; windowVertical = v;
}

void GL_Resolution::UpdateWindowResolution(){
   glutReshapeWindow(windowHorizontal, windowVertical);
}