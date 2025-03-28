using System;

namespace Main {
    internal class Program {
        static void Main(string[] args) {
            StreamReader inputStream = new StreamReader(
                new BufferedStream(
                    Console.OpenStandardInput()
                )
            );
            StreamWriter outputStream = new StreamWriter(
                new BufferedStream(
                Console.OpenStandardOutput()
                )
            );
            var inputString = inputStream.ReadLine();
            if(inputString != null) {
                var inputArray  = inputString.Split();
                var sum = 0;
                foreach(string itm in inputArray) {
                    sum += Int32.Parse(itm);
                }
                outputStream.Write(sum+"");
            }
            outputStream.Flush();
            outputStream.Close();
            inputStream.Close();
        }
    }
}