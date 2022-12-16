Asteroids but worse

Group Members:
Liv Coro
Nils Howland

How to play:
Enter key is used to start and restart the game
Left and right arrow keys are used to rotate your ship
Space key is used to shoot bullets

What each group member did:
Liv Coro:
- Asteroid rendering
- Asteroid movement
- Death/Asteroid player collision
- Asteroid out of bounds
- Asteroid class 

Nils Howland:
- Player movement
- Shooting logic
- Asteroid spawning
- Textures
- Menus and game states
- Bullet Asteroid collision
- Level, and bullet class

Both members:
- Player class
- Audio
- Project structure

Understanding Codebase:
- Classes.h contains all the games classes and structs
- Main.cpp handles menus and game states and passes along update and render functionality to Level.cpp 
  It also handles texture and audio loading and unloading
- Level.cpp handles passing update and rendering functionality to all entities. 
  It also handles all collisions and asteroid spawning
- Player.cpp contains movement logic and the bullet/shooting logic. 
  It also contains the initialization, rendering, and update logic of the player.
- Asteroid.cpp contains the initialization, rendering, and update logic of an asteroid.
