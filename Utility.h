#pragma once
#include <string>
#include <variant>
#include <optional>
#include <map>
#include <iostream>
#include <vector>

namespace hamada::utility {
	using literalType = std::variant<std::int64_t, std::double_t, std::string>;

	enum class OperatorKind
	{
		// Arithmetic
		Plus,
		Minus,
		Star,
		Slash,
		Power,
		Mod,
		Increment,
		Decrement,

		// Relational
		EqEq,
		NotEq,
		Greater,
		GreaterEq,
		Less,
		LessEq,

		// Bitshift
		Rsh,
		Lsh,

		// Bitwise
		And,
		Xor,
		Or,

		// Logical
		LogicalOr,
		LogicalAnd,

		// Assignment
		Equals,
		PlusEq,
		MinusEq,
		StarEq,
		SlashEq,
		PowerEq,
		ModEq,
		XorEq,
		OrEq,
		AndEq,
		LshEq,
		RshEq,

		// Strict Unary
		Inv,
		Not
	};

	enum class LiteralKind
	{
		Float,
		Int,
		String,
		Identifier
	};

	enum class KeywordKind
	{
		Break,
		Case,
		Class,
		Const,
		Var,
		Continue,
		Default,
		Do,
		Else,
		For,
		Foreach,
		Fn,
		If,
		In,
		Private,
		Protected,
		Public,
		Return,
		Static,
		Struct,
		Switch,
		While
	};

	enum class OtherKind
	{
		Dot,
		Comma,
		LParen,
		RParen,
		LBrace,
		RBrace,
		LBracket,
		RBracket,
		Arrow,
		QuestionMark,
		Colon,

		Eof
	};

	using TokenKind = std::variant<OperatorKind, KeywordKind, LiteralKind, OtherKind>;
	inline std::string toString(const OperatorKind& kind) noexcept {
		switch (kind)
		{
			case OperatorKind::Plus:
				return "+";
			case OperatorKind::Minus:
				return "-";
			case OperatorKind::Star:
				return "*";
			case OperatorKind::Slash:
				return "/";
			case OperatorKind::Power:
				return "**";
			case OperatorKind::Mod:
				return "%";
			case OperatorKind::Increment:
				return "++";
			case OperatorKind::Decrement:
				return "--";
			case OperatorKind::EqEq:
				return "==";
			case OperatorKind::NotEq:
				return "!=";
			case OperatorKind::Greater:
				return ">";
			case OperatorKind::GreaterEq:
				return ">=";
			case OperatorKind::Less:
				return "<";
			case OperatorKind::LessEq:
				return "<=";
			case OperatorKind::Rsh:
				return ">>";
			case OperatorKind::Lsh:
				return "<<";
			case OperatorKind::And:
				return "&";
			case OperatorKind::Xor:
				return "^";
			case OperatorKind::Or:
				return "|";
			case OperatorKind::LogicalOr:
				return "||";
			case OperatorKind::LogicalAnd:
				return "&&";
			case OperatorKind::Equals:
				return "=";
			case OperatorKind::PlusEq:
				return "+=";
			case OperatorKind::MinusEq:
				return "-=";
			case OperatorKind::StarEq:
				return "*=";
			case OperatorKind::SlashEq:
				return "/=";
			case OperatorKind::PowerEq:
				return "**=";
			case OperatorKind::ModEq:
				return "%=";
			case OperatorKind::XorEq:
				return "^=";
			case OperatorKind::OrEq:
				return "|=";
			case OperatorKind::AndEq:
				return "&=";
			case OperatorKind::LshEq:
				return "<<=";
			case OperatorKind::RshEq:
				return ">>=";
			case OperatorKind::Inv:
				return "~";
			case OperatorKind::Not:
				return "!";
			default:
				return "";
		}
	}

	inline std::string toString(const KeywordKind& kind) noexcept {
		switch (kind)
		{
			case KeywordKind::Break:
				return "break";
			case KeywordKind::Case:
				return "case";
			case KeywordKind::Class:
				return "class";
			case KeywordKind::Const:
				return "const";
			case KeywordKind::Var:
				return "var";
			case KeywordKind::Continue:
				return "continue";
			case KeywordKind::Default:
				return "default";
			case KeywordKind::Do:
				return "do";
			case KeywordKind::Else:
				return "else";
			case KeywordKind::For:
				return "for";
			case KeywordKind::Foreach:
				return "foreach";
			case KeywordKind::Fn:
				return "fn";
			case KeywordKind::If:
				return "if";
			case KeywordKind::In:
				return "in";
			case KeywordKind::Private:
				return "private";
			case KeywordKind::Protected:
				return "protected";
			case KeywordKind::Public:
				return "public";
			case KeywordKind::Return:
				return "return";
			case KeywordKind::Static:
				return "static";
			case KeywordKind::Struct:
				return "struct";
			case KeywordKind::Switch:
				return "switch";
			case KeywordKind::While:
				return "while";
			default:
				return "";
		}
	}

	inline std::string toString(const OtherKind& kind) noexcept {
		switch (kind)
		{
			case OtherKind::Comma:
				return ";";
			case OtherKind::LParen:
				return "(";
			case OtherKind::RParen:
				return ")";
			case OtherKind::LBrace:
				return "{";
			case OtherKind::RBrace:
				return "}";
			case OtherKind::LBracket:
				return "[";
			case OtherKind::RBracket:
				return "]";
			case OtherKind::Arrow:
				return "->";
			case OtherKind::QuestionMark:
				return "?";
			case OtherKind::Colon:
				return ":";
			case OtherKind::Eof:
				return "End of File";
			default:
				return "";
		};
	}

	inline std::string toString(const LiteralKind& kind) noexcept {
		switch (kind)
		{
			case LiteralKind::Float:
				return "Float";
			case LiteralKind::Int:
				return "Int";
			case LiteralKind::String:
				return "String";
			case LiteralKind::Identifier:
				return "Identifier";
			default:
				return "";
		};
	}

	struct TextSpan
	{
		size_t start, end, column, lineStart, lineEnd;
		TextSpan(size_t start, size_t end, size_t column, size_t lineStart, size_t lineEnd) noexcept
			: start(start), end(end), column(column), lineStart(lineStart), lineEnd(lineEnd) {}
		size_t length() { return end - start; }

		operator std::string() const noexcept { return std::to_string(start) + ".." + std::to_string(end); }
	};

	struct Token
	{
		TokenKind kind;
		std::string lexeme;
		TextSpan span;
		std::optional<literalType> literal;
		Token(TokenKind kind, std::string lexeme, TextSpan span, std::optional<literalType> literal = std::nullopt)
			: kind(kind), lexeme(lexeme), span(span), literal(literal) {}

		explicit operator std::string() const noexcept {
			return "Lexeme: " + lexeme + "\nSpan: " + static_cast<std::string>(span);
		}

		friend std::ostream& operator<<(std::ostream& os, const Token& token) noexcept {
			std::visit(
				[](auto&& arg) {
					using T = std::decay_t<decltype(arg)>;
					if constexpr (std::is_same_v<T, OperatorKind>)
						std::cout << "Kind: " << toString(arg) << '\n';
					else if constexpr (std::is_same_v<T, KeywordKind>)
						std::cout << "Kind: " << toString(arg) << '\n';
					else if constexpr (std::is_same_v<T, LiteralKind>)
						std::cout << "Kind: " << toString(arg) << '\n';
					else if constexpr (std::is_same_v<T, OtherKind>)
						std::cout << "Kind: " << toString(arg) << '\n';
				},
				token.kind);
			os << static_cast<std::string>(token);
			if (token.literal.has_value())
				std::visit(
					[](auto&& arg) {
						using T = std::decay_t<decltype(arg)>;
						if constexpr (std::is_same_v<T, std::int64_t>)
							std::cout << '\n' << "Literal: " << arg;
						else if constexpr (std::is_same_v<T, std::double_t>)
							std::cout << '\n' << "Literal: " << arg;
						else if constexpr (std::is_same_v<T, std::string>)
							std::cout << '\n' << "Literal: " << arg;
					},
					token.literal.value());
			return os;
		}
	};

	inline int getUnaryOpPrecedence(OperatorKind kind) {
		switch (kind)
		{
			case OperatorKind::Increment:
			case OperatorKind::Decrement:
				return 13;
			case OperatorKind::Plus:
			case OperatorKind::Minus:
			case OperatorKind::Inv:
			case OperatorKind::Not:
				return 12;
			default:
				return 0;
		}
	}

	inline int getBinaryOpPrecedence(OperatorKind kind) {
		switch (kind)
		{
			case OperatorKind::Power:
				return 11;
			case OperatorKind::Star:
			case OperatorKind::Slash:
			case OperatorKind::Mod:
				return 10;
			case OperatorKind::Plus:
			case OperatorKind::Minus:
				return 9;
			case OperatorKind::Rsh:
			case OperatorKind::Lsh:
				return 8;
			case OperatorKind::Greater:
			case OperatorKind::GreaterEq:
			case OperatorKind::Less:
			case OperatorKind::LessEq:
				return 7;
			case OperatorKind::EqEq:
			case OperatorKind::NotEq:
				return 6;
			case OperatorKind::And:
				return 5;
			case OperatorKind::Xor:
				return 4;
			case OperatorKind::Or:
				return 3;
			case OperatorKind::LogicalAnd:
				return 2;
			case OperatorKind::LogicalOr:
				return 1;
			default:
				return 0;
		}
	}

	inline std::vector<OperatorKind> getUnaryOperatorKinds() noexcept {
		std::vector<OperatorKind> kinds{}, res{};
		for (int i = static_cast<int>(OperatorKind::Plus); i <= static_cast<int>(OperatorKind::Not); ++i)
			kinds.push_back(static_cast<OperatorKind>(i));
		for (auto& kind : kinds)
			if (getUnaryOpPrecedence(kind) > 0)
				res.push_back(kind);
		return res;
	}

	inline std::vector<OperatorKind> getBinaryOperatorKinds() noexcept {
		std::vector<OperatorKind> kinds{}, res{};
		for (int i = static_cast<int>(OperatorKind::Plus); i <= static_cast<int>(OperatorKind::Not); ++i)
			kinds.push_back(static_cast<OperatorKind>(i));
		for (auto& kind : kinds)
			if (getBinaryOpPrecedence(kind) > 0)
				res.push_back(kind);
		return res;
	}

	inline std::vector<std::string> splitString(const std::string& str, const std::string& delimiter) {
		std::vector<std::string> strings;

		std::string::size_type pos = 0;
		std::string::size_type prev = 0;
		while ((pos = str.find(delimiter, prev)) != std::string::npos)
		{
			strings.push_back(str.substr(prev, pos - prev));
			prev = pos + delimiter.size();
		}

		strings.push_back(str.substr(prev));

		return strings;
	}

	inline std::string repeatString(const std::string& str, size_t count) {
		std::string result = "";
		for (size_t i = 0; i <= count; ++i)
			result += str;
		return result;
	}
}
