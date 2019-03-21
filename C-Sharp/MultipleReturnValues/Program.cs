using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultipleReturnValues
{
    class Program
    {
        class MultipleReturn
        {
            public int AddSum(int x, int y, out int z)
            {
                int sum = x + x + y;
                z = x + y;
                return sum;
            }
        }
        static void Main(string[] args)
        {
            int x;
            MultipleReturn obj = new MultipleReturn();
            int sum = obj.AddSum(4, 5, out x);
            Console.Write("Sum = {0}\n", sum);
            Console.Write("X = {0}", x);
            Console.ReadKey();
        }
    }
}
