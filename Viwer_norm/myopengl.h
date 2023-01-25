#ifndef MYOPENGL_H
#define MYOPENGL_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QColor>
//#include <GLUT>>
class Myopengl : public QOpenGLWidget, public QOpenGLFunctions
{
public:
    Myopengl(QWidget *parent = nullptr);
protected:
    void initializeGL()override;
    void resizeGL(int w, int h)override;
    void paintGL()override;

private:
        void qColorToRGB(const QColor &C, float &r, float &g, float &b) const;
        int normaliza_0_1(float val, float min,float max ) const;
};

#endif // MYOPENGL_H
