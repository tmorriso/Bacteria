# Thomas Morrison 
# September 3, 2015
# Lab 2
# Sales Tax Problem

saleTax = 1.0735  # sales tax multiplier
cost = float(input("What is the cost per item?"))
amount = int(input("How many items were purchased?"))

price = (cost * amount)
lastDigit = (price*100)%10


if price >= 5 or lastDigit == 0:
 print ("The price is $",round(price*saleTax,2))
else: 
 print ("The price is $",price)


