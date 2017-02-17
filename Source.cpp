#include <iostream>
#include "miniStack.h"
#include "Postfix.h"

using namespace std;

void main()
{
	miniStack<char> sVowels(5), temp2;
	Postfix myexp;

	myexp.set("567*+");
	cout << myexp.evaluate() << endl;
	myexp.set("56*82/-");
	cout << myexp.evaluate() << endl;
	myexp.set("462*5+3/+");
	cout << myexp.evaluate() << endl;
	myexp.set("3425*-*6+");
	cout << myexp.evaluate() << endl;
	
	sVowels.push('a');
	sVowels.push('e');
	sVowels.push('i');
	sVowels.push('o');
	sVowels.push('u');

	(temp2 = sVowels).pop();
	temp2.pop();

	cout << "Size of svowels is " << sVowels.size() << endl;
	cout << "Top vowel is " << sVowels.top() << endl;
	
	cout << "Size of temp2 is " << temp2.size() << endl;
	cout << "Top of temp2 is " << temp2.top() << endl;

	if (!sVowels.empty())
		sVowels.pop();
	cout << "Size of svowels is " << sVowels.size() << endl;
	cout << "Top vowel is " << sVowels.top() << endl;

}