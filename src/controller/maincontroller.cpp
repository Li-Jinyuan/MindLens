#include "include/controller/maincontroller.h"
#include <QFileDialog>
#include <QPixmap>

MainController::MainController(ImageModel *model, QObject *parent)
    : QObject(parent), model(model)
{
}

void MainController::selectImage()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr,
        tr("选择图片"), "", tr("图片文件 (*.png *.jpg *.bmp)"));
        
    if (!fileName.isEmpty()) {
        QPixmap pixmap(fileName);
        if (!pixmap.isNull()) {
            QImage image = pixmap.toImage();
            model->setCurrentImage(image);
            emit imageChanged(image);
        }
    }
}

void MainController::adjustRGB(int red, int green, int blue)
{
    // 调用Model进行图像处理并触发更新
    QImage result = model->adjustRGB(model->getCurrentImage(), red, green, blue);
    model->setCurrentImage(result);
    emit imageChanged(result);
}

void MainController::resizeImage(int width, int height)
{
    // 调用Model进行图像缩放并触发更新
    QImage result = model->resizeImage(model->getCurrentImage(), width, height);
    model->setCurrentImage(result);
    emit imageChanged(result);
}
