#include "providedFiles.h"

float *providedFunctions::convert(float **v) {
  return reinterpret_cast<float *>(v);
}

float **providedFunctions::convert(float *v) {
  return reinterpret_cast<float **>(v);
}