# Tom Morrison
# October 1, 2015
# Project 1 
# Real Estate Investment Evaluator 


# Parse File Function
def parsFile(n):
	houseData = []
	houseFile = open(n, 'r')
	for line in houseFile:
		houseData = line.split()
	houseFile.close()
	return houseData

# Monthly Expenitures Function
def monthlyCosts(p,d,z):
	totalInterest = (p - d)*.04
	mortgagePymnt = (p - d + totalInterest)/(12*30)
	if z == 'Boise':
		taxes = (.00795*p)/12
	elif z == 'Boulder':
		taxes = (.00639*p)/12
	elif z == 'Broomfield':
		taxes = (.0079*p)/12
	if z == 'Boise':
		insurance = 44.47 # average monthly insurance
	elif z == 'Broomfield' or z == 'Boulder':
		insurance = 82.48 # average for Colorado
	utilities = 100.00 # rough estimate can elaborate later
	maintenance = 50.00 # rough estimate
	totalMonthlyCost = mortgagePymnt + taxes + insurance + utilities + maintenance
	return totalMonthlyCost

# Monthly Income Function
def monthlyIncome(a,b,c):
	if c == 'Boulder':
		avgRent = 800.00
	elif c == 'Broomfield' :
		avgRent = 700.00
	elif c == 'Boise':
		avgRent = 450.00
	if b >= a/2 :
		avgRent += 50.00
	rentIncome = avgRent*a
	return rentIncome
	
# Total Gain Function
def totalGain(d,k):
	estimatedInflation = 1.25 # can approximate better later
	estimatedGain = d*estimatedInflation + (k*12*30)
	return estimatedGain

# Total Cost Function
def totalCost(f,g,h):
	totalPrice = f * 12.00 * 30.00 # 30 year loan (could be input)
	closingCost = g * .035
	realtorFees = g * .06 	
	finalCost = totalPrice + closingCost + realtorFees + h
	return finalCost
		
# Stock Market Return on Investment Comparison 
def stockMarket(dwnP):
	compoundInterest = dwnP*(1.07)**(30) # Compounded annually at 7% Avg
	print (compoundInterest)
	return compoundInterest
	
def main ():
	fileName = 0
	while fileName != 'q':
		import sys
		fileName = sys.argv[1]
		print("Parsing",fileName)
		houseData = parsFile(fileName)
		bdRm = float(houseData[0]) 
		bthRm = float(houseData[1])
		location = houseData[2]
		price = float(houseData[3])
		dwnPymnt = float(houseData[4])
		condition = houseData[5]
		year = str(houseData[6])
		sqFt = float(houseData[7])
		estimatedCost = monthlyCosts(price,dwnPymnt,location)
		estimatedIncome = monthlyIncome(bdRm,bthRm,location)
		estimatedProfit = estimatedIncome - estimatedCost
		predictedTotalGain = totalGain(price,estimatedIncome)
		predictedTotalCost = totalCost(estimatedCost,price,dwnPymnt)
		predictedTotalProfit = predictedTotalGain - 	predictedTotalCost
		percentReturn = ((predictedTotalProfit-predictedTotalCost)/predictedTotalCost)*100
		stockInvestment = stockMarket(dwnPymnt) - dwnPymnt
		stockReturn = predictedTotalProfit - stockInvestment
		print ('Estimated monthy expenditures = $ %.2f'%estimatedCost)
		print ('Estimated monthly Income = $ %.2f'% estimatedIncome)
		print ('Estimated monthly profit = $ %.2f'% estimatedProfit)
		print ('Predicted total gain = $ %.2f'% predictedTotalGain)
		print ('Predicted total cost = $ %.2f'% predictedTotalCost)
		print ('Predicted total profit = $ %.2f'% predictedTotalProfit)
		print ('Percent return = %.2f'% percentReturn)	
		# print ('Estimated return on downpayment invested in stocks = $ %.2f'% stockInvestment) (still working on this)
		# print ('Realestate return - stock market return = %.2f'% stockReturn)
		fileName = input("Adjust file and rerun 'a' or enter 'q' to quit")
main()
	



