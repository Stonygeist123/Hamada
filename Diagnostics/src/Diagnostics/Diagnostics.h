#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "Utility/Utility.h"
using namespace hamada::utility;

namespace hamada::diagnostics {
	enum class LogLevel
	{
		Warn,
		Info,
		Error,
		Debug
	};

	inline std::string logLevelColor(const LogLevel& level) noexcept;

	inline std::string logLevelReset() noexcept;

	inline std::string logLevelText(const LogLevel& level) noexcept;

	struct Diagnostic
	{
		std::string message, type, filePath, source;
		LogLevel level;
		TextSpan span;
		Diagnostic(LogLevel level, std::string message, std::string type, std::string filePath, TextSpan span,
			std::string source) noexcept
			: level(level), message(message), type(type), filePath(filePath), span(span), source(source) {}

		void print() const;
	};

	struct DiagnosticBag : std::vector<Diagnostic>
	{
		DiagnosticBag() noexcept : std::vector<Diagnostic>{} {}
		void printAll();

		bool any() const noexcept;
	};
}
