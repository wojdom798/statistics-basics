using System;
using System.IO;
using System.Collections.Generic;

namespace BasicStatistics {
  class Program {
    
    static readonly string relativePath = @"..\";
    
    static readonly string fileName = "input04.txt";
    
    static void Main(string[] args) {
      Console.WriteLine("Reading file...");

      double n;
      List<double> numbers = new List<double>();

      try {
        using (StreamReader sr = new StreamReader(relativePath + fileName)) {
          String line = sr.ReadLine();
          n = Convert.ToDouble(line);
          Console.WriteLine(n);

          line = sr.ReadLine();
          foreach (string num in line.Split(' ')) {
            numbers.Add(Convert.ToDouble(num));
          }
        }
      } catch (IOException e) {
        Console.WriteLine("The file \"" + relativePath + fileName + "\" could not be read.");
        Console.WriteLine(e.Message);
      }

      sort(numbers);
      Console.WriteLine("sum = " + sum(numbers));

      foreach (double num in numbers) {
        Console.Write(num);
        Console.Write("; ");
      }

    } // /Main

    static void sort(List<double> l) {
      double tmp;
      for (int i = 0; i < l.Count; i++) {
        for (int j = i + 1; j < l.Count; j++) {
          if (l[i] > l[j]) {
            tmp = l[i];
            l[i] = l[j];
            l[j] = tmp;
          }
        }
      }
    } // /sort

    static double sum(List<double> l) {
      double result = 0;
      for (int i = 0; i < l.Count; i++) {
        result += l[i];
      }
      return result;
    } // /sum

  } // /Program class

}