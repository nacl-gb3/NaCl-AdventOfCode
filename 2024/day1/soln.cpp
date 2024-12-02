#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

#include <cassert>

int solnA(const std::vector<int> &a, const std::vector<int> &b);
int solnB(const std::vector<int> &a, const std::vector<int> &b);

int main() {
  std::ifstream fin{"input"};

  if (!fin) {
    std::cerr << "The file could not be opened\n";
    return 1;
  }

  std::vector<int> a{};
  std::vector<int> b{};
  int num{};
  int word_num{0};
  while (fin >> num) {
    if (word_num % 2 == 0) {
      a.push_back(num);
    } else {
      b.push_back(num);
    }
    word_num++;
  }

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  std::cout << "Solution A: " << solnA(a, b) << "\n";
  std::cout << "Solution B: " << solnB(a, b) << "\n";

  return 0;
}

int solnA(const std::vector<int> &a, const std::vector<int> &b) {
  assert(a.size() == b.size());

  std::size_t list_size = a.size();
  std::vector<int> list_distances(list_size);

  for (std::size_t i{0}; i < list_size; ++i) {
    int larger = std::max(a[i], b[i]);
    int smaller = std::min(a[i], b[i]);
    list_distances[i] = larger - smaller;
  }

  return std::accumulate(list_distances.begin(), list_distances.end(), 0);
}

int solnB(const std::vector<int> &a, const std::vector<int> &b) {
  assert(a.size() == b.size());

  std::unordered_map<int, int> list_b_counts{};

  for (const int &num : b) {
    list_b_counts[num]++;
  }

  size_t similarity_score{0};

  for (const int &num : a) {
    similarity_score += num * list_b_counts[num];
  }

  return similarity_score;
}
