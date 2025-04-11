using System;

namespace Main {
  internal class Program {
    static void Main(string[] args) {
      var sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
      var sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
      var numbers = new List<int>();
      for(int i = 0; i < 10; i++) {
        numbers.Add(0);
      }
      string s;
      s = sr.ReadLine();
      for(int i = 0; i < s.Length; i++) {
        if(s[i] == '9' || s[i] == '6') {
           if(numbers[9]<numbers[6]) {
             numbers[9]++;
           } else {
             numbers[6]++;
           }
           continue;
        }
        numbers[s[i]-'0']++;
      }
      int ans = 0;
      for(int i = 0; i < 10; i++) {
        if(ans>numbers[i]) continue;
        ans = numbers[i];
      }
      sw.Write(ans);
      sw.Close();
      sr.Close();
    }
  }
}