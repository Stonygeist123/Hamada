#include "../Utility.h"
#include "../Lexer/Lexer.h"
using namespace hamada::utility;
using namespace hamada::lexer;

namespace hamada::parser {
	class Expr
	{
	public:
		~Expr() = default;
		virtual TextSpan span() = 0;
		virtual void print(size_t) = 0;
	};

	class Literal
	{
	public:
		Token token;
		Literal(Token token) : token(token) {}
	};

	class Unary
	{
	public:
		Token op;					   //
		std::unique_ptr<Expr> operand; // should I explain it? ok, but we need it for the Parser otherwise the Parser
									   // won't work. U can rea craftingintrpreters.com's
		// explanation on the exprs and u gonna understand them
		Unary(Token op, std::unique_ptr<Expr> operand) : op(op), operand(operand) {}

	private:
	};

}