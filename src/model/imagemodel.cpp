#include "../include/model/imagemodel.h"
#include <QDebug>
#include <QtMath>

ImageModel::ImageModel(QObject *parent) : QObject(parent)
{
    currentImage = QImage(800, 600, QImage::Format_RGB32);
    currentImage.fill(Qt::white);
}

QImage ImageModel::adjustRGB(const QImage &image, int red, int green, int blue)
{
    QImage result = image;
    for (int y = 0; y < result.height(); y++) {
        for (int x = 0; x < result.width(); x++) {
            QRgb pixel = result.pixel(x, y);
            int r = qRed(pixel) + red;
            int g = qGreen(pixel) + green;
            int b = qBlue(pixel) + blue;
            
            r = qBound(0, r, 255);
            g = qBound(0, g, 255);
            b = qBound(0, b, 255);
            
            result.setPixel(x, y, qRgb(r, g, b));
        }
    }
    return result;
}

QImage ImageModel::resizeImage(const QImage &image, int width, int height)
{
    QImage result = image.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    currentImage = result;
    return result;
}

QImage ImageModel::getCurrentImage() const
{
    return currentImage;
}

void ImageModel::setCurrentImage(const QImage &image)
{
    currentImage = image;
}
