using System;
using System.Runtime.InteropServices;

namespace TesterApp
{
    class Program
    {
        [DllImport("version.dll")]
        static extern int GetFileVersionInfoSize(string fileName, [Out] IntPtr handle);

        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");

            IntPtr handle = new IntPtr();
            int fileVersionInfoSize = GetFileVersionInfoSize("TesterApp.dll", handle);

            Console.WriteLine("fileVersionInfoSize: " + fileVersionInfoSize);
            Console.ReadLine();
        }
    }
}
