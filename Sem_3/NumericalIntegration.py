import math

class Numerical_Integration:
    def __init__(self, a, b, n):
        self.x = []
        self.y = []
        self.a = a
        self.b = b
        self.n = n
        self.h = (self.b - self.a) / self.n
        self.calculate_x_y()

    def calculate_x_y(self):
        self.x.append(self.a)
        for i in range(1, self.n + 1):
            self.x.append(self.x[i - 1] + self.h)     
        for i in range(0, self.n + 1):
            self.y.append(round(self.f(self.x[i]), 4))
    
    def f(self, x_point):
        return math.sqrt(math.pow(x_point, 3) + 1)
    
    def Trapezoidal_Rule(self):
        fx = self.y[0] + self.y[self.n]
        for i in range(1, self.n):
            fx += (2 * self.y[i])
        fx *= (self.h / 2)
        return fx

    def Simpsons_13_Rule(self):
        if self.n%2 != 0:
            print("Simpson's 1/3 rule requires sub-intervals 'n' to be even.")
            return 
        
        fx = self.y[0] + self.y[self.n]
        for i in range(1, self.n):
            if i%2 != 0:
                fx += (4 * self.y[i])
            else:
                fx += (2 * self.y[i])
        fx *= (self.h / 3)
        return fx

    def Simpsons_38_Rule(self):
        if self.n%3 != 0:
            print("Simpson's 3/8 rule requires sub-intervals 'n' to be divisible by 3.")
            return 
        
        fx = self.y[0] + self.y[self.n]
        for i in range(1, self.n):
            if i%3 != 0:
                fx += (3 * self.y[i])
            else:
                fx += (2 * self.y[i])
        fx *= ((3 * self.h) / 8)
        return fx   