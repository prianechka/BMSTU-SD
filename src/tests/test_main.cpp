#include <gtest/gtest.h>

int test_main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

int main(int argc, char *argv[])
{
    test_main(argc, argv);
}
