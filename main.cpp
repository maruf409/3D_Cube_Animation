#include<windows.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<stdio.h>

#define window_height 600
#define window_width 600

void init(){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); ///background clear
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1,1,-1,1,2,10); ///NEAR 2,FAR 10
    glMatrixMode(GL_MODELVIEW);
}

void face(float A[],float B[],float C[],float D[]){
    glBegin(GL_POLYGON);                            /// gl_polygon/gl_vertex
        glVertex3fv(A);
        glVertex3fv(B);
        glVertex3fv(C);
        glVertex3fv(D);
    glEnd();

}

void cube(float V0[],float V1[],float V2[],float V3[],float V4[],float V5[],float V6[],float V7[]){     ///cube received each vertex and create desire dace
    ///Front face(V0,V1,V2,V3) red
    glColor3f(1.0,0.0,0.0);
    face(V0,V1,V2,V3);


    ///back face(V4,V5,V6,V7) green
    glColor3f(0.0,1.0,0.0);
    face(V4,V5,V6,V7);

    ///left
    glColor3f(0.0,0.0,1.0);
    face(V4,V0,V3,V7);
    ///right
    glColor3f(1.0,0.0,1.0);
    face(V5,V1,V2,V6);
    ///bottom
    glColor3f(1.0,1.0,0.5);
    face(V3,V2,V6,V7);
    ///top
    glColor3f(0.50,1.0,1.0);
    face(V0,V1,V5,V4);

}

float cx=0.0,cy=0.0,cz=3.0;
float T =0.0;

void spin(){
    T+=0.025;
    if(T>360)
        T = 0;

    glutPostRedisplay();


}

void Display(){
    float vertex[8][3]={  ///8 vertex,each has 3 value
    {-0.5,0.5,0.5},
    {0.5,0.5,0.5},
    {0.5,-0.5,0.5},
    {-0.5,-0.5,0.5},
    {-0.5,0.5,-0.5},
    {0.5,0.5,-0.5},
    {0.5,-0.5,-0.5},
    {-0.5,-0.5,-0.5},

    };
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(cx,cy,cz,0,0,0,0,1,0);
    glRotatef(T,1,1,0);
   // cube(V[0],V[1],V[2],V[3],V[4],V[5],V[6],V[7]);
    cube(vertex[0],vertex[1],vertex[2],vertex[3],vertex[4],vertex[5],vertex[6],vertex[7]);

    glutSwapBuffers();

}
//void custom_special()
void custom_keyboard(unsigned char ch, int x,int y)
{
    ///control camera position by increase/decrease
    switch(ch)
    {
        ///decrease in x coordinate
        case 'x':
            cx-=0.5;
            break;
        case 'X':
        ///increase in x coordinate
            cx+=0.5;
            break;

        ///decrease in x coordinate
        case 'y':
            cy-=0.5;
            break;
        case 'Y':
        ///increase in x coordinate
            cy+=0.5;
            break;

        ///decrease in x coordinate
        case 'z':
            cz-=0.5;
            break;
        case 'Z':
        ///increase in x coordinate
            cz+=0.5;
            break;
        default:
            break;



    }
    glutPostRedisplay();

}



int main()
{
    glutInitWindowSize(500,500);
    glutInitWindowPosition(window_height,window_width);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); ///for 3d use double,DEPTH
    glutCreateWindow("3D Cube");
    init();
    glutDisplayFunc(Display);
  //  glutSpecialFunc(custom_special);
    glutIdleFunc(spin);
    glutKeyboardFunc(custom_keyboard);
    glutMainLoop();

    return 0;
}
