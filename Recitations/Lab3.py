# Recit 3 

fileName = "R03-BoulderWeatherData.csv"


weatherFile = open(fileName, 'r')

print("The name of the file is: %s" % weatherFile.name)

#line = weatherFile.readlines()
#print("Read Lines: %s" % line)
'''
lineCounter = 0 
for line in weatherFile :
	lineCounter += 1
	print(line)
print("The number of lines is" , lineCounter)
'''
'''
weatherInfo = [] 
weatherFile.readline()
for line in weatherFile:
	weatherInfo = line.split(",")
	print ("Rainfall on", weatherInfo[0], "was", weatherInfo[4])
print("The number of columns is", len(weatherInfo))
'''
weatherInfo = []
lineCount = 0
maxRain = 0
rainSum = 0
data = 4
weatherFile.readline()
for line in weatherFile:
	weatherInfo = line.split(",")
	print(weatherInfo)
	weatherInfo[data]=float(weatherInfo[data].strip())
	rainSum += weatherInfo[data]
	linecount = lineCount + 1
	if weatherInfo[data] > maxRain:
		maxRain = weatherInfo[data]
	lineCount += 1

print("The max rain was: %.2f"% maxRain)
print("The average rain was: %.2f"% (rainSum/lineCount))



weatherFile.close()
