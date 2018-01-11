using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PrQ1
{
    class Program
    {
        Queue q = new Queue();
        static void Main(string[] args)
        {
            Program prog = new Program();
            prog.q.Insert(2, "Second");
            prog.q.Insert(1, "First");
            prog.q.Insert(5, "Fifth");
            prog.q.Insert(1, "First2");
            for (int i = 0; i < 5; i++)
            {
                try
                {
                    Console.WriteLine(prog.q.Remove());
                }
                catch(ArgumentOutOfRangeException e)
                {
                    Console.WriteLine("Out of range of queue");
                }
            }
            Console.ReadKey();
        }
    }
}
