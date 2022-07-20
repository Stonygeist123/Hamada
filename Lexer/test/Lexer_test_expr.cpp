#include "helpers.cc"
#include <Utility/Utility.h>

void test_decl() {
	auto tokens = eachToken("var a = 1 + 2");
	auto expected = std::vector<Token>({
		token(KeywordKind::Var, "var"),
		token(LiteralKind::Identifier, "a"),
		token(OperatorKind::Equals, "="),
		token(LiteralKind::Int, "1"),
		token(OperatorKind::Plus, "+"),
		token(LiteralKind::Int, "2"),
		token(OtherKind::Eof, ""),
	});

	for (auto i = 0; i < expected.size(); i++)
	{
		ASSERT(tokens[i].kind == expected[i].kind);
		ASSERT_EQ(tokens[i].lexeme, expected[i].lexeme);
	}
}

void test_fndef() {
	auto tokens = eachToken("fn foo(t: Type) -> int { return \"foo\" }");
	auto expected = std::vector<Token>({
		token(KeywordKind::Fn, "fn"),
		token(LiteralKind::Identifier, "foo"),
		token(OtherKind::LParen, "("),
		token(LiteralKind::Identifier, "t"),
		token(OtherKind::Colon, ":"),
		token(LiteralKind::Identifier, "Type"),
		token(OtherKind::RParen, ")"),
		token(OtherKind::Arrow, "->"),
		token(LiteralKind::Identifier, "int"),
		token(OtherKind::LBrace, "{"),
		token(KeywordKind::Return, "return"),
		token(LiteralKind::String, "\"foo\""),
		token(OtherKind::RBrace, "}"),
		token(OtherKind::Eof, ""),
	});

	for (auto i = 0; i < expected.size(); i++)
	{
		ASSERT(tokens[i].kind == expected[i].kind);
		ASSERT_EQ(tokens[i].lexeme, expected[i].lexeme);
	}
}

void test() {
	test_decl();
	test_fndef();
}

TEST(test();)