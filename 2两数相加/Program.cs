using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2两数相加
{
    class Program
    {
        static void Main(string[] args)
        {
        }

        public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
        {
            ListNode res = null;
            ListNode track = null;
            bool jw = false;
            do
            {
                int temp = jw ? 1 : 0;
                jw = false;
                if (l1 != null)
                {
                    if ((l1.val + temp) >= 10) { jw = true; }
                    temp = (l1.val + temp) % 10;
                    l1 = l1.next;
                }
                if (l2 != null)
                {
                    if ((l2.val + temp) >= 10) { jw = true; }
                    temp = (l2.val + temp) % 10;
                    l2 = l2.next;
                }
                if (track == null)
                {
                    track = new ListNode();
                    res = track;
                    track.val = temp;
                }
                else
                {
                    track.next = new ListNode();
                    track.next.val = temp;
                    track = track.next;
                }

            } while (l1 != null || l2 != null || jw);
            return res;
        }
    }


    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int val = 0, ListNode next = null)
        {
            this.val = val;
            this.next = next;
        }
    }


}
