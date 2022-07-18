#pragma once
#include <string>
#include <vector>
#include "Utility.h"
using namespace hamada::utility;

namespace hamada::parser {
	class Parser
	{
	public:
		std::string filePath;
		Parser(std::string filePath, std::vector<Token> tokens) : filePath(filePath), tokens(tokens) {}

	private:
		std::vector<Token> tokens;
	};
}