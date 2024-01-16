[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/SQs7pKlr)
# Poker? I Hardly Know Her!

### Group Members
Team Name: Poker Crew

Samin Alam, Zac Moore, Brandon Chao
       
### Project Description:

The objective of our game is to test people's abilities to determine how good their poker hand is, and what cards they need to randomly change in order to maximize points. Our game is connected to a server that multiple other clients can connect to, so they all play and then their scores are sent to the server, displaying each user's score next to their username. The players can look to the different scores on the screen of the server and compare with their own scores. This ability to compare is strengethed with the fact that if a player gets a high score, they will be immediately notified by the game, allowing them to taunt their opponents and flex their score as much as they can.


### Instructions:

After the user downloads all the files from the git repository, they must enter the "make" command to compile all the necessary programs. From there, if they wish to run the server, they will only have to type out the "./server" command, after which the server will take care of itself. If they wish to be a player, they must enter the "./client" command. This will start the game for them, with the game prompting them for a username, then displaying a randomly generated hand of cards and further prompting the player on how they would like to change the hand to maximize their points. In order to keep rerolling new rounds, the player must keep calling "./client" after every time they finish a round, yet their responses will continue to be displayed by the same server program.
