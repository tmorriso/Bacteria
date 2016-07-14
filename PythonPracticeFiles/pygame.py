# set up 
import pygame
pygame.init()

# set size
size = [400,500]
screen=pygame.display.set_mode(size)

done = False
while not done:
	user_inputs = pygame.events.get()

	# update 
	screen.blit(your_image, (x,y))
	pygame.display.flip()
	
