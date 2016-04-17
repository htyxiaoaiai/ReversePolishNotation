# ReversePolishNotation
逆波兰表达式的求解
#pragma once
#include<iostream>
#include<stack>
#include<assert.h>
enum Type
{
	OP_NUM,
	OP_SYMBOL
};

enum SYMBOL
{
	ADD,
	SUB,
	MUL,
	DIV
};

struct Cell
{
	Type _type;
	int _value;
};
