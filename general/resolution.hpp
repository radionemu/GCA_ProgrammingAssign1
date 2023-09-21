#ifndef RESOLUTION_HPP
#define RESOLUTION_HPP

#include<iostream>
#include<glm/glm.hpp>

class GL_Resolution{
    private:
        int displayHorizontal;
        int displayVertical;
        int windowHorizontal;
        int windowVertical;

        void GetDesktopResolution(int& horizontal, int& vertical);
        GL_Resolution();
        GL_Resolution(int h, int v) : windowHorizontal(h), windowVertical(v){};//needs?
    public:
        static GL_Resolution &getResInstance(){
            static GL_Resolution rinstance;
            return rinstance;
        };
        glm::vec2 GetDisplayResolution();
        glm::vec2 GetWindowResolution();
        void SetWindowResolution(int height, int vertical);
        void UpdateWindowResolution();
        void AutomateWindowResolution();
};


#endif