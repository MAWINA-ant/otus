#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "lib.h"

using namespace std;

TEST(TestVersion, Subtest_1) {
	ASSERT_TRUE(version() > 0);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	::testing::InitGoogleMock(&argc, argv);

	return RUN_ALL_TESTS();
}
