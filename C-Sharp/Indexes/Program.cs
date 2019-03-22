using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Indexes
{
    public class Employee
    {
        public int id
        {
            get;
            set;
        }
        public string name
        {
            get;
            set;
        }

    }
    public class IndexerSample
    {
        List<Employee> list = new List<Employee>();
        public IndexerSample()
        {
            list.Add(new Employee { id = 1, name = "Hii" });
            list.Add(new Employee { id = 2, name = "Hello" });
            list.Add(new Employee { id = 3, name = "Bye" });
        }
        public string this[int id]
        {
            get
            {
                return list.FirstOrDefault(emp => emp.id == id).name;
            }
            set
            {
                list.FirstOrDefault(emp => emp.id == id).name = value;
            }
        }
    }
    class program
    {
        static void Main(string[] args)
        {
            IndexerSample obj = new IndexerSample();
            for(int i=1;i<=3;i++)
                Console.WriteLine(obj[i]);
            Console.ReadKey();
        }
    }
}