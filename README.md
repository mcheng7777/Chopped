# Chopped
Program in Computing C++ Final Project Cooking Game
By Michael Cheng and Megan Li

3/13/19

PIC 10C, Professor Falcon



This is our Chopped Application, a cooking game consisting of four mini games to achieve the end goal of making a sushi roll. 
There are two players in this game, one playing after the other. 


Running Application:
- This application was created using QtCreator.

- Be sure to have the most updated version of Qt to ensure the best user experience.
- Run the application using QtCreator.

- To install Qt, use this link: https://www.qt.io/download

- Download the open source version. 

- Select the LATEST VERSION when opening the package (5.11 or 5.12)
- If there is an error because the version of Qt is not the most recent, you must reinitialize the project :
	Troubleshooting steps obtained from: https://web.stanford.edu/dept/cs_edu/qt-creator/qt-creator-troubleshooting.shtml
	1. close Qt application
	2. delete the .pro.user file
	3. delete the build file
	4. reconfigure the project when opening it on Qt by selecting all kits
	A new .pro.user file will be created that will allow the application to work on this older Qt version.



Welcome Page:

- This page is the opening page of the application with an option to start game, quit application, and incorporate background music.
- Note: The sound seems to only be audible with Macs, but not with Windows.

Options Page:

- This page allows the user to choose a dish to make. In this current version of the application, there is only a sushi roll option.


Instructions Page:

- These pages provide specific instructions for each of the four mini games.


Ingredients Page:

- This is a game where the user picks ingredients to use for their sushi roll. To play, select the right ingredients for making sushi. If the time runs out before finishing, your score will be based on the correct items you were able to select. 


Cook Rice Page:

- This is a game where the user is cooking the rice. To play, use the space bar to stop the moving widget as close to the center as possible. Press the space bar within 10 seconds of pressing Start. Otherwise, at the end of the time the moving bar will stop and you must press the space bar to continue to the next game.  

In Windows, the moving bar disappears from view.  However, the functionality is still the same; use the space bar to "stop" the moving widget and continue to the next game.  

Chopping Game Page:

- This is a game where sashimi is chopped. To play, use the arrow keys to move the knife and the space bar to cut the fish. There is a timer on this game as well.  You receive +1 for every cut fish and -1 for every missed fish.

Roll Sushi Page:

- This is a game that accomplishes the rolling of the sushi.  To play, correctly input the string at the top of the window as quickly as possible to advance the sushi roll. Your score is based on the number of correct strings you are able to enter before the time runs out. 


Congrats Page:

- This page presents the player's score.


Final Page

- This page displays the winner of the game (whoever has the higher score).

