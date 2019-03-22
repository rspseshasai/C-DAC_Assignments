using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using A = System.Console;
namespace Interfaces
{
    interface myInterface1
    {
        void print();
    }
    interface myInterface2
    {
        void print();
    }
    class myClass:myInterface1,myInterface2
    {
        void myInterface1.print()
        {
            Console.WriteLine("Hi, I'm from Interface 1");
        }
        void myInterface2.print()
        {
            Console.WriteLine("Hi, I'm from Interface 2");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            myClass obj = new myClass();
            ((Interfaces.myInterface1)(obj)).print();
            ((Interfaces.myInterface2)(obj)).print();
            A.ReadKey();

        }
    }
}
