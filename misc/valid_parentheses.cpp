#include <string>
#include <stack>


bool is_valid_parentheses(const std::string& s) {
	std::stack<char> parentheses_stack {};

	for (const char& letter : s) {
		switch (letter) {
			case '[':
				parentheses_stack.push('[');
				continue;
			case '{':
				parentheses_stack.push('{');
				continue;
			case '(':
				parentheses_stack.push('(');
				continue;
			case ']':
				if (!parentheses_stack.empty() && parentheses_stack.top() == '[') {
					parentheses_stack.pop();
					continue;
				}
				return false;
			case '}':
				if (!parentheses_stack.empty() && parentheses_stack.top() == '{') {
					parentheses_stack.pop();
					continue;
				}
				return false;
			case ')':
				if (!parentheses_stack.empty() && parentheses_stack.top() == '(') {
					parentheses_stack.pop();
					continue;
				}
				return false;
		}
	}

	return parentheses_stack.empty();
}

