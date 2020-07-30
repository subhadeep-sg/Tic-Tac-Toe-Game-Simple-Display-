This is the documentation for the Simple Tic Tac Toe Game
The game is both single and multiplayer(two players)
The player has an option of going first or second in single player mode.
There is one source file and two header files.
---------------------------------------------------------------------------------------------------------------------
The header file "TicTacHead.h" contains the following functions:
1. void init()
	Initializes the game board with numbers which act as labels throughout the game
2. void board_reset()
	Resets the contents of the board to spaces or blanks. This is used to start a fresh game.
3. void disp_board()
	Displays the board in its current state. Called to show the board at all points in the game.
4. int update()
	Accepts input to the board. Checks if the board already has an entry in the given position.
5. int win_con()
	Checks for win condition once every entry by either player/computer. Stops the game if a win is found.
6. int draw_cond()
	Checks for guaranteed draw conditions. Stops the game once it is certain the game cannot be won.
7. void Multimode()
	Called when user selects to play multiplayer. Provides the interface for two players to play the game.
8. void error()
	Called when there is an error selecting the Multi/Single player mode.
----------------------------------------------------------------------------------------------------------------------
The header file "GameAI.h" is for the computer interaction and contains the following functions:
1. int centreseek()
	Attempts to update the game board by playing the centre square as the computer. The function makes sure
	there is no occupancy in the centre square first.
2. int seekdiag()
	Attempts to update the game board by playing on any of the 4 corner squares as the computer. Also makes
	sure there is no occupancy first.
3. int danger()
	Attempts to update the game board by playing on a square which would otherwise allow the opponent to win.
	Checks row>column>diagonal>minor diagonal.
4. int winningplay()
	Similar to the danger, tries to update the board by playing on a square that would allow the computer to
	win. Checks row>column>diagonal>minor diagonal.
5. int idealpos()
	Implements the functions winningplay and danger as the best response for the computer.
6. void react()
	Defines the response of the computer to a previous move by checking if centre is occupied, then whether the 
	corners are occupied and finally the idealpos function to check for danger and winningplay.
7. void secplr()
	Defines the response of the computer if the player plays second and computer plays first. 
8. int weakness()
	Accounts for a specific trap that occurs if a player has played on two opposite corners and can fork the 
	opponent by playing on either adjacent diagonals. This function is made for the computer to play.
	eg:
	1 || 2 || 3
	------------
	4 || 5 || 6
	------------
	7 || 8 || 9
	if player has played on labels 1 and 9 and the computer has played on 5 and it is the computer's turn. The 
	computer should try to play 2,4,6,8 because if it plays 3 for example.
	Then the player immediately wins by playing 7. Now the player can win by playing either 4 or 8 regardless
	of whether computer blocks 4 of 8. According to the danger function the computer should check and find the
	danger on 4 first and player then wins by playing 8. (7,8,9)
9. int index()
	Gives the respective label for the specific row and column of the gameboard.
	eg Row=0 , Col=0 then Label should be 1.
10. void firreact()
	Defines the response when of the computer to previous moves but is specialized to the case of first person
	being the player and not the computer.
11. void firplr()
	Defines the response of the computer when player goes first and copmuter second.
12. void Singlemode()
	Called when user selects to play Single player mode. Provides the interface for one player playing against
	the computer.
----------------------------------------------------------------------------------------------------------------------
The source files defines the game board globally and contains the main function
The main function provides the labelled game board and then asks the user whether they want to play Multiplayer or 
Single Player.