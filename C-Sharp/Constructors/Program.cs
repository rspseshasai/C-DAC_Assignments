using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Constructors
{
    class Program
    {
        public class ParentClass
        {
            public ParentClass(string s)
            {
                Console.WriteLine("Parent Constructor - {0}", s);
            }
            public ParentClass()
            {
                Console.WriteLine("Parent Constructor");
            }
        }
        public class ChildClass:ParentClass
        {
            public ChildClass():base("Base Constructor Called From Derived")
            {
                Console.WriteLine("Child Constructor");
            } 
        }
        static void Main(string[] args)
        {
            ParentClass obj = new ParentClass("Main String");
            Console.WriteLine();
            ChildClass obj1 = new ChildClass();
            Console.WriteLine();
            ParentClass obj2 = new ChildClass();
            Console.WriteLine();
            Console.ReadKey();
        }
    }
}