#include "gtest/gtest.h"

int main(int argc, char **argv) {
    //disable cout by setting failbit, remove this line or call std::cout.clear()
    std::cout.setstate(std::ios_base::failbit);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}