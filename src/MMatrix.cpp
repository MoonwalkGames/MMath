#include "MMatrix.h"

MMatrix::MMatrix(int _numRows, int _numCols)
{
	numRows = _numRows;
	numCols = _numCols;

	try
	{
		matrixData = new float*[numRows];

		for (int i = 0; i < numRows; i++)
			matrixData[i] = new float[numCols];
	}
	catch (...)
	{
		std::cout << "Aborting! Matrix memory allocation failed!" << std::endl;
		abort();
	}
	

	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			matrixData[i][j] = 0.0f;
		}
	}
}

MMatrix::~MMatrix()
{
	/*for (int i = 0; i < numRows; ++i)
		delete[] matrixData[i];

	delete[] matrixData;*/
}

void MMatrix::inputValue(int rowNum, int colNum, float val)
{
	try
	{
		if (rowNum < numRows)
		{
			if (colNum < numCols)
				this->matrixData[rowNum][colNum] = val;
			else
				throw(1);
		}
		else
			throw(0);
		
	}
	catch (int errorCode)
	{
		if (errorCode == 0)
			std::cout << "Aborting! The coloumn number you specified in inputValue() is out of bounds!" << std::endl;
		else
			std::cout << "Aborting! The row number you specified in inputValue() is out of bounds!" << std::endl;

		abort();
	}
}

float MMatrix::getValue(int rowNum, int colNum) const
{
	try
	{
		if (rowNum < numRows)
		{
			if (colNum < numCols)
				return this->matrixData[rowNum][colNum];
			else
				throw(1);
		}
		else
			throw(0);

	}
	catch (int errorCode)
	{
		if (errorCode == 0)
			std::cout << "Aborting! The coloumn number you specified in getValue() is out of bounds!" << std::endl;
		else
			std::cout << "Aborting! The row number you specified in getValue() is out of bounds!" << std::endl;

		abort();
	}
}


MMatrix MMatrix::operator+(MMatrix operand)
{
	try
	{
		if ((this->getNumRows() == operand.getNumRows()) && (this->getNumCols() == operand.getNumCols()))
		{
			for (int i = 0; i < numRows; i++)
			{
				for (int j = 0; j < numCols; j++)
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
		std::cout << "Aborting! Added matrices are not the same dimensions!" << std::endl;
		abort();
	}

}

MMatrix MMatrix::operator-(MMatrix operand)
{
	try
	{
		if ((this->getNumRows() == operand.getNumRows()) && (this->getNumCols() == operand.getNumCols()))
		{
			for (int i = 0; i < numRows; i++)
			{
				for (int j = 0; j < numCols; j++)
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
		std::cout << "Aborting! Subtracted matrices are not the same dimensions!" << std::endl;
		abort();
	}

}

MMatrix MMatrix::operator*(float operand)
{
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			inputValue(i, j, getValue(i, j) * operand);
		}
	}
	return *this;
}

MMatrix operator* (float operandF, MMatrix operand)
{

	for (int i = 0; i < operand.getNumRows(); i++)
	{
		for (int j = 0; j < operand.getNumCols(); j++)
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
		if (operandF.getNumCols() == operand.getNumRows())
		{
			MMatrix result(operandF.getNumRows(), operand.getNumCols());

			for (int i = 0; i < result.getNumRows(); i++)
			{
				for (int j = 0; j < result.getNumCols(); j++)
				{
					for (int k = 0; k < operandF.getNumCols(); k++)
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
		std::cout << "Aborting! These matrices cannot be multiplied. The first operand's X does not match the second's Y!" << std::endl;
		abort();
	}
}

int MMatrix::getNumRows() const
{
	return numRows;
}

int MMatrix::getNumCols() const
{
	return numCols;
}

//CHANGE TO THE COMPUTER WAY
std::ostream& operator<< (std::ostream& os, const MMatrix mat)
{

	for (int i = 0; i < mat.getNumCols(); i++)
	{
		os << std::endl;
		for (int j = 0; j < mat.getNumRows(); j++)
		{
			os << "[" << mat.getValue(j, i) << "]";
		}
	}
	std::cout << std::endl;

	return os;
}

