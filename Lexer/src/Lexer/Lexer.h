#pragma once
#include "Utility/Utility.h"
#include "Diagnostics/Diagnostics.h"
using namespace hamada::utility;
using namespace hamada::diagnostics;

namespace hamada::lexer {
	class Lexer
	{
	public:
		bool hadError = false;
		std::vector<Token> tokens{};
		diagnostics::DiagnosticBag diagnostics{};
		std::string source, filePath;
		Lexer(std::string, std::string) noexcept;
		std::vector<Token> lex();

	private:
		size_t line = 1, lineStart = 1, current = 0, start = 0, column = 0;
		std::map<std::string, KeywordKind> keywords{ { "var", KeywordKind::Var }, { "break", KeywordKind::Break },
			{ "case", KeywordKind::Case }, { "class", KeywordKind::Class }, { "const", KeywordKind::Const },
			{ "continue", KeywordKind::Continue }, { "default", KeywordKind::Default }, { "do", KeywordKind::Do },
			{ "else", KeywordKind::Else }, { "fn", KeywordKind::Fn }, { "for", KeywordKind::For },
			{ "false", KeywordKind::False }, { "if", KeywordKind::If }, { "in", KeywordKind::In },
			{ "private", KeywordKind::Private }, { "protected", KeywordKind::Protected },
			{ "public", KeywordKind::Public }, { "return", KeywordKind::Return }, { "static", KeywordKind::Static },
			{ "switch", KeywordKind::Switch }, { "true", KeywordKind::True }, { "while", KeywordKind::While } };

		std::map<std::string, OperatorKind> operators{ { "+", OperatorKind::Plus }, { "-", OperatorKind::Minus },
			{ "*", OperatorKind::Star }, { "/", OperatorKind::Slash }, { "%", OperatorKind::Mod },
			{ "=", OperatorKind::Equals }, { "==", OperatorKind::EqEq }, { "!=", OperatorKind::NotEq },
			{ "<", OperatorKind::Less }, { "<=", OperatorKind::LessEq }, { ">", OperatorKind::Greater },
			{ ">=", OperatorKind::GreaterEq }, { "&&", OperatorKind::LogicalAnd }, { "||", OperatorKind::LogicalOr },
			{ "++", OperatorKind::Increment }, { "--", OperatorKind::Decrement }, { "+=", OperatorKind::PlusEq },
			{ "-=", OperatorKind::MinusEq }, { "*=", OperatorKind::StarEq }, { "/=", OperatorKind::SlashEq },
			{ "%=", OperatorKind::ModEq }, { "&=", OperatorKind::AndEq }, { "|=", OperatorKind::OrEq },
			{ "**", OperatorKind::Power }, { "**=", OperatorKind::PowerEq }, { "|", OperatorKind::Or },
			{ "&", OperatorKind::And }, { "^=", OperatorKind::XorEq }, { "^", OperatorKind::Xor },
			{ "<<", OperatorKind::Lsh }, { ">>", OperatorKind::Rsh }, { "<<=", OperatorKind::LshEq },
			{ ">>=", OperatorKind::RshEq }, { "!", OperatorKind::Not }, { "~", OperatorKind::Inv } };

		std::map<std::string, OtherKind> others{
			{ "->", OtherKind::Arrow },
			{ "?", OtherKind::QuestionMark },
			{ ":", OtherKind::Colon },
			{ "(", OtherKind::LParen },
			{ ")", OtherKind::RParen },
			{ "{", OtherKind::LBrace },
			{ "}", OtherKind::RBrace },
			{ "[", OtherKind::LBracket },
			{ "]", OtherKind::RBracket },
			{ ",", OtherKind::Comma },
			{ ".", OtherKind::Dot },
		};

		void tokenize();
		Token number();
		Token string();
		Token identifier();
		TextSpan span();
		std::optional<Token> otherToken();

		char peek(size_t = 0);
		char advance();
		bool advance(bool);
		bool isAtEnd();

		void error(LogLevel, TextSpan, std::string, std::string = "SyntaxException") noexcept;
	};
}
