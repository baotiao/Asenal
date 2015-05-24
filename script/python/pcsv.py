#!/usr/bin/env python
import csv
writer = csv.writer(open('stocks.csv', 'wb', buffering = 0))
writer.writerows([
    ('GOOG', 'Google, INC', 505, 0.4),
    ('YHOO', 'YaHoo! Inc', 22, 0.3)
    ])
stocks = csv.reader(open('stocks.csv', 'rb'))
print stocks
for ticker, name, price, pct in stocks:
    print '%s is %s (%s%%)' % (name, ticker, pct)
