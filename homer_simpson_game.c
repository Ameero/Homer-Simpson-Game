/* --- THE HOMER SIMPSON GAME      -------------------------------
------------------------------------------------------------------
--- An Interactive Animation of Homer Simpson (fat guy from the --
--- Simpsons who likes donuts and causing nuclear disasters.)    -
--- Made using OpenGL and C...;-) obviously....                  -

By: AMEER ALI...   web: http://ameero.com email:ameer1@gmail.com   

Keys: R - Reset, 
Left mouse click : Bullet Time
Right Mouse Click : spin camera in bullet time
Number keys 1, 2, 3 various acrobatics 
D : Eat Donut
F/ I: interact with surroundings (use near furniture or to kick football

Windows Only - Needs glut.h for OpenGL graphics

*/

#include <GL/glut.h> /* The GLUT toolkit includes the necessary files */
                     /* automatically where they are needed. */
#include <stdlib.h>


/* Display list identifiers */
/* ------------------------------------------------------------------
Display list identifiers for Body Parts */
static GLuint Torso= 1;
static GLuint UppLeftArm= 2;
static GLuint LwrLeftArm= 3;
static GLuint UppRightArm= 4;
static GLuint LwrRightArm= 5;
static GLuint UppRightLeg= 6;
static GLuint LwrRightLeg= 7;
static GLuint UppLeftLeg= 6;
static GLuint LwrLeftLeg= 7;
static GLuint HomerHead= 8;
/* Display list identifiers for Room */
static GLuint FloorPlane= 9;
static GLuint BackWall1= 10;
static GLuint BackWall2= 11;
static GLuint BackWall3= 12;
static GLuint LeftWall1= 13;
static GLuint RightWall1= 14;
static GLuint FrontWall1= 15;
static GLuint Ceiling= 16;
/* Display list identifiers for Room Objects */
static GLuint Lamp1= 17;
static GLuint Sofa= 18;
static GLuint Carpet1= 19;
static GLuint Picture1= 20;
static GLuint Football1= 21;
static GLuint Goal= 22;



#define SPIN	1
#define STOP	2
#define QUIT	3
GLint toggle = 0;
void menu (int);
/* ------------------------------------------------------------------*/



/* Variables */
static GLfloat spin = 0.0;
static GLfloat ZRotate = 0.0;
static GLfloat XRotate = 0.0;
static GLfloat HeadTurn = 0.0;
static GLfloat HeadNod = 0.0;

static GLfloat BodyTurn = 0.0;

static GLfloat MoveX= 0.0;
static GLfloat MoveY= 0.0;
static GLfloat MoveZ= 0.0;

static GLfloat SofaX= 15.0;
static GLfloat SofaY= -8.75;
static GLfloat SofaZ= -14.0;

/*static GLfloat MoveX= -23.0;
static GLfloat MoveY= 0.0;
static GLfloat MoveZ= -28.0;
 */

static GLfloat FootballX= -28.0;
static GLfloat FootballY= -9.0;
static GLfloat FootballZ= 36;


static GLfloat SofaAngle1= 0.0;

static GLfloat LampAngle1= 0.0;
static GLfloat Pic1Angle1= 0.0;
static GLfloat Pic1Y= 10.0;



/* Spin the Carpet... */
static GLfloat CarpetSpin= 0.0;

static GLfloat UpperRightLegAngleY= 0.0;
static GLfloat UpperRightLegAngleX= 0.0;
static GLfloat LowerRightLegAngleY= 0.0;
static GLfloat LowerRightLegAngleX= 0.0;

static GLfloat UpperLeftLegAngleY= 0.0;
static GLfloat UpperLeftLegAngleX= 0.0;
static GLfloat LowerLeftLegAngleY= 0.0;
static GLfloat LowerLeftLegAngleX= 0.0;

static GLfloat UpperLeftLegAngleZ= 0.0;
static GLfloat UpperRightLegAngleZ= 0.0;

static GLfloat UpperRightArmAngleY= 0.0;
static GLfloat UpperRightArmAngleX= 0.0;
static GLfloat LowerRightArmAngleY= 0.0;
static GLfloat LowerRightArmAngleX= 0.0;

static GLfloat UpperLeftArmAngleY= 0.0;
static GLfloat UpperLeftArmAngleX= 0.0;
static GLfloat LowerLeftArmAngleY= 0.0;
static GLfloat LowerLeftArmAngleX= 0.0;

static GLfloat UpperRightArmAngleZ= 0.0;
static GLfloat UpperLeftArmAngleZ= 0.0;

static GLuint time= 0;


static GLuint Fliptimer= 0;







/* --OBJECT AND MATERIAL PROPERTIES----------------------------------*/

GLfloat no_mat[] = {0.0f, 0.0f, 0.0f, 1.0f};

GLfloat mat_specularWHITE[] ={255.0,255.0,255.0,1.0};
GLfloat mat_ambientWHITE[] ={255.0,255.0,255.0,1.0};
GLfloat mat_diffuseWHITE[] ={255.0,255.0,255.0,1.0};
GLfloat mat_shininessWHITE[] ={128.0 * 0.4};

GLfloat mat_specularGRAY[] ={0.75,0.75,0.75,1.0};
GLfloat mat_ambientGRAY[] ={0.5,0.5,0.5,1.0};
GLfloat mat_diffuseGRAY[] ={0.50,0.50,0.50,1.0};
GLfloat mat_shininessGRAY[] ={128.0 * 0.6};

GLfloat mat_specularBLUE[] ={0.75,0.75,0.75,1.0};
GLfloat mat_ambientBLUE[] ={0,0,1,1.0};
GLfloat mat_diffuseBLUE[] ={0.50,0.50,0.50,1.0};
GLfloat mat_shininessBLUE[] ={128.0 };

GLfloat mat_specularGREEN[] ={0.633, 0.727811, 0.633,1.0};
GLfloat mat_ambientGREEN[] ={0.0215, 0.1745, 0.0215,1.0};
GLfloat mat_diffuseGREEN[] ={0.07568, 0.61424, 0.07568,1.0};
GLfloat mat_shininessGREEN[] ={128.0};

GLfloat mat_specularYELLOW[] ={0.75,0.75,0.75,1.0};
GLfloat mat_ambientYELLOW[] ={1,1,0,1.0};
GLfloat mat_diffuseYELLOW[] ={0.50,0.50,0.50,1.0};
GLfloat mat_shininessYELLOW[] ={128.0};

GLfloat mat_specularRED[] ={0.75,0.75,0.75,1.0};
GLfloat mat_ambientRED[] ={1.0,0.0,0.0,1.0};
GLfloat mat_diffuseRED[] ={0.50,0.50,0.50,1.0};
GLfloat mat_shininessRED[] ={128.0};

GLfloat mat_specularBLACK[] ={0.0,0.0,0.0,1.0};
GLfloat mat_ambientBLACK[] ={0.0,0.0,255.0,1.0};
GLfloat mat_diffuseBLACK[] ={0.0,0.0,0.0,1.0};
GLfloat mat_shininessBLACK[] ={0.0 * 0.4};

GLfloat mat_specularYELLOWSKIN[] ={0.75,0.75,0.75,1.0};
GLfloat mat_ambientYELLOWSKIN[] ={1.0, 0.8, 0.0, 1.0};
GLfloat mat_diffuseYELLOWSKIN[] ={0.50,0.50,0.50,1.0};
GLfloat mat_shininessYELLOWSKIN[] ={128.0 };





/*---------------------------------------------------------------*/
void myDrawTorso(void)  /* Draw the main  Torso of Homer Simpson*/
{  

  GLUquadricObj *qobj;


  GLfloat diffW[] = {1.0, 1.0, 1.0, 1.0}; /* diffuse reflection. */  
  GLfloat diffb[] = {0.5, 0.5, 0.5, 1.0};
 
  /* Set the material properties. */
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diffW);


  /* Set up and draw the quadric. */
  qobj = gluNewQuadric();
  gluQuadricDrawStyle(qobj,GLU_FILL);
  gluQuadricNormals(qobj,GLU_SMOOTH);
  /* rotate by -90 degrees about the x-axis so the quadric is aligned along the y-axis */
  glRotated(-90.0,1.0,0.0,0.0); 
  

  /*Draws the most important part of Homer Simpson... His BELLY!!...
   --- Has to be big...round..and authentic beer belly. --- */
  glScaled(1.2, 1.0, 1.0);
  gluSphere(qobj,2.5,30,30);


  /*Draws Lower Abdomon Region.. Gets rid of Egg shape!!
   -- and makes the place ready for adding legs... !! Yipee*/
  glTranslated(0.0,0.0,-3.9);
  gluCylinder(qobj,2.5,2.5,3.9,30,30);

 
   /*shirt collar*/
  
	glTranslated(0.0,0.0,3.5);
 
  gluCylinder(qobj,2.4,0.5,3.0,30,30);
  
	/* Belt */
    glTranslated(0.0,0.0,-4.0);
  gluCylinder(qobj,2.6,2.5,0.6,30,30);

 }



/*---------------------------------------------------------------*/

void myDrawHomerHead(void)

{  
 GLUquadricObj *qobj;

  GLfloat spec[] = {0.0, 0.0, 0.0, 1.0}; /* specular reflection. */
  GLfloat diffY[] = {1.0, 0.8, 0.0, 1.0}; /* diffuse reflection. */  
  GLfloat diffB[] = {0.0, 0.0, 0.0, 0.0};
  GLfloat diffW[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat diffBR[] = {0.5, 0.3, 0.1, 1.0};

  qobj = gluNewQuadric();

  gluQuadricDrawStyle(qobj,GLU_FILL);
  gluQuadricNormals(qobj,GLU_SMOOTH);



 /* Set the material properties. */
  glMaterialf(GL_FRONT, GL_SHININESS, 10);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diffY);


  

  glRotated(-90.0,1.0,0.0,0.0);


glPushMatrix();

 /*HEAD IS DRAWN*/

 glPushMatrix();
 glTranslated(0.0,0.0,-2.5);
 glScaled(1.0, 1.15, 1.5);
  gluSphere(qobj,1.30,30,30);
  glTranslated(0.0,0.0,-3.4);
 gluCylinder(qobj,1.30,1.30,3.5,30,30);
glPopMatrix();

  
  glMaterialf(GL_FRONT, GL_SHININESS, 100);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
glMaterialfv(GL_FRONT, GL_DIFFUSE, diffW);
 
/*LEFT EYE*/ 
 glPushMatrix();
 glTranslated(0.595,-1.0,-2.3);
 gluSphere(qobj,0.6,30,30);
 glPopMatrix();

/*RIGHT EYE*/
 glPushMatrix();
 glTranslated(-0.595,-1.0,-2.3);
 gluSphere(qobj,0.6,30,30);
 glPopMatrix();


 glMaterialfv(GL_FRONT, GL_DIFFUSE, diffB);
/*LEFT PUPIL*/
 glPushMatrix();
 glTranslated(0.595,-1.50,-2.2);
 gluSphere(qobj,0.175,30,30);
 glPopMatrix();




/*RIGHT PUPIL*/
 glPushMatrix();
 glTranslated(-0.595,-1.50,-2.2);
 gluSphere(qobj,0.175,30,30);
 glPopMatrix();


 
 
 glMaterialfv(GL_FRONT, GL_DIFFUSE, diffBR);
 /*MOUTH PART*/ 
 glPushMatrix();
glTranslated(0.0,-1.0,-3.3);
glutSolidCone(1.2,1.2,22,22);

glRotated(180.0,1.0,0.0,0.0);
glutSolidCone(1.2,1.2,22,22);
 glPopMatrix();



 glMaterialfv(GL_FRONT, GL_DIFFUSE, diffY);


/*THE NOSE*/
 glTranslated(0.0,0.0,-2.5);
  glRotated(90.0,1.0,0.0,0.0);
 gluCylinder(qobj,0.25,0.25,2.2,30,30);
 glTranslated(0.0,0.0,2.2);
gluSphere(qobj,0.25,30,30);



 /*THE EARS*/
glPushMatrix();
glTranslated(-1.3,0.0,-2.4);
gluSphere(qobj,0.25,30,30);
glPopMatrix();

 glPushMatrix();
 glTranslated(1.3,0.0,-2.4);
gluSphere(qobj,0.25,30,30);
glPopMatrix();


/*THE HAIR*/

glMaterialfv(GL_FRONT, GL_DIFFUSE, diffB);
glPushMatrix();


glRotated(70.0,1.0,0.0,0.0);
glRotated(20.0,0.0,0.0,1.0);

glTranslated(0.6,-1.8,0.0);


glTranslated(0.0,0.0,-1.9);

gluCylinder(qobj,0.06,0.06,0.8,30,30);

gluSphere(qobj,0.06,30,30);
glTranslated(0.0,0.0,0);

glRotated(-321.0,1.0,0.0,0.0);
gluCylinder(qobj,0.06,0.06,0.8,30,30);

glPopMatrix();

glPushMatrix();


glRotated(70.0,1.0,0.0,0.0);
glRotated(20.0,0.0,0.0,1.0);
glRotated(8.0,0.0,1.0,0.0);
glTranslated(0.8,-2.3,-0.1);


glTranslated(0.0,0.0,-1.9);

gluCylinder(qobj,0.06,0.06,0.8,30,30);

gluSphere(qobj,0.06,30,30);


glRotated(-321.0,1.0,0.0,0.0);
glRotated(-18.0,0.0,1.0,0.0);
gluCylinder(qobj,0.06,0.06,0.8,30,30);

glPopMatrix();





/*THE RIGHT SIDE*/

glPushMatrix();


glRotated(70.0,1.0,0.0,0.0);
glRotated(20.0,0.0,0.0,1.0);

glTranslated(-2.0,-1.8,0.0);


glTranslated(0.0,0.0,-1.9);

gluCylinder(qobj,0.06,0.06,0.8,30,30);

gluSphere(qobj,0.06,30,30);
glTranslated(0.0,0.0,0);

glRotated(-321.0,1.0,0.0,0.0);
gluCylinder(qobj,0.06,0.06,0.8,30,30);

glPopMatrix();

glPushMatrix();


glRotated(70.0,1.0,0.0,0.0);
glRotated(20.0,0.0,0.0,1.0);
glRotated(4.0,0.0,1.0,0.0);
glTranslated(-1.7,-1.3,0.0);


glTranslated(0.0,0.0,-1.9);

gluCylinder(qobj,0.06,0.06,0.8,30,30);

gluSphere(qobj,0.06,30,30);


glRotated(-321.0,1.0,0.0,0.0);
glRotated(-18.0,0.0,1.0,0.0);
gluCylinder(qobj,0.06,0.06,0.8,30,30);

glPopMatrix();

/*TOP OF HIS HEAD... 3 HAIRS :-P */

glPushMatrix();

glTranslated(-0.5,2.0,-2.0);
glRotated(75.0,0.0,1.0,0.0);
gluCylinder(qobj,0.04,0.04,0.8,30,30);
gluSphere(qobj,0.04,30,30);

glRotated(110.0,1.0,0.0,0.0);
gluCylinder(qobj,0.04,0.04,0.4,30,30);
gluSphere(qobj,0.04,30,30);
glPopMatrix();

glPushMatrix();

glTranslated(0.655,1.95,-1.755);
glRotated(90.0,0.0,1.0,0.0);
glPushMatrix();

glRotated(45.0,1.0,0.0,0.0);
gluCylinder(qobj,0.04,0.04,0.2,30,30);
gluSphere(qobj,0.04,30,30);

glPopMatrix();

glRotated(190.0,1.0,0.0,0.0);
gluCylinder(qobj,0.04,0.04,0.4,30,30);
gluSphere(qobj,0.04,30,30);
glPopMatrix();


glPushMatrix();

glTranslated(-0.5,1.905,-2.35);

glRotated(95.0,0.0,1.0,0.0);
gluCylinder(qobj,0.04,0.04,1.3,30,30);
gluSphere(qobj,0.04,30,30);

glRotated(129.0,1.0,0.0,0.0);
gluCylinder(qobj,0.04,0.04,0.4,30,30);
gluSphere(qobj,0.04,30,30);
glPopMatrix();


glPushMatrix();

glTranslated(-0.5,1.905,-2.05);

glRotated(95.0,0.0,1.0,0.0);
gluCylinder(qobj,0.04,0.04,1.3,30,30);
gluSphere(qobj,0.04,30,30);

glRotated(129.0,1.0,0.0,0.0);
gluCylinder(qobj,0.04,0.04,0.4,30,30);
gluSphere(qobj,0.04,30,30);
glPopMatrix();



glPopMatrix();


}



/*----------------------------------------------- ----------------*/
void myDrawUppLeftArm(void)  /* Draw the Left Arm of Homer Simpson*/
{  

  GLUquadricObj *qobj;


  /* Set the material properties. */
  GLfloat spec[] = {0.0, 0.0, 0.0, 1.0}; /* specular reflection. */
  GLfloat diffY[] = {1.0, 0.8, 0.0, 1.0}; /* diffuse reflection. */  
  GLfloat diffB[] = {0.0, 0.0, 0.0, 0.0};
  GLfloat diffW[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat diffBR[] = {0.4, 0.2, 0.1, 1.0};


glMaterialf(GL_FRONT, GL_SHININESS, 0);
glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuseYELLOWSKIN);



  /* Set up and draw the quadric. */
  qobj = gluNewQuadric();
  gluQuadricDrawStyle(qobj,GLU_FILL);
  gluQuadricNormals(qobj,GLU_SMOOTH);
  /* rotate by -90 degrees about the x-axis so the quadric is aligned along the y-axis     */
  glRotated(90.0,1.0,0.0,0.0);
 
  /* Draw the Shoulder .. part of shirt*/
  gluSphere(qobj,0.8,30,30);
  /* Draw Sleeve of Shirt Upper Arm - should be white, as it is his shirt  */
glRotated(30.0,0.0,1.0,0.0);
 
  gluCylinder(qobj,0.8,0.8,2.0,22,22);

  
  /*This draws part of his shirt sleeve..white */
  glTranslated(0.0,0.0,1.55);
  gluCylinder(qobj,0.8,1.0,1.4,22,22);


glMaterialfv(GL_FRONT, GL_DIFFUSE, diffY);

  /*This sraws part of his upper arm.. should be Yellow.. */
   glTranslated(0.0,0.0,1.4);
  gluCylinder(qobj,0.7,0.7,1.4,22,22);
   
  /*elbow Joint */
  glTranslated(0.0,0.0,1.3);
  gluSphere(qobj,0.7,30,30);



 }



/*---------------------------------------------------------------*/
void myDrawLwrLeftArm(void)

{  

  GLUquadricObj *qobj;

  /* Set the material properties. */
  GLfloat spec[] = {0.0, 0.0, 0.0, 1.0}; /* specular reflection. */
  GLfloat diffY[] = {1.0, 0.8, 0.0, 1.0}; /* diffuse reflection. */  
  GLfloat diffB[] = {0.0, 0.0, 0.0, 0.0};
  GLfloat diffW[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat diffBR[] = {0.4, 0.2, 0.1, 1.0};


glMaterialf(GL_FRONT, GL_SHININESS, 0);
glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
glMaterialfv(GL_FRONT, GL_DIFFUSE, diffY);

  /* Set up and draw the quadric. */
  qobj = gluNewQuadric();
  gluQuadricDrawStyle(qobj,GLU_FILL);
  gluQuadricNormals(qobj,GLU_SMOOTH);



 
  gluCylinder(qobj,0.7,0.5,1.9,22,22);
 
  /*Draw the hands... with 4 fingers*/
  glPushMatrix();
  glTranslated(0.0,0.0,2.2);
  glScaled(1.0, 2.0, 1.0);
  gluSphere(qobj,0.5,30,30);


   /*Finger 1*/
  glPushMatrix();
  glTranslated(0.0,0.0,0.0);
  gluCylinder(qobj,0.2,0.2,1.2,22,22);
  glTranslated(0.0,0.0,1.2);
  gluSphere(qobj,0.2,30,30);
  glPopMatrix();

   /*Finger 2*/
  glPushMatrix();
  glRotated(22.0,1.0,0.0,0.0);
  glTranslated(0.0,0.0,0.4);
  gluCylinder(qobj,0.2,0.2,0.8,22,22);
  glTranslated(0.0,0.0,0.8);
  gluSphere(qobj,0.2,30,30);
   glPopMatrix();


   /*Finger 3*/
  glPushMatrix();
  glRotated(35.0,1.0,0.0,0.0);
  glTranslated(0.0,-0.2,0.0);
  gluCylinder(qobj,0.2,0.2,0.8,22,22);
  glTranslated(0.0,0.0,0.8);
  gluSphere(qobj,0.2,30,30);
   glPopMatrix();

  /*Finger 4*/
  glPushMatrix();
  glRotated(-30.0,1.1,0.0,0.0);
  glTranslated(0.0,0.0,0.1);
  gluCylinder(qobj,0.2,0.2,0.8,22,22);
  glTranslated(0.0,0.0,0.8);
  gluSphere(qobj,0.2,30,30);
   glPopMatrix();



  glPopMatrix();


}




/*---------------------------------------------------------------*/

void myDrawUppRightArm(void)  /* Draw the Right Arm of Homer Simpson*/
{  

  GLUquadricObj *qobj;


  /* Set the material properties. */
  GLfloat spec[] = {0.0, 0.0, 0.0, 1.0}; /* specular reflection. */
  GLfloat diffY[] = {1.0, 0.8, 0.0, 1.0}; /* diffuse reflection. */  
  GLfloat diffB[] = {0.0, 0.0, 0.0, 0.0};
  GLfloat diffW[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat diffBR[] = {0.4, 0.2, 0.1, 1.0};


glMaterialf(GL_FRONT, GL_SHININESS, 0);
glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
glMaterialfv(GL_FRONT, GL_DIFFUSE, diffW);
  
  /* Set up and draw the quadric. */
  qobj = gluNewQuadric();
  gluQuadricDrawStyle(qobj,GLU_FILL);
  gluQuadricNormals(qobj,GLU_SMOOTH);
  /* rotate by -90 degrees about the x-axis so the quadric is aligned along the y-axis   */
    glRotated(90.0,1.0,0.0,0.0); 
    
  /* Draw the Shoulder .. part of shirt*/
  gluSphere(qobj,0.8,30,30);
  /* Draw Sleeve of Shirt Upper Arm - should be white, as it is his shirt*/


    glRotated(-30.0,0.0,1.0,0.0); 
  /* Draw Sleeve of Shirt Upper Arm - should be white, as it is his shirt*/

 
  gluCylinder(qobj,0.8,0.8,2.0,22,22);

  
  /*This draws part of his shirt sleeve..white */
  glTranslated(0.0,0.0,1.55);
  gluCylinder(qobj,0.8,1.0,1.4,22,22);


glMaterialfv(GL_FRONT, GL_DIFFUSE, diffY);
  
  /*This sraws part of his upper arm.. should be Yellow.. */
   glTranslated(0.0,0.0,1.4);
  gluCylinder(qobj,0.7,0.7,1.4,22,22);
   
  /*elbow Joint */
  glTranslated(0.0,0.0,1.3);
  gluSphere(qobj,0.7,30,30);

 }



/*---------------------------------------------------------------*/
void myDrawLwrRightArm(void)

{  

  GLUquadricObj *qobj;
  /* Set the material properties. */
  GLfloat spec[] = {0.0, 0.0, 0.0, 1.0}; /* specular reflection. */
  GLfloat diffY[] = {0.0, 0.8, 0.0, 1.0}; /* diffuse reflection. */  
  GLfloat diffB[] = {0.0, 0.0, 0.0, 0.0};
  GLfloat diffW[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat diffBR[] = {0.4, 0.2, 0.1, 1.0};

  GLfloat diffBL[] = {0.0, 0.0, 1.0, 1.0};

glMaterialf(GL_FRONT, GL_SHININESS, 0);
glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
glMaterialfv(GL_FRONT, GL_DIFFUSE, diffY);

qobj = gluNewQuadric();



  /* Set up and draw the quadric. */
  qobj = gluNewQuadric();
  gluQuadricDrawStyle(qobj,GLU_FILL);
  gluQuadricNormals(qobj,GLU_SMOOTH);

  gluCylinder(qobj,0.7,0.5,1.9,22,22);

 

  /*Draw the hands... with 4 fingers*/

  glPushMatrix();
  glTranslated(0.0,0.0,2.2);
  glScaled(1.0, 2.0, 1.0);
  gluSphere(qobj,0.5,30,30);


   /*Finger 1*/
  glPushMatrix();
  glTranslated(0.0,0.0,0.0);
  gluCylinder(qobj,0.2,0.2,1.2,22,22);
  glTranslated(0.0,0.0,1.2);
  gluSphere(qobj,0.2,30,30);
  glPopMatrix();

   /*Finger 2*/
  glPushMatrix();
  glRotated(22.0,1.0,0.0,0.0);
  glTranslated(0.0,0.0,0.4);
  gluCylinder(qobj,0.2,0.2,0.8,22,22);
  glTranslated(0.0,0.0,0.8);
  gluSphere(qobj,0.2,30,30);
   glPopMatrix();

  /*Finger 3*/
   glPushMatrix();
  glRotated(35.0,1.0,0.0,0.0);
  glTranslated(0.0,-0.2,0.0);
  gluCylinder(qobj,0.2,0.2,0.8,22,22);
  glTranslated(0.0,0.0,0.8);
  gluSphere(qobj,0.2,30,30);
   glPopMatrix();
  
    /*Finger 4*/
    glPushMatrix();
  glRotated(-30.0,1.1,0.0,0.0);
  glTranslated(0.0,0.0,0.1);
  gluCylinder(qobj,0.2,0.2,0.8,22,22);
  glTranslated(0.0,0.0,0.8);
  gluSphere(qobj,0.2,30,30);
    glPopMatrix();


   glPopMatrix();



}

/*---------------------------------------------------------------*/
void myDrawUppRightLeg(void)

{  
 GLUquadricObj *qobj;

  GLfloat spec[] = {0.0, 0.0, 0.0, 1.0}; /* specular reflection. */
  GLfloat diff[] = {1.0, 0.8, 0.0, 1.0}; /* diffuse reflection. */  
  GLfloat diffb[] = {0.0, 0.0, 0.0, 1.0};
  GLfloat diffl[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat diffBL[] = {0.1, 0.2, 1.0, 1.0};
 /* Set the material properties. */
  glMaterialf(GL_FRONT, GL_SHININESS, 0);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diffl);

glMaterialfv(GL_FRONT, GL_DIFFUSE, diffBL);

  qobj = gluNewQuadric();
  gluQuadricDrawStyle(qobj,GLU_FILL);
  gluQuadricNormals(qobj,GLU_SMOOTH);



  gluSphere(qobj,1.45,30,30);
  glRotated(-90.0,1.0,0.0,0.0);
  
  glTranslated(0.0,0.0,-3.3);
  gluCylinder(qobj,1.30,1.45,3.5,30,30);



}



/*---------------------------------------------------------------*/
void myDrawLwrRightLeg(void)

{  
 GLUquadricObj *qobj;


  qobj = gluNewQuadric();
  gluQuadricDrawStyle(qobj,GLU_FILL);
  gluQuadricNormals(qobj,GLU_SMOOTH);

  gluSphere(qobj,1.30,30,30);
  glTranslated(0.0,0.0,-3.2);
  gluCylinder(qobj,1.00,1.30,3.2,30,30);

  
  gluSphere(qobj,1.0,30,30);

  

  glTranslated(0.0,-0.5,-0.5);
  glRotated(90.0,1.0,0.0,0.0);
  glScaled(2.6, 1, 4.5);
  
  gluSphere(qobj,0.45,30,30);

}



/*---------------------------------------------------------------*/
void myDrawUppLeftLeg(void)

{  
 GLUquadricObj *qobj;

  GLfloat spec[] = {0.0, 0.0, 0.0, 1.0}; /* specular reflection. */
  GLfloat diff[] = {1.0, 0.8, 0.0, 1.0}; /* diffuse reflection. */  
  GLfloat diffb[] = {0.0, 0.0, 0.0, 1.0};
  GLfloat diffl[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat diffBL[] = {0.1, 0.2, 1.0, 1.0};
 /* Set the material properties. */
  glMaterialf(GL_FRONT, GL_SHININESS, 0);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diffl);

glMaterialfv(GL_FRONT, GL_DIFFUSE, diffBL);

  qobj = gluNewQuadric();
  gluQuadricDrawStyle(qobj,GLU_FILL);
  gluQuadricNormals(qobj,GLU_SMOOTH);
  gluSphere(qobj,1.45,30,30);
  glRotated(-90.0,1.0,0.0,0.0);
  glTranslated(0.0,0.0,-3.3);
  gluCylinder(qobj,1.30,1.45,3.5,30,30);
 
}

/*---------------------------------------------------------------*/
void myDrawLwrLeftLeg(void)
{  
 GLUquadricObj *qobj;

  GLfloat spec[] = {0.0, 0.0, 0.0, 1.0}; /* specular reflection. */
  GLfloat diff[] = {1.0, 0.8, 0.0, 1.0}; /* diffuse reflection. */  
  GLfloat diffb[] = {0.0, 0.0, 0.0, 1.0};
  GLfloat diffl[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat diffBL[] = {0.1, 0.2, 1.0, 1.0};
 /* Set the material properties. */
  glMaterialf(GL_FRONT, GL_SHININESS, 0);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diffl);

glMaterialfv(GL_FRONT, GL_DIFFUSE, diffBL);


  qobj = gluNewQuadric();
  gluQuadricDrawStyle(qobj,GLU_FILL);
  gluQuadricNormals(qobj,GLU_SMOOTH);
  gluSphere(qobj,1.30,30,30);
  glTranslated(0.0,0.0,-3.2);
  gluCylinder(qobj,1.00,1.30,3.2,30,30);
  gluSphere(qobj,1.0,30,30);
  glTranslated(0.0,-0.5,-0.5);
  glRotated(90.0,1.0,0.0,0.0);
  glScaled(2.6, 1, 4.5);  

  
glMaterialfv(GL_FRONT, GL_DIFFUSE, diffb);
  gluSphere(qobj,0.45,30,30);
}


/*---------------------------------------- */
void myDrawFloorPlane(void)
{  
 GLUquadricObj *qobj;

  GLfloat spec[] = {0.0, 0.0, 0.0, 1.0}; /* specular reflection. */
  GLfloat diff[] = {1.0, 0.8, 0.0, 1.0}; /* diffuse reflection. */  
  GLfloat diffb[] = {0.0, 0.0, 0.0, 1.0};
  GLfloat diffl[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat diffBL[] = {0.1, 0.2, 1.0, 1.0};
  GLfloat diffGR[] = {0.1, 0.6, 0.5, 1.0};
 /* Set the material properties. */
  glMaterialf(GL_FRONT, GL_SHININESS,0);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff);

glMaterialfv(GL_FRONT, GL_DIFFUSE, diffGR);


  qobj = gluNewQuadric();
  gluQuadricDrawStyle(qobj,GLU_FILL);
  gluQuadricNormals(qobj,GLU_SMOOTH);
 
   glScaled(32.6, 1.0,33.5);  
  glutSolidCube(3.0);

}


void myDrawCeiling(void)
{  
 GLUquadricObj *qobj;

   GLfloat spec[] = {0.0, 0.0, 0.0, 1.0};
  GLfloat diffl[] = {1.0, 1.0, 1.0, 1.0};
 /* Set the material properties. */


glMaterialfv(GL_FRONT, GL_DIFFUSE, diffl);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec);

  qobj = gluNewQuadric();
  gluQuadricDrawStyle(qobj,GLU_FILL);
  gluQuadricNormals(qobj,GLU_SMOOTH);
 
   glScaled(32.6, 1.0,33.5);  
  glutSolidCube(3.0);

}

void myDrawBackWall1(void)
{  
 GLUquadricObj *qobj;

  GLfloat spec[] = {0.0, 0.0, 0.0, 1.0}; /* specular reflection. */
  GLfloat diff[] = {1.0, 0.8, 0.0, 1.0}; /* diffuse reflection. */  
  GLfloat diffb[] = {0.0, 0.0, 0.0, 1.0};
  GLfloat diffl[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat diffBL[] = {0.1, 0.2, 1.0, 1.0};
  GLfloat diffGR[] = {0.1, 0.6, 0.5, 1.0};
  GLfloat diffPink[] = {0.98, 0.66, 0.94, 1.0};
 /* Set the material properties. */
  glMaterialf(GL_FRONT, GL_SHININESS,0);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff);

glMaterialfv(GL_FRONT, GL_DIFFUSE, diffPink);


  qobj = gluNewQuadric();
  gluQuadricDrawStyle(qobj,GLU_FILL);
  gluQuadricNormals(qobj,GLU_SMOOTH);
 
   glScaled(20.6, 24.0, 1.5);  
  glutSolidCube(3.0);

}




void myDrawBackWall2(void)
{  
 GLUquadricObj *qobj;

  GLfloat spec[] = {0.0, 0.0, 0.0, 1.0}; /* specular reflection. */
  GLfloat diff[] = {1.0, 0.8, 0.0, 1.0}; /* diffuse reflection. */  
  GLfloat diffb[] = {0.0, 0.0, 0.0, 1.0};
  GLfloat diffl[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat diffBL[] = {0.1, 0.2, 1.0, 1.0};
  GLfloat diffGR[] = {0.1, 0.6, 0.5, 1.0};
  GLfloat diffPink[] = {0.98, 0.66, 0.94, 1.0};
 /* Set the material properties. */
  glMaterialf(GL_FRONT, GL_SHININESS,0);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff);

glMaterialfv(GL_FRONT, GL_DIFFUSE, diffPink);


  qobj = gluNewQuadric();
  gluQuadricDrawStyle(qobj,GLU_FILL);
  gluQuadricNormals(qobj,GLU_SMOOTH);
 
   glScaled(5.6, 24.0, 1.5);  
  glutSolidCube(3.0);

}



void myDrawBackWall3(void)
{  
 GLUquadricObj *qobj;

  GLfloat spec[] = {0.0, 0.0, 0.0, 1.0}; /* specular reflection. */
  GLfloat diff[] = {1.0, 0.8, 0.0, 1.0}; /* diffuse reflection. */  
  GLfloat diffb[] = {0.0, 0.0, 0.0, 1.0};
  GLfloat diffl[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat diffBL[] = {0.1, 0.2, 1.0, 1.0};
  GLfloat diffGR[] = {0.1, 0.6, 0.5, 1.0};
  GLfloat diffPink[] = {0.98, 0.66, 0.94, 1.0};
 /* Set the material properties. */
  glMaterialf(GL_FRONT, GL_SHININESS,0);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff);

glMaterialfv(GL_FRONT, GL_DIFFUSE, diffPink);


  qobj = gluNewQuadric();
  gluQuadricDrawStyle(qobj,GLU_FILL);
  gluQuadricNormals(qobj,GLU_SMOOTH);

   glScaled(20.6, 4.0, 1.5);  
  glutSolidCube(3.0);

}





void myDrawLeftWall1(void)
{  
 GLUquadricObj *qobj;

  GLfloat spec[] = {0.0, 0.0, 0.0, 1.0}; /* specular reflection. */
  GLfloat diff[] = {1.0, 0.8, 0.0, 1.0}; /* diffuse reflection. */  
  GLfloat diffb[] = {0.0, 0.0, 0.0, 1.0};
  GLfloat diffl[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat diffBL[] = {0.1, 0.2, 1.0, 1.0};
  GLfloat diffGR[] = {0.1, 0.6, 0.5, 1.0};
  GLfloat diffPink[] = {0.98, 0.66, 0.94, 1.0};
 /* Set the material properties. */
  glMaterialf(GL_FRONT, GL_SHININESS,0);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff);

glMaterialfv(GL_FRONT, GL_DIFFUSE, diffPink);


  qobj = gluNewQuadric();
  gluQuadricDrawStyle(qobj,GLU_FILL);
  gluQuadricNormals(qobj,GLU_SMOOTH);
 glRotated(90.0,0.0,1.0,0.0);
   glScaled(33.6, 24.0, 1.5);  
  glutSolidCube(3.0);

}






void myDrawFrontWall1(void)
{  
 GLUquadricObj *qobj;

  GLfloat spec[] = {0.0, 0.0, 0.0, 1.0}; /* specular reflection. */
  GLfloat diff[] = {1.0, 0.8, 0.0, 1.0}; /* diffuse reflection. */  
  GLfloat diffb[] = {0.0, 0.0, 0.0, 1.0};
  GLfloat diffl[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat diffBL[] = {0.1, 0.2, 1.0, 1.0};
  GLfloat diffGR[] = {0.1, 0.6, 0.5, 1.0};
  GLfloat diffPink[] = {0.98, 0.66, 0.94, 1.0};
 /* Set the material properties. */
  glMaterialf(GL_FRONT, GL_SHININESS,0);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff);

glMaterialfv(GL_FRONT, GL_DIFFUSE, diffPink);


  qobj = gluNewQuadric();
  gluQuadricDrawStyle(qobj,GLU_FILL);
  gluQuadricNormals(qobj,GLU_SMOOTH);
 
   glScaled(33.6, 24.0, 1.5);  
  glutSolidCube(3.0);

}



void myDrawCarpet1(void)
{  
 GLUquadricObj *qobj;



 GLfloat diffCarpetRed[] = {0.98, 0.11, 0.44, 1.0};
 GLfloat diffCarpetPurple[] = {0.30, 0.0, 0.8, 1.0};
 GLfloat diffCarpetBlue[] = {0.02, 0.62, 0.99, 1.0};
  GLfloat diffCarpetOrange[] = {0.94, 0.4, 0.06, 1.0};
   GLfloat spec[] = {0.0, 0.0, 0.0, 1.0};
 /* Set the material properties. */


  glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
glMaterialf(GL_FRONT, GL_SHININESS,0);

glMaterialfv(GL_FRONT, GL_DIFFUSE, diffCarpetRed);


  qobj = gluNewQuadric();
  gluQuadricDrawStyle(qobj,GLU_FILL);
  gluQuadricNormals(qobj,GLU_SMOOTH);
 
  glPushMatrix();
   glScaled(7.6, 1.0, 5.5);  
  glutSolidCube(3.0);
glPopMatrix();

  glPushMatrix();
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diffCarpetPurple);
   glTranslated(0.0,0.01,0.0);
   glScaled(5.6, 1.0, 4.5);  
  glutSolidCube(3.0);
glPopMatrix();

  glPushMatrix();
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diffCarpetBlue);
   glTranslated(0.0,0.02,0.0);
   glScaled(3.4, 1.0, 3.3);  
  glutSolidCube(3.0);
glPopMatrix();

  glPushMatrix();
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diffCarpetOrange);
   glTranslated(0.0,0.03,0.0);
   glScaled(1.6, 1.0, 1.5);  
  glutSolidCube(3.0);
glPopMatrix();


}



void myDrawLamp1(void)
{  
 GLUquadricObj *qobj;

 GLfloat diffCarpetRed[] = {0.98, 0.0, 1.0, 1.0};
 GLfloat diffLightBlue[] = {0.28, 0.81, 0.99, 1.0};
 GLfloat Metalspec[] = {1.0, 1.0, 1.0, 1.0};
 /* Set the material properties. */
  GLfloat diffl[] = {1.0, 1.0, 1.0, 1.0};

  GLfloat mat_emission[] = {0.3f, 0.2f, 0.2f, 0.0f};

  qobj = gluNewQuadric();
  gluQuadricDrawStyle(qobj,GLU_FILL);
  gluQuadricNormals(qobj,GLU_SMOOTH);


  glRotated(90.0,1.0,0.0,0.0);
  
glMaterialfv(GL_FRONT, GL_DIFFUSE, diffCarpetRed);

glTranslated(0.0,0.0,-3.8);
/* Set Light Shade */

gluCylinder(qobj,1.45,3.00,4.5,30,30);

  glMaterialf(GL_FRONT, GL_SHININESS,7);
  glMaterialfv(GL_FRONT, GL_SPECULAR, Metalspec);
glMaterialfv(GL_FRONT, GL_DIFFUSE, diffLightBlue);
/* Set Light Stand - SHINY */

gluCylinder(qobj,0.5,0.5,15.5,30,30);


 /* Set Light Base */
glTranslated(0.0,0.0,15.5);
glRotated(180, 0, 1, 0);
glutSolidCone(3.45,1.2,33,22);




}





void myDrawSofa(void)
{  
 GLUquadricObj *qobj;


	

 /* Set the material properties. */
  GLfloat diffSofa[] = {0.83, 0.44, 0.03, 1.0};
   GLfloat spec[] = {0.0, 0.0, 0.0, 1.0};


  qobj = gluNewQuadric();
  gluQuadricDrawStyle(qobj,GLU_FILL);
  gluQuadricNormals(qobj,GLU_SMOOTH);


  glMaterialfv(GL_FRONT, GL_DIFFUSE, diffSofa);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
  glMaterialf(GL_FRONT, GL_SHININESS,0);
   
  
 /*  glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
  
  glDisable(GL_BLEND);


  */
		

  glRotated(90.0,1.0,0.0,0.0);
  
  glPushMatrix();

 glPushMatrix();
 glScaled(7.0, 1.2, 1.5);  
 glutSolidCube(3.0);
glPopMatrix();



 /* Left Arm Rest */
glPushMatrix();
glTranslated(12.0,-1.0,-1.1);

 glScaled(1.2, 1.9, 2.5);
 glutSolidCube(3.0);


glPopMatrix();

 /* Right Arm Rest */
glPushMatrix();
glTranslated(-12.0,-1.0,-1.1);

 glScaled(1.2, 1.9, 2.5);
 glutSolidCube(3.0);


glPopMatrix();


 /* Back Rest */
  
 glPushMatrix();
 glTranslated(0.0,-2.6,-4.0);
 glScaled(7.0, 0.5, 3.5);  
 glutSolidCube(3.0);
glPopMatrix();


 /*Glass... on the arm rest.. */
 glPushMatrix();
 glEnable(GL_BLEND);
 glBlendFunc(GL_SRC_ALPHA, GL_ONE); 

 glTranslated(-12.0,0.0,-6.3);
  glRotatef(-90, 0,0, 1);

 gluCylinder(qobj,1.00,0.80,1.4,30,30);
  glDisable(GL_BLEND);
 glPopMatrix();

glPopMatrix();
	
}




void myDrawGoal(void)
{  
 GLUquadricObj *qobj;


	

 /* Set the material properties. */
  GLfloat diffSofa[] = {0.83, 0.44, 0.03, 1.0};
   GLfloat spec[] = {0.0, 0.0, 0.0, 1.0};


  qobj = gluNewQuadric();
  gluQuadricDrawStyle(qobj,GLU_FILL);
  gluQuadricNormals(qobj,GLU_SMOOTH);


  glMaterialfv(GL_FRONT, GL_DIFFUSE, diffSofa);
  glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
  glMaterialf(GL_FRONT, GL_SHININESS,10);
   
  
 /*  glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
  
  glDisable(GL_BLEND);


  */
		
  glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
  
  glPushMatrix();
  glRotatef(90, 0,1, 0);
  glScaled(14, 10, 11);
glutSolidCube(1);
 glPopMatrix();



  glDisable(GL_BLEND);

	
}







void  myDrawPicture1(void)
{  
  GLfloat diffSofa[] = {0.5, 0.5, 0.0, 1.0};
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diffSofa);
  glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
  
  glPushMatrix();
  glRotatef(90, 0,1, 0);
  glScaled(1, 10, 10);
glutSolidCube(1);
 glPopMatrix();



  glDisable(GL_BLEND);
 glPushMatrix();
 glTranslated(0.0,0,-1.1);
  glRotatef(90, 0,1, 0);
 glScaled(1, 10, 10);
glutSolidCube(1);
	
glPopMatrix();



}







void  myDrawFootball1(void)
{  
	GLUquadricObj *qobj;
   qobj = gluNewQuadric();
  gluQuadricDrawStyle(qobj,GLU_FILL);
  gluQuadricNormals(qobj,GLU_SMOOTH);
  gluSphere(qobj,2.30,30,30);

}








void myRotateHomer(void)
{ 
  spin = spin - 0.8;
 
  if (spin > 360.0)
    spin = 1.0; 



  glutPostRedisplay();
}




void setLighting(void) /* Set up two lights */
{
  GLfloat ambient[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat diffuse0[] = {1.0, 1.0, 1.0, 1.0}; 
  GLfloat position0[] = {0.0, 22.0, 50.0, 0.0}; /* Behind and up. */
  GLfloat lmodel_ambient[] = {0.0, 0.0, 0.0, 1.0}; /* Set the background ambient lighting. */
  GLfloat lmodel_twoside[] = {GL_TRUE}; /* Compute lighting for both inside and outside faces. */
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
  glLightModelfv(GL_LIGHT_MODEL_TWO_SIDE, lmodel_twoside);

  /* Set the light properties */
  glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse0);
  glLightfv(GL_LIGHT0, GL_POSITION, position0);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
}


void myInit(void) /* Function to initialise the OpenGL parameters. */
{
  glClearColor(0.0,0.0,0.0,0.0); 
  glFrontFace(GL_CCW); /* Front faces defined using a clockwise rotation. */
  glDepthFunc(GL_LEQUAL); /* Plot pixel */
  glEnable(GL_DEPTH_TEST); /* Use a depth (z) buffer to draw only visible objects. */
  glEnable(GL_CULL_FACE); /* Use back face culling to improve speed. */
  glCullFace(GL_BACK); /* Cull only back faces. */
  /* Which shade model to use: GL_FLAT / GL_SMOOTH. */
  glShadeModel(GL_SMOOTH);

  setLighting();

  /* Generate the display lists to store the robot: */
  glNewList(Torso,GL_COMPILE);
   myDrawTorso();
  glEndList();

  glNewList(UppLeftArm,GL_COMPILE);
   myDrawUppLeftArm();
  glEndList();
  

  glNewList(LwrLeftArm,GL_COMPILE);
   myDrawLwrLeftArm();
  glEndList();


  glNewList(UppRightArm,GL_COMPILE);
   myDrawUppRightArm();
  glEndList();


  glNewList(LwrRightArm,GL_COMPILE);
   myDrawLwrRightArm();
  glEndList();

  
  glNewList(UppRightLeg,GL_COMPILE);
   myDrawUppRightLeg();
  glEndList();

  glNewList(LwrRightLeg,GL_COMPILE);
   myDrawLwrRightLeg();
  glEndList();

  glNewList(UppLeftLeg,GL_COMPILE);
   myDrawUppLeftLeg();
  glEndList();

  glNewList(LwrLeftLeg,GL_COMPILE);
   myDrawLwrLeftLeg();
  glEndList();


  glNewList(HomerHead,GL_COMPILE);
   myDrawHomerHead();
  glEndList();

/* ------------------------------------------- */


  glNewList(FloorPlane,GL_COMPILE);
   myDrawFloorPlane();
  glEndList();

  glNewList(Ceiling,GL_COMPILE);
   myDrawCeiling();
  glEndList();

  glNewList(BackWall1,GL_COMPILE);
   myDrawBackWall1();
  glEndList();


  glNewList(BackWall2,GL_COMPILE);
   myDrawBackWall2();
  glEndList();

  glNewList(BackWall3,GL_COMPILE);
   myDrawBackWall3();
  glEndList();

  glNewList(FrontWall1,GL_COMPILE);
   myDrawFrontWall1();
  glEndList();



  glNewList(LeftWall1,GL_COMPILE);
   myDrawLeftWall1();
  glEndList();

  glNewList(RightWall1,GL_COMPILE);
   myDrawLeftWall1();
  glEndList();


  glNewList(Lamp1,GL_COMPILE);
   myDrawLamp1();
  glEndList();

  glNewList(Sofa,GL_COMPILE);
   myDrawSofa();
  glEndList();




  glNewList(Carpet1,GL_COMPILE);
   myDrawCarpet1();
  glEndList();


  glNewList(Picture1,GL_COMPILE);
   myDrawPicture1();
  glEndList();


  glNewList(Football1,GL_COMPILE);
   myDrawFootball1();
  glEndList();

  glNewList(Goal,GL_COMPILE);
   myDrawGoal();
  glEndList();


}

void displayHomer(void) /* Function to be called to determine what is displayed. */
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); /* Clear the screen (colour) buffer. 
*/

  glPushMatrix();

    glTranslated(0.0,0.0,0.0); 
 glRotated(spin, 0,1,0);
 /* The Following is Scenery Object hierachy
   -- Will contain the walls, Lamps, TV etc
  */
  glPushMatrix(); 
  glTranslated(0.0,-13.0,0); 
  glCallList(FloorPlane);  
  glPopMatrix();

  glPushMatrix(); 
  glTranslated(0.0,23.0,0); 
  glCallList(Ceiling);  
  glPopMatrix();


  glPushMatrix(); 
  glTranslated(14.0,-13.0, -30); 
  glCallList(BackWall1);  
  glPopMatrix();


  glPushMatrix(); 
  glTranslated(-44.0,-13.0, -30); 
  glCallList(BackWall2);  
  glPopMatrix();


  glPushMatrix(); 
  glTranslated(-44.0,17.0, -30); 
  glCallList(BackWall3);  
  glPopMatrix();



  glPushMatrix(); 
  glTranslated(0.0,-13.0, 52); 
  glCallList(FrontWall1);  
  glPopMatrix();


  glPushMatrix(); 
  glTranslated(-44.0,-13.0, 0); 
  glCallList(LeftWall1);  
  glPopMatrix();

  glPushMatrix(); 
  glTranslated(44.0,-13.0, 0); 
  glCallList(RightWall1);  
  glPopMatrix();

  glPushMatrix();  
  glRotatef(LampAngle1, 0, 0, 1);
  glTranslated(-8.0,0,-20); 
  glCallList(Lamp1); 
  glPopMatrix();


 glPushMatrix();
 glRotatef(0, 0, 0, 0);
  glRotatef(SofaAngle1, 0, 1, 0);
  glTranslated(SofaX,SofaY, SofaZ); 
  glCallList(Sofa);

  glPopMatrix();


glPushMatrix();
   glRotatef(-Pic1Angle1, 0,1, 0);
 glTranslated(11.5, Pic1Y, -26.5);
    glCallList(Picture1); 
  glPopMatrix();





 glPushMatrix();
 glRotated(CarpetSpin,0,1,0);
  glTranslated(1.0, -12.9, 4); 
  glCallList(Carpet1);  
  glPopMatrix();



  glPushMatrix();
glTranslated(21.0,-9.0,36);    
 glCallList(Goal);
  glPopMatrix();

 glPushMatrix();
 glRotated(0,0,1,0);
  glTranslated(FootballX, FootballY, FootballZ); 
  glCallList(Football1);  
  glPopMatrix();








 /* The Following is Homer Simpson's Object hierachy 
  
	--Homer Simpson is a Child of the Scene.. so if we move the Scene he will too.
  */
 
 glPushMatrix();
glTranslated (MoveX,MoveY,MoveZ); 

glRotated(XRotate,1,0,0);
glRotated(ZRotate,0,0,1);

glRotated(BodyTurn,0,1,0);
  glPushMatrix();
    /*Torso*/

  	glTranslated(0.0,0.0,0.0);
      glCallList(Torso);  
	  

   glPopMatrix();


	/*HOMER HEAD*/
 	 glPushMatrix();
 		glTranslated(0.0,6.5,0.0);
 glRotatef(HeadNod, 1, 0, 0);
		 glRotatef(HeadTurn, 0, 1, 0);
		glCallList(HomerHead); 
	 glPopMatrix();




	/*RIGHT ARM*/
 	 glPushMatrix(); 
	  glTranslated(-2.0,1.5,0.0);
	  
	  glRotatef(UpperRightArmAngleX, 1, 0, 0);
		  glRotatef(UpperRightArmAngleZ, 0, 0, 1);
	  glCallList(UppRightArm);
      
	  glPushMatrix();
	  glRotatef(LowerRightArmAngleX, 1, 0, 0);
 glRotatef(LowerRightArmAngleY, 0, 1, 0);
	  glCallList(LwrRightArm);	
      glPopMatrix();
    glPopMatrix();


   	/*LEFT ARM*/
    glPushMatrix();
	  glTranslated(2.0,1.5,0.0);
		


      glRotatef(UpperLeftArmAngleX, 1, 0, 0);
	  glRotatef(UpperLeftArmAngleZ, 0, 0, 1);
	  glCallList(UppLeftArm);
	   glPushMatrix();
       
	glRotatef(LowerLeftArmAngleX, 1, 0, 0);
         glCallList(LwrLeftArm);
	   glPopMatrix();
	   glPopMatrix();

    glPushMatrix();   

        glPopMatrix();

  /*RIGHT LEG*/
	glPushMatrix();	  
		glTranslated(-1.3,-3.85,0.0); 

		glRotatef(UpperRightLegAngleX, 1, 0, 0);
	  glRotatef(UpperRightLegAngleZ, 0, 0, 1);
		glCallList(UppRightLeg);
	glPushMatrix();	 
	glRotatef(LowerRightLegAngleX, 1, 0, 0);
		glCallList(LwrRightLeg);   
	glPopMatrix();
	glPopMatrix();
  
  /*LEFT LEG*/
  glPushMatrix();	  
  glTranslated(1.3,-3.85,0.0);
  glRotatef(UpperLeftLegAngleX , 1, 0, 0);
  glRotatef(UpperLeftLegAngleZ, 0, 0, 1);
  glCallList(UppLeftLeg);	 
   glPushMatrix();
  glRotatef(LowerLeftLegAngleX , 1, 0, 0);
  glCallList(LwrLeftLeg); 
  glPopMatrix();
  glPopMatrix();
  
  glPopMatrix();


  glPopMatrix();

 
  glutSwapBuffers();
}

void animateKickBall(void)
{ time++;





if  (time < 150) LowerRightLegAngleX +=1.60;
 else if  (time < 170) UpperRightLegAngleX +=1.60;
  
else if  (time < 290) LowerRightLegAngleX -=2.00;


else if  (time < 310) UpperRightLegAngleX -=5.60;



else if  (time < 397)
((FootballX+= 1.60) && (FootballY+= 0.60)) ;

else if  (time < 426)
((FootballX-= 1.4) && (FootballY-= 1.60)) ;




time = time+1;

  glutPostRedisplay();
}


void HomerFlips(void)
{
  Fliptimer++;
  if (Fliptimer < 200) 
UpperRightArmAngleX -= 2.0;

  if (Fliptimer< 200)
  UpperLeftArmAngleX -= 2.0;
	
else if (Fliptimer < 230)
	 
 LowerRightLegAngleX += 2;

else	 if (Fliptimer < 330) 
 LowerLeftLegAngleX += 2;


else	 if (Fliptimer<690) //1190
 ((XRotate += 2) && (MoveZ = MoveZ+0.2));

	
if (Fliptimer<750)//1250
(UpperRightArmAngleX += 2.0)&&(UpperLeftArmAngleX += 2.0);
         
	 
else	 if (Fliptimer <920)// 1420
(UpperRightArmAngleX += 2.0);
         
	else if (Fliptimer < 950)//1450
	 
 LowerRightLegAngleX -= 2;

else	 if (Fliptimer < 1050)// 1550
 LowerLeftLegAngleX -= 2;


Fliptimer = Fliptimer+1;

  glutPostRedisplay();
}





void HomerCartWheels(void)
{
  time++;
  if (time < 111) 
((UpperLeftArmAngleZ += 2.0)&&(UpperRightLegAngleZ -= 1.0)&&(MoveX += 0.2)&&(ZRotate -=3));

 else if (time <222) 

((UpperLeftArmAngleZ -= 1.0)&&(UpperRightArmAngleZ -= 1.0)&&(UpperRightLegAngleZ += 0.5)&&(MoveX += 0.2)&&(ZRotate -=3));


 else if (time <250) 

((UpperLeftArmAngleZ -= 1.0)&&(UpperRightLegAngleZ += 0.5)&&(MoveX += 0.2)&&(ZRotate -=2));
 

 else if (time <378) 

((UpperLeftArmAngleZ += 1.0)&&(UpperRightLegAngleZ -= 0.5)&&(MoveX -= 0.2)&&(ZRotate +=2));

 else if (time < 406) 

((UpperLeftArmAngleZ += 1.0)&&(UpperRightArmAngleZ += 1.0)&&(UpperRightLegAngleZ  -= 0.5)&&(MoveX -= 0.2)&&(ZRotate +=3));

 else if (time < 517) 

((UpperLeftArmAngleZ -= 2.0)&&(UpperRightLegAngleZ += 1.0)&&(MoveX -= 0.2)&&(ZRotate +=3));


 else if (time < 533) 

((UpperRightArmAngleZ += 3.5)&&(UpperRightLegAngleZ += 0.2)&&(MoveX -= 0.00)&&(ZRotate +=3));






 time =  time+1;


  glutPostRedisplay();
}




void animateRightLeg(void)
{ time++;

if  (time < 150) UpperRightLegAngleX -=1.60;
 
     LowerRightLegAngleX +=1.60;

if  (LowerRightLegAngleX =45.60)

LowerRightLegAngleX = LowerRightLegAngleX;

if  (time > 350) UpperRightLegAngleX +=0.60;

if  (UpperRightLegAngleX > 50.60)

UpperRightLegAngleX = -40;

time = time+1;

  glutPostRedisplay();
}


void animateLeftLeg(void)
{

  glutPostRedisplay();
}

void SpinCarpet(void)
{ 
time++;
	
if  (time < 122) 

if  ((MoveZ == 5) && (MoveX == 5))

 CarpetSpin = CarpetSpin+1;

 if (time > 122)

   glutIdleFunc(NULL);



 time = 0.0;


  glutPostRedisplay();
}


//Moves hand to do Famous Homer move, 
//in which he moves his hand to his head... and says.. "Doh"

void TradeMarkDoh(void)
{ 
time++;
	
if  (time < 122) 

(UpperRightArmAngleX -= 1.3)&& (LowerRightArmAngleX+= 0.2)  && (LowerRightArmAngleY+= 0.9)&& (UpperRightArmAngleZ+= 0.2) ;

else if  (time < 244) 



(UpperRightArmAngleX += 1.3)&& (LowerRightArmAngleX-= 0.2)  && (LowerRightArmAngleY-= 0.9)&& (UpperRightArmAngleZ-= 0.2) ;
 

  glutPostRedisplay();
}


void interactiveMode(void)
{ 


//Kick the Football when homer stands behind it


if  ((MoveZ == -33) && (MoveX == 28))

glutIdleFunc(animateKickBall); 


 if  ((MoveZ == -32) && (MoveX == 28))

glutIdleFunc(animateKickBall); 


if  ((MoveZ == -31) && (MoveX == 27))

glutIdleFunc(animateKickBall); 

//animate sofa, lamp, picture.. to move when Homer goes between Lamp and SOfa
if  ((MoveZ == -15) && (MoveX == -1))
(SofaAngle1 = SofaAngle1+1)&&(Pic1Angle1 = Pic1Angle1+1) &&(Pic1Y = Pic1Y-1)&&(LampAngle1 = LampAngle1-1);

if  ((MoveZ == -15) && (MoveX == -2))
(SofaAngle1 = SofaAngle1+1)&&(Pic1Angle1 = Pic1Angle1+1) &&(Pic1Y = Pic1Y-1)&&(LampAngle1 = LampAngle1-1);

if  ((MoveZ == -15) && (MoveX == -3))
(SofaAngle1 = SofaAngle1+1)&&(Pic1Angle1 = Pic1Angle1+1) &&(Pic1Y = Pic1Y-1)&&(LampAngle1 = LampAngle1-1);

if  ((MoveZ == -15) && (MoveX == -4))
(SofaAngle1 = SofaAngle1+1)&&(Pic1Angle1 = Pic1Angle1+1) &&(Pic1Y = Pic1Y-1)&&(LampAngle1 = LampAngle1-1);
if  ((MoveZ == -16) && (MoveX == -4))
(SofaAngle1 = SofaAngle1+1)&&(Pic1Angle1 = Pic1Angle1+1) &&(Pic1Y = Pic1Y-1)&&(LampAngle1 = LampAngle1-1);

if  ((MoveZ == -16) && (MoveX == -2))
(SofaAngle1 = SofaAngle1+1)&&(Pic1Angle1 = Pic1Angle1+1) &&(Pic1Y = Pic1Y-1)&&(LampAngle1 = LampAngle1-1);

if  ((MoveZ == -16) && (MoveX == -3))
(SofaAngle1 = SofaAngle1+1)&&(Pic1Angle1 = Pic1Angle1+1) &&(Pic1Y = Pic1Y-1)&&(LampAngle1 = LampAngle1-1);


if ((SofaAngle1 > 22) || (LampAngle1 < -15))

   glutIdleFunc(NULL);

  glutPostRedisplay();
}


/*------------------------------------------------*/

void myMoveRightX(void)
{
	MoveX = MoveX+1.0;
  glutPostRedisplay();
}

void myMoveLeftX(void)
{
	MoveX = MoveX-1.0;
  glutPostRedisplay();
}

void myMoveForwardZ(void)
{
	MoveZ = MoveZ+1.0;
  glutPostRedisplay();
}


void myMoveBackwardZ(void)
{
	MoveZ = MoveZ-1.0;
  glutPostRedisplay();
}

void myLookLeft(void)
{
	HeadTurn = HeadTurn+4.0;
  glutPostRedisplay();
}

void myLookRight(void)
{
	HeadTurn = HeadTurn-4.0;
  glutPostRedisplay();
}

void myBodyRight(void)
{
	BodyTurn = BodyTurn-4.0;
  glutPostRedisplay();
}


void myBodyLeft(void)
{
	BodyTurn = BodyTurn+4.0;
  glutPostRedisplay();
}

void reset(void)
{
 
UpperRightLegAngleZ=0.0;
UpperRightLegAngleY= 0.0;
UpperRightLegAngleX= 0.0;
 LowerRightLegAngleY= 0.0;
LowerRightLegAngleX= 0.0;

 UpperLeftLegAngleY= 0.0;
UpperLeftLegAngleX= 0.0;
LowerLeftLegAngleY= 0.0;
LowerLeftLegAngleX= 0.0;


UpperRightArmAngleZ= 0.0;
 UpperRightArmAngleX= 0.0;
 LowerRightArmAngleY= 0.0;
 LowerRightArmAngleX= 0.0;

UpperLeftArmAngleZ= 0.0;
 UpperLeftArmAngleX= 0.0;
 LowerLeftArmAngleY= 0.0;
 LowerLeftArmAngleX= 0.0;

 FootballX= -28.0;
 FootballY= -9.0;
 FootballZ= 36;




XRotate = 0.0;
ZRotate = 0.0;
 HeadTurn = 0.0;
	BodyTurn = 0.0;
CarpetSpin= 15.0;
SofaX = 15.0;

SofaAngle1= 0.0;
LampAngle1= 0.0;

Pic1Y=10.0;
Pic1Angle1=0.0;

 //MoveX= -23.0;
// MoveY= 0.0;
 //MoveZ= -28.0;

 MoveX= 0.0;
 MoveY= 0.0;
 MoveZ= 0.0;
 time = 0.0;
Fliptimer = 0.0;
	
    glutIdleFunc(SpinCarpet);
    glutIdleFunc(interactiveMode);

  glutPostRedisplay();
}


void createMenu(void)
{
  

  glutCreateMenu(menu);
  glutAddMenuEntry("Rotate Homer", SPIN);
  glutAddMenuEntry("Stop Spinning", STOP);
  glutAddMenuEntry("Quit the Program", QUIT);
  glutAttachMenu(GLUT_RIGHT_BUTTON);

}


void menu (int item)
{
 switch(item)  {
 case  SPIN:
      glutIdleFunc(TradeMarkDoh);
      break;
 case  STOP:
      glutIdleFunc(NULL);
      break;
 case  QUIT:
      exit(0);
      break;
 }


/* The keyboard callback function:  */
void myKeyboard(unsigned char k, int mouseX, int mouseY) 
{
  switch (k) 
    {
    case 'p':
      myRotateHomer();
      break;
    case 'n':
      glutIdleFunc(NULL);
      break;

	
	case ';':
	 animateRightLeg();
	  break;

    case 'l':
	  animateLeftLeg();
    break;


  /* --------Reset all animation...------------ */
    case 'r':
       reset();
    break;


    /*------------------Control Movement of Homer-------------- */


    case 'w':
	  myMoveForwardZ();
    break;

    case 's':
	  myMoveBackwardZ();
    break;

     case 'a':
	  myMoveLeftX();
    break;

	 case 'd':
	  myMoveRightX();
    break;


	 case 'z':
	  myBodyLeft();
    break;

	 case 'c':
	  myBodyRight();
    break;
	 case '0':
	 SpinCarpet();
    break;

	 case 'e':
	  myLookRight();
    break;

     case 'q':
      myLookLeft();
    break;

     case 'i':
    glutIdleFunc(interactiveMode);
    break;

     case 'k':
    glutIdleFunc(animateKickBall);
    break;


     case '1':
    glutIdleFunc(TradeMarkDoh);
    break;

     case '2':
    glutIdleFunc(HomerFlips);
    break;


     case '3':
    glutIdleFunc(HomerCartWheels);
    break;

 






    case "27":  /* Escape key to exit */
      exit(0);
      break;
    default: /* Otherwise keep going */
      return;





    }
}


/* The mouse callback function: */
void myMouse(int button, int state, int mouseX, int mouseY) 
{
  switch (button)
    {
    case GLUT_RIGHT_BUTTON:  /* Right button to exit */
      if (state == GLUT_DOWN)
	glutIdleFunc(myRotateHomer);
      break;
    case GLUT_LEFT_BUTTON:  /* Right button to exit */
      if (state == GLUT_DOWN)
	glutIdleFunc(NULL);
      break;
    default: /* Otherwise keep going */
      return;
    }
}



/* Tell GLUT what to do if the window is reshaped: */
void myReshape(int width, int height) 
{
  glViewport(0, 0, (GLsizei) width, (GLsizei) height); 
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum (-1.0, 1.0, -1.0, 1.0, 1.0, 200.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
   gluLookAt(0.0,6.0, 22.0, 0.0, 0.0,0.0, 0.0, 1.0,0.0);
}

int main(int argc, char** argv) /* Main function. */
{
  /* Use GLUT to create a window for drawing: */
  glutInit(&argc, argv); 
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
  glutInitWindowSize(800,800); 
  glutInitWindowPosition(100,150); 
  glutCreateWindow("Homer Simpson in 3D");
  /* Define the call back functions: */
  glutDisplayFunc(displayHomer); 
  glutReshapeFunc(myReshape); 
  glutMouseFunc(myMouse); 
  glutKeyboardFunc(myKeyboard); 
   glutIdleFunc(SpinCarpet);
     createMenu();
   myInit();
  glutMainLoop();

  return 0; /* ANSI C requires main to return an int. */
}
