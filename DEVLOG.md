# Dev Log:

## 2024-01-03 (3:35 PM) Samin, Brandon, Zac
We played around with many different ideas we could implement and how they would use the class material, eventually settling on poker.

## 2024-01-04 (3:35 PM) Samin and Brandon
We finalized our plans and timeline for implementing the poker game, including details on how we will use multiple units.

## 2024-01-05 (3:35 PM) Samin, Brandon, Zac
Samin worked on implementing a function to check a player's hand for each combination, finishing loops for high and flush combinations.
Brandon worked on implementing the basics of the poker game, including structs for the cards and hands.
Zac worked on implementing a way for the player's number of "chips" they had in each game to be written to a file.

## 2024-01-08 (1:00 AM) Samin, Brandon, Zac
Brandon changed up how the card struct was going to be structured, instead giving each card an "id" that is an integer connected to their respective face and suits. He also wrote a function for drawing cards that accounted for redraws as well as a function that cleared the board. Samin worked on evaluting the player's hand under the new card system, using multiple helper functions to calculate the value of each poker combination within one hand. Zac worked on taking player data, using a struct to capture the player's initials and chip amount.

## 2024-01-09 (3:35 PM) Samin, Brandon
Brandon focused on making sure that all the combination related functions fit all the edge cases, using sorting to optimize finding the straight combinations and royal flush. Samin continued to work on setting up the single client server, implementing with the ability to execute commands, which would then later be used with forking so that multiple people can connect. 

## 2024-01-10 (3:35 PM) Samin, Brandon, Zac
Zac worked on finishing up the file system as well as starting on the signalling system for exiting the poker game. Samin worked on the client side of his single client server, as well as working with the ability of the server to executee commands. Brandon continued to work on optimizing and the poker game to full functionality, working on evaluating a player hand and fully implementing his sorting algorithm. 

## 2024-01-11 (3:35 PM) Samin, Brandon, Zac
Zac finished the system behind writing player data from the game into files, began work on helping Samin create the single client server. Samin was focused on a specific bug in how execvp ran in his program, as well as how to incorporate forking to fix it, and how to connect the server to the client. While Brandon worked on finishing up the full functionality of the poker game, leaving us with mostly only the networking aspects to work on.

## Player 1

### 2024-01-02 - Brief description
Expanded description including how much time was spent on task.

### 2024-01-03 - Brief description
Expanded description including how much time was spent on task.

## Player 2

### 2024-01-02 - Brief description
Expanded description including how much time was spent on task.

### 2024-01-03 - Brief description
Expanded description including how much time was spent on task.
