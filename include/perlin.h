#pragma once

#include "raylib.h"

class PerlinNoise {
 public:
  int octaves;
  float persistance;

  PerlinNoise(int lod, float per) {
    octaves = lod;
    persistance = per;
  };

  float Get2d(float x, float y);
};