# Lab4.1.py 
"""
def adder(list):
	numThree = 0
	for item in list:
		numThree += item
	return numThree

def main():
	list = []
	x = 3 
	y = 4
	print("x= %i" % x)
	print("y= %i" % y)
	list.append(x)
	list.append(y)
	z = adder(list)

	print("x+y = %i" % z)
main()
"""

# Lab4 problem

def calcFactorial(n):
	fact = 1
	while n > 0 :
		fact = fact * n 
		n = n - 1 
	return fact

def nchoosek(n,k):
	
	
