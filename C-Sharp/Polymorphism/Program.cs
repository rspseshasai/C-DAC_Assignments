using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Polymorphism
{
    public class Base
    {
        public string name;
        public Base()
        {
            name = "Base Name";
        }
        public virtual void Display()
        {
            Console.Write("Base Class Name : {0}\n", name);
        }

    }

    class Derived : Base
    {
        string name_der;
        public Derived()
        {
            name_der = "Der Name";
            //Console.Write("Derived Constructor\n");
        }
        public override void Display()
        {
            Console.Write("\nIn Derived\n\tDerived Class Name : {0}\n\tBase Class Name : {1}\n", name_der, name);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Base obj = new Base();
            obj.Display();

            Console.Write("\n");

            Derived obj1 = new Derived();
            obj1.Display();

            Console.Write("\n");

            Base obj2 = new Derived();
            obj2.Display();

            Console.Write("\n");

            Console.ReadKey();
        }
    }
}
