#include "helpers.cc"

void test_other(std::string str, OtherKind real) { auto value = test_token(str, real); }

void test() {
	test_other("(", OtherKind::LParen);
	test_other(")", OtherKind::RParen);
	test_other("[", OtherKind::LBracket);
	test_other("]", OtherKind::RBracket);
	test_other("{", OtherKind::LBrace);
	test_other("}", OtherKind::RBrace);
	test_other(",", OtherKind::Comma);
	// test_other(";", OtherKind::Semicolon);
	test_other(":", OtherKind::Colon);
	test_other(".", OtherKind::Dot);
	test_other("->", OtherKind::Arrow);
	test_other("?", OtherKind::QuestionMark);
}

TEST(test();)