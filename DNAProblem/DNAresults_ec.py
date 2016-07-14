# Tom Morrison
# September 16, 2015
# Assignment 4
# Collaborators 
# DNA Results Problem with extra credit attempt

# ParsFile function

def parsFile(n): 
	DNAdata = []	
	dictionary = {}
	dictionary["rs1426654"]='skin'
	dictionary["rs7754840"]='diabetes'
	DNAfile = open(n, "r") #read in file from command ln
	for line in DNAfile:
		DNAdata = line.split(" ")
		print (DNAdata)
		if DNAdata[0] != '#':
			DNAdata = line.split("	")	
			DNAdata[3] = DNAdata[3].strip()
			print(DNAdata)
			dictionary[DNAdata[0]] = DNAdata[3]
		#print(dictionary)
	DNAfile.close()
	return dictionary
	

# Diabetes Function

def checkType2Diabetes(d):
	diabetes = d
	#print(diabetes)
	if diabetes == 'CG':  #Why can't I put 'CG' or 'CC'?
		resultD = '1.3x Increased risk for Type-2 Diabetes'
	elif diabetes == 'CC':
		resultD = '1.3x Increased risk for Type-2 Diabetes'
	elif diabetes == 'GG': 
		resultD = 'Normal risk for Type-2 Diabetes'
	else :
		resultD = 'No DNA info on Type-2 Diabetes'
	return resultD

# Skin Type Function

def checkSkinType(s):
	skinType = s
	#print(skinType)
	if skinType == 'AA':
		resultSkin = "Probably light-skinned, European ancestry"
	elif skinType == 'AG':
		resultSkin = "Probably mixed African/European ancestry"
	elif skinType == 'GG':
		resultSkin = "Probably darker-skinned, Asian or African ancestry"
	else: 
		resultSkin = "No DNA info on Skin Type"

	return resultSkin

# Check 1 function for extra credit

def check1(rs1,rs2):
	if rs1 == 'CC':
		if rs2 == 'CC':
			print('[16%] Genetic Privilege: Any Diet Works For You')
		else :
			print('[39%] Genetic Disprivilege: You Will Lose 2.5x As Much Weight on a Low Fat Diet')
	else:
		print('[39%] Genetic Disprivilege: You Will Lose 2.5x As Much Weight on a Low Fat Diet')
		

# Check 2 function for extra credit

def check2(rs1a,rs2b,rs3c):
	if rs1a == 'GG':
		chk1 = check1(rs2b,rs3c)
	else:
		if rs2b == 'CC':
			print ('[39%] Genetic Disprivilege: You Will Lose 2.5x As Much Weight on a Low Fat Diet')
		else :
			print('[45%] Genetic Disprivilege: You Will Lose 2.5x As Much Weight on a Low Carb Diet')




def main ():
	import sys
	fileName = sys.argv[1]	
	print("Parsing", fileName)
	dictionary = parsFile(fileName)
	print(checkType2Diabetes(dictionary["rs7754840"]))
	print(checkSkinType(dictionary["rs1426654"]))
	#Extra Credit Portion
	rs4994 = dictionary.get("rs4994")
	rs1042713 = dictionary.get("rs1042713")
	rs1801282 = dictionary.get("rs1801282")
	rs1042714 = dictionary.get("rs1042714")
	rs1799883 = dictionary.get("rs1799883")
	if rs4994 in ('AA', 'TT'):
		if rs1042713 in ('AA', 'TT'):
			print('[12%] Genetic Privilege: Any Exercise Works For You')
			rnd1 = check1(rs1801282,rs1042714)
		else:
			print('[88%] Genetic Disprivilege: Only High Intensity Exercise Will Help You Lose Weight')
			rnd2 = check2(rs1799883,rs1801282,rs1042714)	
	else:
		print('[88%] Genetic Disprivilege: Only High Intensity Exercise Will Help You Lose Weight')
		rnd3 = check2(rs1799883,rs1801282,rs1042714)
	
	
main()
