#include "ImageView.h"

void ImageView::renderImageView(int width, int height) {
    // 图像视图区域渲染
    glViewport(0, 0, width, height);
    // TODO: 实现图像渲染逻辑
}

void ImageView::renderToolbar(int width, int height) {
    // 工具栏区域渲染
    glViewport(width * 0.8f, 0, width * 0.2f, height * 0.85f);
    // TODO: 实现工具栏渲染逻辑
}

void ImageView::renderThumbnail(int width, int height) {
    // 缩略图区域渲染
    glViewport(0, height * 0.85f, width * 0.8f, height * 0.15f);
    // TODO: 实现缩略图渲染逻辑
}   