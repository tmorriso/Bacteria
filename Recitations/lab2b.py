import math
tax = 0.0735
cost = float(input("What is the cost per item?"))

while cost != -1:

 numberOfItems = int(input("How many were purchased?"))

 lastDigit = round(cost *100) % 10

 if cost > 5 and lastDigit != 0:
  cost += cost * tax 

 print("The price is $%.2f" % (cost*numberOfItems))
 cost = float(input("What is the cost per item?"))

