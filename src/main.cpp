#include "MMath.h"

void main()
{
	MMatrix a = MMatrix(3,1);
	MMatrix b(1, 3);

	a.inputValue(0, 0, 1);
	a.inputValue(1, 0, 2);
	a.inputValue(2, 0, 3);

	b.inputValue(0, 0, 1);
	b.inputValue(0, 1, 2);
	b.inputValue(0, 2, 3);
	
	std::cout << a;
	std::cout << b;
	std::cout << b * a;
	std::cout << a * b;

	system("pause");
}