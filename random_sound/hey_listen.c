#include <SDL.h>
#include <SDL_mixer.h>
#include <stdlib.h>
#include <time.h>

// Regular file
#define PATH_TO_WAV "hey_listen.wav"
// The chance for the sound to play in percentage
#define CHANCE 10
// Interval to play the sound in minutes
#defime INTERVAL 2
// Time to sleep between every check in seconds
#define DELAY 10

static Mix_Chunk *sound; // The sound to be played
static Uint64 ticks; // Used to handle time

// SDL_GetTicks64 returns miliseconds
#define MINUTE(m) ((m) * 60 * 1000)

int main(void) {
  srand(time(NULL));

  // Initialize sdl and mixer
  if (SDL_Init(SDL_INIT_AUDIO) < 0) return 1;
  //                frequency format              channels chunsize
  if (Mix_OpenAudio(44100,    MIX_DEFAULT_FORMAT, 1,       2048) < 0) return 1;
  
  sound = Mix_LoadWAV(PATH_TO_WAV); // Load sound effect
  if (!sound) return 1;

  ticks = SDL_GetTicks64();
  while (1) {
    // When two minutes passed
    if (ticks + MINUTE(INTERVAL) < SDL_GetTicks64()) {
      if (rand() % CHANCE <= 1) {
        //              any_channel sound  times
        Mix_PlayChannel(-1,         sound, 0); // Play sound
      }
      ticks = SDL_GetTicks64(); // Restart timer
    }
    SDL_DELAY(DELAY * 1000);
  }
}

 
 
 
 
 
