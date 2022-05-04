using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7整数反转
{
    class Program
    {
        static void Main(string[] args)
        {
        }
    }

    public class Solution
    {
        public int Reverse(int x)
        {
            int res = 0;
            if (x == 0) { return 0; }
            while (x >= 10 || x <= -10)
            {
                res = res * 10 + (x % 10);
                x /= 10;
            }
            if (res == 0) { return x; }
            else if (res < 0)
            {
                if (res < Int32.MinValue / 10)
                { return 0; }
                else
                {
                    if ((Int32.MinValue - x) > res * 10)
                    { return 0; }
                    else { return res * 10 + x % 10; }
                }
            }
            else if (res > 0)
            {
                if (res > Int32.MaxValue / 10)
                { return 0; }
                else
                {
                    if ((Int32.MaxValue - x) < res * 10)
                    { return 0; }
                    else { return res * 10 + x % 10; }
                }
            }
            return 0;
        }
    }

}
