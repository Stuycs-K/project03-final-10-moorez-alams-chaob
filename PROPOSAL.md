# Final Project Proposal
Texas Hold'em Poker

# Group Members:
Samin Alam, Brandon Chao, Zac Moore
       
# Intentions:
A interprocess program for playing Texas Hold'em poker, with players being able to connect from different machines.
    
# Intended usage:
The client will join the server and then the server will wait for another client or more. It will ask each client to confirm that they are ready to play. Once at least two players are ready, the game will start. Players will start with some "chips" to be used during rounds of Texas Hold'em poker. Players who run out of chips will no longer be able to play in the current room until the game ends. The game ends either when only one non-broke player is still connected, or when only one player has chips left.
  
# Technical Details:
Pipes, sockets, and processes (forking + exec) will be used to allow for simultaneous client connection.
Files will be created and append player data per round (i.e how many chips each player has each round).
Signals can be used to allow for players to elegantly disconnect during a live round.

# Intended pacing:
Jan 8th - Poker game functional on local computer.
Jan 11th - Networking functional.
Jan 13th - Poker game implemented into networking system.
Jan 15th - File creation/appending for player data, signals for player exiting complete.
Jan 16th - Polish and reasonable bug fixes complete.
