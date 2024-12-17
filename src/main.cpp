#include "ImageEditor.h"
#include <iostream>

int main() {
    try {
        ImageEditor editor(1280, 800, "图像编辑器");
        editor.run();
    } catch (const std::exception & e) {
        std::cerr << "错误: " << e.what() << std::endl;
        return -1;
    }
    return 0;
}
