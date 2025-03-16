CC=g++
DEPS=Matrix.hpp
TARGET=matop
OBJS=main.o Matrix.o Add_Sub.o Identity_Symmetric.o Multiply.o Gaussian_Elimination.o Transpose.o LU_Decomposition.o DiagonallyDominant.o Determinant.o

%.o: %.cpp $(DEPS)
	$(CC) -o $@ $<

$(TARGET): $(OBJS)
	$(CC) -o $@ $^
