using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp_2
{
    class Program
    {
        static void Main(string[] args)
        {
            int? i = null;
            i = 0;
            i += 5;
            Console.Write("{0}\n", i);
            Console.Write("{0}\n", i.GetType());
            Console.ReadKey();
        }
    }
}
