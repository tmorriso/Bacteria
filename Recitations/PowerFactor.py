# Thomas Morrison
# August 28, 2015
# Assignment 1 Part 2
# Power Factor Problem 

import math

kW = int(input("Enter the real power:")) # Real Power
kVAr = int(input("Enter the reactive power:")) # Reactive Power


pF = kW/(math.sqrt(math.pow(kW,2)+math.pow(kVAr,2))) #power factor

final = round(pF,4)*100

print ("The Power Factor is:", final,"%")

# This code first imports the necessary math function library, then it defines the real power and the reactive power (kW and kVAr). It then computes the given equation to determine the power factor, finally it rounds the answer to decimal points and prints the response.
