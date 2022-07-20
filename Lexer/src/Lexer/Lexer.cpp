#include "Lexer.h"

namespace hamada::lexer {
	Lexer::Lexer(std::string source, std::string filePath) noexcept : source(source), filePath(filePath) {}
	bool isIdentifierStart(char c) { return isalpha(c) || c == '_'; }

	bool is_identifier_part(char c) { return isIdentifierStart(c) || std::isdigit((unsigned char)c); }

	bool is_number_part(char c) {
		return std::isdigit((unsigned char)c) || c == '.' || c == 'e' || c == '_' || c == '-';
	}

	std::vector<Token> Lexer::lex() {
		while (!isAtEnd())
		{
			start = current;
			lineStart = line;
			tokenize();
		}

		tokens.push_back(Token(OtherKind::Eof, "", span()));
		return tokens;
	}

	void Lexer::tokenize() {
		auto other = otherToken();
		if (other.has_value())
		{
			tokens.push_back(other.value());
			return;
		}
		char c = peek();

		if (std::isspace(c))
		{
			advance();
			return;
		}

		if (isIdentifierStart(c))
		{
			tokens.push_back(identifier());
			return;
		}
		else if (std::isdigit((unsigned char)c))
		{
			tokens.push_back(number());
			return;
		}
		advance();
		error(LogLevel::Error, span(), std::string("Unexpected character '") + c + std::string("'."));
	}

	Token Lexer::number() {
		std::int64_t int_val = 0;
		std::string lexme = "";
		std::double_t float_val = 0, fraction_size = 1;
		bool is_float = false;
		bool is_power = false;

		for (;;)
		{
			int n = 0;
			char c = peek();
			if (!is_number_part(c))
				break;
			lexme += c;
			advance();
			if (c >= '0' && c <= '9')
				n = c - '0';
			else if (c == '_')
			{ continue; }
			else if (c == '.')
			{
				if (is_float)
					error(LogLevel::Error, span(), "Invalid float literal.");
				is_float = true;
				float_val = (std::double_t)int_val;
				continue;
			}
			else if (c == 'e')
			{
				is_power = true;
				break;
			}
			else
				error(LogLevel::Error, span(), "Invalid number literal.");
			if (is_float)
			{
				fraction_size /= 10;
				float_val += ((std::double_t)n) * (fraction_size);
			}
			else
			{
				int_val *= 10;
				int_val += n;
			}
		}

		bool neg_power = false;
		if (is_power)
		{
			std::int64_t power = 0;
			for (;;)
			{
				char c = peek();
				if (c == '\0')
					break;
				if (!(std::isdigit((unsigned char)c)) && c != '-' && c != '_')
					break;
				lexme += c;
				advance();
				if (c == '_')
					continue;
				if (c == '-')
				{
					if (neg_power)
						error(LogLevel::Error, span(), "Invalid number literal with multiple negatives.");
					neg_power = true;
					continue;
				}
				power *= 10;
				power += (std::int64_t)(c - '0');
			}

			if (neg_power)
				power = -power;
			if (power > 0)
			{
				if (!is_float)
					int_val *= (std::int64_t)std::pow(10, power);
			}
			else if (!is_float)
			{
				float_val = (std::double_t)int_val;
				is_float = true;
			}
			if (power == 0)
				error(LogLevel::Warn, span(), "Number literal with power of 0.", "ZeroExponentWarning");

			float_val *= std::pow(10, (std::double_t)power);
		}

		if (is_float)
			return Token(LiteralKind::Float, lexme, span(), float_val);
		else
			return Token(LiteralKind::Int, lexme, span(), int_val);
	}

	Token Lexer::string() {
		std::string lexme = "";
		while ((peek() != '"') && !isAtEnd())
		{
			lexme += peek();
			advance();
		}

		if (isAtEnd())
			error(LogLevel::Error, span(), "Unterminated string.");
		advance();

		std::string value = lexme;
		return Token(LiteralKind::String, "\"" + value + "\"", span(), value);
	}

	Token Lexer::identifier() {
		std::string lexme = "";
		while (is_identifier_part(peek()))
			lexme += advance();
		TokenKind kind = keywords.contains(lexme) ? (TokenKind)keywords.at(lexme) : (TokenKind)LiteralKind::Identifier;
		return Token(kind, lexme, span());
	}

	std::optional<Token> Lexer::otherToken() {
		char c = peek();
		TokenKind kind;
		std::optional<literalType> literal = std::nullopt;
		std::string lexme = "";

		if (others.contains(lexme + c))
		{
			lexme += c;
			advance();
			kind = others.at(lexme);
			return Token(kind, lexme, span(), literal);
		}

		if (c == '-' && peek(1) == '>')
		{
			lexme += c;
			advance();
			lexme += advance();
			kind = others.at(lexme);
			return Token(kind, lexme, span(), literal);
		}

		if (c == '\"')
		{
			advance();
			return string();
		}
		if (operators.contains(lexme))
		{
			kind = operators.at(lexme);
			return Token(kind, lexme, span(), literal);
		}
		while (operators.contains(lexme + c))
		{
			lexme += peek();
			advance();
			c = peek();
			if (c == '\0')
				break;
		}
		if (operators.contains(lexme))
		{
			kind = operators.at(lexme);
			return Token(kind, lexme, span(), literal);
		}
		return std::nullopt;
	}

	char Lexer::peek(size_t offset) { return current + offset >= source.length() ? '\0' : source.at(current + offset); }
	char Lexer::advance() {
		char c = peek();
		++current;
		if (c == '\n')
		{
			lineStart = line;
			++line;
			column = 0;
		}
		else
			++column;
		return c;
	}

	bool Lexer::advance(bool condition) {
		if (condition)
			advance();
		return condition;
	}

	bool Lexer::isAtEnd() { return current >= source.length(); }

	TextSpan Lexer::span() { return TextSpan(start, current, column, lineStart, line); }

	void Lexer::error(LogLevel level, TextSpan span, std::string message, std::string type) noexcept {
		diagnostics.push_back(Diagnostic(level, message, type, filePath, span, source));
		hadError = true;
	}
}
