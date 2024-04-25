#include<iostream>

int main() {
  std::string S1, S2;
  std::cin >> S1 >> S2;
  long long** common_size = new long long*[S1.size()];
  for (unsigned i = 0; i < S1.size(); ++i) {
    common_size[i] = new long long[S2.size()];
    for (unsigned j = 0; j < S2.size(); ++j) {
      if (i == 0 and j == 0) {
        common_size[i][j] = (S1[i] == S2[j]);
        continue;
      }
      if (i == 0) {
        if (S1[i] == S2[j]) {
          common_size[i][j] = 1;
          continue;
        }
        common_size[i][j] = common_size[i][j - 1];
        continue;
      }
      if (j == 0) {
        if (S1[i] == S2[j]) {
          common_size[i][j] = 1;
          continue;
        }
        common_size[i][j] = common_size[i - 1][j];
        continue;
      }
      if (S1[i] == S2[j]) {
        common_size[i][j] = common_size[i - 1][j - 1] + 1;
        continue;
      }
      if (common_size[i - 1][j] >= common_size[i][j - 1]){
        common_size[i][j] = common_size[i - 1][j];
        continue;
      }
      common_size[i][j] = common_size[i][j - 1];
    }
  }
  if (S1.size() <= S2.size()) {
    std::cout << common_size[S1.size() - 1][S2.size() - 1] * 100 / S1.size() << std::endl;
  }
  else {
    std::cout << common_size[S1.size() - 1][S2.size() - 1] * 100 / S2.size() << std::endl;
  }
  for (unsigned i = 0; i < S1.size(); ++i) {
    delete[] common_size[i];
  }
  delete[] common_size;
  return 0;
}