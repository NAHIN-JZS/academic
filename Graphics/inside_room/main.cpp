#include <bits/stdc++.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>

#define PI 3.1416

using namespace std;

double Txval=0,Tyval=0,Tzval=0;
double windowHeight=1000, windowWidth=1000;
//GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0, lpan = 0.0, rpan = 0.0, fdist=0.0,yaw = 0.0, dx = 0.0,dy = 0.0,dz = 0.0,roll=0.0,pitch = 0.0,cdist = 0.0,xaxis = 0.0, yaxis=1.0,zaxis=0.0;
GLfloat alpha = 0.0, theta = 0.0,bita = 0.0, axis_x=0.0, axis_y=0.0;
GLfloat up_x = 0,up_y = 1,up_z = 0;
GLboolean bRotate = false, uRotate = false;

GLfloat theta_pakha =0;
//
GLfloat eyeX =0;// 2;
GLfloat eyeY =0;// 3;
GLfloat eyeZ = 10;

GLfloat nearP = 4, farP = 300;

GLfloat lookX = 0;
GLfloat lookY = 0;
GLfloat lookZ = 0;

bool ambient0 = true, diffuse0 = true, specular0 = true;
bool ambient1 = true, diffuse1 = true, specular1 = true;

float redish[] = {0.5020, 0.0000, 0.0000};
float deep_ash[] = {0.4392, 0.5020, 0.5647};
float blue[] = {0.0,0.0,1.0};
float white[] = {1.0,1.0,1.0};
float ash[] = {0.6627, 0.6627, 0.6627};
float green[] = {0.0,1.0,0.0};
float red[] = {1.0,0.0000, 0.0000};
float brown[] = {0.5451, 0.2706, 0.0745};
float black[] = {0.0, 0.0, 0.0};

//GLfloat alpha = 0.0, theta = 0.0, beta= 0.0, axis_x=0.0, axis_y=0.0, axis_z = 0.0, eyeX = 2.0, eyeY = 3.0, eyeZ = 10.0, roll = 0.0, pitch = 0.0, yaw = 0.0;

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

static GLubyte qs_Indices[2][8] =
{

    /*{0, 1 ,2, 3},
    {2, 3, 7, 6},
    {4, 5, 6, 7},
    {0, 3, 7, 4},
    {1, 0, 4, 5},
    {1, 2, 6, 5}


    {4, 1, 2},
    {4, 2, 3},
    {4, 3, 0},
    {4, 0, 1}*/

    {1,5,2,6,3,7,0,4},
    {6,7,5,4,1,0,2,3}

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



void light0()
{
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {0.3, 0.3, 0.3, 1.0};
    GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 0.0, 9.0, 0.0, 1.0 };

    glEnable( GL_LIGHT0);
    if (ambient0)
    {
        glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient);
    }
    else
    {
        glLightfv( GL_LIGHT0, GL_AMBIENT, no_light);
    }
    if (diffuse0)
    {

        glLightfv( GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    }
    else
    {

        glLightfv( GL_LIGHT0, GL_DIFFUSE, no_light);
    }
    if(specular0)
    {

        glLightfv( GL_LIGHT0, GL_SPECULAR, light_specular);
    }
    else
    {

        glLightfv( GL_LIGHT0, GL_SPECULAR, no_light);
    }
    glLightfv( GL_LIGHT0, GL_POSITION, light_position);

    /*  GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
      glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
      glLightf( GL_LIGHT0, GL_SPOT_CUTOFF, 10.0); */
}

void light1()
{
    glPushMatrix();
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {0.5, 0.5, 0.5, 1.0};
    GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 200, 9.5, -15 };  //0.7, 1.5, 9.0

    glEnable( GL_LIGHT1);

    if(ambient1)
    {
        glLightfv( GL_LIGHT1, GL_AMBIENT, light_ambient);
    }
    else
    {
        glLightfv( GL_LIGHT1, GL_AMBIENT, no_light);
    }

    if(diffuse1)
    {
        glLightfv( GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    }
    else
    {
        glLightfv( GL_LIGHT1, GL_DIFFUSE, no_light);
    }

    if(specular1)
    {
        glLightfv( GL_LIGHT1, GL_SPECULAR, light_specular);
    }
    else
    {
        glLightfv( GL_LIGHT1, GL_SPECULAR, no_light);
    }

    glLightfv( GL_LIGHT1, GL_POSITION, light_position);
//    GLfloat spot_direction[] = { 0.3, -1, -0.8 };
    GLfloat spot_direction[] = { -1.0, -1.0, 0.0 };
//    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
//    glLightf( GL_LIGHT1, GL_SPOT_CUTOFF, 10.0);

    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 20.0);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
//    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);

    glPopMatrix();

    /*GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
    glLightf( GL_LIGHT1, GL_SPOT_CUTOFF, 10.0);*/
}


void drawcube(float am_r, float am_g, float am_b, float df_r,float df_g,float df_b,float sp_r=1.0,float sp_g=1.0,float sp_b=1.0,float shininess = 60)
{
//    glColor3f(1,0,0);
    //glBegin(GL_TRIANGLES);

    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { am_r, am_g, am_b, 1.0 };

//    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_diffuse[] = { df_r, df_g, df_b, 1.0 };
//    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_specular[] = { sp_r, sp_g, sp_b, 1.0 };
//    GLfloat mat_shininess[] = {60};
    GLfloat mat_shininess[] = {shininess};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);


    glBegin(GL_QUAD_STRIP);
    for (GLint i = 0; i <2; i++)
    {
//        glColor3f(colors[i][0],colors[i][1],colors[i][2]);
//        glColor3f(r,g,b);


        glVertex3fv(&v_quad_strip[qs_Indices[i][0]][0]);
        glVertex3fv(&v_quad_strip[qs_Indices[i][1]][0]);
        glVertex3fv(&v_quad_strip[qs_Indices[i][2]][0]);
        glVertex3fv(&v_quad_strip[qs_Indices[i][3]][0]);
        glVertex3fv(&v_quad_strip[qs_Indices[i][4]][0]);
        glVertex3fv(&v_quad_strip[qs_Indices[i][5]][0]);
        glVertex3fv(&v_quad_strip[qs_Indices[i][6]][0]);
        glVertex3fv(&v_quad_strip[qs_Indices[i][7]][0]);
    }
    glEnd();


}

void FrustumChange(bool positive = true)
{
    if(positive)nearP++;
    else nearP--;
}

void Pitch(bool clock = true)
{
    // Translate to origin
    if(clock)bita++;
    else bita--;
    GLfloat dx = 0 ;
    GLfloat dy = 0;
    GLfloat dz = -eyeZ;

    GLfloat new_x = dx;
    GLfloat new_y = dy*cos(bita*PI/180.0)-dz*sin(bita*PI/180.0);
    GLfloat new_z = dy*sin(bita*PI/180.0) +dz*cos(bita*PI/180.0);

    lookX = new_x;
    lookY = new_y;
    lookZ = new_z-dz;


}

void Roll(bool clock = true)
{
    if(clock)alpha++;
    else alpha--;
    up_x = -sin(PI*alpha/180.0);
    up_y = cos(PI*alpha/180);
}

void Yaw(bool clock = true)
{
    if(clock) theta++;
    else theta--;
    GLfloat dx =0;
    GLfloat dy = 0;
    GLfloat dz = -eyeZ;

    GLfloat new_x = dx*cos(theta*PI/180.0)+dz*sin(theta*PI/180.0);
    GLfloat new_y = dy;
    GLfloat new_z = -dx*sin(theta*PI/180.0) +dz*cos(theta*PI/180.0);

    lookX = new_x;
    lookY = new_y;
    lookZ = -dz+new_z;
}


void zoom(bool positive = true)
{
    float dx = lookX - eyeX;
    float dy = lookY - eyeY;
    float dz = lookZ - eyeZ;
    float unit_dist = sqrt(dx*dx+dy*dy+dz*dz);
    if(unit_dist<=.1 && positive)return;
    if(!positive)unit_dist*=-1;
    eyeX+=dx/unit_dist;
    eyeY+=dy/unit_dist;
    eyeZ+=dz/unit_dist;
    lookX+=dx/unit_dist;
    lookY+=dy/unit_dist;
    lookZ+=dz/unit_dist;

}

void fan_handle()
{
    glPushMatrix();
    glTranslatef(100,3.5,-10);
    glScalef(.5,.5,.5);

    glPushMatrix();
    glTranslatef(0.0,7.0,0.0);
    glScalef(0.2,1.0,0.2);
    drawcube(white[0],white[1],white[2],1,1,1);
    glPopMatrix();
    glPopMatrix();
}

void fan()
{

    glPushMatrix();
    glTranslatef(100,3.5,-10);
    glScalef(.5,.5,.5);
    //glRotatef( alpha,axis_x, axis_y, 0.0 );
    glRotatef( theta, axis_x, axis_y, 0.0 );


    glPushMatrix();
    glRotatef(theta_pakha, 0.0, 1.0, 0.0);
    glTranslatef(0.0, 7.0, 0.0);
    glScalef(0.4, 0.4, 0.4);


    //pakha one
    glPushMatrix();
    glScalef(7.0,0.3,2.0);
    drawcube(white[0],white[1],white[2],1,1,1);
    glPopMatrix();
    //pakha two
    glPushMatrix();
    glRotatef(120, 0.0, 1.0, 0.0);
    glScalef(7.0,0.3,2.0);
    drawcube(white[0],white[1],white[2],1,1,1);
    glPopMatrix();
    //pakha three
    glPushMatrix();
    glRotatef(240, 0.0, 1.0, 0.0);
    glScalef(7.0,0.3,1.5);
    drawcube(white[0],white[1],white[2],1,1,1);
    glPopMatrix();


    glPopMatrix();


    glPopMatrix();
}

void drawAlmari()
{

    float red[] = {1.0,0.0000, 0.0000};
    float white[] = {1.0,1.0,1.0};
    float brown[] = {0.5451, 0.2706, 0.0745};
    //almari
    glPushMatrix();
    glTranslatef(10,0,-120);
    glScalef(17,1.7,1.0);

    drawcube(red[0],red[1],red[2],1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(14,0.9,-119.5);
    glScalef(7.3,1.4,1.0);
//     float red[] = {1.0,0.0000, 0.0000};

    drawcube(brown[0],brown[1],brown[2],1,1,1);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(55,0.9,-119.5);
    glScalef(7.3,1.4,1.0);
//     float red[] = {1.0,0.0000, 0.0000};

    drawcube(brown[0],brown[1],brown[2],1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(37,4,-114.5);
    glScalef(.5,.3,.1);
//     float red[] = {1.0,0.0000, 0.0000};

    drawcube(white[0],white[1],white[2],1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(68,4,-114.5);
    glScalef(.5,.3,.1);
//     float red[] = {1.0,0.0000, 0.0000};

    drawcube(white[0],white[1],white[2],1,1,1);
    glPopMatrix();

}


void drawTable()
{

    //table
    glPushMatrix();
    glTranslatef(170,0,3);
    glScalef(0.6,0.9,.4);
    drawcube(brown[0],brown[1],brown[2],1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(195,0,3);
    glScalef(0.6,0.9,.4);
    drawcube(brown[0],brown[1],brown[2],1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(170,0,-50);
    glScalef(0.6,0.9,.4);
    drawcube(brown[0],brown[1],brown[2],1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(195,0,-50);
    glScalef(0.6,0.9,.4);
    drawcube(brown[0],brown[1],brown[2],1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(170,4,5);
    glScalef(6,.1,-11.5);
    drawcube(brown[0],brown[1],brown[2],1,1,1);
    glPopMatrix();

}

void drawLaptop()
{

//laptop

    glPushMatrix();
//    glColor3f(0.3, 0.4, 0.5);
    glTranslatef(170, 4.9, -25);
    glScalef(2.5, 0.0, 3);

    drawcube(black[0],black[1],black[2],1,1,1);
    glPopMatrix();


    glPushMatrix();
//    glColor3f(0.3, 0.4, 0.5);
    glTranslatef(183, 4.9, -25);
    glScalef(0, 0.2, 3);
    float pink[] = {1.0, 0.1, 1.0};
    drawcube(pink[0],pink[1],pink[2],1,1,1);
    glPopMatrix();


//    glPushMatrix();
//    glTranslatef(166.5, 5.05, -13);
//    glScalef(0, 0.155, 2.4);
//    color = {1.0, 1.0, 1.0};

    glPushMatrix();
//    glColor3f(0.3, 0.4, 0.5);
    glTranslatef(182.5, 5.05, -23);
    glScalef(0, 0.155, 2.4);
//    color = {1.0, 1.0, 1.0};
    drawcube(white[0], white[1],white[2],1,1,1);
    glPopMatrix();

}

void drawChair()
{

    //Chair
    glPushMatrix();
    glTranslatef(155, 0, -10);
    glScalef(0.6, 1, .4);
//    vector<float> color = {1.0, 1.0, 1.0};
    float yellow[] = {0.5451, 0.2706, 0.0745};
    drawcube(yellow[0],yellow[1],yellow[2],1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(155, 0, -30);
    glScalef(0.6, 1, .4);
//    color = {1.0, 1.0, 1.0};
    drawcube(yellow[0],yellow[1],yellow[2],1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(175, 0, -10);
    glScalef(0.6, 0.4, .4);
//    color = {1.0, 1.0, 1.0};
    drawcube(yellow[0],yellow[1],yellow[2],1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(175, 0, -30);
    glScalef(0.6, 0.4, .4);
//    color = {1.0, 1.0, 1.0};
    drawcube(yellow[0],yellow[1],yellow[2],1,1,1);
    glPopMatrix();

//     upper portion of the chair
    glPushMatrix();
    glTranslatef(157, 1.9, -7.8);
    glScalef(4.5, 0.1, -4.5);
//    color = {1.0, 0.0, 0.0};
    drawcube(yellow[0],yellow[1],yellow[2],1,1,1);
    glPopMatrix();


    //
    glPushMatrix();
    glTranslatef(155, 3.3, -27.5);
    glScalef(0.6, 0.3, 3.5);
//    color = {1.0, 1.0, 0.0};
    drawcube(white[0],white[1],white[2],1,1,1);
    glPopMatrix();


}

void drawRoom()
{
    //floor
    glPushMatrix();
    glTranslatef(0,-0.1,5);
    glScalef(40.5,0,-30);

    drawcube(deep_ash[0],deep_ash[1],deep_ash[2],1,1,1);
    glPopMatrix();

    //left wall
    glPushMatrix();
    glTranslatef(-0.5,0,5);
    glScalef(0,2,-30);

    drawcube(blue[0],blue[1],blue[2],1,1,1);
    glPopMatrix();

    //front wall
    glPushMatrix();
    glTranslatef(-0.5,0,-130);
    glScalef(40,2,0);
//     float color[] = {128.0,0.0,0.0};

    drawcube(blue[0],blue[1],blue[2],1,1,1);
    glPopMatrix();

    //right wall
    glPushMatrix();
    glTranslatef(200,0,5);
    glScalef(0,2,-30);

    drawcube(blue[0],blue[1],blue[2],1,1,1);
    glPopMatrix();

    //roof
    glPushMatrix();
    glTranslatef(0,10,5);
    glScalef(40.5,0,-30);

    drawcube(deep_ash[0],deep_ash[1],deep_ash[2],1,1,1);
    glPopMatrix();

}

void drawBed()
{

    //front bed side
    glPushMatrix();
    glTranslatef(5,2,0);
    glScalef(20,0.2,1);
//      float color[] = {128.0,0.0,0.0};

    drawcube(redish[0],redish[1],redish[2],1,1,1);
    glPopMatrix();



    glPushMatrix();
    //front-bottom bed leg
    glTranslatef(100,0,0);
//      float color[] = {128.0,0.0,0.0};

    drawcube(redish[0],redish[1],redish[2],1,1,1);

    //bottom bed side
    glTranslatef(0,2,0);
    glScalef(1,0.4,-10);
//      float color[] = {128.0,0.0,0.0};

    drawcube(redish[0],redish[1],redish[2],1,1,1);
    glPopMatrix();



    glPushMatrix();
    //back-bottom bed leg
    glTranslatef(100,0,-50);
//      float color[] = {128.0,0.0,0.0};

    drawcube(redish[0],redish[1],redish[2],1,1,1);

    //back bed side
    glTranslatef(5,2,0);
    glScalef(-20,0.2,1);

//      float color[] = {128.0,0.0,0.0};

    drawcube(redish[0],redish[1],redish[2],1,1,1);

    glPopMatrix();

    glPushMatrix();
    //back upper leg
    glTranslatef(0,0,-50);

//      float color[] = {128.0,0.0,0.0};

    drawcube(redish[0],redish[1],redish[2],1,1,1);

    //upper bed side
    glTranslatef(0,2,0);
    glScalef(1,0.5,10.5);

//      float color[] = {128.0,0.0,0.0};

    drawcube(redish[0],redish[1],redish[2],1,1,1);

    glPopMatrix();

    //bedsheet
    glPushMatrix();
    glTranslatef(5,3,5.3);
    glScaled(19,.1,-11);

    drawcube(white[0],white[1],white[2],1,1,1);
    glPopMatrix();

    //pillow
    glPushMatrix();
    glTranslatef(3,3.5,-1.5);
    glScaled(5,.1,-8);


    drawcube(ash[0],ash[1],ash[2],1,1,1);
    glPopMatrix();

    //katha
    glPushMatrix();
    glTranslatef(50,3,7.0);
    glScaled(10,.15,-11.5);


    drawcube(green[0],green[1],green[2],1,1,1);
    glPopMatrix();

//      glPushMatrix();
//      glTranslatef(0,0,0);
//      glScalef


}

//
//void sphere(GLdouble rad, GLint slices, GLint stacks)
//{
//    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat mat_ambient[] = { 0.5, 0, 0.5, 1.0 };
//    GLfloat mat_diffuse[] = { 1.0, 0, 1.0, 1.0 };
//    GLfloat mat_specular[] = { 1, 1,1, 1.0 };
//    GLfloat mat_shininess[] = {60};
//    GLfloat mat_emission[] = {1.0, 0, 0.5, 1.0};
////front phase niye kaaj hoche
//    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
//    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
//    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
//    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
//
//    glutSolidSphere(rad, slices, stacks);
//}

void drawSphere(float am_r, float am_g, float am_b, float df_r, float df_g, float df_b )
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat mat_ambient[] = { 0.0, 0.5, 0.0, 1.0 };
    GLfloat mat_ambient[] = { am_r, am_g, am_b, 1.0 };

//    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_diffuse[] = { df_r, df_g, df_b, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);



//    glPushMatrix();
//    glTranslatef(155, 0, -15);
//    glScalef(0.6, 1, .4);
    glutSolidSphere (2.0, 20, 16);
//    glPopMatrix();

}

void display(void)
{


    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    //glFrustum(-5,5, -5, 5, 4, 50);
    glFrustum(-8,8,-8,8,nearP,farP);
    //gluPerspective(60,1,5,100);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    //gluLookAt(eyeX,eyeY,eyeZ, lookX,lookY,lookZ, 0,1,0); // camera , ,
    //gluLookAt(eyeX+cdist,eyeY+cdist,eyeZ+cdist, lookX+dx,lookY+dy,lookZ+dz, xaxis,yaxis,zaxis);
    gluLookAt(eyeX,eyeY,eyeZ,lookX,lookY,lookZ,up_x,up_y,up_z);

//    gluLookAt(eyeX,eyeY,eyeZ, axis_x, axis_y, axis_z, 0,1,0);
    glViewport(0, 0, windowHeight, windowWidth);

//    glPushMatrix();

    glRotatef(10.0,0,0,1);

    //sphere
    glPushMatrix();
    glTranslatef(12,-6,-8);

    glScalef(0.5,0.5,.5);
    drawSphere(0.0,0.5,0.0,0.0,1.0,0.0);
    glPopMatrix();

    //front-upper bed leg

//    glPushMatrix();
    glRotatef(-10, 0, 0, 1 );
    glTranslatef(-5,-5,0);
    glScalef(0.1,1,.1);
    //lRotatef( alpha,axis_x, axis_y, 0.0 );
    //glRotatef( theta, axis_x, axis_y, 0.0 );
//     GLfloat color[1][3] = {1,0,0};

    drawcube(redish[0],redish[1],redish[2],1,1,1);
//     glPopMatrix();

//    glRotatef(-10, 0, 0, 1 );


    drawRoom();
    drawBed();


    drawAlmari();


    drawTable();

    drawLaptop();

    drawChair();

//glPushMatrix();
//draw_terbine_base();
//glPopMatrix();

    fan_handle();
//    glPopMatrix();

//    glPushMatrix();
//    glTranslatef(100,3.5,-10);
//    glScalef(.5,.5,.5);
//    //glRotatef( alpha,axis_x, axis_y, 0.0 );
//    glRotatef( theta, axis_x, axis_y, 0.0 );
    fan();
//    glPopMatrix();

    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}


void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    //case '1':
    case '1':
        bRotate = !bRotate;
        uRotate = false;
        axis_x=0.0;
        axis_y=1.0;
        break;

    //case '2':
    case '2':
        uRotate = !uRotate;
        bRotate = false;
        axis_x=1.0;
        axis_y=0.0;
        break;


    case '+': //zoom in
        zoom();
        break;
    case '-': //zoom out
        zoom(false);
        break;
    case '*': //zoom up
        eyeY++;
        lookY++;
        break;
    case '/': //zoom down
        eyeY--;
        lookY--;
        break;

    case 'x':
        eyeX++;
        lookX++;
        break;
    case 'z':
        eyeX--;
        lookX--;
        break;
    case 'y':
        Yaw();
        break;
    case 'Y':
        Yaw(false);
        break;

    case 'r':
        Roll();
        break;
    case 'R':
        Roll(false);
        break;

    case 'p':
        Pitch();
        break;

    case 'P':
        Pitch(false);
        break;


    case 'f':
        FrustumChange();
        break;

    case 'F':
        FrustumChange(false);
        break;
    //ambient light handle
    case 'A':
        ambient0 = true;
        light0();
        break;
    case 'a':
        ambient0 = false;
        light0();
        break;
    //diffuse light handle
    case 'D':
        diffuse0 = true;
        light0();
        break;
    case 'd':
        diffuse0 = false;
        light0();
        break;

    //specular light handle
    case 'S':
        specular0 = true;
        light0();
        break;
    case 's':
        specular0 = false;
        light0();
        break;


    //ambient light handle
    case 'Q':
        ambient1 = true;
        light1();
        break;
    case 'q':
        ambient1 = false;
        light1();
        break;
    //diffuse light handle
    case 'W':
        diffuse1 = true;
        light1();
        break;
    case 'w':
        diffuse1 = false;
        light1();
        break;

    //specular light handle
    case 'E':
        specular1 = true;
        light1();
        break;
    case 'e':
        specular1 = false;
        light1();
        break;


    case 27:	// Escape key
        exit(1);
    }
}




void animate()
{
    if (bRotate == true)
    {
        theta += 0.5;
        if(theta > 360.0)
            theta -= 360.0*floor(theta/360.0);
    }

    if (uRotate == true)
    {
        alpha += 0.5;
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
    glutCreateWindow("Inside Room");

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    light0();
    light1();

    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutMainLoop();

    return 0;
}

