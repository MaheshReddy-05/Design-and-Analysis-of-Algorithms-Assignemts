#include <iostream>
#include <vector>
using namespace std;
struct Mobile {
  int memory;
};
int partition(vector<Mobile> &arr, int low, int high) {
  int pivot = arr[high].memory;
  int i = low - 1;
  for (int j = low; j <= high - 1; j++) {
    if (arr[j].memory <= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return (i + 1);
}
void quickSort(vector<Mobile> &arr, int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}
int main() {
  vector<Mobile> mobiles = {{6}, {2}, {1}, {4}, {5}, {3}};
  int n = mobiles.size();
  quickSort(mobiles, 0, n - 1);
  cout << "Sorted mobiles by memory in ascending order: \n";
  for (int i = 0; i < n; i++) {
    cout << mobiles[i].memory << " ";
  }
  return 0;
}





