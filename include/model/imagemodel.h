#ifndef IMAGEMODEL_H
#define IMAGEMODEL_H

#include <QObject>
#include <QImage>

class ImageModel : public QObject
{
    Q_OBJECT

public:
    explicit ImageModel(QObject *parent = nullptr);

    QImage adjustRGB(const QImage &image, int red, int green, int blue);
    QImage resizeImage(const QImage &image, int width, int height);
    QImage getCurrentImage() const;
    void setCurrentImage(const QImage &image);

private:
    QImage currentImage;
};

#endif // IMAGEMODEL_H
