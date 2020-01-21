# MKS65 - THE FINAL FRONTIER

#### Project Logistics   
- **Project Name:** CMineSweeper-Multiplayer
- **Team Members:** Tammy Chen, Bernard Wang, and Alvin Yao (Period 4)

#### Description of Project

CMineSweeper-Multiplayer will be our team&#39;s attempt at recreating Minesweeper into a competitive (two)-player game. In the single player version, the objective of the game is to clear a board (can be both square/rectangular) containing hidden mines without activating any of them, while trying to accurately identify more mines than your opponent. After uncovering a space on the board, if it is not a mine, it will display the total number of mines contained in the neighboring spaces. 

**Description of User Interface:**

Once the make file is run, the user will be guided to the main menu where they will have a choice of beginner, intermediate, or advanced level. The main difference amongst all these levels will be the grid size. The user will also have the choice of building their own custom grid. After the user has chosen their preferences, they can create the new game. The user can then enjoy a blind version of Minesweeper where their coordinates are sent to the server. The user can also mark down the possible mines. The screen will display options of playing again or exiting the game.(winning/losing will be updated.)


**Description of Technical Design:**
- Reading in and writing into files to store login information and player history. New players will be prompted to enter new username and old players can view their history.
- Allocating memory to store the current status of the gameboard
- Signals for keywords to change settings &amp; exit game
- (ATTEMPTED) Use of networking between two players on different computers

**Data Structures &amp; Algorithms:**
Arrays &amp; Structs
- Used for user login information &amp; gameboard
- For the gameboard, we might incorporate aspects with a struct to be more efficient (tbd)
  - Incorporate structs into the mines

Algorithms
- Research Minesweeper algorithm ([this](https://quantum-p.livejournal.com/19616.html) &amp; [this](https://massaioli.wordpress.com/2013/01/12/solving-minesweeper-with-matricies/))
  - Implement recursion backtracking

**List of Any Required Libraries**
- None

**How to Use Your Project**
To clone the project:
```bash
$ git clone git@github.com:tchen00/MKS65-FinalProject.git
```

#### To run the project:
PART I (Single Player Minesweeper)
```bash
$ cd MKS65-FinalProject
$ make
$ make run
```
PART II (Blind-Multiplayer Minesweeper: establishes connection between client and server)
```bash
$ cd working_blindminesweeper
$ make
$ make fserver
$ make client 
$ ./server (if you are the server)
OR 
$ ./client (if you are one of the players) 
```
**Known Bugs/Things We Couldn't Get Working**
#### Single Player Minesweeper 
- The functionality of the game works fine but the login mechanism has a few bugs. If you enter an existing player as a new player, it will still work. The victories/losses are not updating. 
#### Blind (Multiplayer) Minesweeper
- This is our attempt at using networking. We got the client to server connection down but the client to client connection does not work. The updated minesweeper board is also not returned to the client which is why we called this blind minesweeper. 


--- 
© Copyright 2020 Team bat -- Tammy Chen, Bernard Wang & Alvin Yao
