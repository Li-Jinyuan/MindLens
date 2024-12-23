#pragma once
#include "ImageModel.h"
#include "ImageView.h"
#include <GLFW/glfw3.h>

class ImageController {
private:
    ImageModel model;
    ImageView view;
    GLFWwindow* window;
    int width;
    int height;

public:
    ImageController(int w, int h, const char* title);
    ~ImageController();
    void run();
    void processInput();
    void render();
};