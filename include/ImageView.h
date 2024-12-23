#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class ImageView {
public:
    void renderImageView(int width, int height);
    void renderToolbar(int width, int height);
    void renderThumbnail(int width, int height);
};