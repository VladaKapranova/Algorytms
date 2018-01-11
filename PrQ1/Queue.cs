using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PrQ1
{
    class Queue
    {
        List<Element> queue = new List<Element>();
        public void Insert(int key, string st)
        {
            if (queue.Count == 0)
                queue.Add(new Element(key,st));
            else
            {
                for (int i = 0; i < queue.Count; i++)
                {
                    if (queue[i].key > key)
                    {
                        queue.Insert(i, new Element(key, st));
                        break;
                    }
                    else if (i == queue.Count - 1)
                    {
                        queue.Add(new Element(key, st));
                        break;
                    }
                }
            }
        }

        public string Remove()
        {
            string first = queue[0].st;
            queue.RemoveAt(0);
            return first;
        }
    }
}
