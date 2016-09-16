#include "MMatrix.h"
// Y before X, to avoid flipping variable names everywhere else and preventing crashes and general confusion. What we want, (X,Y) is the opposite
//of how C++ stores stuff.
MMatrix::MMatrix(int c, int r)
{
	sizeX = c;
	sizeY = r;
	matrixData = new float*[c];

	for (int i = 0; i < c; i++)
	{
		matrixData[i] = new float[r];
	}

	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < r; j++)
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
void MMatrix::inputValue(int c, int r, float val)
{
	this->matrixData[c][r] = val;
}

//Needs try/catch
float MMatrix::getValue(int c, int r) const
{
	return this->matrixData[c][r];
}


MMatrix MMatrix::operator+(MMatrix operand)
{
	try
	{
		if ((this->getsizeX() == operand.getsizeX()) && (this->getsizeY() == operand.getsizeY()))
		{
			for (int i = 0; i < sizeX; i++)
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
	catch (...)
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

MMatrix operator* (MMatrix operand, MMatrix operandF)
{
	try
	{
		if (operandF.getsizeY() == operand.getsizeX())
		{
			MMatrix result(operandF.getsizeX(), operand.getsizeY());

			for (int i = 0; i < result.getsizeX(); i++)
			{
				for (int j = 0; j < result.getsizeY(); j++)
				{
					for (int k = 0; k < operandF.getsizeY(); k++)
					{
						float newValue = result.getValue(i,j);
						newValue += (operandF.getValue(i, k) * operand.getValue(k, j));

						result.inputValue(i,j, newValue);
					}
				}
			}
			return result;
		}
		else
		{
			throw(0);
		}
	}
	catch (...)
	{
		std::cout << "Aborting! first oprand's Y do not match second oprand's X!!!" << std::endl;
		abort();
	}
}

int MMatrix::getsizeX() const
{
	return sizeX;
}

int MMatrix::getsizeY() const
{
	return sizeY;
}

//CHANGE TO THE COMPUTER WAY
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
	std::cout << std::endl;

	return os;
}

