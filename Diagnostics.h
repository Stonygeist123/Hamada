#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "Utility.h"
using namespace hamada::utility;

namespace hamada::diagnostics {
	enum class LogLevel
	{
		Warn,
		Info,
		Error,
		Debug
	};

	inline std::string logLevelColor(LogLevel& level) noexcept {
		switch (level)
		{
			case LogLevel::Debug:
				return "\033[32m"; // Green
			case LogLevel::Info:
				return "\033[34m"; // Blue
			case LogLevel::Warn:
				return "\033[33m"; // Orange
			case LogLevel::Error:
				return "\033[1m\033[31m"; // Red
			default:
				return "";
		}
	}

	inline std::string logLevelReset() noexcept { return "\033[0m"; }

	inline std::string logLevelText(LogLevel& level) noexcept {
		switch (level)
		{
			case LogLevel::Debug:
				return "Debug";
			case LogLevel::Info:
				return "Info ";
			case LogLevel::Warn:
				return "Warn ";
			case LogLevel::Error:
				return "Error";
			default:
				return "";
		}
	}

	struct Diagnostic
	{
		std::string message, type, filePath, source;
		LogLevel level;
		TextSpan span;
		Diagnostic(LogLevel level, std::string message, std::string type, std::string filePath, TextSpan span,
			std::string source) noexcept
			: level(level), message(message), type(type), filePath(filePath), span(span), source(source) {}
		/*
		[LogLevel file:line:column] line... errorPart ...line
											^^^^^^^^^
											Type: message

		Example:
		[Error C:/main.cpp:3:5] add($, 2)
									^
									  SyntaxException: Unexpected character '$'.
										*/
		void print() {
			size_t c = span.start + 1;
			std::string levelS = logLevelText(level);
			std::stringstream msg{};
			msg << '[' << levelS << ' ' << span.lineEnd << ':' << c << (span.column <= c ? "" : "-" + span.column)
				<< ']';
			std::string line = source.contains("\n") ? splitString(source, "\n").at(span.lineEnd) : source;
			std::stringstream messageStream{};
			messageStream << msg.str() << ' ' << line << "\n";
			std::string spacing = repeatString(" ", msg.str().length() + span.column - 1);
			messageStream << spacing << repeatString("^", span.end - span.start - 1) << '\n';
			messageStream << spacing << type << ": " << message;

			std::cout << logLevelColor(level) << messageStream.str() << logLevelReset();
		}
	};

	struct DiagnosticBag : std::vector<Diagnostic>
	{
		DiagnosticBag() noexcept : std::vector<Diagnostic>{} {}
		void printAll() {
			for (Diagnostic& diagnostic : *this)
			{
				diagnostic.print();
				std::cout << '\n';
			}
		}

		bool any() const noexcept { return size() > 0; }
	};
}
