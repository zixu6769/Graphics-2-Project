//
//  OpenGL widget
//
#include "projectopengl.h"
#include <QStringList>
#include "Noise.h"
#include <math.h>
#include "Cube.h"
#include "WaveOBJ.h"
#include "Floor.h"
#include "Wall.h"
#include "Stairs.h"
#include "Carpet.h"
#include "Tower.h"
#include "Skytop.h"
#include "Skyback.h"
#include "Skyleft.h"
#include "Skyright.h"
#include "Skyfront.h"
#include "Roof.h"
#include "Leaf.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "Human.h"
#include "Armor.h"
#include "Cloth.h"
#include "Mask.h"
#include "Sword.h"

//  Set up array indexes for program
const int VELOCITY_ARRAY=4;
const int START_ARRAY=5;
const char* Name = ",,,,Vel,Start";

/*
 *  Random numbers with range and offset
 */
static float frand(float rng,float off)
{
    return rand()*rng/RAND_MAX+off;
}

/*
 *  Initialize particles
 */
void projectopengl::InitPart()
{
    //  Array Pointers
    float* vert  = Vert;
    float* color = Color;
    float* vel   = Vel;
    float* start = Start;
    //  Loop over NxN patch
    n = 15;
    
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
        {
            //  Location x,y,z
            //  1
            *vert++ = (i+0.5)/n+5.75;
            *vert++ = 3;
            *vert++ = (j+0.5)/n+22;
            //  2
            *vert++ = (i+0.5)/n-6.65;
            *vert++ = 3;
            *vert++ = (j+0.5)/n+22;
            //  3
            *vert++ = (i+0.5)/n-6.65;
            *vert++ = 3;
            *vert++ = (j+0.5)/n-0.75;
            //  4
            *vert++ = (i+0.5)/n+5.75;
            *vert++ = 3;
            *vert++ = (j+0.5)/n-0.75;
            //  Color r,g,b (0.5-1.0)
            *color++ = frand(0.5,0.5);
            *color++ = frand(0.5,0.5);
            *color++ = frand(0.5,0.5);
            //  Velocity
            *vel++ = frand( 1.0,3.0);
            *vel++ = frand(10.0,0.0);
            *vel++ = frand( 1.0,3.0);
            //  Launch time
            *start++ = frand(2.0,0.0);
        }
}

/*
 *  Draw particles
 */
void projectopengl::DrawPart(void)
{
    QOpenGLFunctions glf(QOpenGLContext::currentContext());
    //  Set particle size
    glPointSize(30);
    //  Point vertex location to local array Vert
    glVertexPointer(3,GL_FLOAT,0,Vert);
    //  Point color array to local array Color
    glColorPointer(3,GL_FLOAT,0,Color);
    //  Point attribute arrays to local arrays
    glf.glVertexAttribPointer(VELOCITY_ARRAY,3,GL_FLOAT,GL_FALSE,0,Vel);
    glf.glVertexAttribPointer(START_ARRAY,1,GL_FLOAT,GL_FALSE,0,Start);
    //  Enable arrays used by DrawArrays
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glf.glEnableVertexAttribArray(VELOCITY_ARRAY);
    glf.glEnableVertexAttribArray(START_ARRAY);
    //  Set transparent large particles
    glEnable(GL_POINT_SPRITE);
    glTexEnvi(GL_POINT_SPRITE,GL_COORD_REPLACE,GL_TRUE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE);
    glDepthMask(0);
    //  Draw arrays
    glDrawArrays(GL_POINTS,0,n*n);
    //  Reset
    glDisable(GL_POINT_SPRITE);
    glDisable(GL_BLEND);
    glDepthMask(1);
    //  Disable arrays
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glf.glDisableVertexAttribArray(VELOCITY_ARRAY);
    glf.glDisableVertexAttribArray(START_ARRAY);
}

//
//  Constructor
//
projectopengl::projectopengl(QWidget* parent)
    : CUgl(parent,false)
{
   N = 100;
   x0 = y0 = 0;
   z0 = 1;
   Vert  = new float[3*N*N];
   Color = new float[3*N*N];
   Vel   = new float[3*N*N];
   Start = new float[N*N];
   InitPart();
}

//
//  Initialize
//
void projectopengl::initializeGL()
{
    eyex = eyey = eyez = 0;
   // Load shaders
   addShader(":/ProceduralXZ.vert",":/Floor.frag");               // 0
   addShader(":/ProceduralXZ.vert",":/Stairs.frag");              // 1
   addShader(":/StoredTextureXY.vert",":/FrontdoorWall.frag");    // 2
   addShader(":/NoiseXY.vert","");                                // 3
   addShader(":/NoiseXY.vert",":/Wood.frag");                     // 4
   addShader(":/NoiseXY.vert",":/Water.frag");                    // 5
   addShader(":/StoredTextureXZ.vert",":/OuterGround.frag");      // 6
   addShader(":/StoredTextureXY.vert",":/Maindoor.frag");         // 7
   addShader(":/NoiseXY.vert",":/Leaf.frag");                     // 8
   addShader(":/Flame.vert",":/Flame.frag",Name);                 // 9
   addShader(":/NoiseXY.vert",":/Skin.frag");                     // 10
   addShader(":/ProceduralXY.vert",":/Cloth.frag");               // 11
   addShader(":/NoiseXY.vert",":/Metal.frag");                    // 12
   addShader(":/ProceduralXY.vert",":/Mask.frag");                // 13
   
   //
   // Create new instances of objects
   //

   Skytop* skytop = new Skytop(":/TropicalSunnyDayUp.bmp");
   Skyback* skyback = new Skyback(":/TropicalSunnyDayBack.bmp");
   Skyleft* skyleft = new Skyleft(":/TropicalSunnyDayLeft.bmp");
   Skyright* skyright = new Skyright(":/TropicalSunnyDayRight.bmp");
   Skyfront* skyfront = new Skyfront(":/TropicalSunnyDayFront.bmp");
    
   Skytop* skytopNight = new Skytop(":/FullMoonUp.bmp");
   Skyback* skybackNight = new Skyback(":/FullMoonBack.bmp");
   Skyleft* skyleftNight = new Skyleft(":/FullMoonLeft.bmp");
   Skyright* skyrightNight = new Skyright(":/FullMoonRight.bmp");
   Skyfront* skyfrontNight = new Skyfront(":FullMoonFront.bmp");
    
   Floor* floor = new Floor();
   Wall* wall = new Wall(":/stone.png");
   Stairs* stairs = new Stairs();
   Carpet* carpet = new Carpet();
    
   Tower* tower1 = new Tower(":/stone.png");
   tower1->setScale(3,3.5,3);
   tower1->setTranslate(-17,-2,-9);
    
   Tower* tower2 = new Tower(":/stone.png");
   tower2->setScale(3,3.5,3);
   tower2->setTranslate(17,-2,-9);
    
   Tower* tower3 = new Tower(":/stone.png");
   tower3->setScale(3,3.5,3);
   tower3->setTranslate(17,-2,19);
    
   Tower* tower4 = new Tower(":/stone.png");
   tower4->setScale(3,3.5,3);
   tower4->setTranslate(-17,-2,19);
    
   Cube* frame = new Cube();
   frame->setScale(8.3,4.3,0.1);
   frame->setTranslate(0,10,-9.8);
    
   Cube* scream = new Cube(":/scream.png");
   scream->setScale(8,4,0.01);
   scream->setTranslate(0,10,-9.7);
    
   Cube* frontdoor = new Cube(":/stone.png");
   frontdoor->setScale(15,11,0.5);
   frontdoor->setTranslate(0,9,20);
   frontdoor->setTex(5,5);
    
   Cube* citywall1 = new Cube(":/stone.png");
   citywall1->setScale(15,9,0.5);
   citywall1->setTranslate(-30,7,-10);
   citywall1->setTex(5,5);
    
   Cube* citywall2 = new Cube(":/stone.png");
   citywall2->setScale(15,9,0.5);
   citywall2->setTranslate(30,7,-10);
   citywall2->setTex(5,5);
    
   Cube* citywall3 = new Cube(":/stone.png");
   citywall3->setScale(10,9,0.5);
   citywall3->setTranslate(40,7,40);
   citywall3->setTex(5,5);
    
   Cube* citywall4 = new Cube(":/stone.png");
   citywall4->setScale(10,9,0.5);
   citywall4->setTranslate(-40,7,40);
   citywall4->setTex(5,5);
    
   Cube* citywall5 = new Cube(":/stone.png");
   citywall5->setScale(0.5,9,25);
   citywall5->setTranslate(-45,7,15);
   citywall5->setTex(5,5);
    
   Cube* citywall6 = new Cube(":/stone.png");
   citywall6->setScale(0.5,9,25);
   citywall6->setTranslate(45,7,15);
   citywall6->setTex(5,5);
    
   Cube* outercitywall1 = new Cube(":/stone.png");
    outercitywall1->setScale(120,11,0.5);
    outercitywall1->setTranslate(0,7,-105);
    outercitywall1->setTex(40,5);
    
    Cube* outercitywall2 = new Cube(":/stone.png");
    outercitywall2->setScale(120,11,0.5);
    outercitywall2->setTranslate(0,7,145);
    outercitywall2->setTex(40,5);
    
    Cube* outercitywall3 = new Cube(":/stone.png");
    outercitywall3->setScale(0.5,11,120);
    outercitywall3->setTranslate(-125,7,20);
    outercitywall3->setTex(40,5);
    
    Cube* outercitywall4 = new Cube(":/stone.png");
    outercitywall4->setScale(0.5,11,120);
    outercitywall4->setTranslate(125,7,20);
    outercitywall4->setTex(40,5);
    
   Tower* tower5 = new Tower(":/stone.png");
   tower5->setScale(5,3,5);
   tower5->setTranslate(-45,-2,-9);
    
   Tower* tower6 = new Tower(":/stone.png");
   tower6->setScale(5,3,5);
   tower6->setTranslate(45,-2,-9);
    
   Tower* tower7 = new Tower(":/stone.png");
   tower7->setScale(5,3,5);
   tower7->setTranslate(-45,-2,40);
    
   Tower* tower8 = new Tower(":/stone.png");
   tower8->setScale(5,3,5);
   tower8->setTranslate(45,-2,40);
    
   Tower* tower9 = new Tower(":/stone.png");
   tower9->setScale(5,3,5);
   tower9->setTranslate(125,-2,-105);
    
   Tower* tower10 = new Tower(":/stone.png");
   tower10->setScale(5,3,5);
   tower10->setTranslate(-125,-2,-105);
    
   Tower* tower11 = new Tower(":/stone.png");
   tower11->setScale(5,3,5);
   tower11->setTranslate(-125,-2,145);
    
   Tower* tower12 = new Tower(":/stone.png");
   tower12->setScale(5,3,5);
   tower12->setTranslate(125,-2,145);
    
   Cube* outerdoor = new Cube(":/stone.png");
   outerdoor->setScale(30,9,0.5);
   outerdoor->setTranslate(0,7,40);
   outerdoor->setTex(10,5);
    
   Cube* base = new Cube(":/grass.bmp");
   base->setScale(55,10,40);
   base->setTranslate(0,-12.5,20);
   base->setTex(5,5);
    
   Cube* river = new Cube();
   river->setScale(70,10,70);
   river->setTranslate(0,-25,20);
    
   Cube* ground = new Cube(":/grass.bmp");
   ground->setScale(125,10,125);
   ground->setTranslate(0,-12.5,20);
   ground->setTex(10,10);
    
   Cube* bridge = new Cube(":/stone.png");
   bridge->setScale(5,0.2,20);
   bridge->setTranslate(0,-2,75);
   bridge->setTex(5,5);
    
   Cube* lefthandrail = new Cube(":/stone.png");
   lefthandrail->setScale(0.2,2,20);
   lefthandrail->setTranslate(-5,0,75);
   lefthandrail->setTex(5,1);

   Cube* righthandrail = new Cube(":/stone.png");
   righthandrail->setScale(0.2,2,20);
   righthandrail->setTranslate(5,0,75);
   righthandrail->setTex(5,1);
    
   Roof* roof = new Roof();
    
   Cube* maindoor = new Cube(":/dark.bmp");
   maindoor->setScale(7,5,0.2);
   maindoor->setTranslate(0,4,40);
   maindoor->setTex(5,5);
    
   Leaf* leaf1 = new Leaf();
   leaf1->setScale(3,3,3);
   leaf1->setTranslate(30,3,0);
    
   Leaf* leaf2 = new Leaf();
   leaf2->setScale(3,3,3);
   leaf2->setTranslate(35,3,5);
    
   Leaf* leaf3 = new Leaf();
   leaf3->setScale(3,3,3);
   leaf3->setTranslate(30,3,15);
   
   Leaf* leaf4 = new Leaf();
   leaf4->setScale(3,3,3);
   leaf4->setTranslate(-30,3,15);
    
   Leaf* leaf5 = new Leaf();
   leaf5->setScale(3,3,3);
   leaf5->setTranslate(-40,3,5);
    
   Leaf* leaf6 = new Leaf();
   leaf6->setScale(3,3,3);
   leaf6->setTranslate(-30,3,50);
    
   Leaf* leaf7 = new Leaf();
   leaf7->setScale(3,3,3);
   leaf7->setTranslate(-80,3,50);
    
   Leaf* leaf8 = new Leaf();
   leaf8->setScale(3,3,3);
   leaf8->setTranslate(80,3,70);
    
   Leaf* leaf9 = new Leaf();
   leaf9->setScale(3,3,3);
   leaf9->setTranslate(100,3,-30);
    
   Leaf* leaf10 = new Leaf();
   leaf10->setScale(3,3,3);
   leaf10->setTranslate(-30,3,-50);
    
   Cylinder* root1 = new Cylinder();
   root1->setScale(1,5,1);
   root1->setTranslate(30,5,0);
    
   Cylinder* root2 = new Cylinder();
   root2->setScale(1,5,1);
   root2->setTranslate(35,5,0);
    
   Cylinder* root3 = new Cylinder();
   root3->setScale(1,5,1);
   root3->setTranslate(30,5,15);
    
   Cylinder* root4 = new Cylinder();
   root4->setScale(1,5,1);
   root4->setTranslate(-30,5,15);
    
   Cylinder* root5 = new Cylinder();
   root5->setScale(1,5,1);
   root5->setTranslate(-40,5,5);
    
   Cylinder* root6 = new Cylinder();
   root6->setScale(1,5,1);
   root6->setTranslate(-30,5,50);
    
   Cylinder* root7 = new Cylinder();
   root7->setScale(1,5,1);
   root7->setTranslate(-80,5,50);
    
   Cylinder* root8 = new Cylinder();
   root8->setScale(1,5,1);
   root8->setTranslate(80,5,70);
    
   Cylinder* root9 = new Cylinder();
   root9->setScale(1,5,1);
   root9->setTranslate(100,5,-30);
    
   Cylinder* root10 = new Cylinder();
   root10->setScale(1,5,1);
   root10->setTranslate(-30,5,-50);
    
   Cylinder* torch1 = new Cylinder();
   torch1->setScale(0.1,3,0.1);
   torch1->setTranslate(6.25,3,22.75);
    
   Cylinder* torch2 = new Cylinder();
   torch2->setScale(0.1,3,0.1);
   torch2->setTranslate(-6.25,3,22.75);
   
   Cylinder* torch3 = new Cylinder();
   torch3->setScale(0.1,3,0.1);
   torch3->setTranslate(-6.25,3,0);
   
   Cylinder* torch4 = new Cylinder();
   torch4->setScale(0.1,3,0.1);
   torch4->setTranslate(6.25,3,0);
   
   Cylinder* torchhead1 = new Cylinder(":/dark.bmp");
   torchhead1->setScale(0.3,0.5,0.3);
   torchhead1->setTranslate(6.25,3,22.75);
   
   Cylinder* torchhead2 = new Cylinder(":/dark.bmp");
   torchhead2->setScale(0.3,0.5,0.3);
   torchhead2->setTranslate(-6.25,3,22.75);
   
   Cylinder* torchhead3 = new Cylinder(":/dark.bmp");
   torchhead3->setScale(0.3,0.5,0.3);
   torchhead3->setTranslate(6.25,3,0);
   
   Cylinder* torchhead4 = new Cylinder(":/dark.bmp");
   torchhead4->setScale(0.3,0.5,0.3);
   torchhead4->setTranslate(-6.25,3,0);
    
   Human* human1 = new Human();
   human1->setGLtranslated(10,22,0);
   
   Human* human2 = new Human();
   human2->setGLtranslated(-10,22,0);
    
   Armor* armor1 = new Armor();
   armor1->setGLtranslated(10,22,0);
    
   Armor* armor2 = new Armor();
   armor2->setGLtranslated(-10,22,0);
    
   Cloth* cloth1 = new Cloth();
   cloth1->setGLtranslated(10,22,0);
    
   Cloth* cloth2 = new Cloth();
   cloth2->setGLtranslated(-10,22,0);
    
   Mask* mask1 = new Mask();
   mask1->setGLtranslated(10,22,0);
    
   Mask* mask2 = new Mask();
   mask2->setGLtranslated(-10,22,0);
    
   Sword* sword1 = new Sword();
   sword1->setGLtranslated(10,22,0);
    
   Sword* sword2 = new Sword();
   sword2->setGLtranslated(-10,22,0);
    

    
   //
   // Load objects
   //
   addObject(skytop);           // 0
   addObject(skyback);          // 1
   addObject(skyleft);          // 2
   addObject(skyright);         // 3
   addObject(skyfront);         // 4
   addObject(ground);           // 5
   addObject(floor);            // 6
   addObject(wall);             // 7
   addObject(stairs);           // 8
   addObject(carpet);           // 9
   addObject(tower1);           // 10
   addObject(tower2);           // 11
   addObject(frame);            // 12
   addObject(scream);           // 13
   addObject(frontdoor);        // 14
   addObject(tower3);           // 15
   addObject(tower4);           // 16
   addObject(citywall1);        // 17
   addObject(citywall2);        // 18
   addObject(citywall3);        // 19
   addObject(citywall4);        // 20
   addObject(citywall5);        // 21
   addObject(citywall6);        // 22
   addObject(tower5);           // 23
   addObject(tower6);           // 24
   addObject(tower7);           // 25
   addObject(tower8);           // 26
   addObject(outerdoor);        // 27
   addObject(base);             // 28
   addObject(river);            // 29
   addObject(bridge);           // 30
   addObject(lefthandrail);     // 31
   addObject(righthandrail);    // 32
   addObject(roof);             // 33
   addObject(maindoor);         // 34
   addObject(leaf1);            // 35
   addObject(leaf2);            // 36
   addObject(leaf3);            // 37
   addObject(leaf4);            // 38
   addObject(leaf5);            // 39
   addObject(leaf6);            // 40
   addObject(root1);            // 41
   addObject(root2);            // 42
   addObject(root3);            // 43
   addObject(root4);            // 44
   addObject(root5);            // 45
   addObject(root6);            // 46
   addObject(skytopNight);      // 47
   addObject(skyfrontNight);    // 48
   addObject(skybackNight);     // 49
   addObject(skyleftNight);     // 50
   addObject(skyrightNight);    // 51
   addObject(torch1);           // 52
   addObject(torchhead1);       // 53
   addObject(torch2);           // 54
   addObject(torchhead2);       // 55
   addObject(torch3);           // 56
   addObject(torch4);           // 57
   addObject(torchhead3);       // 58
   addObject(torchhead4);       // 59
   addObject(human1);           // 60
   addObject(human2);           // 61
   addObject(outercitywall1);   // 62
   addObject(outercitywall2);   // 63
   addObject(outercitywall3);   // 64
   addObject(outercitywall4);   // 65
   addObject(tower9);           // 66
   addObject(tower10);          // 67
   addObject(tower11);          // 68
   addObject(tower12);          // 69
   addObject(armor1);           // 70
   addObject(armor2);           // 71
   addObject(cloth1);           // 72
   addObject(cloth2);           // 73
   addObject(mask1);            // 74
   addObject(mask2);            // 75
   addObject(sword1);           // 76
   addObject(sword2);           // 77
   addObject(leaf7);            // 78
   addObject(leaf8);            // 79
   addObject(leaf9);            // 80
   addObject(leaf10);           // 81
   addObject(root7);            // 82
   addObject(root8);            // 83
   addObject(root9);            // 84
   addObject(root10);           // 85
    
   //  Set noise texture
   CreateNoise3D(GL_TEXTURE1);
   tex = loadImage(":/particle.png");
}

//
//  Draw the window
//
void projectopengl::paintGL()
{
    //  Wall time (seconds)
    float pt = 0.001*time.elapsed();
    zh = fmod(90*pt,360);
   //  Clear screen and Z-buffer
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glEnable(GL_DEPTH_TEST);
   //  Move the skybox based on camera position
   objects[0]->setTranslate(CUgl::eyex,CUgl::eyey,CUgl::eyez);
   objects[1]->setTranslate(CUgl::eyex,CUgl::eyey,CUgl::eyez);
   objects[2]->setTranslate(CUgl::eyex,CUgl::eyey,CUgl::eyez);
   objects[3]->setTranslate(CUgl::eyex,CUgl::eyey,CUgl::eyez);
   objects[4]->setTranslate(CUgl::eyex,CUgl::eyey,CUgl::eyez);
   objects[47]->setTranslate(CUgl::eyex,CUgl::eyey,CUgl::eyez);
   objects[48]->setTranslate(CUgl::eyex,CUgl::eyey,CUgl::eyez);
   objects[49]->setTranslate(CUgl::eyex,CUgl::eyey,CUgl::eyez);
   objects[50]->setTranslate(CUgl::eyex,CUgl::eyey,CUgl::eyez);
   objects[51]->setTranslate(CUgl::eyex,CUgl::eyey,CUgl::eyez);
    
   QVector3D loc(x0,y0,1/z0);
   //  Apply projection
   doModelViewProjection();
   float t = getTime();
   //
   //  No lighting here
   //

    if(CUgl::day){
        objects[0]->display();
        objects[1]->display();
        objects[2]->display();
        objects[3]->display();
        objects[4]->display();
    }
    else{
        objects[47]->display();
        objects[48]->display();
        objects[49]->display();
        objects[50]->display();
        objects[51]->display();
    }
    
   //
   //  Draw objects under light
   //
   doLight();
    
   //**** Outer ground shader ****//
   shader[6]->bind();
   shader[6]->setUniformValue("loc",loc);
   objects[5]->display();                       // Outer Ground
   shader[6]->release();
    
   //**** Floor shader ****//
   shader[0]->bind();
   shader[0]->setUniformValue("loc",loc);
   objects[6]->display();                       // Floor
   objects[33]->display();                      // Roof
   shader[0]->release();
    
   objects[7]->display();                       // Castle Wall
    
   //**** Stair shader ****//
   shader[1]->bind();
   shader[1]->setUniformValue("loc",loc);
   objects[8]->display();                       // Stairs
   shader[1]->release();
    
   objects[9]->display();                       // Carpet
   
   //**** No fragment ****//
   shader[3]->bind();
   shader[3]->setUniformValue("Noise3D",1);
   objects[10]->display();                      // Watch towers
   objects[11]->display();
   objects[15]->display();
   objects[16]->display();
   objects[23]->display();
   objects[24]->display();
   objects[25]->display();
   objects[26]->display();
   objects[66]->display();
   objects[67]->display();
   objects[68]->display();
   objects[69]->display();
    
   objects[53]->display();                     // Torch heads
   objects[55]->display();
   objects[58]->display();
   objects[59]->display();
    
   objects[76]->display();                     // Sword
   objects[77]->display();
   shader[3]->release();
   
   //**** wood shader****//
   shader[4]->bind();
   shader[4]->setUniformValue("Noise3D",1);
   objects[12]->display();                      // Frame
   objects[41]->display();                      // Roots
   objects[42]->display();
   objects[43]->display();
   objects[44]->display();
   objects[45]->display();
   objects[46]->display();
   objects[82]->display();
   objects[83]->display();
   objects[84]->display();
   objects[85]->display();
   objects[52]->display();                     // Torches
   objects[54]->display();
   objects[56]->display();
   objects[57]->display();
   shader[4]->release();
   
   objects[13]->display();                      // Drawing: scream
    
   //**** Front Wall shader ****//
   shader[2]->bind();
   shader[2]->setUniformValue("loc",loc);
   objects[14]->display();                      // Front wall 1
   objects[27]->display();                      // Front wall 2
   shader[2]->release();
    
   objects[17]->display();                      // City walls
   objects[18]->display();
   objects[19]->display();
   objects[20]->display();
   objects[21]->display();
   objects[22]->display();
   objects[62]->display();                     // Outer city walls
   objects[63]->display();
   objects[64]->display();
   objects[65]->display();
    
   objects[28]->display();                      // Inner ground
    
   //**** River shader ****//
   shader[5]->bind();
   shader[5]->setUniformValue("time",t);
   shader[5]->setUniformValue("Noise3D",1);
   shader[5]->setUniformValue("loc",loc);
   objects[29]->display();                      // River
   shader[5]->release();
    
   objects[30]->display();                      // bridge
   objects[31]->display();
   objects[32]->display();
    
   //**** Maindoor shader ****//
   shader[7]->bind();
   shader[7]->setUniformValue("loc",loc);
   objects[34]->display();                      // Maindoor
   shader[7]->release();
    
   //**** Leaf shader ****//
   shader[8]->bind();
   shader[8]->setUniformValue("time",t);
   shader[8]->setUniformValue("Noise3D",1);
   shader[8]->setUniformValue("loc",loc);
   objects[35]->display();                      // Upper part of trees
   objects[36]->display();
   objects[37]->display();
   objects[38]->display();
   objects[39]->display();
   objects[40]->display();
   objects[78]->display();
   objects[79]->display();
   objects[80]->display();
   objects[81]->display();
   shader[8]->release();
    
   //**** Skin shader ****//
   shader[10]->bind();
   shader[10]->setUniformValue("time",t);
   shader[10]->setUniformValue("Noise3D",1);
   shader[10]->setUniformValue("loc",loc);
   objects[60]->display();                     //  Human
   objects[61]->display();
   shader[10]->release();
    
   //**** Cloth shader ****//
    shader[11]->bind();
    shader[11]->setUniformValue("loc",loc);
    objects[72]->display();                     // Cloth
    objects[73]->display();
    shader[11]->release();
    
    if(eqp){
        //**** Metal shader ****//
        shader[12]->bind();
        shader[12]->setUniformValue("time",t);
        shader[12]->setUniformValue("Noise3D",1);
        shader[12]->setUniformValue("loc",loc);
        objects[70]->display();                     // Armor
        objects[71]->display();
        shader[10]->release();
        
        //**** Mask shader ****//
        shader[13]->bind();
        shader[13]->setUniformValue("loc",loc);
        objects[74]->display();                     // Mask
        objects[75]->display();
        shader[13]->release();
    }
   glDisable(GL_LIGHTING);
    //**** Flame shader ****//
    if(!day){
        tex->bind();
        shader[9]->bind();
        shader[9]->setUniformValue("time",pt);
        shader[9]->setUniformValue("img",0);
        shader[9]->setUniformValue("Noise3D",1);
        DrawPart();
        shader[9]->release();
    }
   
   glDisable(GL_DEPTH_TEST);
   //  Emit centers to display
   emit zoom(QString::number((int)z0));
}
