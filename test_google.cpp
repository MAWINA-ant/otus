#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "utils.h"

using namespace std;


// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
TEST(Utils_split, test1) {
    ASSERT_TRUE(Utils::split("", '.') == std::vector<std::string>({""}));
}

TEST(Utils_split, test2) {
    ASSERT_TRUE(Utils::split("11", '.') == std::vector<std::string>({"11"}));
}

TEST(Utils_split, test3) {
    ASSERT_TRUE(Utils::split("..", '.') == std::vector<std::string>({"", "", ""}));
}

TEST(Utils_split, test4) {
    ASSERT_TRUE(Utils::split(".11", '.') == std::vector<std::string>({"", "11"}));
}

TEST(Utils_split, test5) {
    ASSERT_TRUE(Utils::split("11.12", '.') == std::vector<std::string>({"11", "12"}));
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	::testing::InitGoogleMock(&argc, argv);

	return RUN_ALL_TESTS();
}
