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

	inline std::string logLevelColor(const LogLevel&) noexcept;

	inline std::string logLevelReset() noexcept;

	inline std::string logLevelText(const LogLevel&) noexcept;

	struct Diagnostic
	{
		std::string message, type, filePath, source;
		LogLevel level;
		TextSpan span;
		Diagnostic(LogLevel, std::string, std::string, std::string, TextSpan, std::string) noexcept;

		void print() const;
	};

	struct DiagnosticBag : std::vector<Diagnostic>
	{
		DiagnosticBag() noexcept : std::vector<Diagnostic>{} {}
		void printAll();

		bool any() const noexcept;
	};
}
