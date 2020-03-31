#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
using namespace std;

double mean(vector<double> &list);
double median(vector<double> &list);
double mode(vector<double> &list);
void printQuartiles(vector<double>& list);
vector<double>* getQuartiles(vector<double>& list);
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

  // debug - mode
  // static const double lst[] = {1,1,2,5,5,5,5,5,7,8,9,9,30,100,100,100,100,100,100,100};
  // vector<double> v(lst, lst + sizeof(lst) / sizeof(lst[0]));
  // printList(v);
  // cout << "mode: " << mode(v) << endl;

  // debug - quartiles
  static const double lst[] = {4, 17, 7, 14, 18, 12, 3, 16, 10, 4, 4, 12};
  vector<double> v(lst, lst + sizeof(lst) / sizeof(lst[0]));
  sort(v);
  printList(v);
  printQuartiles(v);

  cout << "Interquartile range: ";
  static const double num_list[] = {6, 12, 8, 10, 20, 16};
  static const double freq_list[] = {5, 4, 3, 2, 1, 5};
  vector<double> num(num_list, num_list + sizeof(num_list) / sizeof(num_list[0]));
  vector<double> freq(freq_list, freq_list + sizeof(freq_list) / sizeof(freq_list[0]));
  vector<double> dataSet;
  vector<double>* quartiles;

  n = num.size();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < freq[i]; j++) {
      dataSet.push_back(num[i]);
    }
  }

  quartiles = getQuartiles(dataSet);
  cout << setprecision(1) << fixed << quartiles->at(2) - quartiles->at(0) << endl;



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
  // sort(list);
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
  vector<vector<double>*> countSet;
  int i;
  int maxId = 0;

  for (i = 1; i < list.size(); i++) {
    if (list[i] == current) {
      count++;
    } else {
      vector<double>* tmp = new vector<double>(2);
      tmp->at(0) = current;
      tmp->at(1) = (double) count;
      countSet.push_back(tmp);
      current = list[i];
      count = 1;
    }
  }
  // last element(s)
  vector<double>* tmp = new vector<double>(2);
  tmp->at(0) = current;
  tmp->at(1) = (double) count;
  countSet.push_back(tmp);

  // debug
  // for (i = 0; i < countSet.size(); i++) {
  //   cout << "item: " << countSet[i]->at(0) << ", count: " << countSet[i]->at(1) << endl;
  // }

  for (i = 1; i < countSet.size(); i++) {
    if (countSet[maxId]->at(1) < countSet[i]->at(1)) {
      maxId = i;
    }
  }

  return countSet[maxId]->at(0);
}

void printQuartiles(vector<double>& list) {
    double q2 = median(list);
    double q1;
    double q3;
    vector<double> lowerHalf;
    vector<double> upperHalf;

    sort(list);

    if (list.size() % 2 == 0) {
        for (int i = 0; i < list.size() / 2; i++) {
            lowerHalf.push_back(list[i]);
        }
        for (int i = list.size() / 2; i < list.size(); i++) {
            upperHalf.push_back(list[i]);
        }
    } else {
        for (int i = 0; i < list.size() / 2; i++) {
            lowerHalf.push_back(list[i]);
        }
        for (int i = (list.size() / 2) + 1; i < list.size(); i++) {
            upperHalf.push_back(list[i]);
        }
    }

    q1 = median(lowerHalf);
    q3 = median(upperHalf);

    cout << setprecision(0) << fixed << q1 << endl;
    cout << setprecision(0) << fixed << q2 << endl;
    cout << setprecision(0) << fixed << q3 << endl;
}

vector<double>* getQuartiles(vector<double>& list) {
    double q2 = median(list);
    double q1;
    double q3;
    vector<double> lowerHalf;
    vector<double> upperHalf;
    // bug - setting initial size to 3 and then pushing back
    // other 3 values makes total size of 6
    // vector<double>* quartiles = new vector<double>(3);
    vector<double>* quartiles = new vector<double>();

    sort(list);

    if (list.size() % 2 == 0) {
        for (int i = 0; i < list.size() / 2; i++) {
            lowerHalf.push_back(list[i]);
        }
        for (int i = list.size() / 2; i < list.size(); i++) {
            upperHalf.push_back(list[i]);
        }
    } else {
        for (int i = 0; i < list.size() / 2; i++) {
            lowerHalf.push_back(list[i]);
        }
        for (int i = (list.size() / 2) + 1; i < list.size(); i++) {
            upperHalf.push_back(list[i]);
        }
    }

    q1 = median(lowerHalf);
    q3 = median(upperHalf);

    //debug
    // cout << "q1: " << q1 << " q2: " << q2 << " q3: " << q3 << endl;

    quartiles->push_back(q1);
    quartiles->push_back(q2);
    quartiles->push_back(q3);

    return quartiles;
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
