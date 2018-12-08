
#ifndef SECONDYEARPROJECT_BIU_SHUNTING_YARD_H
#define SECONDYEARPROJECT_BIU_SHUNTING_YARD_H

#include <iostream>
#include "queue"
#include "stack"
#include "Expression.h"
#include "Plus.h"
#include "Minus.h"
#include "Mult.h"
#include "Div.h"
#include "Number.h"

using namespace std;
/**
 * @param exp string expression
 * @return expression
 */
static inline Expression* prefixToExp(string exp) {
    if (exp.length() == 3) {
        switch (exp[2]){
            case '+':
                return new Plus(new Number(exp[0] - '0'), new Number(exp[1] - '0'));
            case '-':
                return new Minus(new Number(exp[0] - '0'), new Number(exp[1] - '0'));
            case '*':
                return new Mult(new Number(exp[0] - '0'), new Number(exp[1] - '0'));
            case '/':
                return new Div(new Number(exp[0] - '0'), new Number(exp[1] - '0'));
        }
    } else{

    }
}

/**
 * implementation of Shunting Yard Algorithm
 * @param expression the expression ass a string
 * @return value of the expression
 */
static inline double shuntingYardAlg(string expression) {
    map<char, int> precedences;
    precedences['+'] = precedences['-'] = 1;
    precedences['*'] = precedences['/'] = 2;
    stack<char> stack1;
    queue<char> queue1;
    for (int i = 0; i < expression.length(); ++i) {
        if (isdigit(expression[i])) queue1.push(expression[i]);
        else {
            if (expression[i] == '(') {
                stack1.push(expression[i]);
            } else if (expression[i] == ')') {
                while (!stack1.empty() && stack1.top() != '(') {
                    queue1.push(stack1.top());
                    stack1.pop();
                }
                stack1.pop();
            } else { // char is an operator:
                while (!stack1.empty() && precedences[stack1.top()] > precedences[expression[i]]) {
                    queue1.push(stack1.top());
                    stack1.pop();
                }
                stack1.push(expression[i]);
            }
        }
    }
    // push rest in stack to queue
    while (!stack1.empty()) {
        queue1.push(stack1.top());
        stack1.pop();
    }
    // 'reverse' queue to a string
    stack<char> stack2;
    while (!queue1.empty()) {
        stack2.push(queue1.front());
        queue1.pop();
    }
    string newExp;
    while (!stack2.empty()) {
        newExp += stack2.top();
        stack2.pop();
    }
    /**
     * From here, calculate the value of the expression:
     */

}

#endif //SECONDYEARPROJECT_BIU_SHUNTING_YARD_H
