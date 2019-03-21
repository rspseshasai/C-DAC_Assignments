using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParamValues
{
    class Program
    {
        class ParamValues
        {
            public int AddSum(int a, int b, params int[] values)
            {
                int sum=0;
                foreach(int i in values)
                {
                    sum += i;
                }
                return sum+a+b;
            }
        }
        static void Main(string[] args)
        {
            ParamValues obj = new ParamValues();
            int sum = obj.AddSum(1,2,3,4,5);
            Console.Write("Sum = {0}", sum);
            Console.ReadKey();
        }
    }
}
