# Demonstration of Benford's Law

[Benford's Law](http://en.wikipedia.org/wiki/Benford%27s_law) finds a practical
use in financial fraud detection because (for example) fictitious invoice amounts
chosen randomly may not exhibit the characteristic Pareto distribution of real data.

## Introduction

Benford's Law has been found to apply to many (but not all) real-world data sources.
In general, numbers that are
[distributed uniformly across many orders of magnitude](http://en.wikipedia.org/wiki/Benford%27s_law#Overview)
are likely to obey Benford's Law.

I have other data sets, but some (*e.g.*, gasoline prices for four years) have too
small a variation. The word count of my weekly activity reports definitely might be
suitable, as it varies from less than 100 to more than 6000.

## Methodology

To illustrate the effect, I used a convenient data set: the amount of
time spent writing my weekly activity reports to my supervisors.

### Data Sources

Approximately 350 data points were available; this is the `real_data` list. For
comparison purposes, I used a cryptographic pseudo-random number generator to
make a list about the same size of `fake_data`.

### Processing and Analysis

For each data set separately, counts were kept of the ten distinct possible
leading digits in a set of accumulators. Because the existence of leading zeros
was inconsistent throughout the data (in the `real_data` set it indicated 'no
data' and no actual data point started with a leading zero; the `fake_data` set
contained, on average, 0.1 percent zero values. To avoid the problem, leading
zero digits were neither counted nor plotted in either data set

## Results

Results of the analysis are shown in the figures:

<table border="0" width="100%">
<tr><td align="center">
<a href="https://github.com/jloughry/notes/new/raw/master/graphics/real_data.png"><img
src="https://github.com/jloughry/notes.new/raw/master/graphics/real_data.png"
alt="This is real data, collected from time spent writing weekly activity reports." width="300"/>
</td>
<td>&nbsp;</td>
<td align="center">
<a href="https://github.com/jloughry/notes/new/raw/master/graphics/fake_data.png"><img
src="https://github.com/jloughry/notes.new/raw/master/graphics/fake_data.png"
alt="This is fake data, just random numbers in the interval [0,1000)." width="300"/>
</td><tr>
</table>

## Interpretation

The `real_data` show a clear Benford's Law distribution; the `fake_data` show
a uniform distribution, as expected.

## Conclusions

Benford's Law applies to this particular kind of real-world data and is useful
for spotting faked results.

