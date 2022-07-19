#include "Diagnostics.h"

namespace hamada::diagnostics {
	std::string logLevelColor(const LogLevel& level) noexcept {
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

	std::string logLevelReset() noexcept { return "\033[0m"; }

	std::string logLevelText(const LogLevel& level) noexcept {
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

	void Diagnostic::print() const {
		size_t c = span.start + 1;
		std::string levelS = logLevelText(level);
		std::stringstream msg{};
		msg << '[' << levelS << ' ' << span.lineEnd << ':' << c << (span.column <= c ? "" : "-" + span.column) << ']';
		std::string line = source.contains("\n") ? splitString(source, "\n").at(span.lineEnd) : source;
		std::stringstream messageStream{};
		messageStream << msg.str() << ' ' << line << "\n";
		std::string spacing = repeatString(" ", msg.str().length() + span.column - 1);
		messageStream << spacing << repeatString("^", span.end - span.start - 1) << '\n';
		messageStream << spacing << type << ": " << message;

		std::cout << logLevelColor(level) << messageStream.str() << logLevelReset();
	}

	void DiagnosticBag::printAll() {
		for (Diagnostic& diagnostic : *this)
		{
			diagnostic.print();
			std::cout << '\n';
		}
	}

	bool DiagnosticBag::any() const noexcept { return size() > 0; }
}