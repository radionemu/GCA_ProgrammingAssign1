#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL/freeglut.h>

#include <stdio.h>

#include "resolution.hpp"
#include "MVP.hpp"

//provide result MVP matrix
GL_Resolution gl_resolution = GL_Resolution::getResInstance();

//for Camera Control
//glm::mat4 transformCam = glm::mat4(1.0);
//glm::vec3 Viewposition = glm::vec3(0,0,5);
//float ViewAngleH = 3.14f;
//float ViewAngleV = 0;

//Proejction Setting
//float initialFoV = 45.0f;

GL_MVP::GL_MVP(){
    UpdateModel();
    UpdateView();
    UpdateProjection(FoV,Fnear,Ffar);
    UpdateMVP();
}

glm::mat4 GL_MVP::getViewMatrix(){
    return View;
}

glm::mat4 GL_MVP::getProjectionMatrix(){
    return Projection;
}

//must update MVP before call this function if you want most recent matrix
glm::mat4 GL_MVP::getMVP(){
    return MVP;
}

void GL_MVP::UpdateMVP(){
    MVP = Projection * View * Model;
}

//you cannot change ratio
void GL_MVP::UpdateProjection(float iFoV, float inear, float ifar){
    glm::vec2 windowRes = gl_resolution.GetWindowResolution();
    Projection = glm::perspective(glm::radians(iFoV), windowRes.x/windowRes.y, inear, ifar);
}

void GL_MVP::UpdateView()
{
    View = VTransform * VRotation;
}

void GL_MVP::TranslateView(glm::vec3 pos)
{
    VTransform = glm::translate(VTransform, pos);
    UpdateView();
}

void GL_MVP::RotateView(glm::vec3 rot)
{
    VRotation = glm::lookAt(
        glm::vec3(1.5,1.5,1.5), // Camera is at (4,3,3), in World Space
        glm::vec3(0,1,0), // and looks at the origin
        glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
    );
    UpdateView();
    //Later
}

void GL_MVP::UpdateModel()
{
    Model = Mtranform * Mrotation * Mscale;
}

void GL_MVP::TranslateModel(glm::vec3 mpos)
{
    Mtranform = glm::translate(Mtranform, mpos);
}

void GL_MVP::RotateModel(glm::vec3 mrot)
{
    //Mrotation = glm::rotate(Mrotation, mrot);
}

void GL_MVP::ScaleModel(glm::vec3 mscl)
{
    Mscale = glm::scale(Mscale, mscl);
}
