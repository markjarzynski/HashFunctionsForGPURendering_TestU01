#!/usr/bin/python
import csv

with open('data.csv', 'rb') as f:
    reader = csv.reader(f)
    l = list(reader)

print(l)
