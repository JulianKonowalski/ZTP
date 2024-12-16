#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>

#define MAX_POINTS 10
#define MIN_COORD -10.0
#define MAX_COORD 10.0

#define BUFFER_WIDTH 80
#define BUFFER_HEIGHT 40

static char buffer[BUFFER_HEIGHT * BUFFER_WIDTH];
static std::random_device rd{};
static std::mt19937 gen{rd()};
static std::normal_distribution<double> d(0.0, 3.33);

double accumulateSquare(double x, double y) { return x + (y * y); }

double calculateLength(const std::vector<double>& vector) {
  double length = 0.0;
  length = std::sqrt(std::accumulate(vector.begin(), vector.end(), length, accumulateSquare));
  return length;
}

std::vector<double> normalize(const std::vector<double>& vector) {
  double length = calculateLength(vector);
  std::vector<double> tmp(2, 1.0 / length);
  std::vector<double> normalized(2);
  std::transform(vector.begin(), vector.end(), tmp.begin(), normalized.begin(), std::multiplies<>());
  return normalized;
}

void drawPoints(const std::vector<std::vector<double>>& points) {
  std::for_each(points.begin(), points.end(), [](auto& vector) { //rasterise
    int x = (vector.at(0) + 1.0) / 2.0 * BUFFER_WIDTH;
    int y = (vector.at(1) + 1.0) / 2.0 * BUFFER_HEIGHT;
    buffer[x + (y * BUFFER_WIDTH)] = '*';
  });
    
  for (int i = 0; i < BUFFER_HEIGHT; ++i) { //print
    for (int j = 0; j < BUFFER_WIDTH; ++j) {
      std::cout << buffer[j + (i * BUFFER_WIDTH)];
    }
    std::cout << "\n";
  }
}

int main(void) {
  std::memset(buffer, ' ', sizeof(buffer));
  srand((unsigned)time(nullptr));
  std::vector<std::vector<double>> points(200);
  std::generate(points.begin(), points.end(), [](){ 
    std::vector<double> vector(2);
    std::generate(vector.begin(), vector.end(), []() { return d(gen); });
    return vector; 
  });
  std::for_each(points.begin(), points.end(), [](auto& vector) { vector = normalize(vector); });
  drawPoints(points);
  return 0;
}