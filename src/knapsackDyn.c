
<!-- saved from url=(0074)https://raw.githubusercontent.com/designerexpert/Knapsack/master/knapsac.c -->
<html><head><meta http-equiv="Content-Type" content="text/html; charset=UTF-8"></head><body><pre style="word-wrap: break-word; white-space: pre-wrap;">#include &lt;stdio.h&gt;
void loadfile()
{
    // TODO: Move Loading file logic here.
    printf("loadfile not implemented yet");
}

// A utility function that returns maximum of two integers
//int max(int a, int b) { return (a &gt; b) ? a : b; }

// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n, int solution[])
{
    // Base Case
    if (n == 0 || W == 0)
        return 0;

    // If weight of the nth item is more than Knapsack capacity W, then
    // this item cannot be included in the optimal solution
    if (wt[n - 1] &gt; W)
        return knapSack(W, wt, val, n - 1, solution);

    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
    {
        int number1 = val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1, solution);
        int number2 = knapSack(W, wt, val, n - 1, solution);

        int maxNum;

        if (number1 &gt; number2)
        {
            solution[n] = 1;
            maxNum = number1;
        }
        else
        {
            solution[n] = 0;
            maxNum = number2;
        }

        return maxNum;
    }
}

int main(int argc, char *argv[])
{
    // Parse Commandline arguments to get file and size
    // char *file = argv[0];
    // char *size = argv[1];
    FILE *fp;
    int buff[100] = {0};
    int weights[100] = {0};
    int values[100] = {0};
    int numbObjects = 0;
    int maxWeight = 100;

    int solution[100] = {0};

    int numberRead = 0;

    fp = fopen("./data/small1.txt", "r");

    for (int i = 0; i &lt; 100; i++)
    {

        for (int j = 0; j &lt; 3; j++)
        {
            int found = fscanf(fp, "%d", &amp;numberRead);
            if (found &gt; 0)
            {
                switch (j)
                {
                case 0:
                    numbObjects++;
                    break;
                case 1:
                    weights[i] = numberRead;
                    break;
                case 2:
                    values[i] = numberRead;
                    break;
                }
            }
        }
    }
    fclose(fp);

    printf("Total num of items in file is: %d\n", numbObjects);

    printf("The best value combination is: %d\n", knapSack(maxWeight, weights, values, numbObjects, solution));

    for (int i = 0; i &lt; 100; i++)
    {
        if (solution[i] == 1)
        {
            printf("Taking item number: %d\n", i);
        }
    }

    return 0;
}</pre></body></html>