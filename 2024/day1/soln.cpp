#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

#include <cassert>
#include <cstdint>

std::uint64_t solnA(const std::vector<std::uint64_t> &a,
                    const std::vector<std::uint64_t> &b);
std::uint64_t solnB(const std::vector<std::uint64_t> &a,
                    const std::vector<std::uint64_t> &b);

int main() {
  std::ifstream fin{"input"};

  if (!fin) {
    std::cerr << "The file could not be opened\n";
    return 1;
  }

  std::vector<std::uint64_t> a{};
  std::vector<std::uint64_t> b{};
  std::uint64_t num{};
  std::size_t word_num{0};
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

std::uint64_t solnA(const std::vector<std::uint64_t> &a,
                    const std::vector<std::uint64_t> &b) {
  assert(a.size() == b.size());

  std::size_t list_size{a.size()};
  std::vector<std::uint64_t> list_distances(list_size);

  for (std::size_t i{0}; i < list_size; ++i) {
    std::uint64_t larger = std::max(a[i], b[i]);
    std::uint64_t smaller = std::min(a[i], b[i]);
    list_distances[i] = larger - smaller;
  }

  return std::accumulate(list_distances.begin(), list_distances.end(), 0);
}

std::uint64_t solnB(const std::vector<std::uint64_t> &a,
                    const std::vector<std::uint64_t> &b) {
  assert(a.size() == b.size());

  std::unordered_map<std::uint64_t, std::uint64_t> list_b_counts{};

  for (const std::uint64_t &num : b) {
    list_b_counts[num]++;
  }

  std::size_t similarity_score{0};

  for (const std::uint64_t &num : a) {
    similarity_score += num * list_b_counts[num];
  }

  return similarity_score;
}
