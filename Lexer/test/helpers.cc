#include <any>
#include <iostream>

#include "Lexer/Lexer.h"

#define ASSERT_EQ(a, b)                                                                                                \
	if (!(a == b))                                                                                                     \
	{                                                                                                                  \
		std::cout << "Assertion failed: " << a << " == " << b << std::endl;                                            \
		exit(1);                                                                                                       \
	}

#define ASSERT(val)                                                                                                    \
	if (!(val))                                                                                                        \
	{                                                                                                                  \
		std::cout << "Assertion " << #val << " failed in " << __FILE__ << ":" << __LINE__ << std::endl;                \
		exit(1);                                                                                                       \
	}

#define TEST(body)                                                                                                     \
	int main() {                                                                                                       \
		try                                                                                                            \
		{ body } catch (std::exception e)                                                                              \
		{                                                                                                              \
			std::cout << e.what() << std::endl;                                                                        \
			return 1;                                                                                                  \
		}                                                                                                              \
	}

using namespace hamada::lexer;

template <typename TestKind> std::optional<literalType> test_token(std::string str, TestKind tkind) {
	auto lexer = Lexer(str, "<stdin>");
	lexer.lex();
	ASSERT(!lexer.hadError)
	auto& tokens = lexer.tokens;
	ASSERT(tokens.size() >= 1)
	auto kind = tokens[0].kind;
	ASSERT(std::holds_alternative<TestKind>(kind))
	ASSERT(std::get<TestKind>(kind) == tkind)
	return tokens[0].literal;
}

std::vector<Token> eachToken(std::string code) {
	auto lexer = Lexer(code, "<stdin>");
	auto tokens = lexer.lex();
	ASSERT(!lexer.hadError)
	return lexer.tokens;
}

auto token(TokenKind kind, std::string lexme) { return Token(kind, lexme, hamada::utility::TextSpan(0, 0, 0, 0, 0)); }