#include "temp.h"

double toc(double farenheight) {
  return (farenheight - 32) / 1.8;
}

double tof(double celcuis) {
  return (celcuis * 1.8) + 32;
}
