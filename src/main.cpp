#include "MMath.h"

void main()
{
	MMatrix matrix(2, 3);
	MMatrix matrix2(2, 3);
	MMatrix matrix3(2, 3);

	matrix.inputValue(0, 0, 1);
	matrix.inputValue(1, 0, 2);
	matrix.inputValue(0, 1, 3);
	matrix.inputValue(1, 1, 4);
	matrix.inputValue(0, 2, 5);
	matrix.inputValue(1, 2, 6);

	matrix2.inputValue(0, 0, 3);
	matrix2.inputValue(1, 0, 2);
	matrix2.inputValue(0, 1, 5);
	matrix2.inputValue(1, 1, 6);
	matrix2.inputValue(0, 2, 9);
	matrix2.inputValue(1, 2, 7);

	matrix3.inputValue(0, 0, 5);
	matrix3.inputValue(1, 0, -4);
	matrix3.inputValue(0, 1, 7);

	std::cout << matrix - matrix2 + matrix3;
	
	system("pause");
}