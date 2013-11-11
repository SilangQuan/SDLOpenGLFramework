#include <iostream>
#include "csdl.h"
#include "cgl.h"

using namespace std;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT =600;
const int SCREEN_BPP = 32;
int main()
{
    CGL *gl = new CGL(SCREEN_WIDTH, SCREEN_HEIGHT);
    gl->initGL();

	int flags= SDL_OPENGL|SDL_RESIZABLE;
    CSDL *sdl = new CSDL(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP,flags, gl);
    sdl->setCaption("Basic Shading");

    while(true)
    {
        sdl->handleEvent(gl);
        gl->renderGL();
    }
    return 0;
}
