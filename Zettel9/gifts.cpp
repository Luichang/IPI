#include <iostream>
#include <vector>
#include "rect.cpp"
#include "gifts.txt"

template<typename T>
void printVectors(std::vector<T> printV) {
    for (auto i : printV) {
        std::cout << i << ", ";
    }
    std::cout << "\b\b " << std::endl;
}

double bssf_score(Rectangle const &free, Rectangle const &obj) {
    double newWidth = free.width() - obj.width();
    double newHeight = free.height() - obj.height();
    if (newHeight < 0 || newWidth < 0) {
        return 1e300;
    }
    else if (newHeight < newWidth){
        return newHeight;
    }
    else {
        return newWidth;
    }
    

}


int main(){
    std::vector<Rectangle> to_be_placed;
    std::vector<Rectangle> already_placed;
    std::vector<Rectangle> free_rectangles;
    to_be_placed = gifts;
    to_be_placed.push_back(tree_stand);
    free_rectangles.push_back(table);
    double smallestBSSF;
    Rectangle smallestGift;
    Rectangle smallestFree;
    bool transposed = false;
    int smallestGiftIndex, smallestFreeIndex;
    do {
        for (int i = 0; i < to_be_placed.size(); ++i)
        {
            smallestBSSF = 8000;
            for (int j = 0; j < free_rectangles.size(); ++j)
            {
                double bssfScore = bssf_score(free_rectangles[j], to_be_placed[i]);
                if (bssfScore < smallestBSSF) {
                    smallestBSSF = bssfScore;
                    smallestGift = to_be_placed[i];
                    smallestFree = free_rectangles[j];
                    transposed = false;
                    smallestGiftIndex = i;
                    smallestFreeIndex = j;
                }
                to_be_placed[i] = to_be_placed[i].transpose();
                bssfScore = bssf_score(free_rectangles[j], to_be_placed[i]);
                if (bssfScore < smallestBSSF) {
                    smallestBSSF = bssfScore;
                    smallestGift = to_be_placed[i];
                    smallestFree = free_rectangles[j];
                    transposed = true;
                    smallestGiftIndex = i; 
                    smallestFreeIndex = j;
                }
            }
        }
        smallestGift.translate(smallestFree.p0());
        already_placed.push_back(smallestGift);
        Rectangle new1;
        Rectangle new2;
        if (free_rectangles[smallestFreeIndex].width() < free_rectangles[smallestFreeIndex].height()) {
            Rectangle n1(
                Point(to_be_placed[smallestGiftIndex].x0(), 
                    to_be_placed[smallestGiftIndex].y1()),
                Point(free_rectangles[smallestFreeIndex].p1())
            );
            Rectangle n2(
                Point(to_be_placed[smallestGiftIndex].x1(),
                    to_be_placed[smallestGiftIndex].y0()),
                Point(free_rectangles[smallestFreeIndex].x1(), 
                    to_be_placed[smallestGiftIndex].y1())
            );
            new1 = n1;
            new2 = n2;
        }
        else {
            Rectangle n1(
                Point(to_be_placed[smallestGiftIndex].x0(),
                    to_be_placed[smallestGiftIndex].y1()),
                Point(to_be_placed[smallestGiftIndex].x1(),
                    free_rectangles[smallestFreeIndex].y1())
            );
            Rectangle n2(
                Point(to_be_placed[smallestGiftIndex].x1(),
                    to_be_placed[smallestGiftIndex].y0()),
                Point(free_rectangles[smallestFreeIndex].p1())
            );
            new1 = n1;
            new2 = n2;
        }
        free_rectangles.erase(free_rectangles.begin() + smallestFreeIndex);
        to_be_placed.erase(to_be_placed.begin() + smallestGiftIndex);
        free_rectangles.push_back(new1);
        free_rectangles.push_back(new2);
    } while (smallestBSSF < 8000);
    std::cout << to_string(free_rectangles[0].p0()) << " ";
    std::cout << to_string(free_rectangles[0].p1()) << std::endl;
    std::cout << to_string(free_rectangles[1].p0()) << " ";
    std::cout << to_string(free_rectangles[1].p1()) << std::endl;
    std::cout << to_string(free_rectangles[2].p0()) << " ";
    std::cout << to_string(free_rectangles[2].p1()) << std::endl;
    std::cout << to_string(free_rectangles[3].p0()) << " ";
    std::cout << to_string(free_rectangles[3].p1()) << std::endl;
    wait_on_enter();
}