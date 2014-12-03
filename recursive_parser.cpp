#include <iostream>
#include "recursive_parser.hpp"


Recursive_Parser::Recursive_Parser()
{

}

Recursive_Parser::~Recursive_Parser()
{

};

void Recursive_Parser::run()
{
	token_eval = lexer.get_token();
	expr();
	if (token_eval.token_type == "15")
		std::cout << "Tis done." << std::endl;
	else
		std::cout << std::endl << "Error with token " <<
		token_eval.token_value << " at expr(), unfinished expression!" << std::endl;
}

void Recursive_Parser::expr()
{
	term();
}

void Recursive_Parser::term()
{
	factor();
	term_prime();
}

void Recursive_Parser::term_prime()
{
	// if we add or subtract
	if (token_eval.token_type == "09" ||
		token_eval.token_type == "10")
	{
		token_eval = lexer.get_token();
		term();
		// token_eval = lexer.get_token();
		term_prime();
	}
}

void Recursive_Parser::factor()
{
	// token is a int
	if (token_eval.token_type == "01")
	{
		token_eval = lexer.get_token();
		factor_prime();
	}
	// token is a real
	else if (token_eval.token_type == "02")
	{
		token_eval = lexer.get_token();
		factor_prime();
	}
	// token is a ( <expr> )
	else if (token_eval.token_type == "13")
	{
		token_eval = lexer.get_token();
		expr();
		if (token_eval.token_type == "14")
		{
			token_eval = lexer.get_token();
			factor_prime();
		}
		else
		{
			std::cout << std::endl << "Error with token " <<
				token_eval.token_value << " at factor()" << std::endl;
			return;
		}
	}
	// if defining a signed/unsigned type
	else if (token_eval.token_type == "09" ||
		token_eval.token_type == "10")
	{
		token_eval = lexer.get_token();
		factor();
	}
	else
	{
		std::cout << std::endl << "Error with token " <<
			token_eval.token_value << " at factor()" << std::endl;
		return;
	}

}

void Recursive_Parser::factor_prime()
{
	// if we're multiplying or dividing
	if (token_eval.token_type == "11" ||
		token_eval.token_type == "12")
	{
		token_eval = lexer.get_token();
		factor();
		factor_prime();
	}
}