#include"postfix.h"
//functions for a dinamically allocated stack structure
void Init(Stiva& s) {
	s = 0;
}
bool IsEmpty(Stiva s) {
	if (s)
		return 0;
	else
		return 1;
}
String Top(Stiva s) {
	return s->value;
}
void Pop(Stiva& s) {
	Element* p = new Element;
	if (!IsEmpty(s)) {
		p = s;
		p = p->next;
		free(s);
		s = p;
	}
}
void Push(Stiva& s, String x) {
	Element* p = new Element;
	p->value = x;
	p->next = s;
	s = p;
}
//function that returns the postfix form of infix expression
String postfix(Stiva& s,String sir) {
	String rez = "";
	int i = 0;
	while (i <= sir.length() - 1) {
		if (isdigit(sir[i])) {
			rez = rez + sir[i];
		}
		else
		{
			if (sir[i] == '(')
				Push(s, String(sir[i]));
			else {
				if (sir[i] == ')') {
					while (!IsEmpty(s) && Top(s) != ")") {
						if (Top(s) != "(")
							rez = rez + Top(s);
						Pop(s);
					}
				}
				else
					if (sir[i] == '+' || sir[i] == '-') {
						while (!IsEmpty(s) && (Top(s) == "*" || Top(s) == "/")) {
								rez = rez + Top(s);
							Pop(s);
						}
						Push(s, String(sir[i]));
					}
							else
							{
								Push(s, String(sir[i]));
							}
			}
		}
		i++;
	}
	while (!IsEmpty(s)) {
		rez = rez + Top(s);
		Pop(s);
	}
	return rez;
}
//function that evaluates the postfix form of an expression
String postfixeval(Stiva& Op, String forma){
int i = 0;
while (i <= forma.length() - 1) {
	if (isdigit(forma[i])) {
		Push(Op, String(forma[i]));
	}
	else
		if (!isdigit(int(forma[i]))) {
			int num1 = Top(Op).toInt();
			Pop(Op);
			int num2 = Top(Op).toInt();
			Pop(Op);
			int rez = 0;
			switch (forma[i]) {
			case '+':
				rez = (num2 + num1);
				break;
			case '-':
				rez = (num2 - num1);
				break;
			case '*':
				rez = (num2 * num1);
				break;
			case '/':
				rez = (num2 / num1);
				break;
			}
			Push(Op, String(rez));

		}
	i++;
}
return String(Top(Op));
}
