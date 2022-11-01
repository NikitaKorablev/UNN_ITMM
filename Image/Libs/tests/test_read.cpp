//
// Created by nikita on 9/22/22.
//

#include "image.h"
#include <gtest.h>

TEST(test_lib, simple_test) {
    cout << "----------Test----------" << endl;

    int h = 2, w = 2;

    ImageInit_v1 image(h, w);
    image.show();

    image.writeF("test.txt");

    ImageInit_v1 image2;
    image2.readF("test.txt");
    image2.show();

    image2.getPixel(0, 0) = 255;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            EXPECT_EQ(image.getPixel(i, j), image2.getPixel(i, j));
        }
    }
}
