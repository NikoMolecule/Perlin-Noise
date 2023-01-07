#include <math.h>
#include <time.h>

#include <cstdlib>
#include <iostream>
#include <vector>

#include "perlin.h"
#include "raylib.h"

using namespace std;

int main(void) {
  srand(time(0));
  const int screenWidth = 512;
  const int screenHeight = 512;

  InitWindow(screenWidth, screenHeight, "perlins go brrrrrrrrrrrrr");

  SetTargetFPS(60);

  Image img = GenImageColor(GetScreenWidth(), GetScreenHeight(), BLACK);
  Texture tx = LoadTextureFromImage(img);

  PerlinNoise perlin(8, 0.5);

  int seed = rand();
  perlin.genOff(seed);

  for (int y = 0; y < 512; y++) {
    for (int x = 0; x < 512; x++) {
      float n = perlin.Get2d(x, y, 256);

      n += 1;
      n /= 2;
      unsigned char c = (unsigned char)round(n * 255);

      ImageDrawPixel(&img, x, y, Color{c, c, c, (unsigned char)255});
    }
  }
  UpdateTexture(tx, img.data);

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BLACK);
    DrawTexture(tx, 0, 0, WHITE);

    EndDrawing();
  }

  UnloadImage(img);
  UnloadTexture(tx);
  CloseWindow();

  return 0;
}

// simple terrain colors.
/*unsigned char r, g, b, a = 255;

if (n < 0.3) {
  r = 4;
  g = 23;
  b = 99;
} else if (n < 0.5) {
  r = 15;
  g = 62;
  b = 163;
} else if (n < 0.53) {
  r = 163;
  g = 145;
  b = 90;
} else if (n < 0.7) {
  r = 18;
  g = 105;
  b = 26;
} else if (n < 0.75) {
  r = 73;
  g = 99;
  b = 78;
} else if (n < 0.85) {
  r = 56;
  g = r;
  b = r;
} else {
  r = 201;
  g = r;
  b = r;
}*/