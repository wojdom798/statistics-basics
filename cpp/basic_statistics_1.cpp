#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <fstream>
using namespace std;

double mean(vector<double> &list);
double median(vector<double> &list);
double mode(vector<double> &list);
void sort(vector<double> &list);
void printList(vector<double> &list);

int main(void) {
  string filePath = "..\\input04.txt";
  ifstream infile;
  char data[100];
  string sdata;

  int n;
  double tmp;
  vector<double> numbers;

  // cin >> n;
  // for (int i = 0; i < n; i++)
  // {
  //   cin >> tmp;
  //   numbers.push_back(tmp);
  // }

  infile.open(filePath);
  infile >> sdata;
  n = stoi(sdata);

  for (int i = 0; i < n; i++) {
    infile >> sdata;
    numbers.push_back(stod(sdata));
  }
  infile.close();

  cout << mean(numbers) << endl;
  cout << median(numbers) << endl;
  cout << mode(numbers) << endl;

  return 0;
}

double mean(vector<double> &list) {
  double mean = 0;
  for (int i = 0; i < list.size(); i++) {
    mean += list[i];
  }
  return mean / list.size();
}

double median(vector<double> &list) {
  sort(list);
  int index;
  if (list.size() % 2 == 0) {
    index = list.size() / 2;
    return (list[index - 1] + list[index]) / 2;
  } else {
    return list[list.size() / 2];
  }
}

double mode(vector<double> &list) {
  int count = 1;
  double current = list[0];
  vector<int> countSet;
  int maxId = 0;
  int modeIndex = 0;
  int i;

  for (i = 0; i < list.size(); i++) {
    if (list[i] == current) {
      count++;
    }
    else {
      countSet.push_back(count);
      count = 1;
      current = list[i];
    }
  }

  for (i = 0; i < countSet.size(); i++) {
    if (countSet[i] > countSet[maxId]) {
      maxId = i;
    }
  }

  for (i = 0; i < maxId; i++) {
    modeIndex += countSet[i];
  }

  return list[modeIndex];
}

void sort(vector<double> &list)
{
  double tmp;
  for (int i = 0; i < list.size(); i++) {
    for (int j = i + 1; j < list.size(); j++) {
      if (list[j] < list[i]) {
        tmp = list[i];
        list[i] = list[j];
        list[j] = tmp;
      }
    }
  }
}

void printList(vector<double> &list)
{
  for (int i = 0; i < list.size(); i++) {
    cout << list[i] << " ";
  }
  cout << endl;
}
