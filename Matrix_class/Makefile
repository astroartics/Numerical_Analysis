CC=g++
CCFLAGS=-I.
DEPS=Matrix.hpp Interpolation.hpp
TARGET=matop
OBJS=main.o Matrix.o Add_Sub.o Identity_Symmetric.o Multiply.o Gaussian_Elimination.o Transpose.o LU_Decomposition.o DiagonallyDominant.o Determinant.o Gauss_Jacobi_Seidel.o Least_Squares.o Lagranges_Interpolation.o ChebyshevPolynomial.o Exponential_Fit.o

%.o: %.cpp $(DEPS)
	$(CC) $(CCFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)