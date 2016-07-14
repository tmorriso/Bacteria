# Thomas Morrison
# August 31, 2015
# Assignment 2
# Dungeon Game Problem

print ("Welcome to Tom's Dungeon")

room = "k"
while room == "k" :
  choice1 = input("You are in the kitchen. There are doors to the west (w), south (s), and east (e).")
  if choice1 == "w" :
   room = "h"
   while room == "h" :
     choice2 = input ("You are in the hallway. There are doors to the south (s), and east (e).")
     if choice2 == "e" :
      room = "k"
     elif choice2 == "s" :
      room = "l"
      print ("You are in the library! You found the Princess! You are a hero!")
     elif choice2 == "q" :
      room = "q"  
     else :
      room = "h"
        
  elif choice1 == "e" :
   room = "lr"
   while room == "lr" :
     choice3 = input ("You are in the living room. There is a door to the (w).")
     if choice3 == "w" :
      room = "k"
     elif choice3 == "q" :
      room = "q"
     else :
      room = "lr"
      
  elif choice1 == "s" :
   room = "F"
   print ("You entered the furnace and fry yourself to death!")
  elif choice1 == "q" :
   room = "q"
  else :
   room = "k"

print("Goodbye!")
