#ifndef MVP_HPP
#define MVP_HPP

#include<glm/glm.hpp>

class GL_MVP{
private:
    //For Models
    glm::mat4 Mscale = glm::mat4(1.0f);
    glm::mat4 Mrotation = glm::mat4(1.0f);
    glm::mat4 Mtranform = glm::mat4(1.0f);
    //For Views
    glm::mat4 VRotation = glm::mat4(1.0f);
    glm::mat4 VTransform = glm::mat4(1.0f);
    //For Projections
    float FoV = 45.0f; //based on degree
    float Fnear = 0.1f;
    float Ffar = 100.0f;
    //final matrices
    glm::mat4 Model = glm::mat4(1.0f);
    glm::mat4 View = glm::mat4(1.0f);
    glm::mat4 Projection = glm::mat4(1.0f);
    glm::mat4 MVP = glm::mat4(1.0f);
public:
    GL_MVP();

    glm::mat4 getModelMatrix();
    glm::mat4 getViewMatrix();
    glm::mat4 getProjectionMatrix();
    glm::mat4 getMVP();

    void UpdateMVP();
    
    void UpdateProjection(float iFoV, float near, float far);
        void UpdateProjection(float iFoV){UpdateProjection(iFoV, Fnear, Ffar);}
        void UpdateProjection(float inear, float ifar){UpdateProjection(FoV, inear, ifar);}
    
    void UpdateView();
        void TranslateView(glm::vec3 pos);
        void RotateView(glm::vec3 rot);
    void UpdateModel();
        void TranslateModel(glm::vec3 mpos);
        void RotateModel(glm::vec3 mrot);
        void ScaleModel(glm::vec3 mscl);


    glm::mat4 getTranslateCam();
    void ClickCamera(int button, int state, int x, int y);
    void TranslateCamera(int x, int y);
};



#endif