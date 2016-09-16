#include "MMath.h"

void main()
{
	/*MMatrix matrix(3, 2);
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

	std::cout << matrix * matrix2;*/

	//std::cout << matrix * 2 << std::endl << std::endl;
	//std::cout << 2 * matrix;
	//std::cout << matrix * matrix2;
	
	/*MMatrix a(2, 3);
	MMatrix b(3, 4);

	a.inputValue(0, 0, 1);
	a.inputValue(1, 0, 2);
	a.inputValue(0, 1, 3);
	a.inputValue(1, 1, 3);
	a.inputValue(0, 2, 2);
	a.inputValue(1, 2, 1);

	b.inputValue(0, 0, 1);
	b.inputValue(1, 0, 2);
	b.inputValue(0, 1, 3);
	b.inputValue(1, 1, 3);
	b.inputValue(0, 2, 2);
	b.inputValue(1, 2, 1);
	std::cout << a * b;
	*/
	MMatrix a(3, 1);
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
	system("pause");
}