#include "helpers.cc"

void test_string(std::string str, std::string real) {
	auto value = test_token(str, LiteralKind::String);
	ASSERT(std::get<std::string>(value.value()) == real)
}

void test() {
	test_string("\"\"", "");
	test_string("\"foo\"", "foo");
	test_string("\"foo bar\"", "foo bar");
}

TEST(test();)