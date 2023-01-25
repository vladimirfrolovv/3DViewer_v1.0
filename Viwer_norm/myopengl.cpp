#include "myopengl.h"

Myopengl::Myopengl(QWidget *parent )
    : QOpenGLWidget{parent}
{

}

void Myopengl::initializeGL()
{
    float r, g, b, a =1.0f;
    initializeOpenGLFunctions();
    qColorToRGB(Qt::black,r,g,b);
    glClearColor(r, g, b, a);

}
void Myopengl::resizeGL(int w, int h)
{

}
void Myopengl::paintGL()
{

}
void Myopengl::qColorToRGB(const QColor &C, float &r, float &g, float &b) const
{
   int red =  C.red();
   int green =  C.green();
    int blue = C.blue();
   r=  normaliza_0_1(red, 1.0f, 255.0f);
     g=  normaliza_0_1(green, 1.0f, 255.0f);
    b=  normaliza_0_1(blue, 1.0f, 255.0f);
}
int Myopengl::normaliza_0_1(float val, float min,float max ) const{
    return (val -min) / (max -min);
}
