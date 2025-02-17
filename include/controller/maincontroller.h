#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include "model/imagemodel.h"

class MainController : public QObject
{
    Q_OBJECT

signals:
    void imageChanged(const QImage &image);

public:
    explicit MainController(ImageModel *model, QObject *parent = nullptr);

public slots:
    void selectImage();
    void adjustRGB(int red, int green, int blue);
    void resizeImage(int width, int height);

private:
    ImageModel *model;
};

#endif // MAINCONTROLLER_H
