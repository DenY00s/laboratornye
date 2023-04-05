#include <iostream>

template<typename T, int N, int M>
class Matrix
{
	T m_matrix[N][M];
public:
	Matrix()
	{
		std::cout << "Constructor #1" << std::endl;
		for (int i = 0;i < N;i++)
			for (int j = 0; j < M;j++)
				m_matrix[i][j] = 0;

	}
	Matrix(T c)
	{
		std::cout << "Constructor #2" << std::endl;
		for (int i = 0;i < N;i++)
			for (int j = 0; j < M;j++)
				m_matrix[i][j] = c;

	}
	~Matrix() = default;
	Matrix(const Matrix& z)
	{
		std::cout << "copy constructor" << std::endl;
		for (int i = 0;i < N;i++)
			for (int j = 0; j < M;j++)
				m_matrix[i][j] = z.m_matrix[i][j];
	}
	Matrix& operator=(const Matrix& z)
	{
		std::cout << "COPY ASSIGMENT OPERATOR" << std::endl;
		if (this == &z)
		{
			return *this;
		}
		for (size_t i = 0; i < N; ++i)
		{
			for (size_t j = 0; j < M; ++j)
			{
				m_matrix[i][j] = z.m_matrix[i][j];
			}
		}

		return *this;

	}
	Matrix operator += (const Matrix& z) const
	{
		Matrix temp;
		if (N != M)
		{
			throw "error";
		}
		for (size_t i = 0; i < N;i++)
			for (size_t j = 0; j < M;j++)
			{
				temp.m_matrix[i][j] += m_matrix[i][j] + z.m_matrix[i][j];
			}
		return *temp;
	}
	Matrix operator + (const Matrix& z)
	{
		Matrix temp;
		if (N != M)
		{
			throw "error";
		}
		for (size_t i = 0; i < N;i++)
			for (size_t j = 0; j < M;j++)
			{
				temp.m_matrix[i][j] += m_matrix[i][j] + z.m_matrix[i][j];
			}
		return temp;
		
	}
	Matrix& operator ++ (T)
	{
		
		for (int i = 0; i < N;i++)
			for (int j = 0; j < M;j++)
			{
				m_matrix[i][j] = m_matrix[i][j] + 1;
			}
		return*this;

	}
	Matrix operator *= (const Matrix& z) const
	{
		if (N != M)
		{
			throw "error";
		}
		Matrix temp;
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < M; j++)
			{
				for (size_t k = 0; k < M; k++)
				{
					temp.m_matrix[i][j] += m_matrix[i][k] * z.m_matrix[k][j];
				}
			}
		}

		return temp;
	}
	Matrix operator * (const Matrix& z)
	{
		if (N != M)
		{
			throw "error";
		}
		Matrix temp;
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < M; j++)
			{
				for (size_t k = 0; k < M; k++)
				{
					temp.m_matrix[i][j] += m_matrix[i][k] * z.m_matrix[k][j];
				}
			}
		}

		return temp;
	}
	void Print()
	{
		std::cout << N << " " << M << std::endl;
		for (int i = 0;i < N;i++)
		{
			for (int j = 0; j < M;j++)
			{
				std::cout << m_matrix[i][j] << '\t';
			}
			std::cout << '\n';
		}
	}
	T& at(size_t i, size_t j)
	{
		return m_matrix[i][j];
	}
	double determinant()
	{
		if (N == 1 && M == 1)
		{
			return m_matrix[0][0]
		}
		if (N == 2 && M == 2)
		{
			return m_matrix[0][0] * m_matrix[1][1]
				- m_matrix[0][1] * m_matrix[1][0];
		}
		else if (N == 3 && M == 3)
		{
			return m_matrix[0][0] * m_matrix[1][1] * m_matrix[2][2] + m_matrix[2][0] * m_matrix[0][1] * m_matrix[1][2] + m_matrix[1][0] * m_matrix[2][1] * m_matrix[0][2] - m_matrix[0][2] * m_matrix[1][1] * m_matrix[2][0] - m_matrix[1][0] * m_matrix[0][1] * m_matrix[2][2] - m_matrix[0][0] * m_matrix[2][1] * m_matrix[1][2];
		}
	}
	template<typename T, size_t N, size_t M>
	friend std::istream& operator >> (std::istream& in, Matrix<T, N, M>& z);
	template<typename T, size_t N, size_t M>
	friend std::ostream& operator << (std::ostream& out, const Matrix<T, N, M>& z);

};
template<typename T, size_t N, size_t M>
std::istream& operator >> (std::istream& in, Matrix<T, N, M>& z)
{
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			in >> z.m_matrix[i][j];
		}
	}

	return in;
}

template<typename T, size_t N, size_t M>
std::ostream& operator << (std::ostream& out, const Matrix<T, N, M>& z)
{
	out << std::endl;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			out << z.m_matrix[i][j] << ' ';
		}
		out << std::endl;
	}

	return out;
}
int main()
{
	Matrix<int,2,2> A(1);
	A.Print();
	Matrix<int, 2, 2> B(3);
	Matrix<int, 2, 2> C;
	Matrix<int, 2, 2> D;
	B.Print();
	C = B + A;
	D = C * A;
	B = A;
	B.Print();
	C.Print();
	D.Print();
	D++;
	D.Print();
}