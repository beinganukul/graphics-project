# Intro
Multiplayer game written in C++ as second semester Computer Graphics(CSC209) project. Created using sdl2.
## dependencies
```bash
yay -S sdl2_ttf sdl2_mixer sdl2
```
## build
```
git clone https://github.com/beinganukul/chor-police.git
cd chor-police
make create-output-dir
make 
```
## run
```
./bin/release/main
```
## how to play
There are two players, one is chor another one is police. chor tries to run away from police off the screen using WASD control whereas police uses mouse to capture chor by hovering mouse over it.
