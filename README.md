To compile and run the game you have to type this in terminal: 'make && ./flappy' 

Game uses following libraries: sfml-graphics, sfml-window, sfml-system, sfml-audio oraz funkcji PixelPerfectCollision (https://github.com/SonarSystems/SFML-Box2D-Tutorials/tree/master/SFML/Tutorial%20013%20-%20Pixel%20Perfect%20Collision%20Detection)

To move the bird you simply have to press space.

Files and things they are doing:
-main.cpp //gameloop, building objects
-Bird.cpp //bird, drawing and moving
-Collision.cpp //exact collisions
-Game.cpp //game mechanics, draving background
-GameState.cpp //gamestates
-Pipes.cpp //Drawing and moving pipes

