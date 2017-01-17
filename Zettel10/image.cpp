#include <iostream>
#include <cassert>
#include "image.hpp"

Image checkerBoard(Image const &im) {
    Image img(im.width(), im.height());
    for (int h = 0; h < img.height(); h++) {
        for (int w = 0; w < img.width(); w++) {
            if (h % 2 == 0) {                       // by having it do something different every second pixelheight it ensures that the checkerboard pattern runns down the columns
                if (w % 2 == 0) {
                    auto p = &img.operator()(w, h); //  by having it check every second pixelwidth it ensures that the checkerboard pattern runns accross the rows
                    *p = 0;
                }
                else {
                    auto p = &img.operator()(w, h);
                    *p = 255;
                }
            }
            else {
                if (w % 2 == 0) {
                    auto p = &img.operator()(w, h);
                    *p = 255;
                }
                else {
                    auto p = &img.operator()(w, h);
                    *p = 0;
                }
            }
        }
    }
    return img;
}

Image chessboard(unsigned int width, unsigned int height, unsigned int square_size) {    Image img(width, height);
    //int counter = 0;
    for (int h = 0; h < img.height(); h += square_size) {
        for (int w = 0; w < img.width(); w += square_size) {
            int nw = w;
            int nh = h;
            int counter = 0;
            while (nw != 0) {
                nw -= square_size;      // needed a way to get a counter to have every other square be white which is why I added dummy numbers that will increase the counter for every iteration of the while loop
                ++counter;
            }
            while (nh != 0) {
                nh -= square_size;
                ++counter;
            }
            if (counter % 2 != 0) {
                for (int sqh = 0; sqh < square_size; sqh++) {       // could not figure out a way to not use the quad for loops
                    for (int sqw = 0; sqw < square_size; sqw++) {
                        auto p = &img.operator()(w + sqw, h + sqh);
                        *p = 255;
                    }
                }
            }
        }
    }
    return img;}Image invert_image(Image const &image) {    Image invert(image.width(), image.height());    for (int h = 0; h < image.height(); h++) {
        for (int w = 0; w < image.width(); w++) {            auto p = &invert.operator()(w, h);
            *p = 255 - image.operator()(w, h);      // reading the points of the original and subtracting 255 from it to have the inverted pixel        }    }    return invert;}

inline void wait_on_enter() {
    std::string dummy;
    std::cout << "Enter to continue..." << std::endl;
    std::getline(std::cin, dummy);
}

int main() {
    Image b(4, 3);
    assert(b.height() == 3 && b.width() == 4);
    for (int h = 0; h < b.height(); h++) {
        for (int w = 0; w < b.width(); w++) {
            assert(b.operator()(w, h) == 0);
        }
    }
    Image newB = checkerBoard(b);
    writePGM(newB, "board4x3.pgm");
    std::cout << to_string(newB);
    Image chess4x3 = readPGM("board4x3.pgm");
    assert(newB == chess4x3);
    Image chessBoard4x3 = chessboard(4, 3, 1);
    assert(chessBoard4x3 == chess4x3);
    
    Image board400x300 = chessboard(400, 300, 20);
    Image board400x300_inverse = invert_image(board400x300);
    writePGM(board400x300_inverse, "board400x300_inverse.pgm");
    Image newBoard400x300 = readPGM("board400x300.pgm");
    assert(board400x300 == newBoard400x300);
    Image newBoard400x300_inverse = readPGM("board400x300_inverse.pgm");
    assert(board400x300_inverse == newBoard400x300_inverse);
    Image Lena = readPGM("lena.pgm");
    Image lenaInverse = invert_image(Lena);
    writePGM(lenaInverse, "lenaInverse.pgm");
    wait_on_enter();
}