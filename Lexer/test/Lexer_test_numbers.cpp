#include "helpers.cc"
#include <sstream>

void test_int(std::string str, std::int64_t real) {
	auto value = test_token(str, LiteralKind::Int);
	try
	{ ASSERT_EQ(std::get<std::int64_t>(value.value()), real) } catch (std::exception&)
	{
		std::cout << "Assertion failed: ";
		if (value.has_value())
			std::visit(
				[](auto&& arg) {
					using T = std::decay_t<decltype(arg)>;
					if constexpr (std::is_same_v<T, std::double_t>)
						std::cout << arg;
					else if constexpr (std::is_same_v<T, std::string>)
						std::cout << arg;
				},
				value.value());
		else
			std::cout << "std::nullopt";
		std::cout << " == " << real << std::endl;
		std::exit(1);
	}
}

void test_float(std::string str, std::double_t real) {
	auto value = test_token(str, LiteralKind::Float);
	try
	{ ASSERT_EQ(std::get<std::double_t>(value.value()), real) } catch (std::exception&)
	{
		std::cout << "Assertion failed: ";
		if (value.has_value())
			std::visit(
				[](auto&& arg) {
					using T = std::decay_t<decltype(arg)>;
					if constexpr (std::is_same_v<T, std::int64_t>)
						std::cout << arg;
					else if constexpr (std::is_same_v<T, std::string>)
						std::cout << arg;
				},
				value.value());
		else
			std::cout << "std::nullopt";
		std::cout << " == " << real << std::endl;
		std::exit(1);
	}
}

void test_power_zero(std::string str) {
	std::stringstream ss{};
	auto lexer = Lexer(str, "<stdin>");
	lexer.lex();
	std::string log = ss.str();
	ASSERT(log.find("with power of 0"));
	ASSERT(log.find("Warn"))
}

void test() {
	test_int("123", 123);
	test_int("1_234", 1234);
	test_int("1e10", 1e10);
	test_float("123.456", 123.456);
	test_float("123e-1", 123e-1);
	test_float("1_234e-1_0", 1234e-10);
	test_power_zero("1e0");
}

TEST(test();)