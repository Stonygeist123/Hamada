#include <iostream>
#include <algorithm>
#include <Windows.h>
#include "Diagnostics/Diagnostics.h"
#include "Lexer/Lexer.h"

int main() {
	while (true)
	{
		std::cout << "\033[32m"
				  << "> "
				  << "\033[0m";
		std::string source;
		getline(std::cin, source);

		if (source.empty() || std::all_of(source.begin(), source.end(), [](const char& c) { return std::isspace(c); }))
			continue;

		hamada::lexer::Lexer lexer(source, "<stdin>");
		std::vector<Token>& tokens = lexer.lex();

		if (lexer.hadError)
			lexer.diagnostics.printAll();
		else
		{
			for (Token& token : tokens)
				std::cout << token << "\n\n";
		}
	}
}
