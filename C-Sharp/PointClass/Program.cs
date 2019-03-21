using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PointClass
{
    class PointClass
    {
        class Point
        {
            int a, b;
            public Point(int a, int b)
            {
                this.a = a;
                this.b = b;
            }
            public void display()
            {
                Console.Write("{0} {1}", a,b);
            }
        }
        static void Main(string[] args)
        {
            Point obj = new Point(4, 5);
            obj.display();
            Console.ReadKey();
        }
    }
}
