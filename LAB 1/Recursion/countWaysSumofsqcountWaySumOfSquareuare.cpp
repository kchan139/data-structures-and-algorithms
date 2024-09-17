int countWaySumOfSquare(int x, int n = 2, int num = 1)
{
    int val = (x - pow(num, 2));
    if (val == 0) return 1;
    if (val < 0)  return 0;
 
    return countWaySumOfSquare (val, 2, num + 1) +
           countWaySumOfSquare (x, 2, num + 1);
}