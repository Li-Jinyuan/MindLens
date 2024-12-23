#include "ImageController.h"
#include <iostream>

ImageController::ImageController(int w, int h, const char* title) : width(w), height(h) {
    if (!glfwInit()) {
        std::cout << "初始化GLFW失败" << std::endl;
        return;
    }

    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) {
        std::cout << "创建窗口失败" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "初始化GLAD失败" << std::endl;
        return;
    }
}

ImageController::~ImageController() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void ImageController::run() {
    while (!glfwWindowShouldClose(window)) {
        processInput();
        render();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void ImageController::processInput() {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void ImageController::render() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    view.renderImageView(width, height);
    view.renderToolbar(width, height);
    view.renderThumbnail(width, height);
}