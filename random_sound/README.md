# random_sound
Play a random sound effect in certain intervals with a certain chance.

## Compile && Run

### C version

#### Dependencies
SDL2 and SDL2_mixer are required.

#### Building
```sh
cc -c hey_listen.c -o hey_listen.o `sdl2-config --cflags`
```

#### Linking
```sh
cc -c hey_listen.o -o hey_listen.exe `sdl2-config --libs` -lSDL_mixer
```

### Running

```sh
hey_listen.exe
```
Preferably, you would want to run it on startup as a background process.

