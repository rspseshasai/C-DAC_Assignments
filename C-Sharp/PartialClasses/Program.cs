using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PartialClasses
{
    partial class Pclass1
    {
        partial void method();
        public void print()
        {
            method();
        }
    }

    
    class Program
    {
        static void Main(string[] args)
        {
            Pclass1 obj = new Pclass1();
            obj.print();
            Console.ReadKey();
        }
    }
}
