#include <iostream>
class MMatrix
{
	public:
		MMatrix(int x, int y);
		~MMatrix();
		void inputValue(int column, int row, float val);
		friend std::ostream& operator<< (std::ostream& os, const MMatrix mat);
		MMatrix operator+ (MMatrix operand);
		MMatrix operator- (MMatrix operand);
		MMatrix operator* (float operand);
		friend MMatrix operator* (MMatrix operandF, MMatrix operand);
		friend MMatrix operator* (float operandF, MMatrix operand);
		int getsizeX() const;
		int getsizeY() const;
		float MMatrix::getValue(int x, int y) const;
		


	private:
		float ** matrixData;
		int sizeX, sizeY;
};