#ifndef CGL_H
#define CGL_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <iostream>
class CGL
{
    public:
        CGL();
        CGL(int _width, int _height);
        virtual ~CGL();
        bool initGL();
        bool resizeGL(int width,int height);
        bool renderGL();
    protected:
    private:
        int width;
        int height;
        glm::mat4 model;
        glm::mat4 view;
        GLuint VertexArrayID;
        GLuint vertexbuffer;
};

#endif // CGL_H
