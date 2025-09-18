# Newton's forward, backward and divided difference

import math
import numpy as np

class Interpolation:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.forward_diff_row = []
        self.backward_diff_row = []
        self.divided_diff = []
        self.gauss_forward_diff = []
        self.gauss_backward_diff = []
        self.difference_table()

    def difference_table(self):
        # self.forward_diff_row = []
        # self.backward_diff_row = []
        curr_col = self.y.copy()
        curr_len = len(curr_col)
        
        while(curr_len > 1):
            for i in range (0, curr_len - 1):
                sub = curr_col[i + 1] - curr_col[i]
                if i == 0:
                    self.forward_diff_row.append(sub)
                if i == (curr_len - 2):
                    self.backward_diff_row.append(sub)
                curr_col.append(sub)
            curr_col = curr_col[curr_len:]
            curr_len = len(curr_col)  

    def calculating_u(self, u, n, is_forward):
        temp = 1
        if is_forward:
            for i in range(0, n):
                temp *= (u - i)
        else:
            for i in range(0, n):
                temp *= (u + i)
        return temp

    def newtons_forward_difference(self, x_point):
        h = self.x[1] - self.x[0]
        u = (x_point - self.x[0]) / h
        # self.difference_table()
        n = len(self.forward_diff_row)
        yx = self.y[0]
        for i in range(1, n + 1):  # +1 ensures the last difference (delta y0) is included
            yx = yx + (self.calculating_u(u, i, True) * self.forward_diff_row[i-1] / math.factorial(i))
        return yx

    def newtons_backward_difference(self, x_point):
        h = self.x[1] - self.x[0]
        u = (x_point - self.x[len(self.x) - 1]) / h
        # self.difference_table()
        n = len(self.backward_diff_row)
        yx = self.y[len(self.y) - 1]
        for i in range(1, n + 1):  
            yx += (self.calculating_u(u, i, False) * self.backward_diff_row[i-1] / math.factorial(i))
        return yx

    def calculating_divided_x(self, x_point, n):
        temp = 1
        for i in range(0, n):
            temp *= (x_point - self.x[i])
        return temp

    def newtons_divided_difference(self, x_point):
        n = len(self.y)
        self.divided_diff = []
        curr_col = self.y.copy()
        curr_x = self.x.copy()
        
        for i in range(1, n):
            for j in range(n - i):
                curr_col[j] = (curr_col[j + 1] - curr_col[j]) / (curr_x[i + j] - curr_x[j])
            self.divided_diff.append(curr_col[0])
        fx = self.y[0]
        for i in range(len(self.divided_diff)):
            fx += self.calculating_divided_x(x_point, i + 1) * self.divided_diff[i]
        return fx

    def Lagrange_Interpolation(self, x_point):
        ratio = 1.0
        result = 0.0

        for i in range(len(self.x)):
            ratio = 1.0
            for j in range(len(self.x)):
                if i != j:
                    ratio *= (x_point - self.x[j]) / (self.x[i] - self.x[j])
            result += self.y[i] * ratio
        return result

    def stirling_coeff(self, p, i):
        coeff = 1.0
        if i%2 != 0:
            coeff *= p
            for k in range(1, (i + 1)//2):
                coeff *= ((p**2) - (k**2))
        else:
            coeff *= (p**2)
            for k in range(1, i//2):
                coeff *= ((p**2) - (k**2))
        return coeff / math.factorial(i)

    def Stirlings_central_difference(self, x_point):
        n = len(self.y)
        self.gauss_forward_diff = []
        self.gauss_backward_diff = []
        curr_col = self.y.copy()
        curr_x = self.x.copy()
        midpoint_forward = midpoint_backward = n // 2
        
        for i in range(1, n):
            new_col = []
            for j in range(n - i):
                new_col.append(curr_col[j + 1] - curr_col[j])
            curr_col = new_col

            length = len(curr_col)
            f_index = b_index = 0
            if i % 2 != 0:  
                b_index = midpoint_backward - (i // 2) - 1  # Go upwards
            else:           
                b_index = midpoint_backward - (i // 2)  # Stay on the same index

            # Backward and forward has common data at even intervals of delta_y
            f_index = midpoint_forward - (i // 2) # When index is odd, we stay on the same row, when even, move one step upwards
    
            # Checking whether indices are within bounds
            if 0 <= f_index < length:
                self.gauss_forward_diff.append(round(curr_col[f_index], 3))
            if 0 <= b_index < length:
                self.gauss_backward_diff.append(round(curr_col[b_index], 3))

        h = self.x[1] - self.x[0]
        p = (x_point - self.x[n // 2]) / h
        yx = self.y[n // 2]
        for i in range(1, len(self.gauss_forward_diff) + 1):
            # Averaging just the odd terms as even terms are common in both gauss forward and backward table
            diff = 0
            if i%2 != 0:
                diff = (self.gauss_forward_diff[i - 1] + self.gauss_backward_diff[i - 1]) / 2
            else:
                diff = self.gauss_forward_diff[i - 1]
                        
            coeff = self.stirling_coeff(p, i)
            yx += coeff * diff
        return yx