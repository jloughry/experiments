#include <stdio.h>
#include <stdlib.h>

typedef double money;

int main(void)
{
	/* for now, prices are double, but they really should be fixed decimal */

	/* "AAPL closed unchanged today, after some volatility." */

	money stockPricesYesterday[] = {539.78, 520.0, 521.0, 600.0, 310.0,
		3.14159, 700.0, 2.0, -1.7, 0, 0, 0, 0, 0, 100.0, 12.12, 100.0, 539.78};

	int buy = 0;
	int sell = 0;
	int last = (int)(sizeof stockPricesYesterday) / (sizeof (money));
	money current_profit = 0.0;
	money best_profit = 0.0;

	for (buy = 0; buy < last - 1; buy++) {
		for (sell = 1 + buy; sell < last; sell++) {
			current_profit = stockPricesYesterday[sell] - stockPricesYesterday[buy];
			if (current_profit > best_profit) {
				best_profit = current_profit;
			}
		}
	}
	printf("Best profit is %.2lf\n", best_profit); /* format to look like dollars */

	return EXIT_SUCCESS;
}

