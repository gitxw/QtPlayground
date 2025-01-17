#include "opengl_image_widget.h"

OpenGLImageWidget::OpenGLImageWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{}

void OpenGLImageWidget::setImage(const QImage &image)
{
    this->image = image;
    update(); // 触发重绘
}

void OpenGLImageWidget::initializeGL() /*override*/
{
    // 初始化OpenGL资源和状态
    initializeOpenGLFunctions();
}

void OpenGLImageWidget::paintGL() /*override*/
{
    glClear(GL_COLOR_BUFFER_BIT);          // 清除屏幕
    QPainter painter(this);                // 创建一个QPainter对象用于绘制QImage
    painter.drawImage(m_targetPos, image); // 在窗口的(0,0)位置绘制image
}

void OpenGLImageWidget::resizeGL(int w, int h) /*override*/
{
    // 设置视口和其他投影设置
    m_targetPos = QRect(0, 0, w, h);
}
