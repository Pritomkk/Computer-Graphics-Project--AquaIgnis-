#include<bits/stdc++.h>
#include <windows.h>
#include <GL/glut.h>
#include <Gl/gl.h> // Include GLUT header

bool aquaJumped = false, ignisJumped = false;
GLfloat aquaJumpHeight = 0.0f, ignisJumpHeight = 0.0f;
bool aquaCeil = false, ignisCeil = false;

bool gamePaused = true;
bool gameStarted = false;

// Menu IDs
int menuID;
void renderBitmapString(float x, float y, float z, void * font, char *string)
{
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }

}

class text{

public :
    void draw (){



     //glColor3f(25.0/255, 49/255, 89/255);
     //79, 149, 189
    //glColor3f (25.0/255.0, 49.0/255.0, 89/255.0);
    glColor3f (32.0/255.0, 33.0/255.0, 3.0/255.0);

     glRectf (0,0,800,800);


    //glColor3f (79.0/255.0, 149.0/255.0, 189/255.0);
    glColor3f(0.2f, 0.18f, 0.05f);
     glRectf (550,650,700,700);
     glRectf (370,650,540,700);
     glRectf (100,650,360,700);
     glRectf (550,590,700,640);
     glRectf (370,590,540,640);
      glRectf (100,590,360,640);


     glRectf (550,530,700,580);
     glRectf (370,530,540,580);
     glRectf (100,530,360,580);


      glRectf (550,470,700,520);
      glRectf (370,470,540,520);
      glRectf (100,470,360,520);

     glRectf (550,410,700,460);
     glRectf (370,410,540,460);
     glRectf (100,410,360,460);


      glRectf (550,350,700,400);
      glRectf (370,350,540,400);
      glRectf (100,350,360,400);

    }

    void draw2(){

        glColor3f (1.0,1.0,1.0);
        renderBitmapString(100.0f, 100.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "American International University - Bangladesh (AIUB)");
        renderBitmapString(100.0f, 140.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Course Name : Computer Graphics ");
        renderBitmapString(100.0f, 180.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Project Name :AquaIgnis   Section :[C]");

        renderBitmapString(200.0f, 385.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Name");
        renderBitmapString(450.0f, 385.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Id");
        renderBitmapString(570.0f, 385.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "contribution");
        renderBitmapString(580.0f, 440.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "25%");
        renderBitmapString(580.0f, 500.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "25%");
        renderBitmapString(580.0f, 560.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "20%");
        renderBitmapString(580.0f, 620.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "20%");
        renderBitmapString(580.0f, 680.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "10%");

        renderBitmapString(100.0f, 250.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Course Instructor: Mahfujur Rahman");
         renderBitmapString(100.0f, 290.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Lecturer,Computer Science Department");
         renderBitmapString(100.0f, 320.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "");

        renderBitmapString(120.0f, 450.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Tazrif Yamshit Raim");
        renderBitmapString(400.0f, 450.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "21-45012-2");

        renderBitmapString(120.0f, 500.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Pritom Chandra Dey  ");
        renderBitmapString(400.0f, 500.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "21-44407-1");

        renderBitmapString(120.0f, 560.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Maishara Monjori");
        renderBitmapString(400.0f, 560.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "21-44383-1");

        renderBitmapString(120.0f, 620.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "MD Ridoy Sarker");
        renderBitmapString(400.0f, 620.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "21-45312-2");

       renderBitmapString(120.0f, 680.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "MD Shohidul Islam");

       renderBitmapString(400.0f, 680.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "20-44342-3");

       renderBitmapString(650.0f, 750.0f, 0.0f, GLUT_BITMAP_HELVETICA_10, "Press Enter to go Next");

      }






};




class wall {
public:
    wall(float x, float y, float width, float height) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }

    void draw() {
        // Set color to brown
        glColor3f (32.0/255.0, 33.0/255.0, 3.0/255.0);

        // Draw rectangle using OpenGL commands
        glBegin(GL_QUADS);
        glVertex2f(x, y);                 // Bottom-left vertex
        glVertex2f(x + width, y);        // Bottom-right vertex
        glVertex2f(x + width, y + height);// Top-right vertex
        glVertex2f(x, y + height);       // Top-left vertex
        glEnd();
    }

    void setPosition(float x, float y) {
        this->x = x;
        this->y = y;
    }

    void setSize(float width, float height) {
        this->width = width;
        this->height = height;
    }


    float x;      // X-coordinate of the object
    float y;      // Y-coordinate of the object
    float width;  // Width of the object
    float height; // Height of the object
};

class scoreboard
{  public:

    void draw ()

    {     glColor3f (32.0/255.0, 33.0/255.0, 3.0/255.0);

         glRectf(268,268,534,534);
         glColor3f(115/255.0, 111/255.0, 52/255.0);
         glRectf (268,268,280,534);
         glRectf (522,268,534,534);


    }


};

class wall2 {
public:

    void draw() {
    glColor3f(0.2f, 0.18f, 0.05f);

/*
   glBegin(GL_QUADS);
    glVertex2f(0, 778);
    glVertex2f(695, 800);
    glVertex2f(745, 800);
    glVertex2f(745, 778);

  glEnd(); */
 // glRectf(750, 778, 800, 800);
glRectf(750, 778, 800, 800);
glRectf(700, 778, 747, 800);
glRectf(640, 778, 697, 800);
glRectf(580, 778, 637, 800);
glRectf(520, 778, 577, 800);
glRectf(460, 778, 517, 800);
glRectf (400, 778, 457, 800);
glRectf (340, 778, 397, 800);
glRectf(280, 778, 337, 800);
glRectf(220, 778, 277, 800);
glRectf(160, 778, 217, 800);
glRectf(100, 778, 157, 800);
glRectf(40, 778, 97, 800);
glRectf(0, 778, 37, 800);

glRectf(725.0, 751.0, 800.0, 773.0);
glRectf(657.0, 751.0, 722.0, 773.0);
glRectf(589.0, 751.0, 654.0, 773.0);
glRectf (521.0, 751.0, 586.0, 773.0);
glRectf(453.0, 751.0, 518.0, 773.0);
glRectf(385.0, 751.0, 450.0, 773.0);
glRectf(317.0, 751.0, 382.0, 773.0);
glRectf(249.0, 751.0, 314.0, 773.0);
glRectf(181.0, 751.0, 246.0, 773.0);
glRectf(113.0, 751.0, 178.0, 773.0);
glRectf(45.0, 751.0, 110.0, 773.0);
glRectf(0.0, 751.0, 60.0, 773.0);
////3rd
 glColor3f(0.2f, 0.18f, 0.05f);
glRectf(750, 724, 800, 746);
glRectf(700, 724, 747, 746);
glRectf(640, 724, 697, 746);
glRectf(580, 724, 637, 746);
glRectf(510, 724, 577, 746);
glRectf(460, 724, 517, 746);
glRectf(400, 724, 457, 746);
glRectf(340, 724, 397, 746);
glRectf(280, 724, 337, 746);
glRectf(220, 724, 277, 746);
glRectf(160, 724, 217, 746);
glRectf(100, 724, 157, 746);
glRectf(40, 724, 97, 746);
glRectf(0, 724, 37, 746);
//4th

glRectf(725.0, 697.0, 800.0, 719.0);
glRectf(657.0, 697.0, 722.0, 719.0);
glRectf(589.0, 697.0, 654.0, 719.0);
glRectf(521.0, 697.0, 586.0, 719.0);
glRectf(453.0, 697.0, 518.0, 719.0);
glRectf(385.0, 697.0, 450.0, 719.0);
glRectf(317.0, 697.0, 382.0, 719.0);
glRectf(249.0, 697.0, 314.0, 719.0);
glRectf(181.0, 697.0, 246.0, 719.0);
glRectf(113.0, 697.0, 178.0, 719.0);
glRectf(45.0, 697.0, 110.0, 719.0);
glRectf(0.0, 697.0, 60.0, 719.0);

//5th
glRectf(750, 670, 800, 692);
glRectf(700, 670, 747, 692);
glRectf(640, 670, 697, 692);
glRectf(580, 670, 637, 692);
glRectf(510, 670, 577, 692);
glRectf(460, 670, 517, 692);
glRectf(400, 670, 457, 692);
glRectf(340, 670, 397, 692);
glRectf(280, 670, 337, 692);
glRectf(220, 670, 277, 692);
glRectf(160, 670, 217, 692);
glRectf(100, 670, 157, 692);
glRectf(40, 670, 97, 692);
glRectf(0, 670, 37, 692);

//6th

glRectf(725.0, 643.0, 800.0, 665.0);
glRectf(657.0, 643.0, 722.0, 665.0);
glRectf(589.0, 643.0, 654.0, 665.0);
glRectf(521.0, 643.0, 586.0, 665.0);
glRectf(453.0, 643.0, 518.0, 665.0);
glRectf(385.0, 643.0, 450.0, 665.0);
glRectf(317.0, 643.0, 382.0, 665.0);
glRectf(249.0, 643.0, 314.0, 665.0);
glRectf(181.0, 643.0, 246.0, 665.0);
glRectf(113.0, 643.0, 178.0, 665.0);
glRectf(45.0, 643.0, 110.0, 665.0);
glRectf(0.0, 643.0, 60.0, 665.0);

//7th set the color

glRectf(750, 612, 800, 638);
glRectf(700, 612, 747, 638);
glRectf(640, 612, 697, 638);
glRectf(580, 612, 637, 638);
glRectf(510, 612, 577, 638);
glRectf(460, 612, 517, 638);
glRectf(400, 612, 457, 638);
glRectf(340, 612, 397, 638);
glRectf(280, 612, 337, 638);
glRectf(220, 612, 277, 638);
glRectf(160, 612, 217, 638);
glRectf(100, 612, 157, 638);
glRectf(40, 612, 97, 638);
glRectf(0, 612, 37, 638);
// 8th
glRectf(725.0, 584.0, 800.0, 606.0);
glRectf(657.0, 584.0, 722.0, 606.0);
glRectf(589.0, 584.0, 654.0, 606.0);
glRectf(521.0, 584.0, 586.0, 606.0);
glRectf(453.0, 584.0, 518.0, 606.0);
glRectf(385.0, 584.0, 450.0, 606.0);
glRectf(317.0, 584.0, 382.0, 606.0);
glRectf(249.0, 584.0, 314.0, 606.0);
glRectf(181.0, 584.0, 246.0, 606.0);
glRectf(113.0, 584.0, 178.0, 606.0);
glRectf(45.0, 584.0, 110.0, 606.0);
glRectf(0.0, 584.0, 60.0, 606.0);

//9th
glRectf(750, 612, 800, 638);
glRectf(700, 612, 747, 638);
glRectf(640, 612, 697, 638);
glRectf(580, 612, 637, 638);
glRectf(510, 612, 577, 638);
glRectf(460, 612, 517, 638);
glRectf(400, 612, 457, 638);
glRectf(340, 612, 397, 638);
glRectf(280, 612, 337, 638);
glRectf(220, 612, 277, 638);
glRectf(160, 612, 217, 638);
glRectf(100, 612, 157, 638);
glRectf(40, 612, 97, 638);
glRectf(0, 612, 37, 638);
//10
glRectf(750, 557, 800, 579);
glRectf(700, 557, 747, 579);
glRectf(640, 557, 697, 579);
glRectf(580, 557, 637, 579);
glRectf(510, 557, 577, 579);
glRectf(460, 557, 517, 579);
glRectf(400, 557, 457, 579);
glRectf(340, 557, 397, 579);
glRectf(280, 557, 337, 579);
glRectf(220, 557, 277, 579);
glRectf(160, 557, 217, 579);
glRectf(100, 557, 157, 579);
glRectf(40, 557, 97, 579);
glRectf(0, 557, 37, 579);

//11
glRectf(725.0, 530.0, 800.0, 552.0);
glRectf(657.0, 530.0, 722.0, 552.0);
glRectf(589.0, 530.0, 654.0, 552.0);
glRectf(521.0, 530.0, 586.0, 552.0);
glRectf(453.0, 530.0, 518.0, 552.0);
glRectf(385.0, 530.0, 450.0, 552.0);
glRectf(317.0, 530.0, 382.0, 552.0);
glRectf(249.0, 530.0, 314.0, 552.0);
glRectf(181.0, 530.0, 246.0, 552.0);
glRectf(113.0, 530.0, 178.0, 552.0);
glRectf(45.0, 530.0, 110.0, 552.0);
glRectf(0.0, 530.0, 60.0, 552.0);
////
glRectf(750, 503, 800, 525);
glRectf(700, 503, 747, 525);
glRectf(640, 503, 697, 525);
glRectf(580, 503, 637, 525);
glRectf(510, 503, 577, 525);
glRectf(460, 503, 517, 525);
glRectf(400, 503, 457, 525);
glRectf(340, 503, 397, 525);
glRectf(280, 503, 337, 525);
glRectf(220, 503, 277, 525);
glRectf(160, 503, 217, 525);
glRectf(100, 503, 157, 525);
glRectf(40, 503, 97, 525);
glRectf(0, 503, 37, 525);
//
glRectf(725.0, 476.0, 800.0, 498.0);
glRectf(657.0, 476.0, 722.0, 498.0);
glRectf(589.0, 476.0, 654.0, 498.0);
glRectf(521.0, 476.0, 586.0, 498.0);
glRectf(453.0, 476.0, 518.0, 498.0);
glRectf(385.0, 476.0, 450.0, 498.0);
glRectf(317.0, 476.0, 382.0, 498.0);
glRectf(249.0, 476.0, 314.0, 498.0);
glRectf(181.0, 476.0, 246.0, 498.0);
glRectf(113.0, 476.0, 178.0, 498.0);
glRectf(45.0, 476.0, 110.0, 498.0);
glRectf(0.0, 476.0, 60.0, 498.0);
//
glRectf(750, 449, 800, 471);
glRectf(700, 449, 747, 471);
glRectf(640, 449, 697, 471);
glRectf(580, 449, 637, 471);
glRectf(510, 449, 577, 471);
glRectf(460, 449, 517, 471);
glRectf(400, 449, 457, 471);
glRectf(340, 449, 397, 471);
glRectf(280, 449, 337, 471);
glRectf(220, 449, 277, 471);
glRectf(160, 449, 217, 471);
glRectf(100, 449, 157, 471);
glRectf(40, 449, 97, 471);
glRectf(0, 449, 37, 471);

//
glRectf(725.0, 422.0, 800.0, 444.0);
glRectf(657.0, 422.0, 722.0, 444.0);
glRectf(589.0, 422.0, 654.0, 444.0);
glRectf(521.0, 422.0, 586.0, 444.0);
glRectf(453.0, 422.0, 518.0, 444.0);
glRectf(385.0, 422.0, 450.0, 444.0);
glRectf(317.0, 422.0, 382.0, 444.0);
glRectf(249.0, 422.0, 314.0, 444.0);
glRectf(181.0, 422.0, 246.0, 444.0);
glRectf(113.0, 422.0, 178.0, 444.0);
glRectf(45.0, 422.0, 110.0, 444.0);
glRectf(0.0, 422.0, 60.0, 444.0);

//
glRectf(750, 395, 800, 417);
glRectf(700, 395, 747, 417);
glRectf(640, 395, 697, 417);
glRectf(580, 395, 637, 417);
glRectf(510, 395, 577, 417);
glRectf(460, 395, 517, 417);
glRectf(400, 395, 457, 417);
glRectf(340, 395, 397, 417);
glRectf(280, 395, 337, 417);
glRectf(220, 395, 277, 417);
glRectf(160, 395, 217, 417);
glRectf(100, 395, 157, 417);
glRectf(40, 395, 97, 417);
glRectf(0, 395, 37, 417);
//
glRectf(725.0, 368.0, 800.0, 390.0);
glRectf(657.0, 368.0, 722.0, 390.0);
glRectf(589.0, 368.0, 654.0, 390.0);
glRectf(521.0, 368.0, 586.0, 390.0);
glRectf(453.0, 368.0, 518.0, 390.0);
glRectf(385.0, 368.0, 450.0, 390.0);
glRectf(317.0, 368.0, 382.0, 390.0);
glRectf(249.0, 368.0, 314.0, 390.0);
glRectf(181.0, 368.0, 246.0, 390.0);
glRectf(113.0, 368.0, 178.0, 390.0);
glRectf(45.0, 368.0, 110.0, 390.0);
glRectf(0.0, 368.0, 60.0, 390.0);

//
glRectf(750, 341, 800, 363);
glRectf(700, 341, 747, 363);
glRectf(640, 341, 697, 363);
glRectf(580, 341, 637, 363);
glRectf(510, 341, 577, 363);
glRectf(460, 341, 517, 363);
glRectf(400, 341, 457, 363);
glRectf(340, 341, 397, 363);
glRectf(280, 341, 337, 363);
glRectf(220, 341, 277, 363);
glRectf(160, 341, 217, 363);
glRectf(100, 341, 157, 363);
glRectf(40, 341, 97, 363);
glRectf(0, 341, 37, 363);
//
glRectf(725.0, 314.0, 800.0, 336.0);
glRectf(657.0, 314.0, 722.0, 336.0);
glRectf(589.0, 314.0, 654.0, 336.0);
glRectf(521.0, 314.0, 586.0, 336.0);
glRectf(453.0, 314.0, 518.0, 336.0);
glRectf(385.0, 314.0, 450.0, 336.0);
glRectf(317.0, 314.0, 382.0, 336.0);
glRectf(249.0, 314.0, 314.0, 336.0);
glRectf(181.0, 314.0, 246.0, 336.0);
glRectf(113.0, 314.0, 178.0, 336.0);
glRectf(45.0, 314.0, 110.0, 336.0);
glRectf(0.0, 314.0, 60.0, 336.0);

//

glRectf(750, 287, 800, 309);
glRectf(700, 287, 747, 309);
glRectf(640, 287, 697, 309);
glRectf(580, 287, 637, 309);
glRectf(510, 287, 577, 309);
glRectf(460, 287, 517, 309);
glRectf(400, 287, 457, 309);
glRectf(340, 287, 397, 309);
glRectf(280, 287, 337, 309);
glRectf(220, 287, 277, 309);
glRectf(160, 287, 217, 309);
glRectf(100, 287, 157, 309);
glRectf(40, 287, 97, 309);
glRectf(0, 287, 37, 309);
//
glRectf(725.0, 260.0, 800.0, 282.0);
glRectf(657.0, 260.0, 722.0, 282.0);
glRectf(589.0, 260.0, 654.0, 282.0);
glRectf(521.0, 260.0, 586.0, 282.0);
glRectf(453.0, 260.0, 518.0, 282.0);
glRectf(385.0, 260.0, 450.0, 282.0);
glRectf(317.0, 260.0, 382.0, 282.0);
glRectf(249.0, 260.0, 314.0, 282.0);
glRectf(181.0, 260.0, 246.0, 282.0);
glRectf(113.0, 260.0, 178.0, 282.0);
glRectf(45.0, 260.0, 110.0, 282.0);
glRectf(0.0, 260.0, 60.0, 282.0);
//

glRectf(750, 233, 800, 255);
glRectf(700, 233, 747, 255);
glRectf(640, 233, 697, 255);
glRectf(580, 233, 637, 255);
glRectf(510, 233, 577, 255);
glRectf(460, 233, 517, 255);
glRectf(400, 233, 457, 255);
glRectf(340, 233, 397, 255);
glRectf(280, 233, 337, 255);
glRectf(220, 233, 277, 255);
glRectf(160, 233, 217, 255);
glRectf(100, 233, 157, 255);
glRectf(40, 233, 97, 255);
glRectf(0, 233, 37, 255);
//

glRectf(725.0, 206.0, 800.0, 228.0);
glRectf(657.0, 206.0, 722.0, 228.0);
glRectf(589.0, 206.0, 654.0, 228.0);
glRectf(521.0, 206.0, 586.0, 228.0);
glRectf(453.0, 206.0, 518.0, 228.0);
glRectf(385.0, 206.0, 450.0, 228.0);
glRectf(317.0, 206.0, 382.0, 228.0);
glRectf(249.0, 206.0, 314.0, 228.0);
glRectf(181.0, 206.0, 246.0, 228.0);
glRectf(113.0, 206.0, 178.0, 228.0);
glRectf(45.0, 206.0, 110.0, 228.0);
glRectf(0.0, 206.0, 60.0, 228.0);

//
glRectf(750, 179, 800, 201);
glRectf(700, 179, 747, 201);
glRectf(640, 179, 697, 201);
glRectf(580, 179, 637, 201);
glRectf(510, 179, 577, 201);
glRectf(460, 179, 517, 201);
glRectf(400, 179, 457, 201);
glRectf(340, 179, 397, 201);
glRectf(280, 179, 337, 201);
glRectf(220, 179, 277, 201);
glRectf(160, 179, 217, 201);
glRectf(100, 179, 157, 201);
glRectf(40, 179, 97, 201);
glRectf(0, 179, 37, 201);
//

glRectf(725.0, 152.0, 800.0, 174.0);
glRectf(657.0, 152.0, 722.0, 174.0);
glRectf(589.0, 152.0, 654.0, 174.0);
glRectf(521.0, 152.0, 586.0, 174.0);
glRectf(453.0, 152.0, 518.0, 174.0);
glRectf(385.0, 152.0, 450.0, 174.0);
glRectf(317.0, 152.0, 382.0, 174.0);
glRectf(249.0, 152.0, 314.0, 174.0);
glRectf(181.0, 152.0, 246.0, 174.0);
glRectf(113.0, 152.0, 178.0, 174.0);
glRectf(45.0, 152.0, 110.0, 174.0);
glRectf(0.0, 152.0, 60.0, 174.0);
//
glRectf(750, 125, 800, 147);
glRectf(700, 125, 747, 147);
glRectf(640, 125, 697, 147);
glRectf(580, 125, 637, 147);
glRectf(510, 125, 577, 147);
glRectf(460, 125, 517, 147);
glRectf(400, 125, 457, 147);
glRectf(340, 125, 397, 147);
glRectf(280, 125, 337, 147);
glRectf(220, 125, 277, 147);
glRectf(160, 125, 217, 147);
glRectf(100, 125, 157, 147);
glRectf(40, 125, 97, 147);
glRectf(0, 125, 37, 147);
//
glRectf(725.0, 98.0, 800.0, 120.0);
glRectf(657.0, 98.0, 722.0, 120.0);
glRectf(589.0, 98.0, 654.0, 120.0);
glRectf(521.0, 98.0, 586.0, 120.0);
glRectf(453.0, 98.0, 518.0, 120.0);
glRectf(385.0, 98.0, 450.0, 120.0);
glRectf(317.0, 98.0, 382.0, 120.0);
glRectf(249.0, 98.0, 314.0, 120.0);
glRectf(181.0, 98.0, 246.0, 120.0);
glRectf(113.0, 98.0, 178.0, 120.0);
glRectf(45.0, 98.0, 110.0, 120.0);
glRectf(0.0, 98.0, 60.0, 120.0);
//
glRectf(750, 71, 800, 93);
glRectf(700, 71, 747, 93);
glRectf(640, 71, 697, 93);
glRectf(580, 71, 637, 93);
glRectf(510, 71, 577, 93);
glRectf(460, 71, 517, 93);
glRectf(400, 71, 457, 93);
glRectf(340, 71, 397, 93);
glRectf(280, 71, 337, 93);
glRectf(220, 71, 277, 93);
glRectf(160, 71, 217, 93);
glRectf(100, 71, 157, 93);
glRectf(40, 71, 97, 93);
glRectf(0, 71, 37, 93);
//
glRectf(725.0, 44.0, 800.0, 66.0);
glRectf(657.0, 44.0, 722.0, 66.0);
glRectf(589.0, 44.0, 654.0, 66.0);
glRectf(521.0, 44.0, 586.0, 66.0);
glRectf(453.0, 44.0, 518.0, 66.0);
glRectf(385.0, 44.0, 450.0, 66.0);
glRectf(317.0, 44.0, 382.0, 66.0);
glRectf(249.0, 44.0, 314.0, 66.0);
glRectf(181.0, 44.0, 246.0, 66.0);
glRectf(113.0, 44.0, 178.0, 66.0);
glRectf(45.0, 44.0, 110.0, 66.0);
glRectf(0.0, 44.0, 60.0, 66.0);
//
glRectf(750, 17, 800, 39);
glRectf(700, 17, 747, 39);
glRectf(640, 17, 697, 39);
glRectf(580, 17, 637, 39);
glRectf(510, 17, 577, 39);
glRectf(460, 17, 517, 39);
glRectf(400, 17, 457, 39);
glRectf(340, 17, 397, 39);
glRectf(280, 17, 337, 39);
glRectf(220, 17, 277, 39);
glRectf(160, 17, 217, 39);
glRectf(100, 17, 157, 39);
glRectf(40, 17, 97, 39);
glRectf(0, 17, 37, 39);
//
glRectf(725.0, 12.0, 800.0, 0.0);
glRectf(657.0, 12.0, 722.0, 0.0);
glRectf(589.0, 12.0, 654.0, 0.0);
glRectf(521.0, 12.0, 586.0, 0.0);
glRectf(453.0, 12.0, 518.0, 0.0);
glRectf(385.0, 12.0, 450.0, 0.0);
glRectf(317.0, 12.0, 382.0, 0.0);
glRectf(249.0, 12.0, 314.0, 0.0);
glRectf(181.0, 12.0, 246.0, 0.0);
glRectf(113.0, 12.0, 178.0, 0.0);
glRectf(45.0, 12.0, 110.0, 0.0);
glRectf(0.0, 12.0, 60.0, 0.0);

glColor3f(115/255.0, 111/255.0, 52/255.0);
glRectf(0, 0, 10, 800);
glRectf(790, 0, 800, 800);






























    }

    /*void setPosition(float x, float y) {
        this->x = x;
        this->y = y;
    }

    void setSize(float width, float height) {
        this->width = width;
        this->height = height;
    }*/


    /*float x;      // X-coordinate of the object
    float y;      // Y-coordinate of the object
    float width;  // Width of the object
    float height; // Height of the objec */
};




void menu(int choice) {
   /* switch (choice) {
        case 1: // Start game
            gamePaused = false;
            gameStarted = true;
            break;
        case 2: // Pause game
            gamePaused = true;
            break;
        case 3: // Restart game
            gamePaused = false;
            gameStarted = true;
            // Reset any necessary game state variables here
            break;
        case 4: // Quit game
            exit(0);
            break;
    }*/

}

/*void createMenu() {
    // Create the menu and add options
    glBegin()
    menuID = glutCreateMenu(menu);
    glutAddMenuEntry("Start", 1);
    glutAddMenuEntry("Pause", 2);
    glutAddMenuEntry("Restart", 3);
    glutAddMenuEntry("Quit", 4);

    // Attach the menu to the right mouse button
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}*/

//classes




class Menu
{
public:
    Menu(float x, float y, float width, float height,bool isSelected) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->isSelected=isSelected;
    }
    void draw()
    {
        //glColor3f (32.0/255.0, 33.0/255.0, 3.0/255.0);

        if(isSelected)
        {
            glColor3f(115/255.0, 111/255.0, 52/255.0);


        }
        else
        {
             glColor3f(0.2f, 0.18f, 0.05f);
        }

        // Draw rectangle using OpenGL commands
        glBegin(GL_QUADS);
        glVertex2f(x, y);                 // Bottom-left vertex
        glVertex2f(x + width, y);        // Bottom-right vertex
        glVertex2f(x + width, y + height);// Top-right vertex
        glVertex2f(x, y + height);       // Top-left vertex
        glEnd();
    }
    float x;      // X-coordinate of the object
    float y;      // Y-coordinate of the object
    float width;  // Width of the object
    float height; // Height of the object
    bool isSelected;
};

class Ignis {
public:
    Ignis(float x, float y, float width, float height) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }

void draw() {
    // Set color to red
    glColor3f(1.0f, 0.0f, 0.0f);

 // Draw small circle above head
    const float radius = width / 4;
    const float centerX = x + width / 2;
    const float centerY = y - height/3 + radius;
    const int numSegments = 64;
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; i++) {
        float theta = 2.0f * 3.1415926f * i / numSegments;
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(centerX + x, centerY + y);
    }
    glEnd();

    // Draw head
    glBegin(GL_POLYGON);
    glVertex2f(x + width / 2, y - height * 0.2f);
    glVertex2f(x + width * 1.2 / 3, y - height * 0.2f);
    glVertex2f(x + width * 0.7f, y + 0.5 * height);
    glVertex2f(x + width * 0.3f, y + 0.5 * height );
    glEnd();

    // Draw body
    glBegin(GL_POLYGON);
    glVertex2f(x + width * 0.25f, y + height * 0.2f);
    glVertex2f(x + width * 0.75f, y + height * 0.2f);
    glVertex2f(x + width * 0.75f, y + height * 0.8f);
    glVertex2f(x + width * 0.25f, y + height * 0.8f);
    glEnd();

    // Draw left arm
    glBegin(GL_POLYGON);
    glVertex2f(x, y + height * 0.55f);
    glVertex2f(x + width * 0.25f, y + height * 0.5f);
    glVertex2f(x + width * 0.25f, y + height * 0.2f);
    glVertex2f(x, y + height * 0.5f);
    glEnd();

    // Draw right arm
    glBegin(GL_POLYGON);
    glVertex2f(x + width, y + height * 0.55f);
    glVertex2f(x + width * 0.75f, y + height * 0.5f);
    glVertex2f(x + width * 0.75f, y + height * 0.2f);
    glVertex2f(x + width, y + height * 0.5f);
    glEnd();

    // Draw left leg
    glBegin(GL_POLYGON);
    glVertex2f(x + width * 0.5f, y + height * 0.8f);
    glVertex2f(x + width * 0.25f, y + height * 0.8f);
    glVertex2f(x + width * 0.35f, y + height);
    glVertex2f(x + width * 0.25f, y + height);
    glEnd();

    // Draw right leg
    glBegin(GL_POLYGON);
    glVertex2f(x + width * 0.5f, y + height * 0.8f);
    glVertex2f(x + width * 0.75f, y + height * 0.8f);
    glVertex2f(x + width * 0.65f, y  + height);
    glVertex2f(x + width * 0.75f, y + height);
    glEnd();


}


    void setPosition(float x, float y) {
        this->x = x;
        this->y = y;
    }

    void setSize(float width, float height) {
        this->width = width;
        this->height = height;
    }

    void moveLeft()
    {
        if(x<=0) return;
        x-=12.5f;
    }

    void moveRight()
    {
        if(x>=765) return;
        x+=12.5f;
    }

    void jump()
    {
        ignisJumped = true;
    }


    float x;      // X-coordinate of the object
    float y;      // Y-coordinate of the object
    float width;  // Width of the object
    float height; // Height of the object
};


class Aqua {
public:
    Aqua(float x, float y, float width, float height) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }
void draw() {
    // Set color to red
    glColor3f(0.0f, 0.0f, 1.0f);

 // Draw small circle above head
    const float radius = width / 4;
    const float centerX = x + width / 2;
    const float centerY = y - height/3 + radius;
    const int numSegments = 64;
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; i++) {
        float theta = 2.0f * 3.1415926f * i / numSegments;
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(centerX + x, centerY + y);
    }
    glEnd();

    // Draw head
    glBegin(GL_POLYGON);
    glVertex2f(x + width / 2, y - height * 0.2f);
    glVertex2f(x + width * 1.2 / 3, y - height * 0.2f);
    glVertex2f(x + width * 0.7f, y + 0.5 * height);
    glVertex2f(x + width * 0.3f, y + 0.5 * height );
    glEnd();

    // Draw body
    glBegin(GL_POLYGON);
    glVertex2f(x + width * 0.25f, y + height * 0.2f);
    glVertex2f(x + width * 0.75f, y + height * 0.2f);
    glVertex2f(x + width * 0.75f, y + height * 0.8f);
    glVertex2f(x + width * 0.25f, y + height * 0.8f);
    glEnd();

    // Draw left arm
    glBegin(GL_POLYGON);
    glVertex2f(x, y + height * 0.55f);
    glVertex2f(x + width * 0.25f, y + height * 0.5f);
    glVertex2f(x + width * 0.25f, y + height * 0.2f);
    glVertex2f(x, y + height * 0.5f);
    glEnd();

    // Draw right arm
    glBegin(GL_POLYGON);
    glVertex2f(x + width, y + height * 0.55f);
    glVertex2f(x + width * 0.75f, y + height * 0.5f);
    glVertex2f(x + width * 0.75f, y + height * 0.2f);
    glVertex2f(x + width, y + height * 0.5f);
    glEnd();

    // Draw left leg
    glBegin(GL_POLYGON);
    glVertex2f(x + width * 0.5f, y + height * 0.8f);
    glVertex2f(x + width * 0.25f, y + height * 0.8f);
    glVertex2f(x + width * 0.35f, y + height);
    glVertex2f(x + width * 0.25f, y + height);
    glEnd();

    // Draw right leg
    glBegin(GL_POLYGON);
    glVertex2f(x + width * 0.5f, y + height * 0.8f);
    glVertex2f(x + width * 0.75f, y + height * 0.8f);
    glVertex2f(x + width * 0.65f, y  + height);
    glVertex2f(x + width * 0.75f, y + height);
    glEnd();


}

    void setPosition(float x, float y) {
        this->x = x;
        this->y = y;
    }

    void setSize(float width, float height) {
        this->width = width;
        this->height = height;
    }

    void moveLeft()
    {
        if(x<=0) return;
        x-=12.5f;
    }

    void moveRight()
    {
        if(x>=770) return;
        x+=12.5f;
    }

    void jump()
    {
        aquaJumped = true;

    }

public:
    float x;      // X-coordinate of the object
    float y;      // Y-coordinate of the object
    float width;  // Width of the object
    float height; // Height of the object
};

class Platform {
public:
    Platform(float x, float y, float width, float height) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }

    void draw() {
        // Set color to brown
        glColor3f(115/255.0, 111/255.0, 52/255.0);

        // Draw rectangle using OpenGL commands
        glBegin(GL_QUADS);
        glVertex2f(x, y);                 // Bottom-left vertex
        glVertex2f(x + width, y);        // Bottom-right vertex
        glVertex2f(x + width, y + height);// Top-right vertex
        glVertex2f(x, y + height);       // Top-left vertex
        glEnd();
    }

    void setPosition(float x, float y) {
        this->x = x;
        this->y = y;
    }

    void setSize(float width, float height) {
        this->width = width;
        this->height = height;
    }


    float x;      // X-coordinate of the object
    float y;      // Y-coordinate of the object
    float width;  // Width of the object
    float height; // Height of the object
};

class Lava {
public:
    Lava(float x, float y, float width, float height) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }

    void draw() {
        // Set color to brown
        glColor3f(1.0f, 0.0f, 0.0f);

        // Draw rectangle using OpenGL commands
        glBegin(GL_QUADS);
        glVertex2f(x, y);                 // Bottom-left vertex
        glVertex2f(x + width, y);        // Bottom-right vertex
        glVertex2f(x + width, y + height);// Top-right vertex
        glVertex2f(x, y + height);       // Top-left vertex
        glEnd();
    }

    void setPosition(float x, float y) {
        this->x = x;
        this->y = y;
    }

    void setSize(float width, float height) {
        this->width = width;
        this->height = height;
    }


    float x;      // X-coordinate of the object
    float y;      // Y-coordinate of the object
    float width;  // Width of the object
    float height; // Height of the object
};





class Water {
public:
    Water(float x, float y, float width, float height) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }

    void draw() {
        // Set color to brown
        glColor3f(0.0f, 0.0f, 1.0f);

        // Draw rectangle using OpenGL commands
        glBegin(GL_QUADS);
        glVertex2f(x, y);                 // Bottom-left vertex
        glVertex2f(x + width, y);        // Bottom-right vertex
        glVertex2f(x + width, y + height);// Top-right vertex
        glVertex2f(x, y + height);       // Top-left vertex
        glEnd();
    }

    void setPosition(float x, float y) {
        this->x = x;
        this->y = y;
    }

    void setSize(float width, float height) {
        this->width = width;
        this->height = height;
    }


    float x;      // X-coordinate of the object
    float y;      // Y-coordinate of the object
    float width;  // Width of the object
    float height; // Height of the object
};

class Toxin {
public:
    Toxin(float x, float y, float width, float height)
     {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }

    void draw()
    {
        // Set color
        glColor3f(0.1f, 1.0f, 0.1f);

        // Draw rectangle using OpenGL commands
        glBegin(GL_QUADS);
        glVertex2f(x, y);                 // Bottom-left vertex
        glVertex2f(x + width, y);        // Bottom-right vertex
        glVertex2f(x + width, y + height);// Top-right vertex
        glVertex2f(x, y + height);       // Top-left vertex
        glEnd();
    }

    void setPosition(float x, float y) {
        this->x = x;
        this->y = y;
    }

    void setSize(float width, float height) {
        this->width = width;
        this->height = height;
    }


    float x;      // X-coordinate of the object
    float y;      // Y-coordinate of the object
    float width;  // Width of the object
    float height; // Height of the object
};


class Button {
public:
    Button(float x, float y, float width, float height) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->isPressed = false;
    }

    void draw()
    {
        if (isPressed)
            {

             glColor3f(1.0f, 1.0f, 1.0f);
        }
        else {
            glColor3f(0.2f, 0.18f, 0.05f); // Red
        }

        // Draw rectangle using OpenGL commands
        glBegin(GL_QUADS);
        glVertex2f(x, y);                 // Bottom-left vertex
        glVertex2f(x + width, y);        // Bottom-right vertex
        glVertex2f(x + width, y + height);// Top-right vertex
        glVertex2f(x, y + height);       // Top-left vertex
        glEnd();
    }

    void setPosition(float x, float y) {
        this->x = x;
        this->y = y;
    }

    void setIsPressed(bool isPressed) {
        this->isPressed = isPressed;
    }

    float x;           // X-coordinate of the button
    float y;           // Y-coordinate of the button
    float width;       // Width of the button
    float height;      // Height of the button
    bool isPressed;    // Whether the button is pressed or not
};

class Box {
public:
    Box(float x, float y, float width, float height) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }

    void draw() {
        // Set color
        glColor3f(0.0f, 1.0f, 1.0f);

        // Draw rectangle using OpenGL commands
        glBegin(GL_QUADS);
        glVertex2f(x, y);                 // Bottom-left vertex
        glVertex2f(x + width, y);        // Bottom-right vertex
        glVertex2f(x + width, y + height);// Top-right vertex
        glVertex2f(x, y + height);       // Top-left vertex
        glEnd();
    }

    void setPosition(float x, float y) {
        this->x = x;
        this->y = y;
    }

    void setSize(float width, float height) {
        this->width = width;
        this->height = height;
    }


    float x;      // X-coordinate of the box
    float y;      // Y-coordinate of the box
    float width;  // Width of the box
    float height; // Height of the box
};


class Door {
public:
    Door(float x, float y, float width, float height) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        isOpen = false;
    }

    void draw() {
        // Set color
        glColor3f(115/255.0, 111/255.0, 52/255.0); //

        // Draw rectangle using OpenGL commands
        glBegin(GL_QUADS);
        glVertex2f(x, y);                 // Bottom-left vertex
        glVertex2f(x + width, y);        // Bottom-right vertex
        glVertex2f(x + width, y + height);// Top-right vertex
        glVertex2f(x, y + height);       // Top-left vertex
        glEnd();

        glColor3f(0.0f,0.0f,0.0f);

        glBegin(GL_QUADS);
        glVertex2f(x+3.0f, y+3.0f);                 // Bottom-left vertex
        glVertex2f(x + width-3.0f, y+3.0f);        // Bottom-right vertex
        glVertex2f(x + width-3.0f, y + height);// Top-right vertex
        glVertex2f(x+3.0f, y + height);       // Top-left vertex
        glEnd();

    }

    void setPosition(float x, float y) {
        this->x = x;
        this->y = y;
    }

    void setSize(float width, float height) {
        this->width = width;
        this->height = height;
    }

    void setOpen(bool open) {
        isOpen = open;
    }

    bool isOpened() {
        return isOpen;
    }


    float x;       // X-coordinate of the door
    float y;       // Y-coordinate of the door
    float width;   // Width of the door
    float height;  // Height of the door
    bool isOpen;  // Whether the door is open or closed
};

void sound()
{

    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME);
   PlaySound("Start.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}
void sound1()
{

    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME);
   PlaySound("game1.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}
void sound2()
{

    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME);
   PlaySound("game2.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}

int Level =2;

text t;
wall2 a ;
scoreboard score;
wall backround1(0.0f,0.0f,800.f,800.0f);
Platform p1(0.0f,770.0f,800.0f, 50.0f);
Platform p2(0.0f, 600.0f, 600.0f, 20.0f);
Platform p3(180.0f, 410.0f, 650.0f, 20.0f);
Platform p4(0.0f, 190.0f, 650.0f, 20.0f);
Aqua aqua (710.0f, 560.0f, 30.0f, 30.0f);
Ignis ignis(770.0f, 560.0f,30.0f,30.0f);
Box box(300.0f, 80.0f, 30.0f, 30.0f);
Toxin maishara(450.0f,600.0f,50.0f, 5.0f);
Lava lava(250.0f, 600.0f, 80.0f, 5.0f);
Water water(300.0f, 410.0f, 80.0f, 5.0f);
Button button(600.0f, 410.0f, 50.0f, 5.0f);
Door doorIgnis(50.0f, 130.0f, 45.0f, 60.0f);
Door doorAqua(130.0f, 130.0f, 45.0f, 60.0f);
Door door(400.0f, 0.0f, 5.0f, 200.0f);
Menu play(300.0f,400.0f,200.0f,50.0f,true);
Menu credits(300.0f,480.0f,200.0f,50.0f,false);
Menu control ( 300.0f,300.0f,200.0f,50.0f,true);
Platform p11(0.0f,770.0f,800.0f, 50.0f);
Platform p22(400.0f, 660.0f, 400.0f, 110.0f);
Door door11(705.0f, 600.0f, 45.0f, 60.0f);
Door door22(625.0f, 600.0f, 45.0f, 60.0f);
Door door33(705.0f, 350.0f, 45.0f, 60.0f);
Door door44(625.0f, 350.0f, 45.0f, 60.0f);



// Function prototypes
void display();
//void reshape(int, int );
//void keyboardCallbackAqua(unsigned char key, int x, int y);
void keyboardCallback(unsigned char key, int x, int y);
void gameOver();
void update(int value);
void boxMove();
void buttonPressed();
void doorMove();
void gameFinish();
void init();
//void sound();
//void wall();

//void updateIgnis(int value);

int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // Set display mode with double buffering and RGBA color model
    glutInitWindowSize(800,600); // Set initial window size
    glutCreateWindow("AquaIgnis");
    init(); // Create window with a title

    // Register callback functions
    glutDisplayFunc(display); // Function for rendering

    //glutReshapeFunc(reshape); // Function for window resizing
    // Register keyboard callback function
    //glutKeyboardFunc(keyboardCallbackAqua);
    glutKeyboardFunc(keyboardCallback);
    //sndPlaySound("game.wav",SND_SYNC);
     //sound3();
    //glutFullScreen();

    //boxMove();
    //gravity(aqua);
    //glutTimerFunc(1, updateIgnis, 0);
    glutTimerFunc(20, update, 0);
    //glutTimerFunc(1, updateIgnis, 0);
    //gameOver(aqua, ignis);
    // Enter GLUT event loop
    /*createMenu();*/
    glutMainLoop();

    return 0;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    // Put your game rendering code here
    // ...
    if (Level==0)
    {
        backround1.draw();
        play.draw();
        credits.draw();
        //control.draw();

        glColor3f(1.0f,1.0f,1.0f);
        renderBitmapString(play.x+2.0f*play.width/5.0f, play.y+2*play.height/3.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Play");
        renderBitmapString(credits.x+2.0f*credits.width/6.0f, credits.y+2*credits.height/3.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Controls");
        renderBitmapString(500.0f, 720.0f, 0.0f, GLUT_BITMAP_HELVETICA_10, "Press Enter to Select. B to go Back  ");
        renderBitmapString(500.0f, 700.0f, 0.0f, GLUT_BITMAP_HELVETICA_10, "Press S,W to go Toggle");
        //renderBitmapString(500.0f, 700.0f, 0.0f, GLUT_BITMAP_HELVETICA_10, "Press B to go Back");

    }
    if(Level==1)
    {

    backround1.draw();
    a.draw();
    doorAqua.draw();
    doorIgnis.draw();
    p1.draw();
    p2.draw();
    p3.draw();
    p4.draw();
    aqua.draw();
    ignis.draw();
    box.draw();
    maishara.draw();
    lava.draw();
    water.draw();
    button.draw();
    door.draw();
    glColor3f (32.0/255.0, 33.0/255.0, 3.0/255.0);
    renderBitmapString(600.0f, 790.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Press C to Quit ");
    glColor3f (1.0, 1.0, 1.0);
    renderBitmapString(130.0f, 130.0f, 0.0f, GLUT_BITMAP_HELVETICA_12, "AQUA");
    renderBitmapString(50.0f, 130.0f, 0.0f, GLUT_BITMAP_HELVETICA_12, "IGNIS");


    }

    if(Level==100){
        backround1.draw();
        a.draw();
        door11.draw();
        door22.draw();
        aqua.draw();
        ignis.draw();
        //wall2.draw();
        p11.draw();
        p22.draw();
    }

    if(Level == 200){
        backround1.draw();
        a.draw();

    door33.draw();
    door44.draw();
    p1.draw();
    p2.draw();
    p3.draw();
    //p4.draw();
    aqua.draw();
    ignis.draw();
    //box.draw();
    maishara.draw();
    lava.draw();
    water.draw();

    }

    if(Level==2)
    {
        t.draw();
        t.draw2();



    }

    if (Level==3)
    {
        backround1.draw();
        a.draw();
        score.draw();
        glColor3f(1.0f,1.0f,1.0f);
        renderBitmapString(350.0f,350.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Game Over");
        renderBitmapString(320.0f,450.0f, 0.0f, GLUT_BITMAP_HELVETICA_12, "Play Again Press  x !");
        //renderBitmapString(350.0f,401.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Winner : Ignis");

    }
    if (Level==4)
    {
        backround1.draw();
        a.draw();
        score.draw();
        glColor3f(1.0f,1.0f,1.0f);
        renderBitmapString(300.0f,350.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Game Over");
       // renderBitmapString(300.0f,401.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Winner : Aqua");
        renderBitmapString(320.0f,450.0f, 0.0f, GLUT_BITMAP_HELVETICA_12, "Play Again Press  x !");

    }

     if (Level==5)
    {
        backround1.draw();
        a.draw();
        score.draw();
        glColor3f(1.0f,1.0f,1.0f);
        renderBitmapString(300.0f,350.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Game Over");
        //renderBitmapString(300.0f,401.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Winner: Ignis");
        renderBitmapString(320.0f,450.0f, 0.0f, GLUT_BITMAP_HELVETICA_12, "Play Again Press  x !");

    }
     if (Level==6)
    {
        backround1.draw();
        a.draw();
        score.draw();
        glColor3f(1.0f,1.0f,1.0f);
        renderBitmapString(300.0f,350.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "ALL LEVEL COMPLETE");
        //renderBitmapString(300.0f,401.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Aqua Vs Ignis");
        renderBitmapString(320.0f,450.0f, 0.0f, GLUT_BITMAP_HELVETICA_12, "Play Again Press  x !");
    }

     if (Level==7)
    {
        backround1.draw();
        glColor3f(1.0f,1.0f,1.0f);
        renderBitmapString(9.0f,30.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "CONTROLS INSTRUCTION");
        renderBitmapString(9.0f,60.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "**********************************");
        renderBitmapString(9.0f,80.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "AQUA");
        renderBitmapString(9.0f,110.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "-> W to Jump");
        renderBitmapString(9.0f,140.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "-> A to Move Left");
        renderBitmapString(9.0f,170.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "-> D to Move Right");
        renderBitmapString(9.0f,210.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "*******************************");
        renderBitmapString(9.0f,250.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "IGNIS");
        renderBitmapString(9.0f,280.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "-> I to Jump");
        renderBitmapString(9.0f,310.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "-> J to Move Left");
        renderBitmapString(9.0f,340.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "-> L to Move Right");
renderBitmapString(9.0f,380.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "*******************************");
        //renderBitmapString(9.0f,380.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "water kills Ignis ");
        renderBitmapString(9.0f,410.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Fire Kills aqua");
        renderBitmapString(9.0f,440.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Green Toxin kill Both");
        renderBitmapString(9.0f,480.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Reach the Door to Advance");
        renderBitmapString(9.0f,520.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "The Red Character is Ignis");
        renderBitmapString(9.0f,560.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "The Blue Character is Aqua");
        renderBitmapString(9.0f,600.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "water kills Ignis ");


        renderBitmapString(600.0f,750.0f, 0.0f, GLUT_BITMAP_HELVETICA_12, "Press V to Back !");
    }





    glutSwapBuffers(); // Swap the front and back buffers for double buffering
}

void init(void)
{
   // // Set the viewport to match the window size

    // Set the projection matrix and load the identity matrix

  glClearColor(0.0,0.0,0.0,1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 800,800, 0, -1, 1);
  glMatrixMode(GL_MODELVIEW);

}


/*void keyboardCallbackAqua(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': // 'w' key pressed
            // Handle jump action
            aqua.jump();
            break;
        case 'a': // 'a' key pressed
            // Handle move left action
            aqua.moveLeft();
            break;
        case 'd': // 'd' key pressed
            // Handle move right action
            aqua.moveRight();
            break;

    }
    glutPostRedisplay();
}*/
/*
void keyboardCallback(unsigned char key, int x, int y)
{

    if(Level ==2)

    {
        switch(key)
        {
        case '>':
            Level=0;
            break;
        }
    }

    if(Level ==3)

    {
        switch(key)
        {
        case 'm':
            Level=1;
            break;
        }
    }


    if(Level==0)
    {
        switch(key)
        {

        case 's':
            if(play.isSelected)
            {
                play.isSelected=false;
                credits.isSelected=true;
            }
            break;
        case 'w':
            if(credits.isSelected)
            {
                play.isSelected=true;
                credits.isSelected=false;
            }
            break;

        case 'e':
            if(play.isSelected)
            {
                Level=1;
                aqua.x=700.0f;
                aqua.y=560.0f;
                ignis.x =770.0f;
                ignis.y=560.0f;
            }
        break;

        case 'b':

           Level=2;

           break;
        }
    }



    if(Level==1)
    {


    switch (key)
    {
        //For ignis

        case 'i': // 'i' key pressed
            // Handle jump action
            if(ignis.y+ignis.height == p1.y || ignis.y+ignis.height == p2.y || ignis.y+ignis.height == p3.y || ignis.y+ignis.height == p4.y){
                ignis.jump();
                //glutTimerFunc(1, update, 0);
            }

            break;
        case 'j': // 'j' key pressed
            // Handle move left action
            ignis.moveLeft();
            //buttonPressed();
            boxMove();
            break;
        case 'l': // 'l' key pressed
            // Handle move right action
            ignis.moveRight();
            //buttonPressed();
            boxMove();
            break;

        //For aqua

        case 'w': // 'w' key pressed
            // Handle jump action
            if(aqua.y+aqua.height == p1.y || aqua.y+aqua.height == p2.y || aqua.y+aqua.height == p3.y || aqua.y+aqua.height == p4.y){
                aqua.jump();
                //glutTimerFunc(1, update, 0);
            }


            break;
        case 'a': // 'a' key pressed
            // Handle move left action
            aqua.moveLeft();
            //buttonPressed();
            boxMove();
            break;
        case 'd': // 'd' key pressed
            // Handle move right action
            aqua.moveRight();
            //buttonPressed();
            boxMove();
            break;
        // Add more cases for other keys or actions as needed
    }


    }






    glutPostRedisplay();
}*/

float arrY[] ={p1.y, p2.y, p3.y, p4.y, 0.0f};
float arrY0[] ={p11.y, p22.y, p11.y, p11.y, 0.0f};
float arrX[] ={p1.x, p2.x, p3.x, p4.x, 0.0f};
float arrX2[]={p1.x+p1.width, p2.x+p2.width, p3.x+p3.width, p4.x+p4.width, 800.0f};
float arrX0[]={p11.x, p22.x, p11.x, p11.x, 0.0f};
float arrX20[]={p11.x+p11.width, p22.x+p22.width, p11.x+p11.width, p11.x+p11.width, 800.0f};

bool aquaPlatformed =true, ignisPlatformed = true, boxPlatformed = true;

void update(int value) {
    gameOver();
    //gameFinish();
    buttonPressed();
    if(Level==200){
            for(int i=0;i<3;i++){
        if(arrY[i]==aqua.y+aqua.height){
            if(arrX[i]<aqua.x+aqua.width && aqua.x<arrX[i]+arrX2[i])
                {aquaPlatformed = true;
                break;}

        }
        else aquaPlatformed =false;

    }
    for(int i=0;i<3;i++){
        if(arrY[i]==ignis.y+ignis.height){
            if(arrX[i]<ignis.x+ignis.width && ignis.x<arrX[i]+arrX2[i])
                {ignisPlatformed = true;
                break;}
        }
        else ignisPlatformed = false;
    }

    for(int i=0;i<3;i++)
    {
        if(arrY[i]==box.y+box.height){
            if(arrX[i]<box.x+ignis.width && box.x<arrX[i]+arrX2[i])
                {boxPlatformed = true;
                break;}
        }

        else boxPlatformed = false;
    }


    if(aquaJumped==true){
        aquaJumpHeight-=2.0f;
        for(int i=0;i<3;i++){
            if(arrY[i]+p3.height>=aqua.y && arrY[i]<=aqua.y){
                if(arrX[i]<aqua.x+aqua.width && aqua.x<arrX2[i])
                    {aquaCeil = true;
                    break;}
            }
            else aquaCeil = false;
        }
        if(!aquaCeil) aqua.y+=aquaJumpHeight;

        if(aquaJumpHeight<=-35.0f){
            aquaJumpHeight=0.0f;
            aquaJumped=false;
            aquaCeil =false;
        }
    }

    if(ignisJumped==true){
        ignisJumpHeight-=2.0f;
        for(int i=0;i<3;i++){
            if(arrY[i]+p3.height>=ignis.y && arrY[i]<=ignis.y){
                if(arrX[i]<ignis.x+ignis.width && ignis.x<arrX2[i])
                    {ignisCeil = true;
                    break;}
            }
            else ignisCeil = false;
        }
        if(!ignisCeil) ignis.y+=ignisJumpHeight;

        if(ignisJumpHeight<=-35.0f){
            ignisJumpHeight=0.0f;
            ignisJumped=false;
            ignisCeil =false;
        }
    }
    }
    if(Level == 1){
    for(int i=0;i<4;i++){
        if(arrY[i]==aqua.y+aqua.height){
            if(arrX[i]<aqua.x+aqua.width && aqua.x<arrX[i]+arrX2[i])
                {aquaPlatformed = true;
                break;}

        }
        else aquaPlatformed =false;

    }
    for(int i=0;i<4;i++){
        if(arrY[i]==ignis.y+ignis.height){
            if(arrX[i]<ignis.x+ignis.width && ignis.x<arrX[i]+arrX2[i])
                {ignisPlatformed = true;
                break;}
        }
        else ignisPlatformed = false;
    }

    for(int i=0;i<4;i++)
    {
        if(arrY[i]==box.y+box.height){
            if(arrX[i]<box.x+ignis.width && box.x<arrX[i]+arrX2[i])
                {boxPlatformed = true;
                break;}
        }

        else boxPlatformed = false;
    }


    if(aquaJumped==true){
        aquaJumpHeight-=2.0f;
        for(int i=0;i<5;i++){
            if(arrY[i]+p3.height>=aqua.y && arrY[i]<=aqua.y){
                if(arrX[i]<aqua.x+aqua.width && aqua.x<arrX2[i])
                    {aquaCeil = true;
                    break;}
            }
            else aquaCeil = false;
        }
        if(!aquaCeil) aqua.y+=aquaJumpHeight;

        if(aquaJumpHeight<=-35.0f){
            aquaJumpHeight=0.0f;
            aquaJumped=false;
            aquaCeil =false;
        }
    }

    if(ignisJumped==true){
        ignisJumpHeight-=2.0f;
        for(int i=0;i<5;i++){
            if(arrY[i]+p3.height>=ignis.y && arrY[i]<=ignis.y){
                if(arrX[i]<ignis.x+ignis.width && ignis.x<arrX2[i])
                    {ignisCeil = true;
                    break;}
            }
            else ignisCeil = false;
        }
        if(!ignisCeil) ignis.y+=ignisJumpHeight;

        if(ignisJumpHeight<=-35.0f){
            ignisJumpHeight=0.0f;
            ignisJumped=false;
            ignisCeil =false;
        }
    }
    }

    if(Level == 100){
        for(int i=0;i<4;i++){
        if(arrY0[i]==aqua.y+aqua.height){
            if(arrX0[i]<aqua.x+aqua.width && aqua.x<arrX0[i]+arrX20[i])
                {aquaPlatformed = true;
                break;}

        }
        else aquaPlatformed =false;

        }

        for(int i=0;i<4;i++){
        if(arrY0[i]==ignis.y+ignis.height){
            if(arrX0[i]<ignis.x+ignis.width && ignis.x<arrX0[i]+arrX20[i])
                {ignisPlatformed = true;
                break;}
        }
        else ignisPlatformed = false;
    }

    if(aquaJumped==true){
        aquaJumpHeight-=2.0f;
        for(int i=0;i<5;i++){
            if(arrY0[i]+p11.height>=aqua.y && arrY0[i]<=aqua.y){
                if(arrX0[i]<aqua.x+aqua.width && aqua.x<arrX20[i])
                    {aquaCeil = true;
                    break;}
            }
            else aquaCeil = false;
        }
        if(!aquaCeil) aqua.y+=aquaJumpHeight;

        if(aquaJumpHeight<=-35.0f){
            aquaJumpHeight=0.0f;
            aquaJumped=false;
            aquaCeil =false;
        }
    }

    if(ignisJumped==true){
        ignisJumpHeight-=2.0f;
        for(int i=0;i<5;i++){
            if(arrY0[i]+p11.height>=ignis.y && arrY0[i]<=ignis.y){
                if(arrX0[i]<ignis.x+ignis.width && ignis.x<arrX20[i])
                    {ignisCeil = true;
                    break;}
            }
            else ignisCeil = false;
        }
        if(!ignisCeil) ignis.y+=ignisJumpHeight;

        if(ignisJumpHeight<=-35.0f){
            ignisJumpHeight=0.0f;
            ignisJumped=false;
            ignisCeil =false;
        }
    }
    }

    if(!boxPlatformed) box.y+=2.0f;

    if(!aquaJumped && !aquaPlatformed) aqua.y+=2.0f;

    if(!ignisJumped && !ignisPlatformed) ignis.y+=2.0f;

    glutPostRedisplay();
    glutTimerFunc(10, update, 0);
}

void boxMove()
{

    if(aqua.x<=aqua.width || aqua.x>=770.0f || ignis.x<=ignis.width || ignis.x>=770.0f) return;
    if(box.y==aqua.y){
        if(aqua.x+aqua.width>=box.x && aqua.x<box.x){
            box.x=aqua.x+aqua.width;
        }
        if(aqua.x<=box.x+box.width && aqua.x+aqua.width>box.x){
            box.x=aqua.x-box.width;
        }
    }
    if(box.y==ignis.y){
        if(ignis.x+ignis.width>=box.x && ignis.x<box.x){
            box.x=ignis.x+ignis.width;
        }

        if(ignis.x<=box.x+box.width && ignis.x+ignis.width>box.x){
            box.x=ignis.x-box.width;
        }
    }


    glutPostRedisplay();
}

void buttonPressed()
{
    if(aqua.y+aqua.height==button.y && aqua.x+aqua.width>button.x && aqua.x<button.x+button.width){
        button.isPressed=true;
    }
    else if(ignis.y+ignis.height==button.y && ignis.x+ignis.width>button.x && ignis.x<button.x+button.width){
        button.isPressed=true;
    }
    else if(box.y+box.height==button.y && box.x+box.width>button.x && box.x<button.x+button.width){
        button.isPressed=true;
    }
    else{
        button.isPressed=false;
    }
    doorMove();
    glutPostRedisplay();
}

void doorMove()
{
    if(button.isPressed==true){
        door.height=0.0f;
        door.isOpen = true;
    }
    else {
        door.height=200.0f;
        door.isOpen=false;
    }

    if (!door.isOpen){
        if (ignis.x + ignis.width >= door.x && ignis.x <= door.x + door.width && ignis.y + ignis.height >= door.y && ignis.y <= door.y + door.height) {
            // Set Ignis's position to just outside the door
            ignis.x = door.x + door.width;

            }

    }


    if (!door.isOpen){
            if (aqua.x + aqua.width >= door.x && aqua.x <= door.x + door.width && aqua.y + aqua.height >= door.y && aqua.y <= door.y + door.height){
            // Set Ignis's position to just outside the door
            aqua.x = door.x + aqua.width;

            }

    }


}

void gameOver()
{
    if(Level == 1){
    if(aqua.y+aqua.height==maishara.y && aqua.x+aqua.width>maishara.x && aqua.x<maishara.x+maishara.width)
    {
        Level =3;
        /*aqua.x=900.0f;
        aqua.y=900.0f;
        ignis.x=900.0f;
        ignis.y=900.0f;*/
    }


    if(ignis.y+ignis.height==maishara.y && ignis.x+ignis.width>maishara.x && ignis.x<maishara.x+maishara.width)
    {
        Level = 4;
    }
    if(aqua.y+aqua.height==lava.y && aqua.x+aqua.width>lava.x && aqua.x<lava.x+lava.width)
    {
        Level = 5;
    }
    if(ignis.y+ignis.height==water.y && ignis.x+ignis.width>water.x && ignis.x<water.x+water.width)
    {
        Level = 4;
    }
    if(ignis.y+ignis.height==doorIgnis.y+doorIgnis.height && ignis.x+ignis.width>doorIgnis.x && ignis.x<doorIgnis.x+doorIgnis.width && aqua.y+aqua.height==doorAqua.y+doorAqua.height && aqua.x+aqua.width>doorAqua.x && aqua.x<doorAqua.x+doorAqua.width)
        {
        Level = 6;
        }
    }
    if(Level==100){
        if(ignis.y+ignis.height==door11.y+door11.height && ignis.x+ignis.width>door11.x && ignis.x<door11.x+door11.width && aqua.y+aqua.height==door22.y+door22.height && aqua.x+aqua.width>door22.x && aqua.x<door22.x+door22.width)
        {
        Level = 200;
        aqua.x = 700.0f;
        aqua.y = 560.0f;
        ignis.x = 770.0f;
        ignis.y = 560.0f;
        box.x=300.0f;
        box.y=80.0f;
        sound();
        }
    }
    if(Level==200){
        if(ignis.y+ignis.height==door33.y+door33.height && ignis.x+ignis.width>door33.x && ignis.x<door33.x+door33.width && aqua.y+aqua.height==door44.y+door44.height && aqua.x+aqua.width>door44.x && aqua.x<door44.x+door44.width)
        {
        Level = 1;
        aqua.x = 20.0f;
                    aqua.y = 700.0f;
                    ignis.x = 100.0f;
                    ignis.y = 700.0f;
                    box.x = 300.0f;
                    box.y = 80.0f;
        sound();
        }
        if(ignis.y+ignis.height==maishara.y && ignis.x+ignis.width>maishara.x && ignis.x<maishara.x+maishara.width)
    {
        Level = 4;
    }
    if(aqua.y+aqua.height==maishara.y && aqua.x+aqua.width>maishara.x && aqua.x<maishara.x+maishara.width)
    {
        Level =3;
        /*aqua.x=900.0f;
        aqua.y=900.0f;
        ignis.x=900.0f;
        ignis.y=900.0f;*/
    }
    if(aqua.y+aqua.height==lava.y && aqua.x+aqua.width>lava.x && aqua.x<lava.x+lava.width)
    {
        Level = 5;
    }
    if(ignis.y+ignis.height==water.y && ignis.x+ignis.width>water.x && ignis.x<water.x+water.width)
    {
        Level = 4;
    }
    }
}

/*
void gameFinish()
{
    if(ignis.y+ignis.height==doorIgnis.y+doorIgnis.height && ignis.x+ignis.width>doorIgnis.x && ignis.x<doorIgnis.x+doorIgnis.width && aqua.y+aqua.height==doorAqua.y+doorAqua.height && aqua.x+aqua.width>doorAqua.x && aqua.x<doorAqua.x+doorAqua.width){
        aqua.x=0.0f;
        aqua.y=0.0f;
        ignis.x=0.0f;
        ignis.y=0.0f;
        Level = 0;
    }
}*/


void keyboardCallback(unsigned char key, int x, int y)
{
   if (key == 'x')
    {
        Level = 100;
        aqua.x = 20.0f;
        aqua.y = 700.0f;
        ignis.x = 100.0f;
        ignis.y = 700.0f;
        sound();
    }

    if (Level == 2)
        {
        switch (key) {
            case 13:
                Level = 0;
                break;
        }
    }

    else if (Level == 3)
        {
        switch (key)
        {
            case 'm':
                Level = 1;
                break;
        }
    }

    else if (Level == 0)
    {

        switch (key) {
            case 's':
                if (play.isSelected) {
                    play.isSelected = false;
                    credits.isSelected = true;
                }
                break;
            case 'w':
                if (credits.isSelected) {
                    play.isSelected = true;
                    credits.isSelected = false;
                }
                break;
            case 13:
                if (play.isSelected)
                {
                    Level = 100;
                    aqua.x = 20.0f;
                    aqua.y = 560.0f;
                    ignis.x = 100.0f;
                    ignis.y = 560.0f;
                    //box.x = 300.0f;
                    //box.y = 80.0f;
                    sound();
                }

                else if (credits.isSelected)
                {
                    Level=7;

                }
                break;

            case 'b':
                Level = 2;
                break;


        }
    }




     else if (Level == 7)
    {

        switch (key)
        {
            case 'v':
                Level=0;
                break;
        }
    }

    else if(Level == 100){
        switch(key){
            // For ignis
            case 'i':
                // Handle jump action
                if (ignis.y + ignis.height == p11.y || ignis.y + ignis.height == p22.y) {
                    ignis.jump();
                    sound1();
                    //glutTimerFunc(1, update, 0);
                }
                break;
            case 'j': // 'j' key pressed
                // Handle move left action

                ignis.moveLeft();

                //buttonPressed();
                boxMove();
                sound1();
                break;
            case 'l': // 'l' key pressed
                // Handle move right action
                if(ignis.x >= 370.0 && ignis.y+ignis.height >= 670.0f){
                    ignis.x =370.0f;
                    return;
                }

                ignis.moveRight();
                //buttonPressed();
                //boxMove();
                sound1();
                break;
            // For aqua
            case 'w': // 'w' key pressed
                // Handle jump action
                if (aqua.y + aqua.height == p11.y || aqua.y + aqua.height == p22.y ) {
                    aqua.jump();
                    sound2();
                    //glutTimerFunc(1, update, 0);
                }
                break;
            case 'a': // 'a' key pressed
                // Handle move left action
                aqua.moveLeft();
                //buttonPressed();
                //boxMove();
                sound2();
                break;
            case 'd': // 'd' key pressed
                // Handle move right action
                if(aqua.x >= 370.0 && aqua.y+aqua.height >= 670.0f){
                    aqua.x =370.0f;
                    return;
                }

                aqua.moveRight();
                //buttonPressed();
                //boxMove();
                sound2();
                break;

            case 'c' :
                Level=0;
                break;
        }
    }


    else if (Level == 1)
        {
        switch (key) {
            // For ignis
            case 'i':
                // Handle jump action
                if (ignis.y + ignis.height == p1.y || ignis.y + ignis.height == p2.y || ignis.y + ignis.height == p3.y || ignis.y + ignis.height == p4.y) {
                    ignis.jump();
                    sound1();
                    //glutTimerFunc(1, update, 0);
                }
                break;
            case 'j': // 'j' key pressed
                // Handle move left action
                ignis.moveLeft();
                //buttonPressed();
                boxMove();
                sound1();
                break;
            case 'l': // 'l' key pressed
                // Handle move right action
                ignis.moveRight();
                //buttonPressed();
                boxMove();
                sound1();
                break;
            // For aqua
            case 'w': // 'w' key pressed
                // Handle jump action
                if (aqua.y + aqua.height == p1.y || aqua.y + aqua.height == p2.y || aqua.y + aqua.height == p3.y || aqua.y + aqua.height == p4.y) {
                    aqua.jump();
                    sound2();
                    //glutTimerFunc(1, update, 0);
                }
                break;
            case 'a': // 'a' key pressed
                // Handle move left action
                aqua.moveLeft();
                //buttonPressed();
                boxMove();
                sound2();
                break;
            case 'd': // 'd' key pressed
                // Handle move right action
                aqua.moveRight();
                //buttonPressed();
                boxMove();
                sound2();
                break;

            case 'c' :
                Level=0;
                break;
            // Add more cases for other keys or actions as needed
        }
    }

    else if (Level == 200)
        {
        switch (key) {
            // For ignis
            case 'i':
                // Handle jump action
                if (ignis.y + ignis.height == p1.y || ignis.y + ignis.height == p2.y || ignis.y + ignis.height == p3.y) {
                    ignis.jump();
                    sound1();
                    //glutTimerFunc(1, update, 0);
                }
                break;
            case 'j': // 'j' key pressed
                // Handle move left action
                ignis.moveLeft();
                //buttonPressed();
                boxMove();
                sound1();
                break;
            case 'l': // 'l' key pressed
                // Handle move right action
                ignis.moveRight();
                //buttonPressed();
                boxMove();
                sound1();
                break;
            // For aqua
            case 'w': // 'w' key pressed
                // Handle jump action
                if (aqua.y + aqua.height == p1.y || aqua.y + aqua.height == p2.y || aqua.y + aqua.height == p3.y) {
                    aqua.jump();
                    sound2();
                    //glutTimerFunc(1, update, 0);
                }
                break;
            case 'a': // 'a' key pressed
                // Handle move left action
                aqua.moveLeft();
                //buttonPressed();
                boxMove();
                sound2();
                break;
            case 'd': // 'd' key pressed
                // Handle move right action
                aqua.moveRight();
                //buttonPressed();
                boxMove();
                sound2();
                break;

            case 'c' :
                Level=0;
                break;
            // Add more cases for other keys or actions as needed
        }
    }
    glutPostRedisplay();
}
