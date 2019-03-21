using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Inheritance
{
    public class Base
    {
        string name;
        public Base()
        {
            name = "Base Constructor";
        }
        public void Display()
        {
            Console.Write("{0}\n", name);
        }

    }

    class Derived : Base
    {
        public Derived()
        {
            Console.Write("Derived Constructor\n");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Derived obj = new Derived();
            obj.Display();
            Console.ReadKey();
        }
    }
}