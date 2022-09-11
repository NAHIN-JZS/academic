#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>

double Txval=0,Tyval=0,Tzval=0;
double windowHeight=700, windowWidth=700;
GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0;
GLboolean bRotate = false, uRotate = false;

static GLfloat v_quad_strip[8][3] =
{
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 5.0},
    {5.0, 0.0, 5.0},
    {5.0, 0.0, 0.0},
    {0.0, 5.0, 0.0},
    {0.0, 5.0, 5.0},
    {5.0, 5.0, 5.0},
    {5.0, 5.0, 0.0}

    /*{0.0, 0.0, 0.0},
    {0.0, 0.0, 2.0},
    {2.0, 0.0, 2.0},
    {2.0, 0.0, 0.0},
    {1.0, 4.0, 1.0}*/
};

static GLubyte qs_Indices[6][4] =
{

    {0, 1 ,2, 3},
    {2, 3, 7, 6},
    {4, 5, 6, 7},
    {0, 3, 7, 4},
    {1, 0, 4, 5},
    {1, 2, 6, 5}


    /*{4, 1, 2},
    {4, 2, 3},
    {4, 3, 0},
    {4, 0, 1}

    {1,5,2,6,3,7,0,4},
    {6,7,5,4,1,0,2,3}*/

};

/*static GLubyte quadIndices[1][4] =
{
    {0, 3, 2, 1}
};

static GLfloat colors[6][3] =
{
    {0.0, 0.0, 1.0},
    {0.5, 0.0, 1.0},
    {0.0, 1.0, 0.0},
    {0.0, 1.0, 1.0},
    {0.8, 1.0, 1.0},
    {0.8, 0.0, 0.0}
};*/

void drawcube(float r, float g, float b)
{
    glColor3f(1,0,0);
    //glBegin(GL_TRIANGLES);
    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {
//        glColor3f(colors[i][0],colors[i][1],colors[i][2]);
        glColor3f(r,g,b);
        glVertex3fv(&v_quad_strip[qs_Indices[i][0]][0]);
        glVertex3fv(&v_quad_strip[qs_Indices[i][1]][0]);
        glVertex3fv(&v_quad_strip[qs_Indices[i][2]][0]);
        glVertex3fv(&v_quad_strip[qs_Indices[i][3]][0]);
//        glVertex3fv(&v_quad_strip[qs_Indices[i][4]][0]);
//        glVertex3fv(&v_quad_strip[qs_Indices[i][5]][0]);
//        glVertex3fv(&v_quad_strip[qs_Indices[i][6]][0]);
//        glVertex3fv(&v_quad_strip[qs_Indices[i][7]][0]);
    }
    glEnd();


}


void display(void)
{


    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glFrustum(-5,5, -5, 5, 4, 50);
     //gluPerspective(60,1,5,100);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(2,3,8, 2,0,0, 0,1,0); // camera , ,

    glViewport(0, 0, windowHeight, windowWidth);



     float redish[] = {0.5020, 0.0000, 0.0000};
     float deep_ash[] = {0.4392, 0.5020, 0.5647};
     float blue[] = {0.0,0.0,1.0};
      float white[] = {1.0,1.0,1.0};
      float ash[] = {0.6627, 0.6627, 0.6627};
      float green[] = {0.0,1.0,0.0};
     float red[] = {1.0,0.0000, 0.0000};
     float brown[] = {0.5451, 0.2706, 0.0745};


//    glRotatef(-10, 0, 0, 1 );
//    glTranslatef(-5,-5,0);
//     glScalef(.5,0,-.5);
//
//
//     glRotatef( alpha,axis_x, axis_y, 0.0 );
//     glRotatef( theta, axis_x, axis_y, 0.0 );
//     drawcube();



    //front-upper bed leg

//    glPushMatrix();
     glRotatef(-10, 0, 0, 1 );
    glTranslatef(-5,-5,0);
     glScalef(0.1,1,.1);
     glRotatef( alpha,axis_x, axis_y, 0.0 );
     glRotatef( theta, axis_x, axis_y, 0.0 );
//     GLfloat color[1][3] = {1,0,0};

      drawcube(redish[0],redish[1],redish[2]);
//     glPopMatrix();

//    glRotatef(-10, 0, 0, 1 );

//floor
    glPushMatrix();
    glTranslatef(0,0,5);
     glScalef(40,0,-30);

      drawcube(deep_ash[0],deep_ash[1],deep_ash[2]);
     glPopMatrix();

     //left wall
    glPushMatrix();
    glTranslatef(-0.5,0,5);
     glScalef(0,2,-30);

      drawcube(blue[0],blue[1],blue[2]);
     glPopMatrix();

     //front wall
    glPushMatrix();
    glTranslatef(-0.5,0,-130);
     glScalef(40,2,0);
//     float color[] = {128.0,0.0,0.0};

      drawcube(blue[0],blue[1],blue[2]);
     glPopMatrix();



    //front bed side
     glPushMatrix();
       glTranslatef(5,2,0);
     glScalef(20,0.2,1);
//      float color[] = {128.0,0.0,0.0};

      drawcube(redish[0],redish[1],redish[2]);
      glPopMatrix();



      glPushMatrix();
      //front-bottom bed leg
      glTranslatef(100,0,0);
//      float color[] = {128.0,0.0,0.0};

      drawcube(redish[0],redish[1],redish[2]);

        //bottom bed side
      glTranslatef(0,2,0);
      glScalef(1,0.4,-10);
//      float color[] = {128.0,0.0,0.0};

      drawcube(redish[0],redish[1],redish[2]);
      glPopMatrix();



      glPushMatrix();
      //back-bottom bed leg
      glTranslatef(100,0,-50);
//      float color[] = {128.0,0.0,0.0};

      drawcube(redish[0],redish[1],redish[2]);

        //back bed side
      glTranslatef(5,2,0);
     glScalef(-20,0.2,1);

//      float color[] = {128.0,0.0,0.0};

      drawcube(redish[0],redish[1],redish[2]);

      glPopMatrix();

      glPushMatrix();
      //back upper leg
      glTranslatef(0,0,-50);

//      float color[] = {128.0,0.0,0.0};

      drawcube(redish[0],redish[1],redish[2]);

        //upper bed side
      glTranslatef(0,2,0);
      glScalef(1,0.5,10.5);

//      float color[] = {128.0,0.0,0.0};

      drawcube(redish[0],redish[1],redish[2]);

      glPopMatrix();

        //bedsheet
      glPushMatrix();
      glTranslatef(5,3,5.3);
      glScaled(19,.1,-11);

      drawcube(white[0],white[1],white[2]);
      glPopMatrix();

      //pillow
      glPushMatrix();
      glTranslatef(3,3.5,-1.5);
      glScaled(5,.1,-8);


      drawcube(ash[0],ash[1],ash[2]);
      glPopMatrix();

      //katha
      glPushMatrix();
      glTranslatef(50,3,7.0);
      glScaled(10,.15,-11.5);


      drawcube(green[0],green[1],green[2]);
      glPopMatrix();

//      glPushMatrix();
//      glTranslatef(0,0,0);
//      glScalef

    //almari
    glPushMatrix();
    glTranslatef(10,0,-120);
     glScalef(17,1.7,1.0);

      drawcube(red[0],red[1],red[2]);
     glPopMatrix();

     glPushMatrix();
    glTranslatef(14,0.9,-119.5);
     glScalef(7.3,1.4,1.0);
//     float red[] = {1.0,0.0000, 0.0000};

      drawcube(brown[0],brown[1],brown[2]);
     glPopMatrix();

     glPushMatrix();
    glTranslatef(55,0.9,-119.5);
     glScalef(7.3,1.4,1.0);
//     float red[] = {1.0,0.0000, 0.0000};

      drawcube(brown[0],brown[1],brown[2]);
     glPopMatrix();

     glPushMatrix();
    glTranslatef(37,4,-114.5);
     glScalef(.5,.3,.1);
//     float red[] = {1.0,0.0000, 0.0000};

      drawcube(white[0],white[1],white[2]);
     glPopMatrix();

     glPushMatrix();
    glTranslatef(68,4,-114.5);
     glScalef(.5,.3,.1);
//     float red[] = {1.0,0.0000, 0.0000};

      drawcube(white[0],white[1],white[2]);
     glPopMatrix();


     //table
        glPushMatrix();
     glTranslatef(170,0,3);
     glScalef(0.6,0.9,.4);
     drawcube(brown[0],brown[1],brown[2]);
     glPopMatrix();

     glPushMatrix();
     glTranslatef(195,0,3);
     glScalef(0.6,0.9,.4);
     drawcube(brown[0],brown[1],brown[2]);
     glPopMatrix();

     glPushMatrix();
     glTranslatef(170,0,-50);
     glScalef(0.6,0.9,.4);
     drawcube(brown[0],brown[1],brown[2]);
     glPopMatrix();

     glPushMatrix();
     glTranslatef(195,0,-50);
     glScalef(0.6,0.9,.4);
     drawcube(brown[0],brown[1],brown[2]);
     glPopMatrix();

     glPushMatrix();
     glTranslatef(170,4,5);
     glScalef(6,.1,-11.5);
     drawcube(brown[0],brown[1],brown[2]);
     glPopMatrix();

    glFlush();
    glutSwapBuffers();
}


void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case 's':
    case 'S':
        bRotate = !bRotate;
        uRotate = false;
        axis_x=0.0;
        axis_y=1.0;
        break;

    case 'r':
    case 'R':
        uRotate = !uRotate;
        bRotate = false;
        axis_x=1.0;
        axis_y=0.0;
        break;
    case '+':
        Tzval+=0.2;
        break;

    case '-':
        Tzval-=0.2;
        break;

    case 27:	// Escape key
        exit(1);
    }
}



void animate()
{
    if (bRotate == true)
    {
        theta += 0.1;
        if(theta > 360.0)
            theta -= 360.0*floor(theta/360.0);
    }

    if (uRotate == true)
    {
        alpha += 0.1;
        if(alpha > 360.0)
            alpha -= 360.0*floor(alpha/360.0);
    }
    glutPostRedisplay();

}


int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(windowHeight, windowWidth);
    glutCreateWindow("Traingle-Demo");
    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutMainLoop();

    return 0;
}

