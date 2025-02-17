#include "include/view/mainwindow.h"
#include "ui_mainwindow.h"
#include "include/controller/maincontroller.h"
#include "../include/model/imagemodel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 初始化Model和Controller
    ImageModel *model = new ImageModel(this);
    MainController *controller = new MainController(model, this);

    // 显示初始图像
    ui->imageLabel->setPixmap(QPixmap::fromImage(model->getCurrentImage()).scaled(
        ui->imageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // 连接Controller的信号到UI更新
    connect(controller, &MainController::imageChanged, this, [this](const QImage &image) {
        ui->imageLabel->setPixmap(QPixmap::fromImage(image).scaled(
            ui->imageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    });

    // 连接UI事件到Controller
    connect(ui->selectImageButton, &QPushButton::clicked,
            controller, &MainController::selectImage);

    connect(ui->redSlider, &QSlider::valueChanged, this, [controller, this]() {
        controller->adjustRGB(ui->redSlider->value(),
                            ui->greenSlider->value(),
                            ui->blueSlider->value());
        ui->redValueLabel->setText(QString::number(ui->redSlider->value()));
    });

    connect(ui->greenSlider, &QSlider::valueChanged, this, [controller, this]() {
        controller->adjustRGB(ui->redSlider->value(),
                            ui->greenSlider->value(),
                            ui->blueSlider->value());
        ui->greenValueLabel->setText(QString::number(ui->greenSlider->value()));
    });

    connect(ui->blueSlider, &QSlider::valueChanged, this, [controller, this]() {
        controller->adjustRGB(ui->redSlider->value(),
                            ui->greenSlider->value(),
                            ui->blueSlider->value());
        ui->blueValueLabel->setText(QString::number(ui->blueSlider->value()));
    });

    connect(ui->applyButton, &QPushButton::clicked, this, [controller, this]() {
        bool widthOk, heightOk;
        int width = ui->widthInput->text().toInt(&widthOk);
        int height = ui->heightInput->text().toInt(&heightOk);
        
        if (widthOk && heightOk && width > 0 && height > 0) {
            controller->resizeImage(width, height);
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
