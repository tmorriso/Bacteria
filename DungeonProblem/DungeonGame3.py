# Thomas Morrison
# August 31, 2015
# Assignment 2
# Dungeon Game Problem no extra credit

print ("Welcome to Tom's Dungeon")

room = "k"
choice = ""

while choice != "q" :
 if room == "k":
  choice = input("You are in the kitchen. There are doors to the west (w), south (s), and east (e).")
  if choice == "s":
   room = "f"
  elif choice == "e": 
   room = "lr"
  elif choice == "w": 
   room = "h" 
 elif room == "f":
  print ("You entered the furnace and fry yourself to death!")
  choice = "q"
 elif room == "h":
  choice = input("You are in the hallway. There are doors to the south (s) and east (e) and north (n).")
  if choice == "s":
    room = "l"
  elif choice == "e":
    room = "k"
  elif choice == "n":
    room = "br"
 elif room == "lr":
  choice = input("You are in the living room. There is a door to the west (w).")
  if choice == "w" :
   room = "k"
 elif room == "l":
  print ("You are in the library. You found the princess! You are a hero!")
  choice = "q" 
 elif room == "br": 
  choice = input("You are in the bedroom. There are doors to the east (e), west (w), and south (s).")
  if choice == "e":
   room = "ws"
  elif choice == "w":
   room = "stairs"
  elif choice == "s":
   room = "h"
 elif room == "ws":
  room = input("You found the mad scientists work shop. You enter a telaportation machine, would you like to teleport to the kitchen (k) or the living room (lr)?") 
 elif room == "stairs":
  print ("You fell down the stairs and died.") 
  choice = "q"

print ("Goodbye!")
