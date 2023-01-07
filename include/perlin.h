#pragma once

#include <vector>

#include "raylib.h"

class PerlinNoise {
 public:
  int octaves;
  float persistance;
  std::vector<Vector2> offsets;

  PerlinNoise(int lod, float per) {
    octaves = lod;
    persistance = per;
  };

  void genOff(int seed);
  float Get2d(float x, float y, float scale);
};