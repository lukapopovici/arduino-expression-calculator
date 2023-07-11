#pragma once
#include<string.h>
#include <Arduino.h>
struct Element {
	String value;
	Element* next;
};

typedef Element* Stiva;
void Init(Stiva& s);
bool IsEmpty(Stiva s);
void Pop(Stiva& s);
String Top(Stiva s);
void Push(Stiva& s, String x);
String postfix(Stiva& s,String sir);
String postfixeval(Stiva& Op,String forma);
