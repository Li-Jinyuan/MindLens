#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class ImageEditor {
private:
    GLFWwindow* window;
    int width;
    int height;
    
    // UI布局参数
    struct {
        float imageViewX = 0.0f;
        float imageViewY = 0.0f;
        float imageViewWidth = 0.8f;
        float imageViewHeight = 0.85f;
        float toolbarX = 0.8f;
        float toolbarWidth = 0.2f;
        float thumbnailY = 0.85f;
        float thumbnailHeight = 0.15f;
    } layout;

public:
    ImageEditor(int w, int h, const char* title);
    ~ImageEditor();
    
    void run();
    
private:
    bool init();
    void processInput();
    void render();
    void renderImageView();
    void renderToolbar(); 
    void renderThumbnail();
    
    static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
}; 