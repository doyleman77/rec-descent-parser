#pragma once
#include "lexer.hpp"
#include "token.hpp"

class Recursive_Parser
{
private:
	Lexer			lexer;
	Token			token_eval;

public:
	/*ctr*/		Recursive_Parser();
	/*dtr*/		~Recursive_Parser();

	void		run();

	void		expr();
	void		term();
	void		term_prime();
	void		factor();
	void		factor_prime();
};