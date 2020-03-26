Aby skompilować i uruchomić grę należy użyć komendy 'make && ./flappy'

Gra korzysta z bibliotek sfml-graphics, sfml-window, sfml-system, sfml-audio oraz funkcji PixelPerfectCollision (https://github.com/SonarSystems/SFML-Box2D-Tutorials/tree/master/SFML/Tutorial%20013%20-%20Pixel%20Perfect%20Collision%20Detection)

W grze poruszamy się za pomocą spacji.

Kod składa się plików:
-main.cpp //gameloop, tworzenie obiektów
-Bird.cpp //Ptak, rysowanie i poruszanie się
-Collision.cpp //Dokładne kolizje
-Game.cpp //mechaniki gry, rysowanie planszy
-GameState //Stany gry
-Pipes.cpp //Rury

