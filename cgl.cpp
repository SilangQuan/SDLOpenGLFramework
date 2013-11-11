#include "cgl.h"

CGL::CGL()
{
    //ctor

}

CGL::CGL(int _width, int _height)
{
    this->width = _width;
    this->height = _height;
}

CGL::~CGL()
{
    //dtor
}

bool CGL::initGL()
{
    /* Enable smooth shading */
    glShadeModel( GL_SMOOTH );
    /* Set the background black */
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
    /* Depth buffer setup */
    glClearDepth( 1.0f );
    /* Enables Depth Testing */
    glEnable( GL_DEPTH_TEST );
    /* The Type Of Depth Test To Do */
    glDepthFunc( GL_LEQUAL );
    /* Really Nice Perspective Calculations */
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );

    model = glm::mat4(1.0f);
    view = glm::lookAt(glm::vec3(-2.0f,5.0f,1.0f), glm::vec3(0.0f,1.0f,0.0f), glm::vec3(0.0f,1.0f,0.0f));

    return( true );
}



bool CGL::resizeGL(int width,int height)
{
    if ( height == 0 )
    {
        height = 1;
    }
    //Reset View
    glViewport( 0, 0, (GLint)width, (GLint)height );
    //Choose the Matrix mode
    glMatrixMode( GL_PROJECTION );
    //reset projection
    glLoadIdentity();
    //set perspection
    gluPerspective( 45.0, (GLfloat)width/(GLfloat)height, 0.1, 100.0 );
    //choose Matrix mode
    glMatrixMode( GL_MODELVIEW );
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
}

bool CGL::renderGL()
{
    // These are to calculate our fps
    static GLint T0     = 0;
	static GLint Frames = 0;
    // Clear the color and depth buffers.
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    // We don't want to modify the projection matrix. */
    glMatrixMode( GL_MODELVIEW );

    glLoadIdentity( );
    // Move down the z-axis.
    glTranslatef( 0.0, 0.0, -5.0 );
    //Draw a square
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(-1.0f  , -1.0f  ,  1.0f  );
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f( 1.0f  , -1.0f  ,  1.0f  );
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f( 1.0f  ,  1.0f  ,  1.0f  );
    glColor3f(1.0f,1.0f,0.0f);
    glVertex3f(-1.0f  ,  1.0f  ,  1.0f  );
    glEnd();

   	SDL_GL_SwapBuffers( );

    // Gather our frames per second
    Frames++;
    {
	GLint t = SDL_GetTicks();
	if (t - T0 >= 5000) {
	    GLfloat seconds = (t - T0) / 1000.0;
	    GLfloat fps = Frames / seconds;
	    printf("%d frames in %g seconds = %g FPS\n", Frames, seconds, fps);
	    T0 = t;
	    Frames = 0;
        }
    }
}
