using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 数组CSharp
{
    internal class _1两数之和
    {
        public int[] TwoSum(int[] nums, int target)
        {
            int a = 0;
            int b = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                for (int j = i + 1; j < nums.Length; j++)
                {
                    if ((nums[i] + nums[j]) == target)
                    {
                        return new int[] { i, j };
                    }
                }
            }
            return new int[] { a, b };
        }
    }
}
