//
// Created by nikita on 9/22/22.
//

#include "image.h"
#include <gtest.h>

TEST(test_lib, simple_test) {
    cout << "----------Test----------" << endl;

    ImageInit_v1 image(2, 2);
    image.show();

    image.writeF("test.txt");

    ImageInit_v1 image2;
    image2.readF("test.txt");
    image2.show();




}
