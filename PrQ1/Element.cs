using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PrQ1
{
    class Element
    {
        public int key { private set;  get; }
        public string st { private set; get; } //Автоматическое свойство
        /// <summary>
        /// Конструктор класса
        /// </summary>
        /// <param name="key">Ключ</param>
        /// <param name="st">Значение</param>
        public Element(int key, string st)
        {
            this.key = key;
            this.st = st;
        }


    }
}
