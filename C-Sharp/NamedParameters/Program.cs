using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NamedParameters
{
    class Program
    {
        class NamedParams
        {
            public int AddSum(int x, int y=0, int z=0)
            {
                int i = x = z;
                return i;
            }
        }
        static void Main(string[] args)
        {
            NamedParams obj = new NamedParams();
            int sum = obj.AddSum(1, z:2);
            Console.Write("Sum = {0}", sum);
            Console.ReadKey();
        }
    }
}
