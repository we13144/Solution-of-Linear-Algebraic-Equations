#ifndef MATRIX_H
#define MATRIX_H

#include "Fraction.h"
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::string;

typedef vector<Fraction> vF;
typedef vector<vector<Fraction>> v_vF;

class Matrix {
public:
	// Operator overloading.
	friend Matrix operator+ (const Matrix&, const Matrix&);
	friend Matrix operator+= (Matrix&, const Matrix&);
	friend Matrix operator- (const Matrix&, const Matrix&);
	friend Matrix operator-= (Matrix&, const Matrix&);
	friend Matrix operator* (const Matrix&, const Matrix&);
	friend Matrix operator*= (Matrix&, const Matrix&);
	friend bool operator== (const Matrix&, const Matrix&);
	friend bool operator!= (const Matrix&, const Matrix&);
	friend std::ostream& operator<< (std::ostream&, const Matrix&);
	friend std::istream& operator>> (std::istream&, Matrix&);
	
public:
	// Constructor.
	Matrix() = default;
	Matrix(size_t temp_row, size_t temp_col) :row(temp_row), col(temp_col) {  // Determine the size of the matrix,default value is zero.
		matrix.resize(row);
		for (size_t i = 0; i < row; i++) {
			matrix[i].resize(col);
		}
	}
	Matrix(const Matrix &rhs) {  // Copy constructor.
		this->row = rhs.row;
		this->col = rhs.col;
		this->matrix = rhs.matrix;
	}
	Matrix & operator=(const Matrix &rhs) {  // Copy-assignment operator.
		if (this != &rhs) {
			this->row = rhs.row;
			this->col = rhs.col;
			this->matrix = rhs.matrix;
		}
		else {
			return *this;
		}
	}
	~Matrix(){ }  // Destructor

	// Nember function
	void resize(const size_t &, const size_t &);  // Reset matrix size. 
	void add_row(size_t &, vF &);  // Add a line.
	void add_to_other_row(size_t &, Fraction &);  // One row of the matrix is multiplied by K,it means matrix is multiplied by K.
	void add_to_other_row(size_t &, size_t &, Fraction &);  // One row of the matrix is multiplied by K and added to the other line.
	void swap_row(size_t &, size_t &);  // Swap two roes;
	void del_row(size_t &);  // Minus one line.
	void add_col(size_t &, vF &);  // Add a column.
	void add_to_other_col(size_t &, Fraction &);  // One column of the matrix is multiplied by K,it means matrix is multiplied by K.
	void add_to_other_col(size_t &, size_t &, Fraction &);  // One column of the matrix is multiplied by K and added to the other column.
	void del_col(size_t &);  // Minus one column.
	void swap_col(size_t &, size_t &);  // Swap two cols;
	Matrix trans();  // Transpose a matrix.
	string cout_out() const;  // Output matrix.
	void cin_in(string &);  // Input matrix.
	void Matrix::resolve(Matrix &temp_m1);   // devide into triangular matrix.
	
private:
	size_t row = 0;  // rows
	size_t col = 0;  // columns
	v_vF matrix;
};

#endif
