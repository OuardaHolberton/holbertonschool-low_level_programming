int total_sum(int rows, int cols)
{
    int r;
    int total = 0;

    for (r = 1; r <= rows; r++)
    {
        total += row_sum(r, cols);
    }

    return total;
}
