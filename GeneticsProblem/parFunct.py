# Main Function
import sys
fileName = sys.argv[1]	
print("Parsing", fileName)
dictionary = {}
dictionary["rs1426654"]='skin'
dictionary["rs7754840"]='diabetes'

# pars Function
DNAdata = []	
DNAfile = open(fileName, "r") #read in file from command ln
for line in DNAfile:
	DNAdata = line.split(" ")
	#print (DNAdata)
	if DNAdata[0] != '#':
		DNAdata = line.split("	")	
		DNAdata[3] = DNAdata[3].strip()
		dictionary[DNAdata[0]] = DNAdata[3]
print(dictionary)
DNAfile.close()

# Diabetes Function
diabetes = dictionary["rs7754840"]
print(diabetes)
if diabetes == 'CG':  #Why can't I put 'CG' or 'CC'?
	print('1.3x Increased risk for Type-2 Diabetes')
elif diabetes == 'CC':
	print('1.3x Increased risk for Type-2 Diabetes')
elif diabetes == 'GG': 
	print('Normal risk for Type-2 Diabetes')
else :
	print('No DNA info on Type-2 Diabetes')

# Skin Type Function
skinType = dictionary["rs1426654"]
print(skinType)
if skinType == 'AA':
	print("Probably light-skinned, European ancestry")
elif skinType == 'AG':
	print("Probably mixed African/European ancestry")
elif skinType == 'GG':
	print("Probably darker-skinned, Asian or African ancestry")
else:
	print("No DNA info on Skin Type")


