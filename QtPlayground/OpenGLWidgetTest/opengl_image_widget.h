#pragma once

#include <QImage>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QPainter>

class OpenGLImageWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit OpenGLImageWidget(QWidget *parent = nullptr);

    void setImage(const QImage &image);

protected:
    void initializeGL() override;

    void paintGL() override;

    void resizeGL(int w, int h) override;

private:
    QImage image;      // 存储要显示的QImage对象
    QRect m_targetPos; // 目标位置
};
