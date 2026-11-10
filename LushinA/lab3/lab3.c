#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int read_guess(int n, int guess[])
{
    int i, c;
    int used[10] = { 0 };

    c = getchar();
    while (c == ' ' || c == '\n') {
        if (c == EOF) return 0;
        c = getchar();
    }

    for (i = 0; i < n; i++)
    {
        if (c < '0' || c > '9')
        {
            while (c != '\n' && c != EOF)
                c = getchar();
            return 0;
        }

        int digit = c - '0';

        if (i == 0 && digit == 0)
        {
            while (c != '\n' && c != EOF)
                c = getchar();
            return 0;
        }

        if (used[digit])
        {
            while (c != '\n' && c != EOF)
                c = getchar();
            return 0;
        }

        used[digit] = 1;
        guess[i] = digit;
        c = getchar();
    }

    if (c != '\n' && c != ' ' && c != EOF)
    {
        while (c != '\n' && c != EOF)
            c = getchar();
        return 0;
    }

    while (c != '\n' && c != EOF)
        c = getchar();

    return 1;
}

int main()
{
    int n, c;
    int secret[5], guess[5];
    int bulls, cows;
    int ok, good;
    int i, j;

    srand((unsigned)time(NULL));
    printf("GAME 'cows and bulls', input n from 2 to 5:\n");

    do
    {
        good = 1;
        if (scanf("%d", &n) != 1)
        {
            while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Bad input, try again, please.\n");
            good = 0;
        }
        else
        {
            while ((c = getchar()) != '\n' && c != EOF) {}
            if (n < 2 || n > 5)
            {
                printf("Wrong n, try again.\n");
                good = 0;
            }
        }
    } while (!good);

    for (i = 0; i < n; i++)
    {
        int r;
        do
        {
            r = rand() % 10;
            ok = 1;
            if (i == 0 && r == 0) {
                ok = 0;
            }
            for (j = 0; j < i; j++) {
                if (secret[j] == r) {
                    ok = 0;
                }
            }
        } while (!ok);
        secret[i] = r;
    }

    bulls = 0;
    while (bulls != n)
    {
        printf("Your guess: ");

        if (!read_guess(n, guess))
        {
            printf("Bad input! Enter %d unique digits (no leading zero).\n", n);
            continue;
        }

        bulls = 0;
        cows = 0;
        for (i = 0; i < n; i++)
        {
            if (guess[i] == secret[i])
            {
                bulls++;
            }
            else
            {
                for (j = 0; j < n; j++)
                {
                    if (i != j && guess[i] == secret[j])
                    {
                        cows++;
                    }
                }
            }
        }

        printf("Bulls: %d, Cows: %d\n", bulls, cows);
    }

    printf("You win!\n");
    return 0;
}
