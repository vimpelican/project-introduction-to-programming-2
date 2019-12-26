#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <vector>
using namespace std;

const string simbols = "(+-*/) ";

string GetPostFix(const string infixExpression);
double Calculate(const string postfixExpression);

#endif