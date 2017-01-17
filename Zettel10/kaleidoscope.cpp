#include <iostream>
#include <cassert>
#include "image.hpp"

inline void wait_on_enter() {
    std::string dummy;
    std::cout << "Enter to continue..." << std::endl;
    std::getline(std::cin, dummy);
}

Image mirror_x(Image const &image) {
    int imageHeight = image.height();
    int imageWidth = image.width();
    int mirrorWidth = imageWidth * 2;
    Image mirrorImage(mirrorWidth, imageHeight);
    for (int height = 0; height < imageHeight; ++height) {
        for (int width = 0; width < mirrorWidth; ++width) {
            if (width < imageWidth) {
                auto p = &mirrorImage.operator()(width, height);
                *p = image.operator()(width, height);
            }
            else {
                auto p = &mirrorImage.operator()(width, height);
                *p = image.operator()(mirrorWidth - width - 1, height);
            }
        }
    }
    return mirrorImage;
}

Image mirror_y(Image const &image) {
    int imageHeight = image.height();
    int imageWidth = image.width();
    int mirrorHeight = imageHeight * 2;
    Image mirrorImage(imageWidth, mirrorHeight);
    for (int height = 0; height < mirrorHeight; ++height) {
        for (int width = 0; width < imageWidth; ++width) {
            if (height < imageHeight) {
                auto p = &mirrorImage.operator()(width, height);
                *p = image.operator()(width, height);
            }
            else {
                auto p = &mirrorImage.operator()(width, height);
                *p = image.operator()(width, (mirrorHeight - height) - 1);
            }
        }
    }
    return mirrorImage;
}

Image kaleidoscope4(Image const &image) {
    Image mirrorImage = mirror_x(image);
    Image mirrorMirrorImage = mirror_y(mirrorImage);
    return mirrorMirrorImage;
}

Image kaleidoscope8(Image const &image) {
    int imageHeight = image.height();
    int imageWidth = image.width();
    Image diagonal(imageWidth, imageHeight);
    for (int height = 0; height < imageHeight; ++height) {
        for (int width = 0; width < imageWidth; ++width) {
            if (width < height) {
                auto p = &diagonal.operator()(width, height);
                *p = image.operator()(width, height);
            }
            else {
                auto p = &diagonal.operator()(width, height);
                *p = image.operator()(height, width);
            }
        }
    }
    return kaleidoscope4(diagonal);
}

int main() {
    Image Lena = readPGM("lena.pgm");
    Image mirrorX = mirror_x(Lena);
    Image mirrorY = mirror_y(Lena);
    Image mirrorXY = kaleidoscope4(Lena);
    Image diagonal = kaleidoscope8(Lena);
    Image mirrorXTest = readPGM("mirror_x_test.pgm");
    Image mirrorYTest = readPGM("mirror_y_test.pgm");
    Image mirrorXYTest = readPGM("kaleidoskop4_test.pgm");
    Image kaleidoscope = readPGM("kaleidoskop8_test.pgm");
    Image my_image = readPGM("my_image.pgm");
    Image my_kaleidoscope = kaleidoscope8(my_image);
    assert(mirrorX == mirrorXTest);
    assert(mirrorY == mirrorYTest);
    assert(mirrorXY == mirrorXYTest);
    assert(kaleidoscope == diagonal);
    writePGM(my_kaleidoscope, "my_kaleidoscope.pgm");
    wait_on_enter();
}