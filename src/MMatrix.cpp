#include "MMatrix.h"
// Y before X, to avoid flipping variable names everywhere else and preventing crashes and general confusion. What we want, (X,Y) is the opposite
//of how C++ stores stuff.
MMatrix::MMatrix(int y, int x)
{
	sizeX = y;
	sizeY = x;
	matrixData = new float* [y];

	for (int i = 0; i < y; i++)
	{
		matrixData[i] = new float [x];
	}

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			matrixData[i][j] = 0.0f;
		}
	}
}

MMatrix::~MMatrix()
{
	//sadlkfjlkasdfkjlsalsfdajjkkjsdfjkdla
}
//Needs try/catch
void MMatrix::inputValue(int x, int y, float val)
{
	this->matrixData[x][y] = val;
}
//Needs try/catch
float MMatrix::getValue(int x, int y) const
{
	return this->matrixData[x][y];
}


MMatrix MMatrix::operator+(MMatrix operand)
{
	try
	{
		if ((this->getsizeX() == operand.getsizeX()) && (this->getsizeY() == operand.getsizeY()))
		{
			for (int i = 0; i <	sizeX; i++)
			{
				for (int j = 0; j < sizeY; j++)
				{
					inputValue(i, j, getValue(i, j) + operand.getValue(i, j));
				}
			}
			return *this;
		}
		else
		{
			throw(0);
		}
	}
	catch(...)
	{
		std::cout << "Aborting! Added matrices are not the same dimensions!!!" << std::endl;
		abort();
	}
	
}

MMatrix MMatrix::operator-(MMatrix operand)
{
	try
	{
		if ((this->getsizeX() == operand.getsizeX()) && (this->getsizeY() == operand.getsizeY()))
		{
			for (int i = 0; i < sizeX; i++)
			{
				for (int j = 0; j < sizeY; j++)
				{
					inputValue(i, j, getValue(i, j) - operand.getValue(i, j));
				}
			}
			return *this;
		}
		else
		{
			throw(0);
		}
	}
	catch (...)
	{
		std::cout << "Aborting! Added matrices are not the same dimensions!!!" << std::endl;
		abort();
	}

}

MMatrix MMatrix::operator*(float operand)
{
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			inputValue(i, j, getValue(i, j) * operand);
		}
	}
	return *this;
}

MMatrix operator* (float operandF, MMatrix operand)
{
	for (int i = 0; i < operand.getsizeX(); i++)
	{
		for (int j = 0; j < operand.getsizeY(); j++)
		{
			operand.inputValue(i, j, operand.getValue(i, j) * operandF);
		}
	}
	return operand;
}
int MMatrix::getsizeX() const
{
	return sizeX;
}

int MMatrix::getsizeY() const
{
	return sizeY;
}
std::ostream& operator<< (std::ostream& os, const MMatrix mat)
{

	for (int i = 0; i < mat.getsizeY(); i++)
	{
		os << std::endl;
		for (int j = 0; j < mat.getsizeX(); j++)
		{
			os << "[" << mat.getValue(j, i) << "]";
		}
	}

	return os;
}

