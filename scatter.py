#!/usr/bin/env python3
import sys
import csv
import matplotlib.pyplot as plt

if not (len(sys.argv) > 1):
    exit()

filename = sys.argv[1]

with open(filename, 'r') as f:
    reader = csv.reader(f, delimiter='\t')
    l = list(reader)
    
name = []
speed = []
crush = []

for i in l[1:]:
    name.append(i[0])
    speed.append(float(i[1]))
    crush.append(int(i[2]))

print(name)
print(speed)
print(crush)

fig, ax = plt.subplots()
ax.scatter(speed, crush)

plt.xlabel(l[0][1])
plt.ylabel(l[0][2])

for i, txt in enumerate(name):
    ax.annotate(txt, (speed[i], crush[i]), xytext=(2, 12), textcoords='offset pixels', horizontalalignment='left', verticalalignment='top', fontsize=8)

plt.savefig('image.png')
